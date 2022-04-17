#include "fast_pwm.h"
/*
 * Fast PWM library made by Belen Septian 
 * This library can be used for ATmega8535/ATmega16 using MightyCore bootloader
 * Connect LED/Motor to pin PD7 of ATmega8535/ATmega16
 * Please do not remove this copyright
*/

void setup() {
  // put your setup code here, to run once:
  PWM_set(false); //true for fast PWM (to control LED), false for phase corrected PWM (to control motor)
}

void loop() {
  // put your main code here, to run repeatedly:
  setPWM(255);
  delay(1000);
  setPWM(100);
  delay(1000);
  setPWM(0);
  delay(1000);
}