// pwm_mrk.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set PWM mark
// *regs: PWM mapping, value: mark
void pwm_mrk(uint32_t *regs, uint32_t value){
  regs[5] = value;
}