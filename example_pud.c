/*
  example_pud.c
  Port pull up/down example
  pull up and read, then pull down and read
  compile: cc example_pud.c -o example_pud -lregister
  execute: sudo ./example_pud
*/

#include <register.h>

int main(){
  int ret;
  uint32_t *regs;

  regs = regs_map(OFF_PRT);
  if(regs == MAP_FAILED){
    fprintf(stderr, "fail to get registers map. %s\n", strerror(errno));
    return -1;
  }

  fnc_wr(regs, 25, 0); //set GPIO25 as input
  prt_pud(regs, 25, 2);//pull up GPIO25
  ret = prt_rd(regs, 25); // read GPIO25;
  printf("GPIO%d value:%d\n", 25, ret);

  prt_pud(regs, 25, 1);//pull down GPIO25
  ret = prt_rd(regs, 25); // read GPIO25;
  printf("GPIO%d value:%d\n", 25, ret);

  prt_pud(regs, 25, 0);//clear pull up/down GPIO25

  ret = munmap((void *)regs, getpagesize());
  if(ret){
    fprintf(stderr, "fail to unmap. %s\n", strerror(errno));
    return -1;
  }
  return 0;
}
