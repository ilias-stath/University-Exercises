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
void main() {
   char floater_value;
   char highbyte, lowbyte;
   int tank_temp;
   char text[6];

   //Start serial communication wit serial Tank

   Lcd_init();
   UART1_init(9600);

   //Turn on OUTLET VALVE
   Lcd_Out(1,1,"TURN ON OUTLET");
   UART1_Write(0x01);  // 0x01 is the address of the outlet valve
   UART1_Write(0x01);  // With 1 we turn the outlet valve on

   delay_ms(2000);

   //Turn off OUTLET VALVE
   Lcd_out(1,1,"TURN OFF OUTLET");
   UART1_Write(0x01);  // 0x01 is the address of the outlet valve
   UART1_Write(0x00);  // With 0 we turn the outlet valve off
   
   delay_ms(2000);
   
   //Turn on INLET VALVE
   Lcd_Out(1,1,"TURN ON INLET");
   UART1_Write(0x00);  // 0x01 is the address of the inlet valve
   UART1_Write(0x01);  // With 1 we turn the outlet valve on

   delay_ms(2000);

   //Turn off INLET VALVE
   Lcd_out(1,1,"TURN OFF INLET");
   UART1_Write(0x00);  // 0x01 is the address of the inlet valve
   UART1_Write(0x00);  // With 0 we turn the outlet valve off

   // READ LOW FLOATER
   UART1_Write(0x11);         // Speficie floater address
   while(!UART1_Data_Ready()) {}   // wait for data to come
   floater_value = UART1_Read();

   if(floater_value == 0)
       Lcd_Out(1,1,"TANK IS EMPTY");
   else
       Lcd_Out(1,1,"TANK NOT EMPTY");

   //READ TANK TEMPERATURE
   UART1_Write(0x31);
   while(!UART1_Data_Ready()) {}
       highbyte = UART1_Read();
   while(!UART1_Data_Ready()) {}
       lowbyte = UART1_Read();

   tank_temp = highbyte;
   tank_temp = (tank_temp << 8) | lowbyte;   //swift 8bytes left the highbyte and add the lowbyte

   //Convert number to string
   WordToStr(tank_temp,text);
   Lcd_Out(2,1,"TEMP:");
   Lcd_Out(2,7,text);
}