//specify stepper connecting pins
int STEPPER0 = 8;
int STEPPER1 = 9;
int STEPPER2 = 10;
int STEPPER3 = 11;

int SERVO = 5;

int INTPIN1 = 2;
int INTPIN2 = 3;


volatile int NewServoPosition =  250;
volatile int OldServoPosition = 0;

volatile int stepperSpeed=10;
volatile int direction = 0;

// We create these variables so we can delay the time inside the interrupt routines in order to not have
// errors that are created from accidental double taps. currentTime symbolizes the current time that
// we call the interrupt and pastTime symbolizes the previous time that an interrupt happend
volatile long currentTime1 = 0;
volatile long pastTime1 =0;
volatile long currentTime2 = 0;
volatile long pastTime2 =0;

// We use the elapsed value as a delay. The higher the elapsedValue the lower the interrupt frequency,
// because we use the elapsed value as a lower margin for the division between currentTime and pastTime
volatile long elapsedValue = 200;



void setup() {

  // Set pins as outputs
  pinMode(STEPPER0, OUTPUT);
  pinMode(STEPPER1, OUTPUT);
  pinMode(STEPPER2, OUTPUT);
  pinMode(STEPPER3, OUTPUT);

  pinMode(SERVO,OUTPUT);

  noInterrupts(); // Deactivating the interrupts in order to do the settings

   // Connecting intPin with an interrupt and with a routine
  attachInterrupt(digitalPinToInterrupt(INTPIN1),buttonPressed1,RISING); 
  attachInterrupt(digitalPinToInterrupt(INTPIN2),buttonPressed2,RISING);
  // buttonPressed is a routine checking if the button is pressed when RISING(getting pressed), i must create the routine

  interrupts(); // Activating Interrupts

}

void stepper_turn(int direction, int speed,  int steps)
{
  int count;
  if (direction == 0){
    count = 0;
    do {
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
    }while ( count < steps);  
  }
  else{
    count = 0;
    do {
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
    }while (count < steps);

  }
}


void loop() {
  stepper_turn(direction, stepperSpeed, 5);
  if (NewServoPosition != OldServoPosition){
    analogWrite(SERVO,NewServoPosition);
    OldServoPosition = NewServoPosition;
  }
}

// Routine 1 changes the stepper direction
void buttonPressed1(){
  currentTime1 = millis(); //This function gives us the time from the start of the programm in miliseconds
  if((currentTime1 - pastTime1) > 500){
    if(direction == 0){
      direction = 1;
    }else{
      direction = 0;
    }
  }
  pastTime1 = currentTime1;
  
}
// Routine 2 changes the servo angle
void buttonPressed2(){
   currentTime2 = millis();
    if((currentTime2 - pastTime2) > 500){
      if(NewServoPosition == 250){
        NewServoPosition = 0;
      }
      else{
        NewServoPosition = 250;  
      }
    }
    pastTime2 = currentTime2;
}