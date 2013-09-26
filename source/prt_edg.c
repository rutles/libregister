// prt_edg.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set Edge detect
// *regs: GPIO mapping, port: GPIO number, val: 0 none, 1 rising, 2 falling, 3 both
void prt_edg(uint32_t *regs, int port, int val){
  if(val & 1)//rising
    regs[19] |= (1 << port);
  else
    regs[19] &= ~(1 << port);

  if(val & 2)//falling
    regs[22] |= (1 << port);
  else
    regs[22] &= ~(1 << port);
}