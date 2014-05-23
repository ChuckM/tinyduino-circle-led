README
------

This is a program for driving the [Circle LED](https://tiny-circuits.com/shop/tinyshield-circle-edge-leds/) shield from
[Tiny Circuits](http://tiny-circuits.com). The weird thing about 
CharliePlexing is that you turn on the LEDs by making two pins outputs
and the other inputs. So realistically you can only turn on one LED at
a time.

The one at a time restriction makes using/programming this shield a
lot harder than it might otherwise be (say if you had 21 GPIO pins or
a shift register. The solution then is to turn on all the LEDs that
should be on rapidly enough that the persitence of vision that the
human eye has perceives them as being on.

This code uses the 
[Timer1 library](http://playground.arduino.cc/Code/Timer1)
from the Arduinio site to create an interrupt service routine that is
called once per millisecond (every 1,000 microseconds) that
illuminates an LED if it is 'supposed' to be on. Given the period, it
lights every LED once in 21 mS. So the entire array is refreshed at a
rate of about 48 Hz. You can make it run faster by reducing the timer
constant but doing so will start to interfere with responsiveness of
the Arduino. 

To use the LEDs with this code you simply set the value in the
led\_data array to 1 (for on) or 0 (for off). The example code first
illumnates all LEDs and then extinguishes them all.

