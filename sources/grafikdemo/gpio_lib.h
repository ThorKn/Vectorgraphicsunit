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

// Function prototypes
void init_gpios();
void open_gpios(int *fds);
void close_gpios(int *fds);
void set_gpios (int *fsd, 
				        char mx[10], 
				        char my[10],
				        char mz[10],
                char size[10],
				        char rx[10], 
				        char ry[10],
				        char rz[10],
                char visible[10],
                char category[10]);


