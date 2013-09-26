/*
  example_clk.c
  Piezo sounder shall be connected to GPIO4
  Beep on/off repeat 10 interval 0.5sec
  compile: cc example_clk.c -o example_clk -lregister
  execute: sudo ./example_clk
*/

#include <register.h>

int main(){
  int i;
  int ret;
  uint32_t *regs;

  regs = fnc_clk();
  if(regs == MAP_FAILED){
    fprintf(stderr, "fail to get registers map. %s\n", strerror(errno));
    return -1;
  }
  clk_frq(regs, 4700);// 4.7kHz, this is minimum frequency

  for(i = 0; i < 10; i++){
    clk_sw(regs, 1);// beep
    usleep(500000);
    clk_sw(regs, 0);// stop
    usleep(500000);
  }

  ret = munmap((void *)regs, getpagesize());
  if(ret)
    fprintf(stderr, "fail to unmap. %s\n", strerror(errno));
  return ret;
}
