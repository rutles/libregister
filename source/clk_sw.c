// clk_sw.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// CLK turn on/off
// *regs: PWM mapping, val: 0 off, 1 on
void clk_sw(uint32_t *regs, int val){
  if(val){
    regs[28] = 0x5A000000 | 0x11;// enable clock
  } else {
    regs[28] = 0x5A000000 | 0x01;// disable clock
    while(regs[28] & 0x80); // loop while busy
  }
}
