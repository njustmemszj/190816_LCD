# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\01_Xilinx_FPGA\1908_IIC_slave_PSoC\190816_LCD\190816_LCD.cydsn\190816_LCD.cyprj
# Date: Fri, 16 Aug 2019 10:49:58 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]


# Component constraints for D:\01_Xilinx_FPGA\1908_IIC_slave_PSoC\190816_LCD\190816_LCD.cydsn\TopDesign\TopDesign.cysch
# Project: D:\01_Xilinx_FPGA\1908_IIC_slave_PSoC\190816_LCD\190816_LCD.cydsn\190816_LCD.cyprj
# Date: Fri, 16 Aug 2019 10:49:55 GMT
