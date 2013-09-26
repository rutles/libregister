// fnc_wr.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// function select
// *regs: GPIO mapping, port: GPIO number, val: function value
void fnc_wr(uint32_t *regs, int port, int val){
  regs[port / 10] &=  ~(7 << ((port % 10) * 3));
  regs[port / 10] |= (val << ((port % 10) * 3));
}