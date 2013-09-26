// prt_event.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// get Edge detect status
// *regs: GPIO mapping, port: GPIO number
// return: 1 detect, 0 not detect
int prt_event(uint32_t *regs, int port){
  int ret;

  ret = regs[16] &= ~(1 << port);//read detect
  if(ret)
    regs[16] |= (1 << port);//clear detect

  return ret;
}
