#include <TimerOne.h>
#include "TM1637Display.h"

#define CLK 10
#define DIO 11
#define LED 2

TM1637Display fnd(CLK, DIO);
volatile uint8_t tSec = 0;
volatile uint8_t tMin = 0;
volatile uint8_t tFlag = 1;
volatile long tPeriod = 1000000;
int led = 1;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Timer1.initialize(tPeriod); // 1sec
  Timer1.attachInterrupt(OneSec);  // ISR
  fnd.setBrightness(1);
  fnd.showNumberDecEx(0, 0x40, true);
}

void OneSec()
{
  tSec = tSec + 1;
  if(tSec == 3){
    led = 0; 
  }
  if(tSec == 10){
    led = 1;
    tSec = 0;
    tMin += 10;
  }
}

void loop(){
  uint16_t num;
  num = tMin + tSec;
  fnd.showNumberDecEx(num);
  if(led == 1){   
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
