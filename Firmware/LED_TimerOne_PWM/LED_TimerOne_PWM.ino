//#include <TimerOne.h>
//#define LED 9
//int led = 0;
//
//void setup(){
//  pinMode(LED, OUTPUT);
//  Timer1.initialize(3000000); // 1sec
//  Timer1.pwm(LED, 512);
//}
//
//void loop(){
//  if(led == 0){
//    Timer1.setPeriod(3000000);
//    Timer1.setPwmDuty(LED, 512);
//    led = 1;
//  }
//  else{
//    Timer1.setPeriod(7000000);
//    Timer1.setPwmDuty(LED, 0);
//    led = 0;
//  }
////  Timer1.pwm(LED, 1023, 3000000);
////  Timer1.setPwmDuty(LED, 1023);
////  Timer1.pwm(LED, 0, 7000000);
////  Timer1.setPwmDuty(LED, 0);
//}

#include <TimerOne.h>
#define LED 9

volatile uint8_t tMsec = 0;
volatile long tPeriod = 100000;

void setup(){
  pinMode(LED, OUTPUT);
  Timer1.initialize(tPeriod); // 0.1초
}

void loop(){
  if(tMsec == 3){
    Timer1.pwm(LED, 1023);
  }
  if(tMsec == 10){
    Timer1.pwm(LED, 0);
    tMsec = 0;
  }
  tMsec += 1;
}
