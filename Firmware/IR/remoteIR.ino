#include <TM1637Display.h>
#include "IRSendRev.h"

#define DIO 11
#define CLK 10
#define IR_OUT_PIN 2 // IR 수신기 D2에 연결

TM1637Display FND(CLK, DIO); // FND객체 생성 및 초기화
String input; // 리모콘에서 입력받은 값 저장할 변수
unsigned char dta[20]; // 수신한 데이터 저장 변수

void setup() {
  IR.Init(IR_OUT_PIN); // IR을 수신할 핀 설정
  FND.setBrightness(0x04); // FND의 밝기 초기화
}

void loop() {
  if(IR.IsDta()){ // 데이터가 수신되었다면
    IR.Recv(dta);    // 수신한 데이터를 dta에 넣는다.
    if(dta[D_DATA+2] == 176 && dta[D_DATA+3] == 79) input = ""; // c를 입력받았을 경우 input 초기화
    else if(dta[D_DATA+2] == 2 && dta[D_DATA+3] == 253) input = String(input.toInt() + 1);  // +를 입력받았을 경우 input 값에서 하나 증가
    else if(dta[D_DATA+2] == 152 && dta[D_DATA+3] == 103) input = String(input.toInt() - 1);  // -를 입력받았을 경우 input 값에서 하나 감소
    
    if(input.length()<4){ // input의 길이가 4보다 작을 경우만 숫자 입력을 출력할 수 있음
      if(dta[D_DATA+2] == 104 && dta[D_DATA+3] == 151) input += String(0);  // 0을 입력 받았을 경우 input에 문자로 0 더해줌
      else if(dta[D_DATA+2] == 48 && dta[D_DATA+3] == 207) input += String(1); // 1을 입력 받았을 경우 input에 문자로 1 더해줌
      else if(dta[D_DATA+2] == 24 && dta[D_DATA+3] == 231) input += String(2); // 2을 입력 받았을 경우 input에 문자로 2 더해줌
      else if(dta[D_DATA+2] == 122 && dta[D_DATA+3] == 133) input += String(3); // 3을 입력 받았을 경우 input에 문자로 3 더해줌
      else if(dta[D_DATA+2] == 16 && dta[D_DATA+3] == 239) input += String(4); // 4을 입력 받았을 경우 input에 문자로 4 더해줌
      else if(dta[D_DATA+2] == 56 && dta[D_DATA+3] == 199) input += String(5); // 5을 입력 받았을 경우 input에 문자로 5 더해줌
      else if(dta[D_DATA+2] == 90 && dta[D_DATA+3] == 165) input += String(6); // 6을 입력 받았을 경우 input에 문자로 6 더해줌
      else if(dta[D_DATA+2] == 66 && dta[D_DATA+3] == 189) input += String(7); // 7을 입력 받았을 경우 input에 문자로 7 더해줌
      else if(dta[D_DATA+2] == 74 && dta[D_DATA+3] == 181) input += String(8); // 8을 입력 받았을 경우 input에 문자로 8 더해줌
      else if(dta[D_DATA+2] == 82 && dta[D_DATA+3] == 173) input += String(9); // 9을 입력 받았을 경우 input에 문자로 9 더해줌
    }
  }
  FND.showNumberDec(input.toInt()); // fnd에 숫자로 출력
}