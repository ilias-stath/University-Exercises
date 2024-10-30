//Specify stepper and servo pins
int STEPPER0 = 8;
int STEPPER1 = 9;
int STEPPER2 = 10;
int STEPPER3 = 11;

int SERVO1 = 5;
int SERVO2 = 6;

int BUTTONRIGHT = 12;
int BUTTONLEFT = 13;

int delay_time = 200;
int count;
int BrState = LOW, BlState = LOW;

int ServoPosition1=0, NewServoPosition1=0, ServoPosition2=0, NewServoPosition2=0;

void setup() {
  pinMode(STEPPER0,OUTPUT);
  pinMode(STEPPER1,OUTPUT);
  pinMode(STEPPER2,OUTPUT);
  pinMode(STEPPER3,OUTPUT);

  pinMode(SERVO1, OUTPUT);
  pinMode(SERVO2, OUTPUT);

  pinMode(BUTTONRIGHT,INPUT);
  pinMode(BUTTONLEFT,INPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void stepper_turn(int direction, int speed){
  if (direction == 0){
    count = 0;
    do{
      digitalWrite(STEPPER0,0);
      digitalWrite(STEPPER1,1);
      digitalWrite(STEPPER2,0);
      digitalWrite(STEPPER3,1);
      delay(speed);

      digitalWrite(STEPPER0,1);
      digitalWrite(STEPPER1,0);
      digitalWrite(STEPPER2,0);
      digitalWrite(STEPPER3,1);
      delay(speed);

      digitalWrite(STEPPER0,1);
      digitalWrite(STEPPER1,0);
      digitalWrite(STEPPER2,1);
      digitalWrite(STEPPER3,0);
      delay(speed);

      digitalWrite(STEPPER0,0);
      digitalWrite(STEPPER1,1);
      digitalWrite(STEPPER2,1);
      digitalWrite(STEPPER3,0);
      delay(speed);

      count++;
    }while(count < 10);
  }else{
    count = 0;
    do{
      digitalWrite(STEPPER3,0);
      digitalWrite(STEPPER2,1);
      digitalWrite(STEPPER1,0);
      digitalWrite(STEPPER0,1);
      delay(speed);

      digitalWrite(STEPPER3,1);
      digitalWrite(STEPPER2,0);
      digitalWrite(STEPPER1,0);
      digitalWrite(STEPPER0,1);
      delay(speed);

      digitalWrite(STEPPER3,1);
      digitalWrite(STEPPER2,0);
      digitalWrite(STEPPER1,1);
      digitalWrite(STEPPER0,0);
      delay(speed);

      digitalWrite(STEPPER3,0);
      digitalWrite(STEPPER2,1);
      digitalWrite(STEPPER1,1);
      digitalWrite(STEPPER0,0);
      delay(speed);

      count++;
    }while(count < 10);
  }
}

void loop() {
  //--Control Stepper

  int stepPot = analogRead(A0);
  
  int speedPot = map(stepPot,0,1023,0,100);

  BrState = digitalRead(BUTTONRIGHT);

  BlState = digitalRead(BUTTONLEFT);

  //delay(5000);

  

  if(BrState == HIGH){
    stepper_turn(0,speedPot);
  }else if(BlState == HIGH){
    stepper_turn(1,speedPot);
  }
  
  //stepper_turn(1,50);
  //delay(10000);

  //Control Servo
  //analogWrite(SERVO1,200);

  //analogWrite(SERVO2,150); 
  //Katw apo 128 den gyrnaei

  //Control Servo1
  int Servo1Pot = analogRead(A1);

  NewServoPosition1 = map(Servo1Pot, 0, 1023, 0, 255);

  if(NewServoPosition1 != ServoPosition1){
    ServoPosition1 = NewServoPosition1;
    analogWrite(SERVO1,ServoPosition1);
  }


  //Control Servo2
  int Servo2Pot = analogRead(A2);

  NewServoPosition2 = map(Servo2Pot, 0, 1023, 0, 255);

  if(NewServoPosition2 != ServoPosition2){
    ServoPosition2 = NewServoPosition2;
    analogWrite(SERVO2,ServoPosition2);
  }

  

}
