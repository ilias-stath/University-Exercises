#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs=13, en=12, d4=8, d5=9, d6=10, d7=11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4;
const byte COLS = 3;



char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char customKey;
int tempKey;
int num[2];
int num12;

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("2017 Stathakos");

}

void loop() {
  for(int i=0; i<2; i++){
    customKey = customKeypad.getKey();

    if(customKey){
      if(i==0){
        for(int j=0; j<9; j++){
          lcd.setCursor(j,1);
          lcd.write(0b00010000);
          if(j==1){
            j=4;
          }
        } 
      }
      tempKey = int(customKey);
      if(tempKey >= 48 && tempKey <= 57){
        lcd.setCursor(i,1);
        lcd.print(customKey);
        num[i] = tempKey;
      }else{
        i--;
      }
    }else{
      i--;
    }
  }
  
  lcd.setCursor(5,1);
  num12 = (num[0]-48)*10 + (num[1] - 48);
  num12 = num12*num12;

  lcd.print(num12);
}
