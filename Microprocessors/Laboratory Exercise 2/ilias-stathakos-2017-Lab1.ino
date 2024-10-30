void setup() {
  // put your setup code here, to run once:
  //DDRD = 0xFF; //
  DDRD = 0b11111111; //(hex , binary)
  //DDRB = 0b00001111 epeidi omws den jr ti thelw na kanw me ta prwta 4 tote kanw to parakatw
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  PORTD = 0b11011010;
  digitalWrite(9,1);
  delay(10);
  digitalWrite(9,0);
  
  PORTD = 0b11111100;
  digitalWrite(10,1); 
  delay(10);
  digitalWrite(10,0);

  PORTD = 0b01100000;
  digitalWrite(11,1); 
  delay(10);
  digitalWrite(11,0);

  PORTD = 0b11100000;
  digitalWrite(12,1); 
  delay(10);
  digitalWrite(12,0);  
  
}
