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

void init_gpios() {

  int exportfd, directionfd;
  char export_buffer[4];
  char dir_path_buffer[34];
  int gpio_nr;  

  for (gpio_nr = 266; gpio_nr < 906; gpio_nr++) {

    // Export GPIOs
    exportfd = open("/sys/class/gpio/export", O_WRONLY);
    if (exportfd < 0) {
      printf("Cannot open GPIO to export it\n");
      exit(1);
    }
    sprintf(export_buffer, "%d", gpio_nr);    
    write(exportfd, export_buffer, 3);
    close(exportfd);
    printf("GPIO%d exported successfully\n", gpio_nr);

    // Set direction of GPIO to output
    sprintf(dir_path_buffer, "/sys/class/gpio/gpio%d/direction", gpio_nr);
    directionfd = open(dir_path_buffer, O_RDWR);
    if (directionfd < 0)
    {
      printf("Cannot open GPIO direction it\n");
      exit(1);
    }
    write(directionfd, "out", 3);
    close(directionfd);
    printf("GPIO%d direction set as output successfully\n", gpio_nr);
  }
}

void open_gpios(int *fds){

  int fd_nr;
  char open_path_buffer[30];

  for (fd_nr = 0; fd_nr < 640; fd_nr++) {

    sprintf(open_path_buffer, "/sys/class/gpio/gpio%d/value", (fd_nr + 266));
    fds[fd_nr] = open(open_path_buffer, O_RDWR);

    if (fds[fd_nr] < 0)
    {
        printf("Cannot open GPIO value\n");
        exit(1);
    }
    printf("GPIO%d value opened\n", (fd_nr + 266));
  } 

}

void close_gpios(int *fds){

  int fd_nr;

  for (fd_nr = 0; fd_nr < 640; fd_nr++) {
    close(fds[fd_nr]);
  }

}

void set_gpios (int *fsd, 
				char mx[10], 
				char my[10],
				char mz[10],
        char size[10],
				char rx[10], 
				char ry[10],
				char rz[10],
        char visible[10],
        char category[10]) {

  int i, k, j;

 

  for (j = 0; j < 10; j++) {

    // ----------Set rotation für object j 

    // Set rx[j] 
    for (i = 7; i >= 0; i--) {
      k = rx[j] >> i;
      if (k & 1) {
        write(fsd[i + (j * 64)], "1", 2);
      } else {
        write(fsd[i + (j * 64)], "0", 2);
      }
    }

    // Set ry[j] 
    for (i = 7; i >= 0; i--) {
      k = ry[j] >> i;
      if (k & 1) {
        write(fsd[i + 8 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 8 + (j * 64)], "0", 2);
      }
    }

    // Set rz[j]
    for (i = 7; i >= 0; i--) {
      k = rz[j] >> i;
      if (k & 1) {
        write(fsd[i + 16 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 16 + (j * 64)], "0", 2);
      }
    }

    // Set visible
    if (visible[j] == 1) {
        write(fsd[24 + (j * 64)], "1", 2);
    } else {
        write(fsd[24 + (j * 64)], "0", 2);
    }

    // Set category
    for (i = 6; i >= 0; i--) {
      k = category[j] >> i;
      if (k & 1) {
        write(fsd[i + 25 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 25 + (j * 64)], "0", 2);
      }
    }

    // ----------Set middlepoint für object j


    // Set mx[j] 
    for (i = 7; i >= 0; i--) {
      k = mx[j] >> i;
      if (k & 1) {
        write(fsd[i + 32 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 32 + (j * 64)], "0", 2);
      }
    }

    // Set my[j] 
    for (i = 7; i >= 0; i--) {
      k = my[j] >> i;
      if (k & 1) {
        write(fsd[i + 40 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 40 + (j * 64)], "0", 2);
      }
    }

    // Set mz[j]
    for (i = 7; i >= 0; i--) {
      k = mz[j] >> i;
      if (k & 1) {
        write(fsd[i + 48 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 48 + (j * 64)], "0", 2);
      }
    }

    // Set size[j]
    for (i = 7; i >= 0; i--) {
      k = size[j] >> i;
      if (k & 1) {
        write(fsd[i + 56 + (j * 64)], "1", 2);
      } else {
        write(fsd[i + 56 + (j * 64)], "0", 2);
      }
    }
  }
}
/*

// ----------Set rotation für object 1  

  // Set rz1 
  for (i = 7; i >= 0; i--) {
    k = rz1 >> i;
    if (k & 1) {
      write(fsd[i+64], "1", 2);
    } else {
      write(fsd[i+64], "0", 2);
    }
  }

  // Set ry1 
  for (i = 7; i >= 0; i--) {
    k = ry1 >> i;
    if (k & 1) {
      write(fsd[i+72], "1", 2);
    } else {
      write(fsd[i+72], "0", 2);
    }
  }

  // Set rx1
  for (i = 7; i >= 0; i--) {
    k = rx1 >> i;
    if (k & 1) {
      write(fsd[i+80], "1", 2);
    } else {
      write(fsd[i+80], "0", 2);
    }
  }

  // Set unused
  for (i = 7; i >= 0; i--) {
    k = 0;
    if (k & 1) {
      write(fsd[i+88], "1", 2);
    } else {
      write(fsd[i+88], "0", 2);
    }
  }

// ----------Set middlepoint für object 1  

  // Set mz1 
  for (i = 7; i >= 0; i--) {
    k = mz1 >> i;
    if (k & 1) {
      write(fsd[i+96], "1", 2);
    } else {
      write(fsd[i+96], "0", 2);
    }
  }

  // Set my1 
  for (i = 7; i >= 0; i--) {
    k = my1 >> i;
    if (k & 1) {
      write(fsd[i+104], "1", 2);
    } else {
      write(fsd[i+104], "0", 2);
    }
  }

  // Set mx1
  for (i = 7; i >= 0; i--) {
    k = mx1 >> i;
    if (k & 1) {
      write(fsd[i+112], "1", 2);
    } else {
      write(fsd[i+112], "0", 2);
    }
  }

  // Set unused
  for (i = 7; i >= 0; i--) {
    k = 0;
    if (k & 1) {
      write(fsd[i+120], "1", 2);
    } else {
      write(fsd[i+120], "0", 2);
    }
  }
}
*/



