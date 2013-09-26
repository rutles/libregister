// clk_frq.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set CLK frequency
// *regs: CLK mapping, val: frequency
void clk_frq(uint32_t *regs, uint32_t val){
  uint32_t save;
  int di, dr, df;

  di = 19200000 / val;
  dr = 19200000 % val;
  df = (int)((double)dr * 4096.0 / 19200000.0);

  save = regs[28];//backup on/off
  clk_sw(regs, 0);//temporary off
  regs[29] = 0x5A000000 | (di << 12) | df;
  regs[28] = save;//restore on/off
}
