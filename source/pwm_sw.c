// pwm_sw.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// PWM turn on/off
// *regs: PWM mapping, val: 0 off, 1 on
void pwm_sw(uint32_t *regs, uint32_t val){
  if(val)
    regs[0] |= 1;
  else
    regs[0] &= ~1;
}