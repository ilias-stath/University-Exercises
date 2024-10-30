//Firstly i need to connect com1 and com2 with "virtual serial ports", open com 2 with cutecom and select com1 form "PICSimLab" from File->Configure->Serial Ports
//Using LCD and UART Libraries
unsigned short kp,cnt;
char txt[6];

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
char txt2[] = "AEM:";

char  read_keypad()
{
   char var, key;
   char TEMPPORTB, TEMPPORTD, TEMPTRISB, TEMPTRISD;

   TEMPPORTB = PORTB;
   TEMPPORTD = PORTD;
   TEMPTRISB = TRISB;
   TEMPTRISD = TRISD;



   PORTB = 0xFF;      //Set all pins to 1;
   TRISB = 0xFF;      //configure PORTB as input;

   TRISD = 0x00;     //configure PORT D as outpout
   PORTD = 0xFF;     //set all pins of PORT D to 1;

   key =0;
   do {
           // scan first row
           PORTD.F0 = 0;
           delay_ms(10);
           var = PORTB;

           if (var.F0 == 0)      key = '<';
           else if (var.F1 == 0) key = '0';
           else if (var.F2 == 0) key = '>';
           PORTD.F0 =1;

           // scan second row
           PORTD.F1 = 0;
           delay_ms(10);
           var = PORTB;
           if (var.F0 == 0)      key = '7';
           else if (var.F1 == 0) key = '8';
           else if (var.F2 == 0) key = '9';
           PORTD.F1 =1;

           // scan third row
           PORTD.F2 =0;
           delay_ms(10);
           var = PORTB;
           if (var.F0 == 0)      key = '4';
           else if (var.F1 == 0) key = '5';
           else if (var.F2 == 0) key = '6';
           PORTD.F2 =1;

           // scan forth row
           PORTD.F3 =0;
           delay_ms(10);
           var = PORTB;
           if (var.F0 == 0)      key = '1';
           else if (var.F1 == 0) key = '2';
           else if (var.F2 == 0) key = '3';
           PORTD.F3 =1;
   }while (key == 0);

   PORTB = TEMPPORTB;
   PORTD = TEMPPORTD;
   TRISB = TEMPTRISB;
   TRISD = TEMPTRISD;



   return key;

}

void main(){

    char serial_input;
    UART1_init(9600);

    delay_ms(1000);
    Lcd_Init();                        // Initialize LCD

    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    Lcd_Out(1,1,txt1);
    Lcd_Out(2,1,txt2);                 // Write text in second row

    UART_Write_text("Ilias Stathakos");
    UART_Write(0x0A);  //New line
    UART_Write(0x0D);  //Cursor return to start on line

    UART_Write_text("Enter your AEM at the Keypad");
    UART_Write(0x0A);  //New line
    UART_Write(0x0D);

    cnt = 0;
     
    //Read 4 keys from the keypad
    kp=read_keypad();
    delay_ms(200);
    Lcd_Chr(2,8+cnt,kp);
    UART1_Write(kp);
    txt[cnt]=kp;
    cnt++;
    
    kp=read_keypad();
    delay_ms(200);
    Lcd_Chr(2,8+cnt,kp);
    UART1_Write(kp);
    txt[cnt]=kp;
    cnt++;
    
    kp=read_keypad();
    delay_ms(200);
    Lcd_Chr(2,8+cnt,kp);
    UART1_Write(kp);
    txt[cnt]=kp;
    cnt++;
    
    kp=read_keypad();
    delay_ms(200);
    Lcd_Chr(2,8+cnt,kp);
    UART1_Write(kp);
    txt[cnt]=kp;
    cnt++;

    while(UART1_Data_Ready() != 0){
       UART1_Read();
    }

    UART1_Write(0x0A);
    UART1_Write(0x0D);
    UART1_Write_Text("Enter a character:");
    UART1_Write(0x0A);
    UART1_Write(0x0D);
    
    while(UART1_Data_Ready()==0){} // Wait for data to be ready
    serial_input = UART1_Read();
    LCD_Chr(1,14,serial_input);
    
    delay_ms(1000);

}