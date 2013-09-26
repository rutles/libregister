Raspberry Pi BCM2835 peripheral registers handling library

Setup

pi@raspberrypi~$ git clone https://github.com/rutles/libregister<br>
pi@raspberrypi~$ cd libregister/source<br>
pi@raspberrypi~/libregister/source$ make<br>
pi@raspberrypi~/libregister/source$ sudo make install<br>

following commands are usable as needed.

pi@raspberrypi~/libregister/source$ make clean<br>
pi@raspberrypi~/libregister/source$ sudo make uninstall

Usage

c source -&gt #include &ltregister.h&gt<br>
compile -&gt add option -lregister to command line tail

ex.<br>
cc example_pwm.c -o example_pwm -lregister<br>
sudo example_pwm.c<br>

Function<br>
see libregister/source/register.h or /usr/local/include/register.h

Tetsuya Suzuki, 2013<br>
GNU General Public License
