#include <TM1637Display.h>

#define TOUCH 3
#define CLK 10
#define DIO 11
#define VOLUME 0
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

char buf[80];
TM1637Display fnd(CLK, DIO);
volatile int touched = 0;

void setup(){
  Serial.begin(9600);
  //touch sensor int1
  attachInterrupt(digitalPinToInterrupt(TOUCH), touch_isr, RISING);
  //FND 초기화
  fnd.setBrightness(4);
}

void touch_isr(){
  touched = 1;
}

void loop(){
  int adValue;
  int degree;
  unsigned long pt, ct;
  if(touched == 1){
    //adc
    pt = micros();
    adValue = analogRead(VOLUME);
    ct = micros();
    Serial.print("analogRead() 실행시간 : "); Serial.println(ct-pt);
    
    // display
    degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
    pt = micros();
    fnd.showNumberDec(degree);
    ct = micros();
    Serial.print("fnd.showNumberDec() 실행시간 : "); Serial.println(ct-pt);
    
    sprintf(buf, "degree: %d", degree);
    Serial.println(buf);
    touched = 0;
  }
}

//#include <TM1637Display.h>
//
//#define DIO 11
//#define CLK 10
//#define TOUCH 2
//#define analogPin 5
//#define FULL_ANGLE 280
//#define MAX_ADC 1023.0
//
//TM1637Display tm1637(CLK, DIO);
//volatile int Touched = 0;
//int adValue;
//int degree;
//
//void setup() {
//  degree = 0;
//  tm1637.setBrightness(0x04);
//  tm1637.showNumberDec(degree);
//
//  pinMode(TOUCH, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT0, RISING);
//}
//
//void ISR_INT0()
//{
//  Touched = 1;
//}
//
//void loop() {
//  if (Touched == 1) {
//    adValue = analogRead(analogPin);        // 12 bit 0 ~ 1023
////    analogWrite(DIO, adValue>>2);     //  8 bit 0 ~ 255
//
//    degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
//    tm1637.showNumberDec(degree);
//    Touched = 0;
//  }
//}
