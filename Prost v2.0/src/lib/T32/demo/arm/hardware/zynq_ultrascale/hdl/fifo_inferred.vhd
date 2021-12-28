library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use work.util_pkg;
use work.util_pkg.minbits;
use work.util_pkg.is_defined;

-- both ports behave as an avalon streaming interface with readLatency = 0;
-- the read port has the added bonus that as long as oRValid = '0', the old
-- data remains on oRData (would be undefined in avalon standard)
entity fifo_inferred is
	generic (
		gBits:         positive; -- width of input and output ports
		gDepth:        positive; -- number of entries the FIFO can hold. The maximum fill state is one less than this value.
		gAsynchronous: boolean   -- whether the FIFO operates asynchronously. If set to false, both write and read port clock signals must be identical, as gray code conversion is not used
	);
	port (
		iWClk:     in  std_logic;
		iWRst:     in  std_logic;                              -- asynchronous reset; Note that if one port is reset, the other port must also be reset before either reset may be released.
		iWValid:   in  std_logic;                              -- write enable
		iWData:    in  std_logic_vector(gBits - 1 downto 0);   -- data is written iff iWValid = '1' and oWReady = '1'
		oWReady:   out std_logic;
		oWFree:    out unsigned(minbits(gDepth) - 1 downto 0); -- guaranteed number of words that can be written before the fifo is full

		iRClk:     in  std_logic;
		iRRst:     in  std_logic;                              -- asynchronous reset; Note that if one port is reset, the other port must also be reset before either reset may be released.
		iRReady:   in  std_logic;                              -- read enable
		oRData:    out std_logic_vector(gBits - 1 downto 0);   -- read transfer happens iff iRReady = '1' and oRValid = '1'
		oRValid:   out std_logic;
		oREmpty:   out std_logic;                              -- '1' if the FIFO is empty; data may not yet have arrived at the output, so usually oRValid is the relevant signal here; oREmpty = '1' is only a guarantee in synchronous mode!
		oRAvail:   out unsigned(minbits(gDepth) - 1 downto 0)  -- guaranteed number of words that can be read before the fifo is empty
	);
end entity;

architecture behavioral of fifo_inferred is
	-- wrappers around gray code conversion functions; if we are a synchronous FIFO, we don't actually need to use gray code!
	function bin2gray(bin: unsigned) return std_logic_vector is
	begin
		if gAsynchronous then
			return util_pkg.bin2gray(bin);
		else
			return std_logic_vector(bin);
		end if;
	end function;

	function gray2bin(gray: std_logic_vector) return unsigned is
	begin
		if gAsynchronous then
			return util_pkg.gray2bin(gray);
		else
			return unsigned(gray);
		end if;
	end function;

	constant cAddrBits: natural := minbits(gDepth);

	type tFifo is array(0 to gDepth - 1) of std_logic_vector(gBits - 1 downto 0);
	signal rFifo: tFifo;

	-- stuff that is synchronous to write side
	signal wWFull:        std_logic;
	signal wWEn:          std_logic;
	signal wWWAddr:       unsigned        (cAddrBits - 1 downto 0);
	signal rWWAddr:       unsigned        (cAddrBits - 1 downto 0) :=          to_unsigned(0,          cAddrBits);
	signal wWWAddrInc:    unsigned        (cAddrBits - 1 downto 0);
	signal rWWAddrGray:   std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(0,          cAddrBits));
	signal rWWAddrGray1:  std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(0,          cAddrBits));
	signal wWRAddr1:      unsigned        (cAddrBits - 1 downto 0);

	-- synchronizer from write to read side; in a synchronous FIFO, these become simple wires
	signal rWRAddrGray1:  std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(gDepth - 1, cAddrBits));

	-- stuff that is synchronous to read side
	signal wREmpty:       std_logic;
	signal wREn:          std_logic;
	signal wRRAddr:       unsigned        (cAddrBits - 1 downto 0);
	signal rRRAddr:       unsigned        (cAddrBits - 1 downto 0) :=          to_unsigned(0,          cAddrBits);
	signal wRRAddrInc:    unsigned        (cAddrBits - 1 downto 0);
	signal rRRAddrGray:   std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(0,          cAddrBits));
	signal rRRAddrGray1:  std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(gDepth - 1, cAddrBits));
	signal wRWAddr:       unsigned        (cAddrBits - 1 downto 0);
	signal rRValid:       std_logic                                := '0';

	-- synchronizer from read to write side; in a synchronous FIFO, these become simple wires
	signal rRWAddrGray1:  std_logic_vector(cAddrBits - 1 downto 0) := bin2gray(to_unsigned(0,          cAddrBits));

