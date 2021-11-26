#include "IRSendRev.h"
#define IR_FREQ 38
unsigned char ir_data[40] = { 0, 60, 60, 20, 60, 0, 0 };
char packet[30];

void setup() {
  Serial.begin(9600);
  IR.Init();
  Serial.println("== INIT == ");
}

void make_irdata()
{
  int psize;
  psize = strlen(packet);
  ir_data[0] = 5 + psize;
  ir_data[5] = psize;
  strcpy(&ir_data[6], packet);
}

void loop() {
  byte cnt;
  if(Serial.available()) {
    cnt = Serial.readBytes(packet, 250);
    packet[cnt] = 0;
    make_irdata();
    Serial.print("Send:");
    Serial.print(packet);
    IR.Send(ir_data, IR_FREQ);
    }
}