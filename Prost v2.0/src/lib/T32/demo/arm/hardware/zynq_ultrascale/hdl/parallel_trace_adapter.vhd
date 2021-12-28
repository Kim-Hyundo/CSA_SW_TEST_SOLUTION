library ieee;
use ieee.std_logic_1164.all;

-- adapter that takes a continuous data stream from a TPIU and explicitly instantiates DDR buffers
entity parallel_trace_adapter is
	generic (
		gPlatform:       string;         -- determines type of DDR buffers to use; use one of "ZYNQ7000", "ULTRASCALE", "CYCLONE5"
		gBitsIn:         positive := 32; -- port width from processor to fabric
		gBitsOut:        positive := 16; -- port width from fabric to FPGA pins; must be gBitsIn or gBitsIn / 2; the latter is only allowed if gBitsIn == 32 or gBitsIn == 16
		gPipelineStages: natural  :=  2  -- number of additional pipeline stages to help with timing
	);
	port (
		iClk:  in  std_logic; -- SDR clock used to sample iData
		iData: in  std_logic_vector(gBitsIn - 1 downto 0);

		-- these must be directly connected to output pins
		oClk:  out std_logic;
		oData: out std_logic_vector(gBitsOut - 1 downto 0)
	);
end entity;

library ieee;
use ieee.std_logic_1164.all;

-- instantiate the appropriate type of DDR buffer needed for different FPGAs
entity ddr_buffer is
	generic (
		gPlatform:        string;
		gBits:            natural
	);
	port (
		iClk:             in  std_logic;
		iData0:           in  std_logic_vector(gBits - 1 downto 0);
		iData1:           in  std_logic_vector(gBits - 1 downto 0);
		oData:            out std_logic_vector(gBits - 1 downto 0)
	);
end entity;

library ieee;
use ieee.std_logic_1164.all;

-- generate the test pattern expected by TRACE32
entity test_pattern_generator is
	generic (
		gBits:            positive
	);
	port (
		iClk:             in  std_logic;
		oData0:           out std_logic_vector(gBits - 1 downto 0);
		oData1:           out std_logic_vector(gBits - 1 downto 0)
	);
end entity;

architecture structural of ddr_buffer is
	-- define minimal components here instead of using
	-- VCOMPONENTS/ALTERA_MF_COMPONENTS libraries so we can use a single VHDL
	-- file for both vendors

	component ODDR
		generic (
			DDR_CLK_EDGE: string
		);
		port (
			Q:            out std_logic;
			C:            in  std_logic;
			CE:           in  std_logic;
			D1:           in  std_logic;
			D2:           in  std_logic;
			R:            in  std_logic;
			S:            in  std_logic
		);
	end component;

	component ODDRE1
		generic (
			SRVAL:        std_logic
		);
		port (
			Q:            out std_logic;
			C:            in  std_logic;
			D1:           in  std_logic;
			D2:           in  std_logic;
			SR:           in  std_logic
		);
	end component;

	component ALTDDIO_OUT
		generic (
			WIDTH:        integer
		);
		port (
			DATAIN_H:     in  std_logic;
			DATAIN_L:     in  std_logic;
			OUTCLOCK:     in  std_logic;
			ASET:         in  std_logic;
			DATAOUT:      out std_logic
		);
	end component;

begin
	eBits: for i in gBits - 1 downto 0 generate
		eZynq: if gPlatform = "ZYNQ7000" generate
			yOddr: ODDR generic map (
				DDR_CLK_EDGE => "SAME_EDGE"
			) port map (
				Q            => oData(i),
				C            => iClk,
				CE           => '1',
				D1           => iData0(i),
				D2           => iData1(i),
				R            => '0',
				S            => '0'
			);
		end generate;

		eUltraScale: if gPlatform = "ULTRASCALE" generate
			yOddre1: ODDRE1 generic map (
				SRVAL        => '1'
			) port map (
				Q            => oData(i),
				C            => iClk,
				D1           => iData0(i),
				D2           => iData1(i),
				SR           => '0'
			);
		end generate;

		eCyclone5: if gPlatform = "CYCLONE5" generate
			yAltddioOut: ALTDDIO_OUT generic map (
				WIDTH        => 1
			) port map (
				DATAIN_H     => iData0(i),
				DATAIN_L     => iData1(i),
				OUTCLOCK     => iClk,
				ASET         => '0',
				DATAOUT      => oData(i)
			);
		end generate;
	end generate;
