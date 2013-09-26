// register.h
// libregister header file
// Tetsuya Suzuki, 2013

#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>

// offset address
#define OFF_PRT 0x20200000 // port registers
#define OFF_PWM 0x2020C000 // PWM registers
#define OFF_CLK 0x20101000 // clock registers
#define OFF_PAD 0x20100000 // pads registers

// Create new mapping of registers
// offset: offset address of registers
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *regs_map(off_t offset);

// function select value
#define FNC_IN 0
#define FNC_OUT 1
#define FNC_PWM 2 // GPIO18 only
#define FNC_CLK 4 // GPIO4 only

// read selected function
// *regs: GPIO mapping, port: GPIO number
// return: function select value
int fnc_rd(uint32_t *regs, int port);

// select function
// *regs: GPIO mapping, port: GPIO number, val: function select value
void fnc_wr(uint32_t *regs, int port, int val);

// read port level
// *regs: GPIO mapping, port: GPIO number
// return: 1 or 0
int prt_rd(uint32_t *regs, int port);

// write port level
// *regs: GPIO mapping, port: GPIO number, val: 1 or 0
void prt_wr(uint32_t *regs, int port, int val);

// pull up/down value
#define PULL_NONE 0
#define PULL_UP 1
#define PULL_DOWN 2

// set pull up/down to a input port
// *regs: GPIO mapping, port: GPIO number, val: pull up/down value
// return: success flag
int prt_pud(uint32_t *regs, int port, int val);

// edge select value
#define EDG_NONE 0
#define EDG_RISING 1
#define EDG_FALLING 2
#define EDG_BOTH 3

// set Edge detect enable
// *regs: GPIO mapping, port: GPIO number, val: edge select value
void prt_edg(uint32_t *regs, int port, int val);

// get Edge detect status
// *regs: GPIO mapping, port: GPIO number
// return: 1 detect, 0 not detect
int prt_event(uint32_t *regs, int port);

// change drive strength of all GPIO pins
// val: 0 - 7 -> 2mA - 16mA
void prt_drv(int val);

// CLK turn on/off
// *regs: PWM mapping, val: 0 off, 1 on
void clk_sw(uint32_t *regs, int val);

// set CLK frequency
// *regs: CLK mapping, val: frequency in Hz
void clk_frq(uint32_t *regs, uint32_t val);

// set GPIO4 as free running clock out
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *fnc_clk(void);

// set PWM space
// *regs: PWM mapping, val: space
void pwm_spc(uint32_t *regs, uint32_t val);

// set PWM mark
// *regs: PWM mapping, value: mark
void pwm_mrk(uint32_t *regs, uint32_t value);

// PWM turn on/off
// *regs: PWM mapping, val: 0 off, 1 on
void pwm_sw(uint32_t *regs, uint32_t val);

// set PWM clock devide
// *regs: PWM mapping, val: divide
// NOTE: Frequency = 19200kHz / space / divide
void pwm_clk(uint32_t *regs, uint32_t val);

// set GPIO18 as PWM M/S mode
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *fnc_pwm(void);

#endif
