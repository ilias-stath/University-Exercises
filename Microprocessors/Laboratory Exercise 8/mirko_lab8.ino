#include <SPI.h>
#include "Ucglib.h"

Ucglib_PCF8833_16x132x132_SWSPI ucg(/*sclk=*/13, /*data=*/11, /*cs=*/9, /*reset*/ 8);

int KEYA = 0;
int KEYB = 1;
int KEYC = 2;
int KEYD = 3;

int Pos, xNew, yNew, xOld = 65, yOld = 65;

void setup() {
  pinMode(KEYA, INPUT);
  pinMode(KEYB, INPUT);
  pinMode(KEYC, INPUT);
  pinMode(KEYD, INPUT);

  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();

  ucg.setFont(ucg_font_ncenR12_tr);
  ucg.setColor(255, 240, 0);

  ucg.setPrintPos(0, 25);
  ucg.print("Hello 2017!");

  ucg.setColor(123, 180, 255);
  ucg.drawTriangle(65, 80, 10, 40, 120, 40);

  ucg.setColor(0, 255, 0);
  ucg.drawCircle(65, 100, 20, UCG_DRAW_UPPER_RIGHT | UCG_DRAW_UPPER_LEFT);

  delay(2000);

  ucg.clearScreen();

  ucg.setColor(182,56,78);
  ucg.drawDisc(65, 65, 2, UCG_DRAW_ALL);

  ucg.clearScreen();
}

void setColor(){
  if(digitalRead(KEYA)==0) ucg.setColor(255,0,0);
  else if(digitalRead(KEYB)==0) ucg.setColor(0,255,0);
  else if(digitalRead(KEYC)==0) ucg.setColor(0,0,255);
  else if(digitalRead(KEYD)==0) ucg.setColor(255,128,64);
}

void loop() {
  setColor();
  Pos = analogRead(A0);
  // map the result to 0 - 131
  xNew = map(Pos, 0, 1023, 0, 131);

  Pos = analogRead(A1);
  // map the result to 0 - 131
  yNew = map(Pos, 0, 1023, 0, 131);

  if(xOld != xNew || yOld != yNew){
    ucg.drawLine(xOld, yOld, xNew, yNew);
    xOld = xNew;
    yOld = yNew;
  }


}
