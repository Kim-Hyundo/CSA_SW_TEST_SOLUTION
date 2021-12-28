library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity led_common is
	generic (
		gTraceSdrFreq:  real;
		gUserFreq:      real := 156.25e6
	);
	port (
		iClk125:        in  std_logic;
		iClk74_25:      in  std_logic;
		iClkTraceSdr:   in  std_logic;
		iClkUser:       in  std_logic := '0';

		-- to drive the oTraceActive LED
		iTraceDataSdr:  in  std_logic_vector(31 downto 0);

		-- to drive the oFifoOverflow LED
		iFifoReady:     in  std_logic := '1';
		iFifoValid:     in  std_logic := '0';

		oBlink125:      out std_logic; -- has a frequency of 1 Hz if iClk125 is correct
		oBlink74_25:    out std_logic; -- has a frequency of 1 Hz if iClk74_25 is correct
		oBlinkTraceSdr: out std_logic; -- has a frequency of 1 Hz if iClkTraceSdr is correct
		oBlinkUser:     out std_logic; -- has a frequency of 1 Hz if iClkUser is correct (HSSTP only)

		oTraceActive:   out std_logic; -- illuminates for 0.1 s if non-idle trace data is detected
		oFifoOverflow:  out std_logic  -- illuminates for 1.0 s if an overflow is detected (HSSTP only)
	);
end entity;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity led_blinker is
	generic (
		gFreq:          real
	);
	port (
		iClk:           in  std_logic;
		oBlink:         out std_logic
	);
end entity;

architecture behavioral of led_common is
	function minbits(num: positive) return natural is
		variable i: natural := 1;

	begin
		for j in 0 to 32 loop
			if i >= num then
				return j;
			else
				i := i * 2;
			end if;
		end loop;
		return 32;
	end function;

	signal rTraceDataSdr: std_logic_vector(31 downto 0);

	signal rCntActive:    unsigned(minbits(natural(gTraceSdrFreq * 0.1)) - 1 downto 0) := (others => '0');
	signal rCntOverflow:  unsigned(minbits(natural(gTraceSdrFreq * 1.0)) - 1 downto 0) := (others => '0');
	signal rActive:       std_logic := '0';
	signal rOverflow:     std_logic := '0';

begin
	yBlink125:      entity work.led_blinker generic map (gFreq => 125.00e6     ) port map (iClk => iClk125,      oBlink => oBlink125     );
	yBlink74_25:    entity work.led_blinker generic map (gFreq =>  75.25e6     ) port map (iClk => iClk74_25,    oBlink => oBlink74_25   );
	yBlinkTraceSdr: entity work.led_blinker generic map (gFreq => gTraceSdrFreq) port map (iClk => iClkTraceSdr, oBlink => oBlinkTraceSdr);
	yBlinkUser:     entity work.led_blinker generic map (gFreq => gUserFreq    ) port map (iClk => iClkUser,     oBlink => oBlinkUser    );

	pActive: process(iClkTraceSdr)
	begin
		if rising_edge(iClkTraceSdr) then
			rTraceDataSdr <= iTraceDataSdr;
			if rTraceDataSdr /= x"7FFFFFFF" and rTraceDataSdr /= x"7FFF7FFF" then
				rCntActive <= to_unsigned(natural(gTraceSdrFreq * 0.1) - 1, rCntActive'length);
				rActive <= '1';
			elsif rCntActive > 0 then
				rCntActive <= rCntActive - 1;
			else
				rActive <= '0';
			end if;
		end if;
	end process;

	oTraceActive <= rActive;

	pOverflow: process(iClkTraceSdr)
	begin
		if rising_edge(iClkTraceSdr) then
			if iFifoValid = '1' and iFifoReady = '0' then
				rCntOverflow <= to_unsigned(natural(gTraceSdrFreq * 1.0) - 1, rCntOverflow'length);
				rOverflow <= '1';
			elsif rCntOverflow > 0 then
				rCntOverflow <= rCntOverflow - 1;
			else
				rOverflow <= '0';
			end if;
		end if;
	end process;

	oFifoOverflow <= rOverflow;
end architecture;

architecture behavioral of led_blinker is
	function minbits(num: positive) return natural is
		variable i: natural := 1;

	begin
		for j in 0 to 32 loop
			if i >= num then
				return j;
			else
				i := i * 2;
			end if;
		end loop;
		return 32;
	end function;

	signal rCnt:       unsigned(minbits(natural(gFreq / 2.0)) - 1 downto 0) := (others => '0');
	signal rBlink:     std_logic := '0';

begin
	pBlink: process(iClk)
	begin
		if rising_edge(iClk) then
			if rCnt /= natural(gFreq / 2.0) - 1 then
				rCnt <= rCnt + 1;
			else
				rCnt <= (others => '0');
				rBlink <= not rBlink;
			end if;
		end if;
	end process;

	oBlink <= rBlink;
end architecture;
