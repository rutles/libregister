// fnc_rd.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// read selected function
// *regs: GPIO mapping, port: GPIO number
// return: function value, ex.0 input, 1 output
int fnc_rd(uint32_t *regs, int port){
  return (regs[port / 10] >> (port % 10) * 3) & 7;
}