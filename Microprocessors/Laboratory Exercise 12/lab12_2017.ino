// Interrupts using arduino
// Circuit Digest

#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
//rs,en,d4,d5,d6,d7

unsigned int i=0;

int ledPin1 = 13;
int ledPin2 = 1;
int ledPin3 = 4;

int intPin1 = 2;
int intPin2 = 3;

// Volatile means that the compiler doesn't delete the variable if unused
volatile byte output1 = HIGH;
volatile byte output2 = HIGH;

volatile unsigned value = 1000; //The smaller the starting value the higher the interrupt frequency, when it reaches 0 it does an interrupt



void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ilias Stathakos");

  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

  noInterrupts(); //Deactivating Interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = value; //Preload time
  TCCR1B |= (1 << CS10)|(1 << CS12); //Shifting and applying, 1024 prescaling, division between clock and 1024
  TIMSK1 |= (1 << TOIE1); //Enable time
  //Explaination at interrupt lecture(lecture7) page 22 figure 16-2.

   //Connecting intPin with an interrupt and with a routine
  attachInterrupt(digitalPinToInterrupt(intPin1),buttonPressed1,RISING); 
  attachInterrupt(digitalPinToInterrupt(intPin2),buttonPressed2,RISING);
  //buttonPressed is a routine checking if the button is pressed when RISING(getting pressed), i must create the routine

  interrupts(); //Activating Interrupts


}

void loop() {
  
  lcd.setCursor(7,1);
  lcd.print(i);
  if(i<500) i++;
  else(i=0);

  digitalWrite(ledPin1,output1); //Turns LED ON 
  digitalWrite(ledPin2,output2); //Turns LED on 

}
//Routines open a led and close the other
void buttonPressed1(){
  output1 = HIGH;
  output2 = LOW;
}
void buttonPressed2(){
  output1 = LOW;
  output2 = HIGH;
}
//ISR->Interrupt Service Routine, TImeR1_OVF->When timer1 overflows
ISR(TIMER1_OVF_vect){  
  TCNT1 = value;
  digitalWrite(ledPin3,digitalRead(ledPin3)^1); //^1 means XOR with 1, reversing the value of ledPin3
}
