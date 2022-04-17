#include "avr/io.h"
#include <util/delay.h>
#include "fast_pwm.h"

void PWM_set(bool mode){ // PWM setup function
  if(mode == true) //fast pwm to control LED
  {
    DDRD |= (1<<PD7); //set PD7 as PWM output
    TCCR2 |= (1<<WGM20)|(1<<WGM21); //select Fast PWM mode by setting bits 
    TCCR2 |=(1<<COM21)|(1<<CS20)|(0<<CS21)|(0<<CS22); //clear OC2 on compare match
  }
  else //phase corrected pwm to control motor
  {
    DDRD |= (1<<PD7); //set PD7 as PWM output
    TCCR2 |= (1<<WGM20)|(0<<WGM21); //select Phase PWM mode by setting bits 
    TCCR2 |=(1<<COM21)|(1<<CS20)|(0<<CS21)|(0<<CS22); //clear OC2 on compare match
  }
}

void setPWM(int duty)
{
  OCR2=duty;
}