// prt_rd.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// read port level
// *regs: GPIO mapping, port: GPIO number
// return: 1 or 0
int prt_rd(uint32_t *regs, int port){
  return (regs[13] >> port) & 1;
}