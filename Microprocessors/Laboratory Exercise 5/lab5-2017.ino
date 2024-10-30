// Include the library code:
// Tools -> Manage Libraries -> filter "keypad by mark stanley"
#include <LiquidCrystal.h>
#include <Keypad.h>

// Initialize the library by associating any needed pin
// with the arduino pin number it is connected to based on the pins we put in spare parts
const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //LiquidCrystal lcd is a class for the lcd display


// For keypad
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; // Naming the keypad buttons to be specific characters  

byte rowPins[ROWS] = {7, 6, 5, 4}; // Pins for the rows based on the pins we put in spare parts
byte colPins[COLS] = {3, 2, 1, 0}; // Pins for the columns based on the pins we put in spare parts

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); // Creating a class instance for the keypad
// 8 lines 
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
  };


void setup() {

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2); // Dimensions 16x2

  // Save character in lcd memory at place 0
  lcd.createChar(0,heart);

  // Move the cursor to a specific place
  lcd.setCursor(0,0);
  // Print a message to te LCD
  lcd.print("Ilias Stathakos"); // Used for printng a string

  lcd.setCursor(6,1);
  // Print a message to te LCD
  lcd.print("2017"); // Used for printng a string

  lcd.setCursor(15,1);

  lcd.write(0b10110101); // Write prints only one character, 0b10110101 Chinese character (mirrored attika bank logo)

  lcd.setCursor(0,1);
  lcd.write(0b00010000);

  
}

void loop() {
  char customkey = customKeypad.getKey(); // Get pressed key from the keypad

  if(customkey){
    // Set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0)
    lcd.setCursor(4,1);
    //print the character pressed on key pad
    lcd.print(customkey);
  }

}
