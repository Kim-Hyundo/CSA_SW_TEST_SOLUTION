library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

use work.util_pkg.all;

entity stream_width_expander is
	generic (
		gBitsPerSymbol:     positive;
		-- there are always two input symbols per beat
		gOutSymbolsPerBeat: positive
	);
	port (
		iClk:               in  std_logic;
		iRst:               in  std_logic;

		iData:              in  std_logic_vector(2 * gBitsPerSymbol - 1 downto 0);
		iValid:             in  std_logic;
		iLast:              in  std_logic;

		oData:              out std_logic_vector(gOutSymbolsPerBeat * gBitsPerSymbol - 1 downto 0);
		oValid:             out std_logic;
		oLast:              out std_logic;
		oEmpty:             out std_logic_vector(gOutSymbolsPerBeat - 1 downto 0)
	);
end entity;

architecture behavioral of stream_width_expander is
	type tArray is array(natural range <>) of std_logic_vector(gBitsPerSymbol - 1 downto 0);

	signal wInData:        tArray(1 downto 0);
	signal wOutData:       tArray(gOutSymbolsPerBeat - 1 downto 0);

	type tState is record
		-- delayed version of iData and iLast, needed if we can't process iData
		-- right away
		in_data:            tArray(1 downto 0);
		in_last:            std_logic;
		-- whether we need to load symbols from in_data
		--   _mux = '0': we need to load both symbols from in_data
		--   _mux = '1': we only need to load in_data(1)
		load_delayed:       std_logic;
		load_delayed_mux:   std_logic;
		-- counts the number of valid bytes in data, already including any data
		-- that is scheduled to be loaded using the load_delayed mechanism
		counter:            unsigned(minbits(gOutSymbolsPerBeat) - 1 downto 0);
		-- output registers
		data:               tArray(gOutSymbolsPerBeat - 1 downto 0);
		valid:              std_logic;
		last:               std_logic;
		empty:              std_logic_vector(gOutSymbolsPerBeat - 1 downto 0);
	end record;

	constant cStateInit: tState := (
		in_data             => (others => (others => 'U')),
		in_last             => 'U',
		load_delayed        => '0',
		load_delayed_mux    => 'U',
		counter             => (others => '0'),
		data                => (others => (others => 'U')),
		valid               => '0',
		last                => 'U',
		empty               => (others => 'U')
	);

	signal rState:         tState := cStateInit;
	signal wState:         tState;

begin
	pCombinatorial: process(rState, wInData, iValid, iLast)
	begin
		wState              <= rState;

		wState.in_data      <= wInData;
		wState.in_last      <= iLast;

		wState.load_delayed <= '0';
		wState.load_delayed_mux <= 'U';

		wState.valid        <= '0';
		wState.last         <= 'U';
		wState.empty        <= (others => 'U');

		for i in wState.data'range loop
			if i = 1 and rState.load_delayed = '1' and rState.load_delayed_mux = '0' then
				wState.data(i) <= rState.in_data(1);
			elsif i = 0 and rState.load_delayed = '1' and rState.load_delayed_mux = '0' then
				wState.data(i) <= rState.in_data(0);
			elsif i = 0 and rState.load_delayed = '1' and rState.load_delayed_mux = '1' then
				wState.data(i) <= rState.in_data(1);
			elsif i = rState.counter then
				wState.data(i) <= wInData(0);
			elsif i /= 0 and i - 1 = rState.counter then
				wState.data(i) <= wInData(1);
			end if;
		end loop;

		if iValid = '1' then
			if rState.load_delayed = '1' and rState.in_last = '1' then
				-- evil case: We have old symbols in in rState.in_data that also
				-- form the end of a packet. Therefore, we don't use the new data
				-- at all until the next clock cycle.
				wState.counter <= to_unsigned(2, rState.counter'length);
				wState.valid  <= '1';
				wState.last   <= '1';
				wState.empty  <= (others => '1');
				wState.empty(0) <= '0';
				wState.empty(1) <= rState.load_delayed_mux;
				wState.load_delayed  <= '1';
				wState.load_delayed_mux <= '0';
			elsif rState.counter = gOutSymbolsPerBeat - 1 then
				-- wrapping case: the new data doesn't fit into the current output
				-- beat.
				wState.counter <= to_unsigned(1, rState.counter'length);
				wState.valid  <= '1';
				wState.last   <= '0';
				wState.empty  <= (others => '0');
				wState.load_delayed  <= '1';
				wState.load_delayed_mux <= '1';
			elsif rState.counter = gOutSymbolsPerBeat - 2 then
				-- new input beat exactly fills the output beat
				wState.counter <= to_unsigned(0, rState.counter'length);
				wState.valid  <= '1';
				wState.last   <= iLast;
				wState.empty  <= (others => '0');
			elsif iLast = '1' then
				wState.counter <= to_unsigned(0, rState.counter'length);
				wState.valid  <= '1';
				wState.last   <= '1';
				for i in wState.empty'range loop
					if i < 2 or i - 2 < rState.counter then
						wState.empty(i) <= '0';
					else
						wState.empty(i) <= '1';
					end if;
				end loop;
			else
				-- normal case
				wState.counter <= rState.counter + 2;
			end if;
		elsif rState.load_delayed = '1' and rState.in_last = '1' then
			wState.counter   <= to_unsigned(0, rState.counter'length);
			wState.valid     <= '1';
			wState.last      <= '1';
			wState.empty     <= (others => '1');
			wState.empty(0)  <= '0';
			wState.empty(1)  <= rState.load_delayed_mux;
		end if;
	end process;

	pSynchronous: process(iRst, iClk)
	begin
		if iRst = '1' then
			rState           <= cStateInit;
		elsif rising_edge(iClk) then
			rState           <= wState;
		end if;
	end process;

	wInData(0) <= iData(1 * gBitsPerSymbol - 1 downto 0 * gBitsPerSymbol);
	wInData(1) <= iData(2 * gBitsPerSymbol - 1 downto 1 * gBitsPerSymbol);

	eOut: for i in gOutSymbolsPerBeat - 1 downto 0 generate
		wOutData(i) <= rState.data(i) when rState.valid = '1' and rState.empty(i) = '0' else (others => 'U');
		oData((i + 1) * gBitsPerSymbol - 1 downto i * gBitsPerSymbol) <= wOutData(i);
	end generate;
	oValid <= rState.valid;
	oLast  <= rState.last;
	oEmpty <= rState.empty;
end architecture;
