/*
 *
 * Author:   Thorsten Knoll
 * Date:     09/26/2016
 *
 * This file is made for usage with Vivado Design Suite 2016.1
 */

##Switches
# Switch 0
set_property PACKAGE_PIN G15 [get_ports {z_invert[0]}];
set_property IOSTANDARD LVCMOS33 [get_ports {z_invert[0]}]

##Buttons
# Button 0
#set_property PACKAGE_PIN B18 [get_ports {aux_reset_in}];
#set_property IOSTANDARD LVCMOS33 [get_ports {aux_reset_in}]

##Pmod Header JB
# JB_1
set_property PACKAGE_PIN T20 [get_ports {x[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[0]}]

# JB_2
set_property PACKAGE_PIN U20 [get_ports {x[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[1]}]

# JB_3
set_property PACKAGE_PIN V20 [get_ports {x[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[2]}]

# JB_4
set_property PACKAGE_PIN W20 [get_ports {x[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[3]}]

# JB_7
set_property PACKAGE_PIN Y18 [get_ports {x[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[4]}]

# JB_8
set_property PACKAGE_PIN Y19 [get_ports {x[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[5]}]

# JB_9
set_property PACKAGE_PIN W18 [get_ports {x[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[6]}]

# JB_10
set_property PACKAGE_PIN W19 [get_ports {x[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {x[7]}]

##Pmod Header JC
# JC_1
set_property PACKAGE_PIN V15 [get_ports {y[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[0]}]

# JC_2
set_property PACKAGE_PIN W15 [get_ports {y[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[1]}]

# JC_3
set_property PACKAGE_PIN T11 [get_ports {y[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[2]}]

# JC_4
set_property PACKAGE_PIN T10 [get_ports {y[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[3]}]

# JC_7
set_property PACKAGE_PIN W14 [get_ports {y[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[4]}]

# JC_8
set_property PACKAGE_PIN Y14 [get_ports {y[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[5]}]

# JC_9
set_property PACKAGE_PIN T12 [get_ports {y[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[6]}]

# JC_10
set_property PACKAGE_PIN U12 [get_ports {y[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {y[7]}]

##Pmod Header JD
# JD_1
set_property PACKAGE_PIN T14 [get_ports {z[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {z[0]}]

##Pmod Header JE
# JE_1 - Joystick Axis 0
#set_property PACKAGE_PIN V12 [get_ports {gpio_io_i[0]}]
#set_property PULLUP "TRUE" [get_ports {gpio_io_i[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {gpio_io_i[0]]
# JE_2 - Joystick Axis 1
#set_property PACKAGE_PIN W16 [get_ports {gpio_io_i[1]}]
#set_property PULLUP "TRUE" [get_ports {gpio_io_i[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {gpio_io_i[1]}]
# JE_3 - Joystick Axis 2
#set_property PACKAGE_PIN J15 [get_ports {gpio_io_i[2]}]
#set_property PULLUP "TRUE" [get_ports {gpio_io_i[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {gpio_io_i[2]}]
# JE_4 - Joystick Axis 3
#set_property PACKAGE_PIN H15 [get_ports {gpio_io_i[3]}]
#set_property PULLUP "TRUE" [get_ports {gpio_io_i[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {gpio_io_i[3]}]
# JE_10 - Firebutton
#set_property PACKAGE_PIN Y17 [get_ports {gpio2_io_i[0]}]
#set_property PULLUP "TRUE" [get_ports {gpio2_io_i[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {gpio2_io_i[0]}]

##VGA Connector
set_property PACKAGE_PIN M19 [get_ports {red_out[0]}];
set_property IOSTANDARD LVCMOS33 [get_ports {red_out[0]}]

set_property PACKAGE_PIN L20 [get_ports {red_out[1]}];
set_property IOSTANDARD LVCMOS33 [get_ports {red_out[1]}]

set_property PACKAGE_PIN J20 [get_ports {red_out[2]}];
set_property IOSTANDARD LVCMOS33 [get_ports {red_out[2]}]

set_property PACKAGE_PIN G20 [get_ports {red_out[3]}];
set_property IOSTANDARD LVCMOS33 [get_ports {red_out[3]}]

set_property PACKAGE_PIN F19 [get_ports {red_out[4]}];
set_property IOSTANDARD LVCMOS33 [get_ports {red_out[4]}]

set_property PACKAGE_PIN H18 [get_ports {green_out[0]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[0]}]

set_property PACKAGE_PIN N20 [get_ports {green_out[1]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[1]}]

set_property PACKAGE_PIN L19 [get_ports {green_out[2]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[2]}]

set_property PACKAGE_PIN J19 [get_ports {green_out[3]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[3]}]

set_property PACKAGE_PIN H20 [get_ports {green_out[4]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[4]}]

set_property PACKAGE_PIN F20 [get_ports {green_out[5]}];
set_property IOSTANDARD LVCMOS33 [get_ports {green_out[5]}]

set_property PACKAGE_PIN P20 [get_ports {blue_out[0]}];
set_property IOSTANDARD LVCMOS33 [get_ports {blue_out[0]}]

set_property PACKAGE_PIN M20 [get_ports {blue_out[1]}];
set_property IOSTANDARD LVCMOS33 [get_ports {blue_out[1]}]

set_property PACKAGE_PIN K19 [get_ports {blue_out[2]}];
set_property IOSTANDARD LVCMOS33 [get_ports {blue_out[2]}]

set_property PACKAGE_PIN J18 [get_ports {blue_out[3]}];
set_property IOSTANDARD LVCMOS33 [get_ports {blue_out[3]}]

set_property PACKAGE_PIN G19 [get_ports {blue_out[4]}];
set_property IOSTANDARD LVCMOS33 [get_ports {blue_out[4]}]

set_property PACKAGE_PIN P19 [get_ports hsync];
set_property IOSTANDARD LVCMOS33 [get_ports hsync]

set_property PACKAGE_PIN R19 [get_ports vsync];
set_property IOSTANDARD LVCMOS33 [get_ports vsync]
