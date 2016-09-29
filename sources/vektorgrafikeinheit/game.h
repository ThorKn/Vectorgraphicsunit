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
#include "types.h"

void vec_engine  (uint32 obj1ch1,
				  uint32 obj1ch2,
				  uint32 obj2ch1,
				  uint32 obj2ch2,
				  uint32 obj3ch1,
 				  uint32 obj3ch2,
				  uint32 obj4ch1,
				  uint32 obj4ch2,
				  uint32 obj5ch1,
 				  uint32 obj5ch2,
				  uint32 obj6ch1,
				  uint32 obj6ch2,
				  uint32 obj7ch1,
 				  uint32 obj7ch2,
				  uint32 obj8ch1,
				  uint32 obj8ch2,
				  uint32 obj9ch1,
 				  uint32 obj9ch2,
				  uint32 obj10ch1,
				  uint32 obj10ch2,
				  uint8 *x,
				  uint8 *y,
				  uint1 *z,
				  uint1 z_invert,
				  uint32 vgabuf[24578],
  				  uint11 hcount,
  				  uint10 vcount);

void cube_init   (Obj_l *list_out,
		          Point m, uint8 size);

void pyramid_init(Obj_l *list_out,
		          Point m, uint8 size);

void translate   (Obj_l *list_out,
		          Obj_l *list_in,
				  Vector vtrans);

void rotate      (Obj_l *list_out,
		          Obj_l *list_in,
				  uint8 a,
				  uint8 b,
				  uint8 c);

void to_surfaces (Obj_s *list_out,
		          Obj_l *list_in);

void projection  (Obj_p *list_out,
		          Obj_s *list_in,
				  int d);

void draw        (Obj_p *list_in,
		          uint8 *x,
				  uint8* y,
				  uint1 *z,
				  uint1 z_inv);

void crossproduct(Vector *vout,
		          Vector *v1,
				  Vector *v2);

void vga_draw    (Obj_p *list_in,
				  uint32 vgabuf[24578]);

void vga_draw_point(uint32 vgabuf[24578],
		        int x,
				int y);

void vga_draw_line(uint32 vgabuf[24578],
		       int x0,
			   int y0,
			   int x1,
			   int y1);
