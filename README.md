Raspberry Pi BCM2835 peripheral registers handling library

Setup

pi@raspberrypi~$ cd libregister<br>
pi@raspberrypi~/libregister$ make<br>
pi@raspberrypi~/libregister$ sudo make install<br>

following commands are usable as needed.

make clean<br>
sudo make uninstall

Usage

c source -&gt #include &ltregister.h&gt
compile -&gt add option -lregister to command line tail

ex.<br>
cc example_pwm.c -o example_pwm -lregister<br>
sudo example_pwm.c<br>

Function<br>
see source/register.h or /usr/local/include/register.h

Tetsuya Suzuki, 2013<br>
GNU General Public License
