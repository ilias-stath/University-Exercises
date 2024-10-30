#include <Wire.h>   // -> I2C library in arduino

#define EEPROM_ID 0xA0 >> 1  // Shifting the addresses 1 bit right and from 8bit we make it 7bit
#define DS1621_ID 0x90 >> 1
#define DS1307_ID 0xD0 >> 1

void setup() {
  int i;

  Serial.begin(9600); // Starts serial connection
  Wire.begin(); // Starts I2C, "join I2C bus(address optional for master)"

  // Starting condition to see if everthing works well
  Wire.beginTransmission(EEPROM_ID);   // Transmit to device 24c04
  Wire.write(0);  // Write to the mem address 0
  for(i=0; i<30; i++){
    Wire.write(0xAA);
  }
  Wire.endTransmission(); // Stops the transmittion

  // Setup temperature sensor
  Wire.beginTransmission(DS1621_ID);  // Connect to thermometer
  Wire.write(0xAC);  // Access Config, like set-up for some registers
  Wire.write(0x02);  // set continuous conversion (continuously keep track of temp)
  Wire.beginTransmission(DS1621_ID);  // Restart Wire.write(0xEE); in order to read it 
  Wire.endTransmission();

}

void loop() {
  Serial.print("Starting main loop\n");

  Serial.print("Writing data to EEPROM\n");
  Wire.beginTransmission(EEPROM_ID); // transmit to device #A0>>1
  Wire.write(16);  // Specifie the starting memory byte to write
  Wire.write('I');
  Wire.write('L');
  Wire.write('I');
  Wire.write('A');
  Wire.write('S');  // Sends one byte at a time
  Wire.endTransmission(); // Stop trasmitting

  int8_t firstByte;
  int8_t secondByte;
  float temp;
  int8_t seconds,minutes,hour,day,date,month,year;
  int8_t x;

  delay(1000);

  Wire.beginTransmission(DS1621_ID);
  Wire.write(0xAA);   // Read temperature command
  Wire.endTransmission();
  Wire.requestFrom(DS1621_ID,2);  // Request 2 bytes from DS1621 (0.5 degrees)

  firstByte = Wire.read();  // Get first byte (temp integer)
  secondByte = Wire.read();  // Get second byte (decimal number of temperature 0.5)


  temp = firstByte;

  if(secondByte)  // If there is a 0.5 deg difference
    temp += 0.5;

  Serial.println(temp);  // println 
  delay(1000);

  Serial.print("\nReading time from RTC ds1307 at address D0..\n");

  Wire.beginTransmission(DS1307_ID);  // Transmit to device #D0>>1
  Wire.write(0); // Specifies starting memory byte
  Wire.endTransmission();

  x = Wire.requestFrom(DS1307_ID,7); // Transmit from device #DO>>1
  if(x!= 7) Serial.print("Error reading from RTC\n");

  seconds = Wire.read();  // Reads one byte
  minutes = Wire.read();
  hour = Wire.read();
  day = Wire.read();
  date = Wire.read();
  month = Wire.read();
  year = Wire.read();
  Wire.endTransmission();  // Stop transmitting

  Serial.write(seconds);
  Serial.write(minutes);
  Serial.write(hour);
  Serial.write(day);
  Serial.write(date);
  Serial.write(month);
  Serial.write(year);

  delay(1000);

  Serial.write("\n");

  Serial.write(((seconds & 0x7F)>>4) + 0x30);
  Serial.write((seconds & 0x0F) + 0x30);
  Serial.write(" Seconds\n");

  Serial.write(((minutes & 0x7F)>>4) + 0x30);
  Serial.write((minutes & 0x0F) + 0x30);
  Serial.write(" Minutes\n");

  delay(1000);
  exit(0);
}
