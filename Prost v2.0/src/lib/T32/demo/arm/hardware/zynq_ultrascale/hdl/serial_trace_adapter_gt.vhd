library IEEE;
use IEEE.std_logic_1164.all;

entity serial_trace_adapter_gt is
	port (
		iTraceClk:  in  std_logic;
		iTraceRst:  in  std_logic;
		iUserClk:   in  std_logic;
		iUserRst:   in  std_logic;

		-- synchronous to iTraceClk
		iData:      in  std_logic_vector(31 downto 0);

		-- for external overflow detection; synchronous to iTraceClk
		oFifoReady: out std_logic;
		oFifoValid: out std_logic;

		-- synchronous to iUserClk
		oData:      out std_logic_vector(31 downto 0);
		oDataK:     out std_logic_vector( 3 downto 0)
	);
end entity;

architecture behavioral of serial_trace_adapter_gt is
	constant cFifoSymbolsPerBeat:      positive := 2;
	constant cFifoDepth:               positive := 32;

	signal wFifoData:                std_logic_vector(31 downto 0);
	signal wFifoValid:               std_logic;
	signal wFifoLast:                std_logic;
	signal wFifoReady:               std_logic;

	signal wFifoWData:                 std_logic_vector(16 * cFifoSymbolsPerBeat + 1 - 1 downto 0);
	signal wFifoRData:                 std_logic_vector(16 * cFifoSymbolsPerBeat + 1 - 1 downto 0);

	signal wEncoderData:                std_logic_vector(16 * cFifoSymbolsPerBeat - 1 downto 0);
	signal wEncoderValid:               std_logic;
	signal wEncoderLast:                std_logic;
	signal wEncoderEmpty:               std_logic_vector(cFifoSymbolsPerBeat - 1 downto 0);
	signal wEncoderReady:               std_logic;

begin
	yTpiuToStream: entity work.tpiu_to_stream port map (
		iClk          => iTraceClk,
		iRst          => iTraceRst,
		iData         => iData,
		oData         => wFifoData,
		oValid        => wFifoValid,
		oLast         => wFifoLast
	);

	wFifoWData(16 * cFifoSymbolsPerBeat - 1 downto 0) <= wFifoData;
	wFifoWData(16 * cFifoSymbolsPerBeat) <= wFifoLast;

	oFifoValid       <= wFifoValid;

	yFifo: entity work.fifo_inferred generic map (
		gBits         => 16 * cFifoSymbolsPerBeat + 1,
		gDepth        => cFifoDepth,
		gAsynchronous => true
	) port map (
		iWClk         => iTraceClk,
		iWRst         => iTraceRst,
		iWValid       => wFifoValid,
		iWData        => wFifoWData,
		oWReady       => oFifoReady,
		oWFree        => open,
		iRClk         => iUserClk,
		iRRst         => iUserRst,
		iRReady       => wEncoderReady,
		oRData        => wFifoRData,
		oRValid       => wEncoderValid,
		oREmpty       => open,
		oRAvail       => open
	);

	wEncoderData     <= wFifoRData(16 * cFifoSymbolsPerBeat - 1 downto 0);
	wEncoderEmpty    <= (others => '0');
	wEncoderLast     <= wFifoRData(16 * cFifoSymbolsPerBeat);

	yAuroraEncoder: entity work.aurora_encoder generic map (
		gLanes        => 1,
		gBytesPerLane => 4
	) port map (
		iClk          => iUserClk,
		iRst          => iUserRst,
		iData         => wEncoderData,
		iValid        => wEncoderValid,
		iLast         => wEncoderLast,
		iEmpty        => wEncoderEmpty,
		oReady        => wEncoderReady,
		oData         => oData,
		oDataK        => oDataK
	);
end architecture;
