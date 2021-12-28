library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tpiu_to_stream is
	port (
		iClk: in  std_logic;
		iRst: in  std_logic;

		-- Data from TPIU that is clocked using iClk.
		iData: in std_logic_vector(31 downto 0);

		-- Connect to an AXIS FIFO that is in turn connected to the Aurora sink.
		-- Ignore the tready signal, set tkeep to "1111"
		oData:  out std_logic_vector(31 downto 0);
		oValid: out std_logic;
		oLast:  out std_logic
	);
end entity;

architecture behavioral of tpiu_to_stream is
	signal rDataA:           std_logic_vector(31 downto 0);
	signal rDataB:           std_logic_vector(31 downto 0);

	signal rData:            std_logic_vector(31 downto 0);
	signal rValid:           std_logic;
	signal rLast:            std_logic;

	signal rFrameCounter:    unsigned(11 downto 0);
	signal rFrameInProgess:  std_logic;
	signal rFullSyncSent:    std_logic;
	signal rFullSyncPending: std_logic;

begin
	pMain: process(iRst, iClk)
	begin
		if iRst = '1' then
			rDataA           <= (others => '1');
			rDataB           <= (others => '1');
			rData            <= (others => '1');
			rValid           <= '0';
			rLast            <= '0';
			rFrameCounter    <= (others => '1');
			rFrameInProgess  <= '0';
			rFullSyncSent    <= '0';
			rFullSyncPending <= '0';
		elsif rising_edge(iClk) then
			rDataA <= iData;
			rDataB <= rDataA;
			rData <= rDataB;

			if rFullSyncSent = '1' then
				rFrameCounter <= (others => '1');
				rFullSyncSent <= '0';
			elsif rFrameCounter /= 0 then
				rFrameCounter <= rFrameCounter - 1;
				rFullSyncPending <= '0';
			else
				rFullSyncPending <= '1';
			end if;

			rLast <= '0';

			if rDataB = x"7FFFFFFF" then
				-- Full sync words should pass through once in a while to provide
				-- alignment points for the decoder. We use a counter to count the
				-- number of frames since the last full sync that was written to
				-- the FIFO. If there is a long gap in trace data, we want the new
				-- data to be immediately preceded by a start-of-packet followed by
				-- a full sync. This is required to guarantee that the receiver can
				-- perform lane alignment synchronisation and CoreSight alignment
				-- synchronisation if it was switched on during the gap.
				--
				-- We use the following rules:
				--
				--  - The first full sync after the counter has expired is passed
				--    through as end-of-packet.
				--  - Any further full syncs are dropped if they're followed by
				--    another full sync.
				--  - The last full sync before actual data is then used as the
				--    start-of-packet.

				if rFullSyncPending = '0' then
					-- last full sync was recent enough
					rValid <= '0';
				elsif rFrameInProgess = '1' then
					rValid <= '1';
					rLast <= '1';
					rFrameInProgess <= '0';
				elsif rDataA = x"7FFFFFFF" then
					-- the next word is also a full sync; delay sending the full
					-- sync until right before the next data word
					rValid <= '0';
				else
					-- send the full sync
					rValid <= '1';
					rFrameInProgess <= '1';
					rFullSyncSent <= '1';
					rFullSyncPending <= '0';
				end if;
			elsif rDataB = x"7FFF7FFF" or rDataB = x"FFFFFFFF" then
				-- these frames are never useful
				rValid <= '0';
			else
				rValid <= '1';
				rFrameInProgess <= '1';
			end if;
		end if;
	end process;

	oData <= rData;
	oValid <= rValid;
	oLast <= rLast;
end architecture;
