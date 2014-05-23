/*
 * Use a timer to auto-refresh all 21 LEDs on the Circle LED
 * shield from Tiny-Circuits.com
 *
 * Author: Chuck McManis
 */
#include <TimerOne.h>

char led_state[21] = {
  0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0
};

unsigned char led = 0;
static unsigned char sel_led[] = {
// hi, lo
  0x56,  // D1
  0x65,  // D2
  0x57,  // D3
  0x75,  // D4
  0x67,  // D5
  0x76,  // D6
  0x68,  // D7
  0x86,  // D8
  0x58,  // D9
  0x85,  // D10
  0x87,  // D11
  0x78,  // D12
  0x97,  // D13
  0x79,  // D14
  0x98,  // D15
  0x89,  // D16
  0x59,  // D17
  0x95,  // D18
  0x69,  // D19
  0x96,  // D20
  0x94  // D21
};


void light_led() {
  static int cur_led = 0;
  int next_led = ((cur_led + 1) % 21);
  int hi_side = (sel_led[cur_led] >> 4) & 0xf;
  int lo_side = sel_led[cur_led] & 0xf;
  pinMode(hi_side, INPUT);
  pinMode(lo_side, INPUT);
  if (led_state[next_led]) {
    led_on(next_led);
  }
  cur_led = next_led;
}

void setup() {
  leds_off();
  Timer1.attachInterrupt(light_led, 1000);
}


void leds_off( void ) {
  int i;
  for (i = 4; i < 10; i++) {
    pinMode(i, INPUT);
  }
}

void led_on(int l) {
  int hi_led = (sel_led[l] >> 4) & 0xf;
  int lo_led = sel_led[l] & 0xf;
  
  digitalWrite(hi_led, HIGH);
  digitalWrite(lo_led, LOW);
  pinMode(hi_led, OUTPUT);
  pinMode(lo_led, OUTPUT);
}

void loop() {
  int i;
  for (i = 0; i < 21; i++) {
    led_state[i] = 1;
    delay(10);
  }
  for (i = 0; i < 21; i++) {
    led_state[i] = 0;
    delay(10);
  }
}

