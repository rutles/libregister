// prt_drv.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// change drive strength of all GPIO pins
// val: 0 - 7 -> 2mA - 16mA
void prt_drv(int val){
  uint32_t state;
  uint32_t *regs;

  regs = regs_map(OFF_PAD);
  state = (regs[11] & ~7) | val;
  regs[11] = 0x5A000000 | state;
  munmap((void *)regs, getpagesize());
}
