// fnc_clk.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set GPIO4 as free running clock out
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *fnc_clk(){
  uint32_t *regs;

  regs = regs_map(OFF_PRT);
  if(regs == MAP_FAILED)
    return MAP_FAILED;
  fnc_wr(regs, 4, FNC_CLK);//set GPIO4 for CLK
  munmap((void *)regs, getpagesize());

  regs = regs_map(OFF_CLK);
  if(regs == MAP_FAILED)
    return MAP_FAILED;
  return regs;
}
