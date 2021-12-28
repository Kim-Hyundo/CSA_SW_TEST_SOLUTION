library IEEE;
use IEEE.std_logic_1164.all;

entity serial_trace_adapter_axis is
	generic (
		gBytes: positive -- must be even and >= 4
	);
	port (
		iClk:   in  std_logic;
		iRst:   in  std_logic;

		iData:  in  std_logic_vector(31 downto 0);

		oData:  out std_logic_vector(8 * gBytes - 1 downto 0);
		oValid: out std_logic;
		oLast:  out std_logic;
		oKeep:  out std_logic_vector(gBytes - 1 downto 0)
		-- no iReady; sink must always accept data!
	);
end entity;

architecture behavioral of serial_trace_adapter_axis is
begin
	eWithExpander: if gBytes > 4 generate
		signal wExpanderData:  std_logic_vector(31 downto 0);
		signal wExpanderValid: std_logic;
		signal wExpanderLast:  std_logic;

		signal wExpandedEmpty: std_logic_vector(gBytes / 2 - 1 downto 0);

	begin
		yTpiuToStream: entity work.tpiu_to_stream port map (
			iClk            => iClk,
			iRst            => iRst,
			iData           => iData,
			oData           => wExpanderData,
			oValid          => wExpanderValid,
			oLast           => wExpanderLast
		);

		yStreamWidthExpander: entity work.stream_width_expander generic map (
			gBitsPerSymbol     => 16,
			gOutSymbolsPerBeat => gBytes / 2
		) port map (
			iClk   => iClk,
			iRst   => iRst,
			iData  => wExpanderData,
			iValid => wExpanderValid,
			iLast  => wExpanderLast,
			oData  => oData,
			oValid => oValid,
			oLast  => oLast,
			oEmpty => wExpandedEmpty
		);

		eKeep: for i in gBytes / 2 - 1 downto 0 generate
			oKeep(2 * i + 0) <= not wExpandedEmpty(i);
			oKeep(2 * i + 1) <= not wExpandedEmpty(i);
		end generate;
	end generate;

	eWithoutExpander: if gBytes = 4 generate
		yTpiuToStream: entity work.tpiu_to_stream port map (
			iClk            => iClk,
			iRst            => iRst,
			iData           => iData,
			oData           => oData,
			oValid          => oValid,
			oLast           => oLast
		);

		oKeep <= (others => '1');
	end generate;
end architecture;