end architecture;

library ieee;
use ieee.numeric_std.all;

architecture behavioral of parallel_trace_adapter is
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

	type tDataPipeline is array(gPipelineStages downto 0) of std_logic_vector(gBitsIn - 1 downto 0);
	signal wrDataPipeline: tDataPipeline;

	-- these signals can be constrained to be placed right before the matching IOBs
	signal rData0: std_logic_vector(gBitsOut - 1 downto 0) := (others => '0');
	signal rData1: std_logic_vector(gBitsOut - 1 downto 0) := (others => '0');

	-- Prevent instantiation of a shift register. The entire point of the
	-- pipeline stages is to allow spreading across the FPGA, so merging them
	-- into a RAM-based shift register is counterproductive.
	attribute PRESERVE: boolean;
	attribute PRESERVE of rData0: signal is TRUE;
	attribute PRESERVE of rData1: signal is TRUE;
	attribute PRESERVE of wrDataPipeline: signal is TRUE;

begin
	wrDataPipeline(gPipelineStages) <= iData;

	ePipeline: for i in gPipelineStages - 1 downto 0 generate
		pPipleline: process(iClk)
		begin
			if rising_edge(iClk) then
				wrDataPipeline(i) <= wrDataPipeline(i + 1);
			end if;
		end process;
	end generate;

	eDirect: if gBitsIn = gBitsOut generate
		signal rClk: std_logic := '0';

	begin
		pClk: process(iClk)
		begin
			if rising_edge(iClk) then
				rClk <= not rClk;
				rData0 <= wrDataPipeline(0);
				rData1 <= wrDataPipeline(0);
			end if;
		end process;

		yBufferData: entity work.ddr_buffer generic map (
			gPlatform => gPlatform,
			gBits     => gBitsOut
		) port map (
			iClk      => iClk,
			iData0    => rData0,
			iData1    => rData1,
			oData     => oData
		);

		yBufferClk: entity work.ddr_buffer generic map (
			gPlatform => gPlatform,
			gBits     => 1
		) port map (
			iClk      => iClk,
			iData0(0) => rClk,
			iData1(0) => rClk,
			oData(0)  => oClk
		);
	end generate;

	eIndirect: if gBitsIn = gBitsOut * 2 and (gBitsIn = 32 or gBitsIn = 16) generate
		signal wPatternData0: std_logic_vector(gBitsOut - 1 downto 0);
		signal wPatternData1: std_logic_vector(gBitsOut - 1 downto 0);

		-- A TPIU with port size 16  can never produce the pattern 0xFFFF 0x0000
		-- in continuous mode, and a TPIU with port size 32 can never produce the
		-- word 0xFFFFFFFF, but this occurs in the test pattern set by T32. This
		-- pattern cycles through all four available pattern types, using each
		-- pattern for gBitsIn cycles, so if we count to 4 * gBitsIn without
		-- seeing the special pattern again, we can assume that test pattern
		-- generation has been switched off.
		signal rUseTestPattern: std_logic := '0';
		signal rCounter: unsigned(minbits(gBitsIn) + 2 - 1 downto 0) := (others => '0');

	begin
		eDetector16: if gBitsIn = 16 generate
			signal rAllOnes: std_logic := '0';

		begin
			pTestPatternDetector: process(iClk)
			begin
				if rising_edge(iClk) then
					if wrDataPipeline(0) = x"FFFF" then
						rAllOnes <= '1';
					else
						rAllOnes <= '0';
					end if;

					if wrDataPipeline(0) = x"0000" and rAllOnes = '1' then
						rCounter <= (others => '1');
						rUseTestPattern <= '1';
					elsif rCounter > 0 then
						rCounter <= rCounter - 1;
						rUseTestPattern <= '1';
					else
						rUseTestPattern <= '0';
					end if;
				end if;
			end process;
		end generate;

		eDetector32: if gBitsIn = 32 generate
		begin
			pTestPatternDetector: process(iClk)
			begin
				if rising_edge(iClk) then
					if wrDataPipeline(0) = x"FFFFFFFF" then
						rCounter <= (others => '1');
						rUseTestPattern <= '1';
					elsif rCounter > 0 then
						rCounter <= rCounter - 1;
						rUseTestPattern <= '1';
					else
						rUseTestPattern <= '0';
					end if;
				end if;
			end process;
		end generate;

		yTestPatternGenerator: entity work.test_pattern_generator generic map (
			gBits => gBitsOut
		) port map (
			iClk => iClk,
			oData0 => wPatternData0,
			oData1 => wPatternData1
		);

		pData: process(iClk)
		begin
			if rising_edge(iClk) then
				if rUseTestPattern = '1' then
					rData0 <= wPatternData0;
					rData1 <= wPatternData1;
				else
					rData0 <= wrDataPipeline(0)(gBitsOut - 1 downto 0);
					rData1 <= wrDataPipeline(0)(gBitsIn - 1 downto gBitsOut);
				end if;
			end if;
		end process;

		yBufferData: entity work.ddr_buffer generic map (
			gPlatform => gPlatform,
			gBits     => gBitsOut
		) port map (
			iClk      => iClk,
			iData0    => rData0,
			iData1    => rData1,
			oData     => oData
		);

		yBufferClk: entity work.ddr_buffer generic map (
			gPlatform => gPlatform,
			gBits     => 1
		) port map (
			iClk      => iClk,
			iData0(0) => '1',
			iData1(0) => '0',
			oData(0)  => oClk
		);
	end generate;
