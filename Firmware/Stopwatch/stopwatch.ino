#include <TimerOne.h>
#include "TM1637Display.h"

#define CLK 10
#define DIO 11
#define TOUCH 2

TM1637Display fnd(CLK, DIO);
volatile uint16_t tSec = 0;
volatile uint16_t tMsec = 0;
volatile uint16_t tFlag = 0;
volatile long tPeriod;
volatile int Touched = 0;

void setup() {
  pinMode(TOUCH, INPUT_PULLUP);
  tPeriod = 50000;
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT0, RISING);
  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(blinked);
  fnd.setBrightness(1);
  fnd.showNumberDecEx(0, 0x40, true);
}

void ISR_INT0(){
  Touched ^= 1;
}

void blinked(){
  if(Touched == 1){
    tMsec = tMsec + 5;
    if(tMsec == 100){
      tSec += 1;
      tMsec = 0;
    }
    tFlag = 1;
  }
  else{
    tMsec = 0;
    tSec = 0;
    tFlag = 0;
  }
}

void loop() {
  uint16_t num;
  uint16_t dot;
  if(tFlag == 1 && Touched == 1){
    num = tSec * 100 + tMsec;
    dot = (tMsec % 50 == 0) ? 0 : 0x40; // 0.5초 마다 깜빡
    fnd.showNumberDecEx(num, dot, true);
    tFlag = 0;
  }
}
