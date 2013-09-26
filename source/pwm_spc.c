// pwm_spc.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set PWM space
// *regs: PWM mapping, val: space
void pwm_spc(uint32_t *regs, uint32_t val){
  regs[4] = val;
  usleep(10);
}