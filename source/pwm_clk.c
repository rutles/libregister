// pwm_clk.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set PWM clock devide
// *regs: PWM mapping, val: divide
// NOTE: Frequency = 19200kHz / space / divide
void pwm_clk(uint32_t *regs, uint32_t val){
  uint32_t save;
  uint32_t *regs_clk;

  save = regs[0];
  regs[0] = 0;

  regs_clk = regs_map(OFF_CLK);
  regs_clk[40] = 0x5A000000 | 1;
  usleep(100);
  while(regs_clk[40] & 0x80)
    usleep(1);
  regs_clk[41] = 0x5A000000 | (val << 12);

  regs_clk[40] = 0x5A000000 | 0x11;
  munmap((void *)regs_clk, getpagesize());
  regs[0] = save;
}