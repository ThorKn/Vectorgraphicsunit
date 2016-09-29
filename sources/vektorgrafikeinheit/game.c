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
#include <math.h>
#include "game.h"

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
  				  uint10 vcount) {
#pragma HLS INTERFACE ap_none port=vcount
#pragma HLS INTERFACE ap_none port=hcount
#pragma HLS INTERFACE ap_memory port=vgabuf
#pragma HLS RESOURCE variable=vgabuf core=RAM_1P_BRAM latency=2
#pragma HLS INTERFACE ap_none port=z_invert
#pragma HLS INTERFACE ap_none port=z
#pragma HLS INTERFACE ap_none port=y
#pragma HLS INTERFACE ap_none port=x
#pragma HLS INTERFACE ap_none port=obj10ch2
#pragma HLS INTERFACE ap_none port=obj10ch1
#pragma HLS INTERFACE ap_none port=obj9ch2
#pragma HLS INTERFACE ap_none port=obj9ch1
#pragma HLS INTERFACE ap_none port=obj8ch2
#pragma HLS INTERFACE ap_none port=obj8ch1
#pragma HLS INTERFACE ap_none port=obj7ch2
#pragma HLS INTERFACE ap_none port=obj7ch1
#pragma HLS INTERFACE ap_none port=obj6ch2
#pragma HLS INTERFACE ap_none port=obj6ch1
#pragma HLS INTERFACE ap_none port=obj5ch2
#pragma HLS INTERFACE ap_none port=obj5ch1
#pragma HLS INTERFACE ap_none port=obj4ch2
#pragma HLS INTERFACE ap_none port=obj4ch1
#pragma HLS INTERFACE ap_none port=obj3ch2
#pragma HLS INTERFACE ap_none port=obj3ch1
#pragma HLS INTERFACE ap_none port=obj2ch2
#pragma HLS INTERFACE ap_none port=obj2ch1
#pragma HLS INTERFACE ap_none port=obj1ch2
#pragma HLS INTERFACE ap_none port=obj1ch1
#pragma HLS INTERFACE ap_ctrl_none port=return

	int i, j, k;
	uint1 z_inv;
	Obj_l list_init;
	Obj_l list_trans;
	Obj_l list_rot;
	Obj_s list_surfaces;
	Obj_p list_proj;
	Point m_objects[10];
	Vector r_objects[10];
	uint8 size_objects[10];
	uint1 vis_objects[10];
	uint4 cat_objects[10];
	Vector t_objects = {0,0,0};
	z_inv = z_invert;

	// Fill middelpoint-, rotation-vectors and size of all objects
	m_objects[0].xyz[0] = (int) ((obj1ch1 & ((uint32) 255)) - 127);
	m_objects[0].xyz[1] = (int) (((obj1ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[0].xyz[2] = (int) ((obj1ch1 >> 16) & ((uint32) 255));
	size_objects[0] = (uint8) ((obj1ch1 >> 24) & ((uint32) 255));

	r_objects[0].xyz[0] = (int) (obj1ch2 & ((uint32) 255));
	r_objects[0].xyz[1] = (int) ((obj1ch2 >> 8) & ((uint32) 255));
	r_objects[0].xyz[2] = (int) ((obj1ch2 >> 16) & ((uint32) 255));
	vis_objects[0] = (uint1) ((obj1ch2 >> 24) & ((uint32) 1));
	cat_objects[0] = (uint4) ((obj1ch2 >> 25) & ((uint32) 15));

	m_objects[1].xyz[0] = (int) ((obj2ch1 & ((uint32) 255)) - 127);
	m_objects[1].xyz[1] = (int) (((obj2ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[1].xyz[2] = (int) ((obj2ch1 >> 16) & ((uint32) 255));
	size_objects[1] = (uint8) ((obj2ch1 >> 24) & ((uint32) 255));

	r_objects[1].xyz[0] = (int) (obj2ch2 & ((uint32) 255));
	r_objects[1].xyz[1] = (int) ((obj2ch2 >> 8) & ((uint32) 255));
	r_objects[1].xyz[2] = (int) ((obj2ch2 >> 16) & ((uint32) 255));
	vis_objects[1] = (uint1) ((obj2ch2 >> 24) & ((uint32) 1));
	cat_objects[1] = (uint4) ((obj2ch2 >> 25) & ((uint32) 15));

	m_objects[2].xyz[0] = (int) ((obj3ch1 & ((uint32) 255)) - 127);
	m_objects[2].xyz[1] = (int) (((obj3ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[2].xyz[2] = (int) ((obj3ch1 >> 16) & ((uint32) 255));
	size_objects[2] = (uint8) ((obj3ch1 >> 24) & ((uint32) 255));

	r_objects[2].xyz[0] = (int) (obj3ch2 & ((uint32) 255));
	r_objects[2].xyz[1] = (int) ((obj3ch2 >> 8) & ((uint32) 255));
	r_objects[2].xyz[2] = (int) ((obj3ch2 >> 16) & ((uint32) 255));
	vis_objects[2] = (uint1) ((obj3ch2 >> 24) & ((uint32) 1));
	cat_objects[2] = (uint4) ((obj3ch2 >> 25) & ((uint32) 15));

	m_objects[3].xyz[0] = (int) ((obj4ch1 & ((uint32) 255)) - 127);
	m_objects[3].xyz[1] = (int) (((obj4ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[3].xyz[2] = (int) ((obj4ch1 >> 16) & ((uint32) 255));
	size_objects[3] = (uint8) ((obj4ch1 >> 24) & ((uint32) 255));

	r_objects[3].xyz[0] = (int) (obj4ch2 & ((uint32) 255));
	r_objects[3].xyz[1] = (int) ((obj4ch2 >> 8) & ((uint32) 255));
	r_objects[3].xyz[2] = (int) ((obj4ch2 >> 16) & ((uint32) 255));
	vis_objects[3] = (uint1) ((obj4ch2 >> 24) & ((uint32) 1));
	cat_objects[3] = (uint4) ((obj4ch2 >> 25) & ((uint32) 15));

	m_objects[4].xyz[0] = (int) ((obj5ch1 & ((uint32) 255)) - 127);
	m_objects[4].xyz[1] = (int) (((obj5ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[4].xyz[2] = (int) ((obj5ch1 >> 16) & ((uint32) 255));
	size_objects[4] = (uint8) ((obj5ch1 >> 24) & ((uint32) 255));

	r_objects[4].xyz[0] = (int) (obj5ch2 & ((uint32) 255));
	r_objects[4].xyz[1] = (int) ((obj5ch2 >> 8) & ((uint32) 255));
	r_objects[4].xyz[2] = (int) ((obj5ch2 >> 16) & ((uint32) 255));
	vis_objects[4] = (uint1) ((obj5ch2 >> 24) & ((uint32) 1));
	cat_objects[4] = (uint4) ((obj5ch2 >> 25) & ((uint32) 15));

	m_objects[5].xyz[0] = (int) ((obj6ch1 & ((uint32) 255)) - 127);
	m_objects[5].xyz[1] = (int) (((obj6ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[5].xyz[2] = (int) ((obj6ch1 >> 16) & ((uint32) 255));
	size_objects[5] = (uint8) ((obj6ch1 >> 24) & ((uint32) 255));

	r_objects[5].xyz[0] = (int) (obj6ch2 & ((uint32) 255));
	r_objects[5].xyz[1] = (int) ((obj6ch2 >> 8) & ((uint32) 255));
	r_objects[5].xyz[2] = (int) ((obj6ch2 >> 16) & ((uint32) 255));
	vis_objects[5] = (uint1) ((obj6ch2 >> 24) & ((uint32) 1));
	cat_objects[5] = (uint4) ((obj6ch2 >> 25) & ((uint32) 15));

	m_objects[6].xyz[0] = (int) ((obj7ch1 & ((uint32) 255)) - 127);
	m_objects[6].xyz[1] = (int) (((obj7ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[6].xyz[2] = (int) ((obj7ch1 >> 16) & ((uint32) 255));
	size_objects[6] = (uint8) ((obj7ch1 >> 24) & ((uint32) 255));

	r_objects[6].xyz[0] = (int) (obj7ch2 & ((uint32) 255));
	r_objects[6].xyz[1] = (int) ((obj7ch2 >> 8) & ((uint32) 255));
	r_objects[6].xyz[2] = (int) ((obj7ch2 >> 16) & ((uint32) 255));
	vis_objects[6] = (uint1) ((obj7ch2 >> 24) & ((uint32) 1));
	cat_objects[6] = (uint4) ((obj7ch2 >> 25) & ((uint32) 15));

	m_objects[7].xyz[0] = (int) ((obj8ch1 & ((uint32) 255)) - 127);
	m_objects[7].xyz[1] = (int) (((obj8ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[7].xyz[2] = (int) ((obj8ch1 >> 16) & ((uint32) 255));
	size_objects[7] = (uint8) ((obj8ch1 >> 24) & ((uint32) 255));

	r_objects[7].xyz[0] = (int) (obj8ch2 & ((uint32) 255));
	r_objects[7].xyz[1] = (int) ((obj8ch2 >> 8) & ((uint32) 255));
	r_objects[7].xyz[2] = (int) ((obj8ch2 >> 16) & ((uint32) 255));
	vis_objects[7] = (uint1) ((obj8ch2 >> 24) & ((uint32) 1));
	cat_objects[7] = (uint4) ((obj8ch2 >> 25) & ((uint32) 15));

	m_objects[8].xyz[0] = (int) ((obj9ch1 & ((uint32) 255)) - 127);
	m_objects[8].xyz[1] = (int) (((obj9ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[8].xyz[2] = (int) ((obj9ch1 >> 16) & ((uint32) 255));
	size_objects[8] = (uint8) ((obj9ch1 >> 24) & ((uint32) 255));

	r_objects[8].xyz[0] = (int) (obj9ch2 & ((uint32) 255));
	r_objects[8].xyz[1] = (int) ((obj9ch2 >> 8) & ((uint32) 255));
	r_objects[8].xyz[2] = (int) ((obj9ch2 >> 16) & ((uint32) 255));
	vis_objects[8] = (uint1) ((obj9ch2 >> 24) & ((uint32) 1));
	cat_objects[8] = (uint4) ((obj9ch2 >> 25) & ((uint32) 15));

	m_objects[9].xyz[0] = (int) ((obj10ch1 & ((uint32) 255)) - 127);
	m_objects[9].xyz[1] = (int) (((obj10ch1 >> 8) & ((uint32) 255)) - 127);
	m_objects[9].xyz[2] = (int) ((obj10ch1 >> 16) & ((uint32) 255));
	size_objects[9] = (uint8) ((obj10ch1 >> 24) & ((uint32) 255));

	r_objects[9].xyz[0] = (int) (obj10ch2 & ((uint32) 255));
	r_objects[9].xyz[1] = (int) ((obj10ch2 >> 8) & ((uint32) 255));
	r_objects[9].xyz[2] = (int) ((obj10ch2 >> 16) & ((uint32) 255));
	vis_objects[9] = (uint1) ((obj10ch2 >> 24) & ((uint32) 1));
	cat_objects[9] = (uint4) ((obj10ch2 >> 25) & ((uint32) 15));

	// Graphics-Pipeline-Loop for all objects
	for (j = 0; j < 10; j++) {

		// Keep z down
		for(i = 0; i < 10; i++) {
			*z = z_inv;
		}
		if (vis_objects[j]) {
			if (cat_objects[j] == 0) {
				// Initialize actual object
				cube_init (&list_init, m_objects[j], size_objects[j]);
			} else {
				pyramid_init (&list_init, m_objects[j], size_objects[j]);
			}

			// Translate object
			translate (&list_trans, &list_init, t_objects);

			// Rotate object
			rotate (&list_rot, &list_trans, r_objects[j].xyz[0], r_objects[j].xyz[1], r_objects[j].xyz[2]);

			// Calculate object's surfaces
			to_surfaces (&list_surfaces, &list_rot);

			// Project obejct to 2-D
			projection (&list_proj, &list_surfaces, 255);

			// Draw object to Rasterizer
			if ((vcount > (uint11) 100) &&
				(vcount < (uint11) 500))
			{
				vga_draw(&list_proj, vgabuf);
			} else if ((vcount > (uint10) 0) &&
					   (vcount < (uint10) 80))
			{
				// Or clear the vga_buffer
				for (k = 0; k < 24576; k++) {
					vgabuf[k] = 0;
				}
			}

			// Draw object to vectorscreen x,y,z
			draw (&list_proj, x, y, z, z_inv);
		}
		// Keep z down
		for (i = 0; i < 10; i++) {
			*z = z_inv;
		}
	}
}

void cube_init(Obj_l *list_out, Point m, uint8 size) {

	Obj_l result;
	int i,j;

	// Initialize the local variable result
	for (i = 0; i < 3; i++) {
		result.middle.xyz[i] = m.xyz[i];
	}
	result.points[0].xyz[0] = m.xyz[0] - size;
	result.points[0].xyz[1] = m.xyz[1] - size;
	result.points[0].xyz[2] = m.xyz[2] + size;

	result.points[1].xyz[0] = m.xyz[0] + size;
	result.points[1].xyz[1] = m.xyz[1] - size;
	result.points[1].xyz[2] = m.xyz[2] + size;

	result.points[2].xyz[0] = m.xyz[0] + size;
	result.points[2].xyz[1] = m.xyz[1] + size;
	result.points[2].xyz[2] = m.xyz[2] + size;

	result.points[3].xyz[0] = m.xyz[0] - size;
	result.points[3].xyz[1] = m.xyz[1] + size;
	result.points[3].xyz[2] = m.xyz[2] + size;

	result.points[4].xyz[0] = m.xyz[0] - size;
	result.points[4].xyz[1] = m.xyz[1] + size;
	result.points[4].xyz[2] = m.xyz[2] - size;

	result.points[5].xyz[0] = m.xyz[0] + size;
	result.points[5].xyz[1] = m.xyz[1] + size;
	result.points[5].xyz[2] = m.xyz[2] - size;

	result.points[6].xyz[0] = m.xyz[0] + size;
	result.points[6].xyz[1] = m.xyz[1] - size;
	result.points[6].xyz[2] = m.xyz[2] - size;

	result.points[7].xyz[0] = m.xyz[0] - size;
	result.points[7].xyz[1] = m.xyz[1] - size;
	result.points[7].xyz[2] = m.xyz[2] - size;

	// Copy result to list_l
	for (i = 0; i < 3; i++) {
		list_out->middle.xyz[i] = result.middle.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			list_out->points[i].xyz[j] = result.points[i].xyz[j];
		}
	}
}

void pyramid_init(Obj_l *list_out, Point m, uint8 size) {

	Obj_l result;
	int i,j;

	// Initialize the local variable result
	for (i = 0; i < 3; i++) {
		result.middle.xyz[i] = m.xyz[i];
	}
	result.points[0].xyz[0] = m.xyz[0] - size;
	result.points[0].xyz[1] = m.xyz[1] - size;
	result.points[0].xyz[2] = m.xyz[2] + size;

	result.points[1].xyz[0] = m.xyz[0] + size;
	result.points[1].xyz[1] = m.xyz[1] - size;
	result.points[1].xyz[2] = m.xyz[2] + size;

	result.points[2].xyz[0] = m.xyz[0] + 3;
	result.points[2].xyz[1] = m.xyz[1] + size;
	result.points[2].xyz[2] = m.xyz[2] + 3;

	result.points[3].xyz[0] = m.xyz[0] - 3;
	result.points[3].xyz[1] = m.xyz[1] + size;
	result.points[3].xyz[2] = m.xyz[2] + 3;

	result.points[4].xyz[0] = m.xyz[0] - 3;
	result.points[4].xyz[1] = m.xyz[1] + size;
	result.points[4].xyz[2] = m.xyz[2] - 3;

	result.points[5].xyz[0] = m.xyz[0] + 3;
	result.points[5].xyz[1] = m.xyz[1] + size;
	result.points[5].xyz[2] = m.xyz[2] - 3;

	result.points[6].xyz[0] = m.xyz[0] + size;
	result.points[6].xyz[1] = m.xyz[1] - size;
	result.points[6].xyz[2] = m.xyz[2] - size;

	result.points[7].xyz[0] = m.xyz[0] - size;
	result.points[7].xyz[1] = m.xyz[1] - size;
	result.points[7].xyz[2] = m.xyz[2] - size;

	// Copy result to list_l
	for (i = 0; i < 3; i++) {
		list_out->middle.xyz[i] = result.middle.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			list_out->points[i].xyz[j] = result.points[i].xyz[j];
		}
	}
}

void translate(Obj_l *list_out, Obj_l *list_in, Vector vtrans) {

	Obj_l result;
	int i, j;

	// Copy list_in to local variable result
	// And add the translation to it
	for (i = 0; i < 3; i++) {
		result.middle.xyz[i] = list_in->middle.xyz[i] + vtrans.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			result.points[i].xyz[j] = list_in->points[i].xyz[j] + vtrans.xyz[j];
		}
	}

	// Copy local variable result to list_t
	for (i = 0; i < 3; i++) {
		list_out->middle.xyz[i] = result.middle.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			list_out->points[i].xyz[j] = result.points[i].xyz[j];
		}
	}
}

void rotate(Obj_l *list_out, Obj_l *list_in, uint8 a, uint8 b, uint8 c) {

	Obj_l result1, result2, result3;
	int i, j;
	int mx_temp, my_temp, mz_temp;
	Vector trans_temp;
	float angle, co, si, x_temp, y_temp, z_temp;

	// Copy list_in to local variable result
	// And and the translation to it
	for (i = 0; i < 3; i++) {
		result1.middle.xyz[i] = list_in->middle.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			result1.points[i].xyz[j] = list_in->points[i].xyz[j];
		}
	}

	// 0. Copy middle to temps
	mx_temp = result1.middle.xyz[0];
	my_temp = result1.middle.xyz[1];
	mz_temp = result1.middle.xyz[2];
	trans_temp.xyz[0] = -mx_temp;
	trans_temp.xyz[1] = -my_temp;
	trans_temp.xyz[2] = -mz_temp;

	// 1. Translate to 0,0,0
	translate(&result2, &result1, trans_temp);

	// 2. Rotate around x
	co = cos_table[a];
	si = sin_table[a];
	for (i = 0; i < 8; i++) {
		y_temp = (float)result2.points[i].xyz[1];
		z_temp = (float)result2.points[i].xyz[2];
		result2.points[i].xyz[1] = (int)((co * y_temp) - (si * z_temp));
		result2.points[i].xyz[2] = (int)((si * y_temp) + (co * z_temp));
	}
	// 3. Rotate around y
	co = cos_table[b];
	si = sin_table[b];
	for (i = 0; i < 8; i++) {
		x_temp = (float)result2.points[i].xyz[0];
		z_temp = (float)result2.points[i].xyz[2];
		result2.points[i].xyz[0] = (int)((co * x_temp) + (si * z_temp));
		result2.points[i].xyz[2] = (int)(((si) * (-1.0) * x_temp) + (co * z_temp));
	}

	// 4. Rotate around z
	co = cos_table[c];
	si = sin_table[c];
	for (i = 0; i < 8; i++) {
		x_temp = (float)result2.points[i].xyz[0];
		y_temp = (float)result2.points[i].xyz[1];
		result2.points[i].xyz[0] = (int)((co * x_temp) - (si * y_temp));
		result2.points[i].xyz[1] = (int)((si * x_temp) + (co * y_temp));
	}

	// 5. Translate reverse to 1.
	trans_temp.xyz[0] = mx_temp;
	trans_temp.xyz[1] = my_temp;
	trans_temp.xyz[2] = mz_temp;
	translate(&result3, &result2, trans_temp);

	// Copy local variable result to list_out
	for (i = 0; i < 3; i++) {
		list_out->middle.xyz[i] = result1.middle.xyz[i];
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			list_out->points[i].xyz[j] = result3.points[i].xyz[j];
		}
	}
}

void to_surfaces(Obj_s *list_out, Obj_l *list_in) {

	Obj_s result;
	Vector s00, s01, s10, s11, s20, s21, s30, s31, s40, s41, s50, s51;
	Vector n0, n1, n2, n3, n4, n5;
	int i, j, k;

	// Surface 0
	for (i = 0; i < 3; i++) {
		result.surfaces[0].points[0].xyz[i] = list_in->points[0].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[0].points[1].xyz[i] = list_in->points[1].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[0].points[2].xyz[i] = list_in->points[2].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[0].points[3].xyz[i] = list_in->points[3].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s00.xyz[i] = result.surfaces[0].points[1].xyz[i] - result.surfaces[0].points[0].xyz[i];
		s01.xyz[i] = result.surfaces[0].points[3].xyz[i] - result.surfaces[0].points[0].xyz[i];
	}
	crossproduct(&n0, &s00, &s01);
	for (i = 0; i < 3; i++) {
		result.normals[0].xyz[i] = n0.xyz[i];
	}

	// Surface 1
	for (i = 0; i < 3; i++) {
		result.surfaces[1].points[0].xyz[i] = list_in->points[4].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[1].points[1].xyz[i] = list_in->points[5].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[1].points[2].xyz[i] = list_in->points[6].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[1].points[3].xyz[i] = list_in->points[7].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s10.xyz[i] = result.surfaces[1].points[1].xyz[i] - result.surfaces[1].points[0].xyz[i];
		s11.xyz[i] = result.surfaces[1].points[3].xyz[i] - result.surfaces[1].points[0].xyz[i];
	}
	crossproduct(&n1, &s10, &s11);
	for (i = 0; i < 3; i++) {
		result.normals[1].xyz[i] = n1.xyz[i];
	}

	// Surface 2
	for (i = 0; i < 3; i++) {
		result.surfaces[2].points[0].xyz[i] = list_in->points[1].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[2].points[1].xyz[i] = list_in->points[6].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[2].points[2].xyz[i] = list_in->points[5].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[2].points[3].xyz[i] = list_in->points[2].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s20.xyz[i] = result.surfaces[2].points[1].xyz[i] - result.surfaces[2].points[0].xyz[i];
		s21.xyz[i] = result.surfaces[2].points[3].xyz[i] - result.surfaces[2].points[0].xyz[i];
	}
	crossproduct(&n2, &s20, &s21);
	for (i = 0; i < 3; i++) {
		result.normals[2].xyz[i] = n2.xyz[i];
	}

	// Surface 3
	for (i = 0; i < 3; i++) {
		result.surfaces[3].points[0].xyz[i] = list_in->points[2].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[3].points[1].xyz[i] = list_in->points[5].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[3].points[2].xyz[i] = list_in->points[4].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[3].points[3].xyz[i] = list_in->points[3].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s30.xyz[i] = result.surfaces[3].points[1].xyz[i] - result.surfaces[3].points[0].xyz[i];
		s31.xyz[i] = result.surfaces[3].points[3].xyz[i] - result.surfaces[3].points[0].xyz[i];
	}
	crossproduct(&n3, &s30, &s31);
	for (i = 0; i < 3; i++) {
		result.normals[3].xyz[i] = n3.xyz[i];
	}

	// Surface 4
	for (i = 0; i < 3; i++) {
		result.surfaces[4].points[0].xyz[i] = list_in->points[0].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[4].points[1].xyz[i] = list_in->points[3].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[4].points[2].xyz[i] = list_in->points[4].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[4].points[3].xyz[i] = list_in->points[7].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s40.xyz[i] = result.surfaces[4].points[1].xyz[i] - result.surfaces[4].points[0].xyz[i];
		s41.xyz[i] = result.surfaces[4].points[3].xyz[i] - result.surfaces[4].points[0].xyz[i];
	}
	crossproduct(&n4, &s40, &s41);
	for (i = 0; i < 3; i++) {
		result.normals[4].xyz[i] = n4.xyz[i];
	}

	// Surface 5
	for (i = 0; i < 3; i++) {
		result.surfaces[5].points[0].xyz[i] = list_in->points[0].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[5].points[1].xyz[i] = list_in->points[7].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[5].points[2].xyz[i] = list_in->points[6].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		result.surfaces[5].points[3].xyz[i] = list_in->points[1].xyz[i];
	}
	for (i = 0; i < 3; i++) {
		s50.xyz[i] = result.surfaces[5].points[1].xyz[i] - result.surfaces[5].points[0].xyz[i];
		s51.xyz[i] = result.surfaces[5].points[3].xyz[i] - result.surfaces[5].points[0].xyz[i];
	}
	crossproduct(&n5, &s50, &s51);
	for (i = 0; i < 3; i++) {
		result.normals[5].xyz[i] = n5.xyz[i];
	}

	// Copy the local variable result to list_s
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			for(k = 0; k < 3; k++) {
				list_out->surfaces[i].points[j].xyz[k] = result.surfaces[i].points[j].xyz[k];
			}
		}
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 3; j++) {
			list_out->normals[i].xyz[j] = result.normals[i].xyz[j];
		}
	}

}

void projection(Obj_p *list_out, Obj_s *list_in, int d) {

	Obj_p result;
	int i, j, k;
	int x_view, y_view, z_view, x_norm, y_norm, z_norm;

	// Copy the list_s to local variable result
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			for(k = 0; k < 3; k++) {
				result.surfaces[i].points[j].xyz[k] = list_in->surfaces[i].points[j].xyz[k];
			}
		}
	}
	for (i = 0; i < 6; i++) {
		x_view = list_in->surfaces[i].points[0].xyz[0];
		y_view = list_in->surfaces[i].points[0].xyz[1];
		z_view = list_in->surfaces[i].points[0].xyz[2] + d;
		x_norm = list_in->normals[i].xyz[0];
		y_norm = list_in->normals[i].xyz[1];
		z_norm = list_in->normals[i].xyz[2];
		if (((x_view * x_norm) + (y_view * y_norm) + (z_view * z_norm)) <= 0) {
			result.visible[i] = true;
		} else {
			result.visible[i] = false;
		}
	}

	// Projection onto screenplane (x-y)
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			result.surfaces[i].points[j].xyz[0] = ((d * result.surfaces[i].points[j].xyz[0]) / (result.surfaces[i].points[j].xyz[2] + d));
			result.surfaces[i].points[j].xyz[1] = ((d * result.surfaces[i].points[j].xyz[1]) / (result.surfaces[i].points[j].xyz[2] + d));
			result.surfaces[i].points[j].xyz[2] = 0;
		}
	}

	// Copy the result to list_p
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			for(k = 0; k < 3; k++) {
				list_out->surfaces[i].points[j].xyz[k] = result.surfaces[i].points[j].xyz[k];
			}
		}
	}
	for (i = 0; i < 6; i++) {
		list_out->visible[i] = result.visible[i];
	}

}

void draw(Obj_p *list_in, uint8 *x, uint8* y, uint1 *z, uint1 z_inv) {

	Obj_p result;
	int i,j,k;
	uint8 x_temp, y_temp;

	// Copy list_p to local variable result
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 3; k++) {
				result.surfaces[i].points[j].xyz[k] = list_in->surfaces[i].points[j].xyz[k];
			}
		}
	}
	for (i = 0; i < 6; i++) {
		result.visible[i] = list_in->visible[i];
	}

	for (i = 0; i < 6; i++) {
		if (result.visible[i]) {
			x_temp = (uint8)(result.surfaces[i].points[0].xyz[0]) + 127;
			y_temp = (uint8)(result.surfaces[i].points[0].xyz[1]) + 127;
			for (k = 0; k < 1200; k++) {
				*z = z_inv;
				*x = x_temp;
				*y = y_temp;
			}
			for (j = 0; j < 4; j++) {
				x_temp = (uint8)(result.surfaces[i].points[j].xyz[0]) + 127;
				y_temp = (uint8)(result.surfaces[i].points[j].xyz[1]) + 127;
				for (k = 0; k < 1500; k++) {
					*z = ~z_inv;
					*x = x_temp;
					*y = y_temp;
				}
			}
			x_temp = (uint8)(result.surfaces[i].points[0].xyz[0]) + 127;
			y_temp = (uint8)(result.surfaces[i].points[0].xyz[1]) + 127;
			for (k = 0; k < 1000; k++) {
				*z = ~z_inv;
				*x = x_temp;
				*y = y_temp;
			}
			for (k = 0; k < 1200; k++) {
				*z = z_inv;
				*x = x_temp;
				*y = y_temp;
			}
		}
	}
}

void crossproduct(Vector *vout, Vector *v1, Vector *v2) {

	Vector result;
	Vector vin1;
	Vector vin2;
	int i;

	for(i = 0; i < 3; i++) {
		vin1.xyz[i] = v1->xyz[i];
		vin2.xyz[i] = v2->xyz[i];
	}

	result.xyz[0] = ((vin1.xyz[1]*vin2.xyz[2])-(vin1.xyz[2]*vin2.xyz[1]));
	result.xyz[1] = ((vin1.xyz[2]*vin2.xyz[0])-(vin1.xyz[0]*vin2.xyz[2]));
	result.xyz[2] = ((vin1.xyz[0]*vin2.xyz[1])-(vin1.xyz[1]*vin2.xyz[0]));

	for (i = 0; i < 3; i++) {
		vout->xyz[i] = result.xyz[i];
	}

}

void vga_draw(Obj_p *list_in, uint32 vgabuf[24578]) {

	Obj_p result;
	int i,j,k;
	int x_0, y_0, x_1, y_1;

	// Copy list_p to local variable result
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 3; k++) {
				result.surfaces[i].points[j].xyz[k] = list_in->surfaces[i].points[j].xyz[k];
			}
		}
	}
	for (i = 0; i < 6; i++) {
		result.visible[i] = list_in->visible[i];
	}

	for (i = 0; i < 6; i++) {
		if (result.visible[i]) {
			x_0 = ((result.surfaces[i].points[3].xyz[0]) + 127) * 4;
			y_0 = 767 - (((result.surfaces[i].points[3].xyz[1]) + 127) * 3);
			for (j = 0; j < 4; j++) {
				x_1 = ((result.surfaces[i].points[j].xyz[0]) + 127) * 4;
				y_1 = 767 - (((result.surfaces[i].points[j].xyz[1]) + 127) * 3);
				vga_draw_line(vgabuf, x_0, y_0, x_1, y_1);
				x_0 = x_1;
				y_0 = y_1;
			}
		}
	}
}

void vga_draw_point(uint32 vgabuf[24578],
		        int x,
				int y)
{
	int index, index2;
	uint6 bit;
	uint32 buf, buf2;

	index = (y * 32) + (x / 32);
	index2 = (y * 32) + (x / 32);
	bit = (x % 32);
	buf = vgabuf[index];
	buf2 = buf | (((uint32)(0x01)) << bit);
	vgabuf[index2] = buf2;
}

void vga_draw_line(uint32 vgabuf[24578],
		       int x0,
			   int y0,
			   int x1,
			   int y1)
{
	int dx, sx, dy, sy, error, error2;
	int x_0, y_0, x_1, y_1;

	x_0 = x0;
	y_0 = y0;
	x_1 = x1;
	y_1 = y1;

	dx =  abs(x_1 - x_0);
	dy = abs(y_1 - y_0);

	sx = x_0 < x_1 ? 1 : -1;
	sy = y_0 < y_1 ? 1 : -1;

	error = dx - dy;

	while(1) {
		vga_draw_point(vgabuf, x_0, y_0);

		if(x_0 == x_1 && y_0 == y_1) {
			break;
		}

		error2 = error * 2;

		if (error2 > -dy) {
			error = error - dy;
			x_0 = x_0 + sx;
		}

		if (error2 < dx) {
			error = error + dx;
			y_0 = y_0 + sy;
		}
	}
}