end architecture;

library ieee;
use ieee.numeric_std.all;

architecture behavioral of test_pattern_generator is
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

	signal rCounter: unsigned(minbits(gBits) downto 0) := (others => '0');
	signal rData0: std_logic_vector(gBits - 1 downto 0);
	signal rData1: std_logic_vector(gBits - 1 downto 0);

begin
	pRegisters: process(iClk)
	begin
		if rising_edge(iClk) then
			rCounter <= rCounter + 1;

			for i in gBits - 1 downto 0 loop
				if rCounter(rCounter'high downto rCounter'high - 1) = "00" then
					rData0(i) <= '1';
					rData1(i) <= '0';
				elsif rCounter(rCounter'high downto rCounter'high - 1) = "01" then
					if i mod 2 = 0 then
						rData0(i) <= '1';
						rData1(i) <= '0';
					else
						rData0(i) <= '0';
						rData1(i) <= '1';
					end if;
				elsif rCounter(rCounter'high downto rCounter'high - 1) = "10" then
					rData0(i) <= '1';
					rData1(i) <= '1';
					if rCounter(rCounter'high - 2 downto 0) = i / 2 then
						if i mod 2 = 0 then
							rData0(i) <= '0';
						else
							rData1(i) <= '0';
						end if;
					end if;
				else
					rData0(i) <= '0';
					rData1(i) <= '0';
					if rCounter(rCounter'high - 2 downto 0) = i / 2 then
						if i mod 2 = 0 then
							rData0(i) <= '1';
						else
							rData1(i) <= '1';
						end if;
					end if;
				end if;
			end loop;
		end if;
	end process;

	oData0 <= rData0;
	oData1 <= rData1;
end architecture;
