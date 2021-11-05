#include <TimerOne.h>
#define LED 9
int led = 0;

void setup(){
  pinMode(LED, OUTPUT);
  Timer1.initialize(3000000); // 1sec
  Timer1.pwm(LED, 512);
}

void loop(){
  if(led == 0){
    Timer1.setPeriod(3000000);
    Timer1.setPwmDuty(LED, 512);
    led = 1;
  }
  else{
    Timer1.setPeriod(7000000);
    Timer1.setPwmDuty(LED, 0);
    led = 0;
  }
//  Timer1.pwm(LED, 1023, 3000000);
//  Timer1.setPwmDuty(LED, 1023);
//  Timer1.pwm(LED, 0, 7000000);
//  Timer1.setPwmDuty(LED, 0);
}
