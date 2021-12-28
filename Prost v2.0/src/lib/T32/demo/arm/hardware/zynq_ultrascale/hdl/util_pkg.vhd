library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

package util_pkg is
	-- returns the minimum number of bits required to hold a value ranging from 0 to num - 1
	function minbits(num: positive) return natural;
	function min(vA, vB: integer) return integer;
	function max(vA, vB: integer) return integer;

	-- conversion functions between unsigned binary and gray code
	function bin2gray(bin: unsigned) return std_logic_vector;
	function gray2bin(gray: std_logic_vector) return unsigned;

	-- check whether all bits are '0' or '1'; used to properly propagate undefined values across decisions and arithmetic, avoiding warnings and simulation mismatches
	function is_defined(a: std_logic) return boolean;
	function is_defined(a: std_logic_vector) return boolean;
	function is_defined(a: unsigned) return boolean;
	function is_defined(a: signed) return boolean;

	function to_str(vVal: std_logic) return string;
	function to_hex(vVal: unsigned; vPrefix: boolean := true) return string;
	function to_hex(vVal: std_logic_vector; vPrefix: boolean := true) return string;
end package;

package body util_pkg is
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

	function min(vA, vB: integer) return integer is
	begin
		if vA < vB then
			return vA;
		else
			return vB;
		end if;
	end function;

	function max(vA, vB: integer) return integer is
	begin
		if vA < vB then
			return vB;
		else
			return vA;
		end if;
	end function;

	function bin2gray(bin: unsigned) return std_logic_vector is
	begin
		return std_logic_vector(bin xor (bin srl 1));
	end function;

	-- see http://aggregate.org/MAGIC/#Gray%20Code%20Conversion
	function gray2bin(gray: std_logic_vector) return unsigned is
		variable bin: unsigned(gray'length - 1 downto 0);
		variable i: positive;

	begin
		bin := unsigned(gray);
		i := 1;

		while i < bin'length loop
			bin := bin xor (bin srl i);

			i := i * 2;
		end loop;

		return bin;
	end function;

	function is_defined(a: std_logic) return boolean is
	begin
		if a /= '0' and a /= '1' then
			return false;
		else
			return true;
		end if;
	end function;

	function is_defined(a: std_logic_vector) return boolean is
	begin
		for i in a'range loop
			if not is_defined(a(i)) then
				return false;
			end if;
		end loop;
		return true;
	end function;

	function is_defined(a: unsigned) return boolean is
	begin
		return is_defined(std_logic_vector(a));
	end function;

	function is_defined(a: signed) return boolean is
	begin
		return is_defined(std_logic_vector(a));
	end function;

	function to_str(vVal: std_logic) return string is
	begin
		case vVal is
			when '0' => return "0";
			when '1' => return "1";
			when 'U' => return "U";
			when 'X' => return "X";
			when 'W' => return "W";
			when 'L' => return "L";
			when 'H' => return "H";
			when 'Z' => return "Z";
			when '-' => return "-";
		end case;
	end function;

	function to_hex(vVal: unsigned; vPrefix: boolean := true) return string is
		alias lVal: unsigned(vVal'length - 1 downto 0) is vVal;
		constant cDigits: string(16 downto 1) := "FEDCBA9876543210";
		variable vRet: string(6 downto 1);
		constant cRef: unsigned(min(4, lVal'length) - 1 downto 0) := lVal(min(4, lVal'length) - 1 downto 0);
		constant cRest: unsigned(lVal'length - 1 - cRef'length downto 0) := lVal(lVal'length - 1 downto cRef'length);
		variable vEquals: boolean;

	begin
		if vPrefix then
			return integer'image(vVal'length) & "'h" & to_hex(vVal, false);
		end if;

		if vVal'length = 0 then
			return "";
		end if;

		if is_defined(cRef) then
			return to_hex(cRest, false) & cDigits(to_integer(cRef) + 1 downto to_integer(cRef) + 1);
		end if;

		vEquals := true;
		for i in cRef'range loop
			if cRef(i) /= cRef(0) then
				vEquals := false;
			end if;
		end loop;

		if vEquals then
			return to_hex(cRest, false) & to_str(cRef(0));
		end if;

		for i in cRef'range loop
			vRet(i + 2 downto i + 2) := to_str(cRef(i));
		end loop;

		vRet(1) := '}';
		vRet(cRef'length + 2) := '{';
		return to_hex(cRest, false) & vRet(cRef'length + 2 downto 1);
	end function;

	function to_hex(vVal: std_logic_vector; vPrefix: boolean := true) return string is
	begin
		return to_hex(unsigned(vVal), vPrefix);
	end function;
end package body;
