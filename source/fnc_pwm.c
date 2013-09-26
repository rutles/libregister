// fnc_pwm.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set GPIO18 as PWM M/S mode
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *fnc_pwm(){
  uint32_t *regs;

  regs = regs_map(OFF_PRT);
  if(regs == MAP_FAILED)
    return MAP_FAILED;
  fnc_wr(regs, 18, FNC_PWM);//set GPIO18 for PWM
  munmap((void *)regs, getpagesize());

  regs = regs_map(OFF_PWM);
  if(regs == MAP_FAILED)
    return MAP_FAILED;
  regs[0] |= 0x80;// PWM/MS mode
  return regs;
}
