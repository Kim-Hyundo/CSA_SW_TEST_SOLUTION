library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity synchronizer is
	generic (
		gBits:              positive;
		gRst:               std_logic_vector := "";
		gBypass:            boolean := false
	);
	port (
		iClk:               in  std_logic;
		iRst:               in  std_logic;
		iData:              in  std_logic_vector(gBits - 1 downto 0);
		oData:              out std_logic_vector(gBits - 1 downto 0)
	);

begin
	assert gRst'length = 0 or gRst'length = gBits report "gRst must be empty (equivalent to an undefined reset value) or exactly gBits long!" severity error;
end entity;

architecture behavioral of synchronizer is
	constant cRst:         std_logic_vector(gRst'length - 1 downto 0) := gRst;

	attribute PRESERVE:    boolean;
	attribute ALTERA_ATTRIBUTE: string;

	attribute ALTERA_ATTRIBUTE of behavioral: architecture is "-name SDC_STATEMENT ""set_false_path -to [get_cells -compatibility_mode {*synchronizer_tua3kQzoIplQ4BuBlq4su5qFWGxL8h:*:rSync0}]""";

begin
	eNoBypass: if not gBypass generate
		-- random code to make (almost) absolutely sure the SDC constraint doesn't target the wrong signals
		synchronizer_tua3kQzoIplQ4BuBlq4su5qFWGxL8h: for i in iData'range generate
			signal wAsync:   std_logic;
			signal rSync0:   std_logic;
			signal rSync1:   std_logic;

			attribute PRESERVE of rSync0: signal is TRUE;
			attribute PRESERVE of rSync1: signal is TRUE;

			attribute ALTERA_ATTRIBUTE of rSync0: signal is "-name SYNCHRONIZER_IDENTIFICATION ""FORCED IF ASYNCHRONOUS""";

		begin
			wAsync           <= iData(i);
			oData(i)         <= rSync1;

			process(iRst, iClk)
			begin
				if iRst = '1' then
					if cRst'length /= 0 then
						rSync0  <= cRst(i);
						rSync1  <= cRst(i);
					else
						rSync0  <= 'U';
						rSync1  <= 'U';
					end if;
				elsif rising_edge(iClk) then
					rSync0     <= wAsync;
					rSync1     <= rSync0;
				end if;
			end process;
		end generate;
	end generate;

	eBypass: if gBypass generate
		oData               <= iData;
	end generate;
end architecture;
