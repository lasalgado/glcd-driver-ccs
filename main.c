#include<16F877A.h>

#fuses XT,NOWDT

#use delay(clock=4000000)
#use standard_io(B)
#use standard_io(D)

#include"qc12864b.c"

#define ACTIVAR_BUS_GLCD PIN_B5

void InicioPantalla();

void main() {

   port_b_pullups(TRUE);
   InicioPantalla();
  
   output_high(PIN_B0);
   while(TRUE){
      output_low(PIN_B0);
      delay_ms(250);
      output_high(PIN_B0);
      delay_ms(250);  
   }
}

void InicioPantalla(){
   output_D(0x00);                  //manda cero a los 8 pines para datos de la pantalla
   output_low(ACTIVAR_BUS_GLCD);    //habilitacion de bus de pantalla
   
   Set_GLCD_Flags(PIN_B1,PIN_B2,PIN_B4,PIN_B3,PIN_D0,PIN_D1,PIN_D2,PIN_D3,PIN_D4,PIN_D5,PIN_D6,PIN_D7);
   if(Init_GLCD()){
      SendWord_GLCD(WRITE_INST,0x80);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x01);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x02);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x42);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x43);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x44);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x45);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x46);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x47);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x48);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x49);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x4A);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x4B);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x4C);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x4D);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x4F);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x50);
      delay_us(75);
      
      
      SendWord_GLCD(WRITE_INST,0x90);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x30);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x31);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x32);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x33);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x34);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x35);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x36);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x37);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x38);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x39);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x3A);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x3B);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x3C);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x3D);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x3F);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x10);
      delay_us(75);
      
      
      SendWord_GLCD(WRITE_INST,0x94);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x36);
      delay_us(75);
      SendWord_GLCD(WRITE_DATA,0x36);
      delay_us(75);
   }
}
