// prt_pud.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// set pull up/down to a input port
// *regs: GPIO mapping, port: GPIO number, val: 0 none, 1 pull down, 2 pull up
// return: success flag
int prt_pud(uint32_t *regs, int port, int val){
  if(fnc_rd(regs, port)){
    printf("GPIO%d FSEL: %d\n", port, fnc_rd(regs, port));
    fprintf(stderr, "pull up/down set valid only input port.\n");
    return -1;
  }

  regs[37] = val;// pull up/down control signal
  usleep(1);// wait 150 cycles
  regs[38] = (1 << port);// port specify
  usleep(1);// wait 150 cycles
  regs[37] = 0;// remove control signal
  regs[38] = 0;// remove port specify
  return 0;
}
