#define  SEND_CMD(A)   PORTE.F2=0; PORTE.F1=1; PORTD = A;  PORTE.F1=0;
#define  SEND_DATA(A)  PORTE.F2=1; PORTE.F1=1; PORTD = A;  PORTE.F1=0;


// LCD module connections
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections

char txt1[] = "STATHAKOS";
char txt2[] = "ILIAS";



void main(){

    TRISE.F1 =0;
    TRISE.F2 =0;
    TRISD=0x00;

    //Manual control of LCD Display without libraries
    PORTE.F1 = 0;             //SET ENABLE  TO  0
    delay_ms(100);

    //Set display mode
    PORTE.F2 = 0;               //RS ->0
    PORTE.F1 = 1;                //EN->1
    PORTD = 0b00110000;   //set 8 bit  mode  2 lines 5x8 ROM
    PORTE.F1=0;                  //EN->0
    delay_ms(100);

    //Set display mode   again
    SEND_CMD(0b00110000);
    delay_ms(100);

    //Turn display ON
    SEND_CMD(0b00001100);
    delay_ms(100);

    //Set cursor moving direction,  using the defined MACRO
    SEND_CMD(0b00001100);
    delay_ms(100);

    //Clear LCD screen, using the defined MACRO
    SEND_CMD(0b00000001);

    delay_ms(100);

    //DEFINE SCREEN POSITION
    //Set DDRAM to the value corresponding to position on panel
    SEND_CMD(0xC7);

    //Specify the character to display be giving the ASCII value of the character.
    SEND_DATA(0X4B)   // Set DB7-DB0-> 01001011  which is the CGROM address where K is stored
                      // SEND_DATA('K');      Can specify ASCII value of character (ASCIII of K is 4B).
    delay_ms(1000);

    //Specify the character to display be giving the ASCII value of the character.
    //SEND_DATA(0X4D)   // Set DB7-DB0-> 01001101  which is the CGROM address where M is stored
    SEND_DATA('M');      //Can specify ASCII value of character (ASCIII of K is 4B).

    SEND_CMD(0b10000110);
    
    delay_ms(1000);
    
    SEND_DATA('2');
    
    delay_ms(1000);
    
    SEND_DATA('0');
    
    delay_ms(1000);
    
    SEND_DATA('1');
    
    delay_ms(1000);
    
    SEND_DATA('7');
    

    delay_ms(3000);



  delay_ms(3000);



  Lcd_Init();                        // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,1,txt1);

  Lcd_Out(2,1,txt2);                 // Write text in second row


}