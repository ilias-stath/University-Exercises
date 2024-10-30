char  read_keypad()
{
   char var, key;
   char TEMPPORTB, TEMPPORTD, TEMPTRISB, TEMPTRISD;

   TEMPPORTB = PORTB;
   TEMPPORTD = PORTD;
   TEMPTRISB = TRISB;
   TEMPTRISD = TRISD;



   PORTB = 0xFF;      //Set all pins to 1;
   TRISB = 0xFF;      //Configure PORTB as input;

   TRISD = 0x00;     //Configure PORT D as outpout;
   PORTD = 0xFF;     //Set all pins of PORT D to 1;

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


void main() {
     char hex_digit[16] = {0x3F, 0x06, 0x5B, 0x4F,
                      0x66, 0x6D, 0x7D, 0x07,
                      0x7F, 0x6F, 0x77, 0x7C,
                      0x39, 0x5E, 0x0f, 0x71} ;

     char keypressed;


     //Read a key from the keypad
     keypressed = read_keypad();


     //Display keypressed on DISP1
     TRISD = 0x00;
     TRISA.F2 =0;
     PORTA.F2 = 1;

     PORTD = hex_digit[keypressed-0x30];
     delay_ms(1000);


}