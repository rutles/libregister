/*
  example_pwm.c
  LED with resistor shall be connected to GPIO18
  harf bright on/off repeat 10 interval 0.5sec
  compile: cc example_pwm.c -o example_pwm -lregister
  execute: sudo ./example_pwm
*/

#include <register.h>

int main(){
  int i;
  int ret;
  uint32_t *regs;

  regs = fnc_pwm();
  if(regs == MAP_FAILED){
    fprintf(stderr, "fail to get registers map. %s\n", strerror(errno));
    return -1;
  }
  pwm_spc(regs, 64);// space 64 clock
  pwm_mrk(regs, 32);// mark 32 clock (duty 50%)
  pwm_clk(regs, 8);// divide 8 (37.5 kHz)

  for(i = 0; i < 10; i++){
    pwm_sw(regs, 1);
    usleep(500000);
    pwm_sw(regs, 0);
    usleep(500000);
  }

  ret = munmap((void *)regs, getpagesize());
  if(ret)
    fprintf(stderr, "fail to unmap. %s\n", strerror(errno));
  return ret;
}
