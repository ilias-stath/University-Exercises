unsigned int steps;
unsigned int potSpeed;
unsigned int stepPot;
unsigned int servPot1;
unsigned int servPot2;
unsigned int Newservo1_position=0, Newservo2_position=0, servo1_position=0, servo2_position=0;

void turn_stepper(int direction, int speed){
     if(direction == 0){
          steps = 0;
          do{
             PORTB.F4 = 0;
             PORTB.F5 = 1;
             PORTB.F6 = 0;
             PORTB.F7 = 1;
             vdelay_ms(speed);
             
             PORTB.F4 = 1;
             PORTB.F5 = 0;
             PORTB.F6 = 0;
             PORTB.F7 = 1;
             vdelay_ms(speed);
             
             PORTB.F4 = 1;
             PORTB.F5 = 0;
             PORTB.F6 = 1;
             PORTB.F7 = 0;
             vdelay_ms(speed);
             
             PORTB.F4 = 0;
             PORTB.F5 = 1;
             PORTB.F6 = 1;
             PORTB.F7 = 0;
             vdelay_ms(speed);
             
             steps++;
          }while(steps < 50);
     }else{
           steps = 0;
           do{
              PORTB.F7 = 0;
              PORTB.F6 = 1;
              PORTB.F5 = 0;
              PORTB.F4 = 1;
              vdelay_ms(speed);
              
              PORTB.F7 = 1;
              PORTB.F6 = 0;
              PORTB.F5 = 0;
              PORTB.F4 = 1;
              vdelay_ms(speed);
              
              PORTB.F7 = 1;
              PORTB.F6 = 0;
              PORTB.F5 = 1;
              PORTB.F4 = 0;
              vdelay_ms(speed);
              
              PORTB.F7 = 0;
              PORTB.F6 = 1;
              PORTB.F5 = 1;
              PORTB.F4 = 0;
              vdelay_ms(speed);
              
              steps++;
           }while(steps < 50);
     }


}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
} // Apo arduino documentation

void main() {

     PORTD = 0x00;
     PORTC = 0xFF;
     
     ADC_init();

     TRISA = 0xFF;
     TRISD = 0xFF;
     TRISB = 0x00;
     TRISC = 0x00;


     PWM1_Init(500);
     PWM2_Init(500);
     PWM1_start();
     PWM2_start();

     while(1){
         stepPot  = ADC_read(0);
         potSpeed = map(stepPot,0, 1023, 1, 100);
         if(PORTD.F0 == 1){
             turn_stepper(0,potSpeed);
         }else if(PORTD.F1 == 1){
             turn_stepper(1,potSpeed);
         }

         // I put 0-255 because the servos relax at 90 degrees so with this they can
         //go from 90 to almost 270, which is 180 degrees of autonomy
         
         servPot1 = ADC_read(1);
         Newservo1_position = map(servPot1, 0, 1023, 0, 255);

         if(Newservo1_position != servo1_position){
            servo1_position = Newservo1_position;
            PWM1_Set_Duty(servo1_position);
         }


         servPot2 = ADC_read(2);
         Newservo2_position = map(servPot2, 0, 1023, 0, 255);

         if(Newservo2_position != servo2_position){
            servo2_position = Newservo2_position;
            PWM2_Set_Duty(servo2_position);
         }

         delay_ms(1000);
     }
    
}