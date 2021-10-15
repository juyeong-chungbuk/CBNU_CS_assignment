#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define TOUCH 2
#define analogPin 5
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display tm1637(CLK, DIO);
volatile int Touched = 0;
int adValue;
int degree;

void setup() {
  Serial.begin(9600);
  degree = 0;
  tm1637.setBrightness(0x04);
  tm1637.showNumberDec(degree);

  pinMode(TOUCH, INPUT_PULLUP);
  Serial.println("Ready");

  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT0, RISING);
}

void ISR_INT0()
{
  Touched = 1;
}

void loop() {
  if (Touched == 1) {
    Serial.println("Touched");
  
    adValue = analogRead(analogPin);        // 12 bit 0 ~ 1023
    analogWrite(DIO, adValue>>2);     //  8 bit 0 ~ 255
    Serial.println(adValue);

    degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
    tm1637.showNumberDec(degree);
    Serial.println(degree);
    delay(1000);
    Touched = 0;
  }
}
