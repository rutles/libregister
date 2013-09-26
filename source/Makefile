libregister.a:clk_frq.o clk_sw.o fnc_clk.o fnc_pwm.o fnc_rd.o fnc_wr.o \
prt_drv.o prt_edg.o prt_event.o prt_pud.o prt_rd.o prt_wr.o \
pwm_clk.o pwm_mrk.o pwm_spc.o pwm_sw.o regs_map.o

.c.o:
	cc -c -I. $<
	ar r libregister.a $@

clk_frq.o:clk_frq.c register.h
clk_sw.o:clk_sw.c register.h
fnc_clk.o:fnc_clk.c register.h
fnc_pwm.o:fnc_pwm.c register.h
fnc_rd.o:fnc_rd.c register.h
fnc_wr.o:fnc_wr.c register.h
prt_drv.o:prt_drv.c register.h
prt_edg.o:prt_edg.c register.h
prt_event.o:prt_event.c register.h
prt_pud.o:prt_pud.c register.h
prt_rd.o:prt_rd.c register.h
prt_wr.o:prt_wr.c register.h
pwm_clk.o:pwm_clk.c register.h
pwm_mrk.o:pwm_mrk.c register.h
pwm_spc.o:pwm_spc.c register.h
pwm_sw.o:pwm_sw.c register.h
regs_map.o:regs_map.c register.h

install:libregister.a
	install -o root -g staff -m 0644 register.h /usr/local/include
	install -o root -g staff -m 0644 libregister.a /usr/local/lib

uninstall:
	rm -f /usr/local/include/register.h
	rm -f /usr/local/lib/libregister.a

clean:
	rm -f *.o
	rm -f libregister.a
