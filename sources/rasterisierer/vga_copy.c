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

void ram_copy(uint32 vgabuf_in[24576],
			        uint32 vgaram_out[24576],
		          uint11 hcount,
			        uint10 vcount)
{
#pragma HLS INTERFACE ap_none port=vcount
#pragma HLS INTERFACE ap_none port=hcount
#pragma HLS RESOURCE variable=vgaram_out core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_memory port=vgaram_out
#pragma HLS RESOURCE variable=vgabuf_in core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_memory port=vgabuf_in
#pragma HLS INTERFACE ap_ctrl_none port=return
	if ((vcount > 767) && (vcount < 780)) {
		int i;
		for (i = 0; i < 24576; i++) {
			vgaram_out[i] = vgabuf_in[i];
		}
	}
}

