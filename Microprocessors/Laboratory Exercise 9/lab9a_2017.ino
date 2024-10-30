#include <SPI.h>
#include "Ucglib.h"

Ucglib_PCF8833_16x132x132_SWSPI ucg(/*sclk=*/13, /*data=*/11, /*cs=*/9, /*reset*/ 8);

#define trigPin1 2
#define trigPin2 3
#define echoPin1 4
#define echoPin2 5

#define SERVO 6

int Pos, xNew, yNew, xOld = 65, yOld = 65, y=0;
float duration;
float distance1, distance2; 

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);

  pinMode(SERVO, OUTPUT);
  analogWrite(SERVO,215);

  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();

  ucg.setFont(ucg_font_ncenR12_tr);
  ucg.setColor(255, 240, 0);

  ucg.setPrintPos(0, 25);
  ucg.print("Hello 2017!");

  ucg.clearScreen();



}

void loop() {

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  distance1 = duration*0.01723; //343 m/s iso me 0.01723 m/ms kai kanoyme dia 2 dioti to shma lambanete san phgaine-ela, emeis theloume to phgaine

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH);
  distance2 = duration*0.01723;

  // Debug
  //ucg.setPrintPos(0,50);
  //ucg.print(distance1);
  //ucg.setPrintPos(0,75);
  //ucg.print(distance2);
  //delay(3000);
  //ucg.clearScreen();

  if(distance1 > distance2 + 5){
    analogWrite(SERVO,170);
  }else if(distance2 > distance1 + 5){
    analogWrite(SERVO,250);
  }else{
    analogWrite(SERVO,215);
  }

  ucg.setColor(0,0,0);
  ucg.drawLine(0,y,131,y);

  ucg.setColor(255,240,0);
  ucg.drawLine(65,y,65-distance1/4,y);

  ucg.setColor(0,240,255);
  ucg.drawLine(65,y,65+distance2/4,y);

  if(y < 131){
    y++;
  }else{
    y=0;
  }


}