begin
	assert gAsynchronous or iRClk = iWClk report "synchronous FIFO detected asynchronous clocks!" severity failure;
	assert gAsynchronous or iRRst = iWRst report "synchronous FIFO detected asynchronous resets!" severity failure;

	pWriteFifo: process(iWRst, iWClk)
	begin
		if rising_edge(iWClk) then
			if wWEn = '1' then
				rFifo(to_integer(rWWAddr)) <= iWData;
			end if;
		end if;
	end process;

	pReadFifo: process(iRRst, iRClk)
	begin
		if rising_edge(iRClk) then
			if wREn = '1' then
				oRData <= rFifo(to_integer(rRRAddr));
			end if;
		end if;
	end process;

	-- write side logic
	wWEn       <= iWValid and not wWFull;
	wWFull     <= '1' when rWRAddrGray1 = rWWAddrGray else '0';
	oWReady    <= not wWFull;
	wWRAddr1   <= gray2bin(rWRAddrGray1);
	oWFree     <= (others => 'U') when not is_defined(wWRAddr1) or not is_defined(rWWAddr) else wWRAddr1 - rWWAddr when wWRAddr1 >= rWWAddr or 2 ** cAddrBits = gDepth else wWRAddr1 + gDepth - rWWAddr;
	wWWAddrInc <= rWWAddr + 1 when rWWAddr /= gDepth - 1 or 2 ** cAddrBits = gDepth else (others => '0');
	wWWAddr    <= wWWAddrInc when wWEn = '1' else rWWAddr;
	pWrite: process(iWRst, iWClk)
	begin
		if iWRst = '1' then
			rWWAddr         <=          to_unsigned(0,          cAddrBits);
			rWWAddrGray     <= bin2gray(to_unsigned(0,          cAddrBits));
			rWWAddrGray1    <= bin2gray(to_unsigned(0,          cAddrBits));
		elsif rising_edge(iWClk) then
			rWWAddr         <= wWWAddr;
			rWWAddrGray     <= bin2gray(wWWAddr);
			rWWAddrGray1    <= rWWAddrGray; -- delayed one extra clock cycle so the RAM write can finish
		end if;
	end process;

	-- read side logic
	wREn    <= (iRReady or not rRValid) and not wREmpty;
	wREmpty <= '1' when rRRAddrGray = rRWAddrGray1 else '0';
	oREmpty <= wREmpty when gAsynchronous else '1' when rRRAddr = rWWAddr else '0';
	oRValid <= rRValid;
	wRWAddr <= gray2bin(rRWAddrGray1);
	oRAvail <= (others => 'U') when not is_defined(wRWAddr) or not is_defined(rRRAddr) else wRWAddr - rRRAddr when wRWAddr >= rRRAddr or 2 ** cAddrBits = gDepth else wRWAddr + gDepth - rWWAddr;
	wRRAddrInc <= rRRAddr + 1 when rRRAddr /= gDepth - 1 or 2 ** cAddrBits = gDepth else (others => '0');
	wRRAddr <= wRRAddrInc when wREn = '1' else rRRAddr;
	pRead: process(iRClk, iRRst)
	begin
		if iRRst = '1' then
			rRRAddr         <=          to_unsigned(0,          cAddrBits);
			rRRAddrGray     <= bin2gray(to_unsigned(0,          cAddrBits));
			rRRAddrGray1    <= bin2gray(to_unsigned(gDepth - 1, cAddrBits));
			rRValid         <= '0';
		elsif rising_edge(iRClk) then
			rRRAddr         <= wRRAddr;
			rRRAddrGray     <= bin2gray(wRRAddr);

			if wREn = '1' then
				rRRAddrGray1 <= rRRAddrGray;
			end if;

			if iRReady = '1' or rRValid = '0' then
				rRValid      <= not wREmpty;
			end if;
		end if;
	end process;

	eSyncAsync: if gAsynchronous generate
		ySyncReadToWrite: entity work.synchronizer generic map (
			gBits           => cAddrBits,
			gRst            => bin2gray(to_unsigned(gDepth - 1, cAddrBits))
		) port map (
			iClk            => iWClk,
			iRst            => iWRst,
			iData           => rRRAddrGray1,
			oData           => rWRAddrGray1
		);

		ySyncWriteToRead: entity work.synchronizer generic map (
			gBits           => cAddrBits,
			gRst            => bin2gray(to_unsigned(0,          cAddrBits))
		) port map (
			iClk            => iRClk,
			iRst            => iRRst,
			iData           => rWWAddrGray1,
			oData           => rRWAddrGray1
		);
	end generate;

	eSyncSync: if not gAsynchronous generate
		rWRAddrGray1    <= rRRAddrGray1;
		rRWAddrGray1    <= rWWAddrGray1;
	end generate;
end architecture;
