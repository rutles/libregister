// prt_wr.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// write port level
// *regs: GPIO mapping, port: GPIO number, val: 1 or 0
void prt_wr(uint32_t *regs, int port, int val){
  if(val)
    regs[7] = (1 << port);
  else
    regs[10] = (1 << port);
}