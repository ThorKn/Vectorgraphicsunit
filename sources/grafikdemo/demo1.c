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

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <linux/input.h>
#include "gpio_lib.h"

int main() {

  // Instances 
  int openfds[640];
  int i, j, k;
  char input;
  char mx[10], my[10], mz[10], size[10], rx[10], ry[10], rz[10], visible[10], category[10];

  // Initialize GPIOs
  init_gpios();
  open_gpios((int *)&openfds);

	printf("Welcome to Demo1\n");

  while (1)  {

    /***********************************
     * DEMO PART 1: Single Cube Object *
     ***********************************/

    // Initialize Objectparameters
    for (i = 0; i < 10; i++) {
      mx[i] = 0;
      my[i] = 0;
      mz[i] = 0;
      size[i] = 0;

      rx[i] = 0;
      ry[i] = 0;
      rz[i] = 0;
      visible[i] = 0;
      category[i] = 0;
    }

    // Display a Cube in Object 0    
    mx[0] = 127;
    my[0] = 127;
    mz[0] = 127;
    rx[0] = 50;
    ry[0] = 100;
    rz[0] = 150;
    category[0] = 0;
    size[0] = 5;
    visible[0] = 1;

    set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);

    for (i = 5; i < 20; i++) {
      size[0] = i;      
      set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
      usleep(25000);
    } 

    for (j = 0; j < 2; j++) {
      // Resize Object 0
      for (i = 20; i < 100; i++) {
        size[0] = i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
      for (i = 100; i > 20; i--) {
        size[0] = i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
    }
    for (j = 0; j < 2; j++) {
      // Resize Object 0 and rotate it
      for (i = 20; i < 100; i++) {
        size[0] = i;
        rx[0] = 30 + i;
        ry[0] = 80 + i;
        rz[0] = 130 + i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
      for (i = 100; i > 20; i--) {
        size[0] = i;      
        rx[0] = 30 + i;
        ry[0] = 80 + i;
        rz[0] = 130 + i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
    }
    for (i = 20; i > 5; i--) {
      size[0] = i;      
      set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
      usleep(25000);
    }

    /***********************************
     * DEMO PART 2: Single Pyramid Object *
     ***********************************/

    // Initialize Objectparameters
    for (i = 0; i < 10; i++) {
      mx[i] = 0;
      my[i] = 0;
      mz[i] = 0;
      size[i] = 0;

      rx[i] = 0;
      ry[i] = 0;
      rz[i] = 0;
      visible[i] = 0;
      category[i] = 0;
    }

    // Display a Pyramid in Object 0    
    mx[0] = 127;
    my[0] = 127;
    mz[0] = 127;
    rx[0] = 220;
    ry[0] = 20;
    rz[0] = 0;
    category[0] = 1;
    size[0] = 5;
    visible[0] = 1;

    set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);

    for (i = 5; i < 20; i++) {
      size[0] = i;      
      set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
      usleep(25000);
    } 

    for (j = 0; j < 2; j++) {
      // Resize Object 0
      for (i = 20; i < 100; i++) {
        size[0] = i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
      for (i = 100; i > 20; i--) {
        size[0] = i;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
    }
    for (j = 0; j < 2; j++) {
      // Resize Object 0 and rotate it
      for (i = 20; i < 100; i++) {
        size[0] = i;
        rx[0] = 240 - i;
        ry[0] = i;
        rz[0] = i - 20;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
      for (i = 100; i > 20; i--) {
        size[0] = i;      
        rx[0] = 240 - i;
        ry[0] = i;
        rz[0] = i - 20;      
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
    }
    for (i = 20; i > 5; i--) {
      size[0] = i;      
      set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
      usleep(25000);
    }

    /***********************************
     * DEMO PART 3: 10 Objects *
     ***********************************/

    // Initialize Objectparameters
    for (i = 0; i < 10; i++) {
      mx[i] = 15 + (i * 22);
      mz[i] = 127;
      size[i] = 15;

      rx[i] = 0;
      ry[i] = 0;
      rz[i] = 0;
      visible[i] = 1;
      category[i] = i % 2;
    }
  
    my[0] = 142;
    my[2] = 142;
    my[4] = 142;
    my[6] = 142;
    my[8] = 142;
    my[1] = 112;
    my[3] = 112;
    my[5] = 112;
    my[7] = 112;
    my[9] = 112;

    // Move and rotate the objects
    for (j = 0; j < 3; j++) {
      for (i = 0; i < 60; i++) {
        my[0] = 142 + i;
        my[2] = 142 + i;
        my[4] = 142 + i;
        my[6] = 142 + i;
        my[8] = 142 + i;
        my[1] = 112 - i;
        my[3] = 112 - i;
        my[5] = 112 - i;
        my[7] = 112 - i;
        my[9] = 112 - i;
        for (k = 0; k < 10; k++) {
          rx[k] = i;
          ry[k] = i;
          rz[k] = i;      
        }
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }

      for (i = 60; i > 0; i--) {
        my[0] = 142 + i;
        my[2] = 142 + i;
        my[4] = 142 + i;
        my[6] = 142 + i;
        my[8] = 142 + i;
        my[1] = 112 - i;
        my[3] = 112 - i;
        my[5] = 112 - i;
        my[7] = 112 - i;
        my[9] = 112 - i;
        for (k = 0; k < 10; k++) {
          rx[k] = i;
          ry[k] = i;
          rz[k] = i;      
        }     
        set_gpios((int*)&openfds, mx, my, mz, size, rx, ry, rz, visible, category);
        usleep(25000);
      }
    }
  }

  close_gpios((int *)&openfds);

	return 0;
}
