// Include the libraries
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Wire.h>

// Initialize the LCD library by associating any needed pin
// with the arduino pin number it is connected to based on the pins we put in spare parts
const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //LiquidCrystal lcd is a class for the lcd display


// Initialize the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Naming the keypad buttons to be specific characters 
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 


byte rowPins[ROWS] = {A0,A1,A2,A3}; // Pins for the rows based on the pins we put in spare parts
byte colPins[COLS] = {7,6,5,4}; // Pins for the columns based on the pins we put in spare parts

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); // Creating a class instance for the keypad


// Initialize the EEPROM
#define EEPROM_ID 0xA0 >> 1 // Shifting the address 1 bit right so from an 8bit we make it a 7bit, it is needed for the I2C library(Wire)

// Variables for the main body
unsigned int desired_vol=0, lByte, hByte, vol=0, temp;
int floater_val, choice=0;

void setup() {

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2); // Dimensions 16x2

  // Start serial connection
  Serial.begin(9600); 
  // Starts I2C
  Wire.begin(); 
  
}

void loop() {

  // The delay is added because when th loop reaches the end, sometimes it doesn't take into consideration the 
  // delay there, so it clears the lcd before you can read the last message(TEMP 26 \n CYCLE COMPLETE)
  delay(2000);
  lcd.clear();

  // Setting the variable at zero after each iteration of the loop
  desired_vol = 0;
  // Move the cursor to the first row first column of the LCD
  lcd.setCursor(0,0);
  // Print the surname and AM to the LCD
  lcd.print("STATHAKOS,  2017"); 
  // Move the cursor to the second row first column of the LCD
  lcd.setCursor(0,1);
  // Print the volume message
  lcd.print("ENTER VOL:????");
  
  // Transmit to deice 24c04 EEPROM
  Wire.beginTransmission(EEPROM_ID); 
  // Write to mem at address 0x10
  Wire.write(0x10); 

  
  // Loop for getting the numbers from the keypad and at the same time saving them at EEPROM, in order to have a better code efficiency
  for(int i=0; i<4; i++){
    // Get pressed key from the keypad
    char customkey = customKeypad.getKey(); 
    
    if(customkey){
      // Set the cursor to column 10+i, line 1
      lcd.setCursor(10+i,1);

      // Save the numbers to EEPROM
      Wire.write(int(customkey));

      // Print the character pressed on key pad
      lcd.print(customkey);
    }else{
      i--;
    }
  }

  // End the transmission
  Wire.endTransmission(); 

  delay(1000);

  // clear the lcd display
  lcd.clear(); 

  // Move the cursor to the first row first column of the LCD and print the message
  lcd.setCursor(0,0);
  lcd.print("SAVING VOLUME");

  // Move the cursor to the second row first column of the LCD and print the message
  lcd.setCursor(0,1);
  lcd.print("TO EEPROM");

  delay(2000);

  // Request from the EEPROM the 4 bytes, each byte is a number for the volume
  Wire.beginTransmission(EEPROM_ID);
  Wire.write(0x10);
  Wire.endTransmission(EEPROM_ID);
  Wire.requestFrom(EEPROM_ID,4);

  // Clear the LCD and set cursor at first row first column
  lcd.clear();
  lcd.setCursor(0,0);

  // Reading the bytes and multiplying each one with their corresponding multiplication of the unit in order to create the 4 digit number.
  // We first get the byte at place 0x10,wich has the biggest multiplication of the unit, and last the byte at place 0x13, wich has the lowest multiplication of the unit.
  // The previous assumption is based on the way that I stored the numbers

  // For Byte number 4 (biggest byte)
  vol = Wire.read() - 48;
  vol = vol*1000;
  desired_vol += vol;

  // For Byte number 3 (2nd biggest byte)
  vol = Wire.read() - 48;
  vol = vol*100;
  desired_vol += vol; 

  // For Byte number 2 (2nd lowest byte)
  vol = Wire.read() - 48;
  vol = vol*10;
  desired_vol += vol; 

  // For Byte number 1 (lowest byte)
  vol = Wire.read() - 48;
  desired_vol += vol;  
  
  // Printing the message and number on first row
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("VOLUME");
  lcd.setCursor(10,0);
  lcd.print(desired_vol);

  delay(1000);

  // Printing the messages on first and second row accordingly
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OUTLET ON");
  lcd.setCursor(0,1);
  lcd.print("INLET OFF");

  delay(1000);

  // Closing the inlet valve
  Serial.write(0x00);
  Serial.write(0x00);

  // Opening the outlet valve
  Serial.write(0x01);
  Serial.write(0x01);

  // Checking the low-floater, as long as it remains 1(tank has water), the code will stay in the loop and
  // the outlent valve won't close.
  // The same logic(while or do while loop) is applied to all checks(volume and temperature)
  do{
    Serial.write(0x11);
    while(!Serial.available()){}
    floater_val = Serial.read();
  }while(floater_val == 1);

  // Closing the outlet valve after the low-floater is 0(tank is empty)
  Serial.write(0x01);
  Serial.write(0x00);


  // Printing the messages on first and second row accordingly
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OUTLET OFF");
  lcd.setCursor(0,1);
  lcd.print("INLET ON");

  // Opening the inlet valve
  Serial.write(0x00);
  Serial.write(0x01);

  // Ckecking the volume in order to close the inlet valve after the wanted volume is reached
  // We get the tank volume in 2 bytes that come in sequence with first the high byte, so in order to 
  // get the full volume, we must join the bytes and get a 2 byte number(16 bit number)
  do{
    Serial.write(0x30);
    while(!Serial.available()){}
    hByte = Serial.read();
    while(!Serial.available()){}
    lByte = Serial.read();
    // In order to join the bytes, we need to swift the bits of the first byte 8 places to the left, so they become the high byte og the 16bit number(2bytes)
    // and then use an "or" mask in order to put the low byte at the low byte of the 16bit number(2bytes)
    vol = (hByte << 8 ) | lByte;
  }while(vol < desired_vol);

  // Closing the intlet valve
  Serial.write(0x00);
  Serial.write(0x00);

  // Calculating current temp
  // In order to calculate the temperature, we need to do the same procedure as the procedure we did for the volume
  Serial.write(0x31);
  while(!Serial.available()){}
  hByte = Serial.read();
  while(!Serial.available()){}
  lByte = Serial.read();

  temp = (hByte << 8 ) | lByte;

  // Printing the messages on first and second row accordingly
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP");
  lcd.setCursor(12,0);
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("STIR/HEATER ON");

  delay("1000");

  // Starting stirrer
  Serial.write(0x04);
  Serial.write(0x01);

  // Cheking temp to start cooler or heater or do nothing(starting temp already at 26)
  if(temp < 26){
    Serial.write(0x02);
    Serial.write(0x01);
    choice = 1;
  }else if(temp > 26){
    Serial.write(0x03);
    Serial.write(0x01);
    choice = 2;
  }else{
    choice = 0;
  }

  // Ckecking the temp in order to then close the heater/cooler and stirrer after the wanted temp is reached
  while(temp != 26){
    Serial.write(0x31);
    while(!Serial.available()){}
    hByte = Serial.read();
    while(!Serial.available()){}
    lByte = Serial.read();
    temp = (hByte << 8 ) | lByte;
  }


  // Closing heater or cooler or nothing(if we didn't open anything at the start)
  if(choice == 1){
    Serial.write(0x02);
    Serial.write(0x00);
  }else if(choice == 2){
    Serial.write(0x03);
    Serial.write(0x00);
  }

  // Closing stirrer
  Serial.write(0x04);
  Serial.write(0x00);

  // Printing the messages on first and second row accordingly
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP");
  lcd.setCursor(12,0);
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("CYCLE COMPLETE");

  delay("2000");


}
