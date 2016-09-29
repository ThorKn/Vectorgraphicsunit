/*
 *
 * Author:   Thorsten Knoll
 * Date:     09/26/2016
 *
 * GPLv3-Copyright:
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity vga_sync is
    Port ( clk_in : in STD_LOGIC;
           hcount : out STD_LOGIC_VECTOR(10 downto 0);
           vcount : out STD_LOGIC_VECTOR(9 downto 0);
           hsync : out STD_LOGIC;
           vsync : out STD_LOGIC );
end vga_sync;

architecture Behavioral of vga_sync is

signal h_count: integer range 0 to 1344:=0;
signal v_count: integer range 0 to 806:=0;

begin

  process (clk_in, h_count, v_count)
  begin
        
    -- Start at the rising edge of the clock
    if (clk_in'event AND clk_in='1') then
    
      -- Count h_count and v_count
      if (h_count < 1343) then
        h_count <= h_count + 1;
      else
        h_count <= 0;
        if (v_count < 805) then
          v_count <= v_count + 1;
        else
          v_count <= 0;
        end if;
      end if;

      -- Generate h_sync
      if (h_count > 1047 AND h_count < 1084) then
        hsync <= '1';
      else
        hsync <= '0';
      end if;

      -- Generate v_sync
      if (v_count > 770 AND v_count < 777) then
        vsync <= '1';
      else
        vsync <= '0';
      end if;
      
    end if;
    
    hcount <= STD_LOGIC_VECTOR(to_unsigned(h_count, 11));
    vcount <= STD_LOGIC_VECTOR(to_unsigned(v_count, 10));
    
  end process;

end Behavioral;
