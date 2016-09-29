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

#include <ap_cint.h>

void vga_out( uint32 vgaram_in[24576],
		          uint11 hcount,
			        uint10 vcount,
			        uint5 *red_out,
			        uint6 *green_out,
			        uint5 *blue_out)
{
#pragma HLS INTERFACE ap_none port=blue_out
#pragma HLS INTERFACE ap_none port=green_out
#pragma HLS INTERFACE ap_none port=red_out
#pragma HLS INTERFACE ap_none port=vcount
#pragma HLS INTERFACE ap_none port=hcount
#pragma HLS INTERFACE ap_ctrl_none port=return
	uint32 linebuffer[32];
#pragma HLS RESOURCE variable=linebuffer core=RAM_1P_LUTRAM
	int i,j;

	if ((hcount > (uint11) 1024) &&
		(hcount < (uint11) 1058) &&
		(vcount >= (uint10) 0) &&
		(vcount < (uint10) 767))
	{
		for (i = 0; i < 32; i++) {
			linebuffer[i] = vgaram_in[((vcount + 1) * 32) + i];
		}
	} else if ((hcount > (uint11) 1024) &&
			   (hcount < (uint11) 1058) &&
			   (vcount > (uint10) 766) &&
			   (vcount < (uint10) 768))
	{
		for (j = 0; j < 32; i++) {
			linebuffer[j] = vgaram_in[j];
		}
	} else if ((hcount < (uint11) 1024) &&
			   (vcount < (uint10) 768) &&
			  ((linebuffer[((hcount) / 32)] >> (hcount % 32)) & 0x01))
	{
		*red_out = 31;
		*green_out = 63;
		*blue_out = 31;
	} else {
		*red_out = 0;
		*green_out = 0;
		*blue_out = 0;
	}
}

