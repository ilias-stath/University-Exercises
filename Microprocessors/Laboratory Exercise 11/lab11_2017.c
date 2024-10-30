//Firstly i need to connect com1 and com2 with "virtual serial ports", open com 2 with cutecom and select com1 form "PICSimLab" from File->Configure->Serial Ports
//Using LCD and UART Libraries

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

char i=0;

void interrupt(){   //trexei otan patithei interrupt 0
     PORTC.F0 = 1;  //arm relay1
     INTCON = 0b11010000;
}

void interrupt_low(){
     if(INTCON3.INT2IF){
        PORTC.F0 = 0;  //disable relay1
        INTCON3 = 0b00011000;
     }else{
        PORTC.F2 = ~PORTC.F2;  //turn fan on
        INTCON3 = 0b00011000;
     }
}

void main(){

     unsigned int mem_loc;
     unsigned char mem_data, count;
     
     INTCON = 0b11010000;
     INTCON3 = 0b00011000;
     RCON = 0b10000000;
     
     TRISC = 0x00;

     UART1_init(9600);
     Lcd_Init();
     
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1,1,"STATHAKOS");
     
     UART_Write_text("2017");
     UART_Write(0x0A);  //New line
     UART_Write(0x0D);  //Cursor return to start on line
     
     UART1_Write_Text("FLASH MEM. DUMP");
     mem_loc = 0x0000;
     for(count=0;count<16*10;count++){
         mem_data = FLASH_Read(mem_loc);
         UART1_Write(mem_data);
         mem_loc++;
         delay_ms(50);
     }
     
     while(1){
              Lcd_chr(2,5, i);
              i++;
              if(i>0x7A) i=0x20;
     }

}