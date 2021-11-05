#include <TimerOne.h>
#include "TM1637Display.h"

#define CLK 10
#define DIO 11
#define TOUCH 2

TM1637Display fnd(CLK, DIO);
volatile uint8_t tSec = 0;
volatile uint8_t tMin = 0;
volatile uint8_t tFlag = 1;
volatile long tPeriod = 1000000;
volatile int Touched = 0;
int tTouched = 0;

void setup(){
  Serial.begin(9600);
  pinMode(TOUCH, INPUT_PULLUP);
  tPeriod = 1000000;
  Timer1.initialize(tPeriod); // 1sec
  Timer1.attachInterrupt(OneSec);  // ISR
  fnd.setBrightness(1);
  fnd.showNumberDecEx(0, 0x40, true);
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT0, RISING);
}

void ISR_INT0(){
  Touched += 1;
  Serial.print(Touched);
}

void OneSec()
{
  tSec = tSec + 5;
  if(tSec == 100){
    tMin += 1;
    tSec = 0; 
  }
  tFlag = 1;
}

void loop(){
  uint16_t num;
  uint16_t dot;
//  if(Touched % 2 == 1){
//    tFlag = 0;
//  }
  
  if(tFlag == 1){
    num = tMin + 100 + tSec;
    dot = (tSec % 50 == 0)? 0 : 0x40;  // 0.5초 마다 깜빡거림
    fnd.showNumberDecEx(num, dot, true);
    tFlag = 0;
//    if(Touched % 2 == 0){
//    tMin = 0;
//    tSec = 0;
//  }
  }
}
