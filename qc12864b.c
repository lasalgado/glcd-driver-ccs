/* ACCESS MODE FOR PARALLEL INTERFACE RS & RW 
               RS RW
   WRITE_INST  0  0
   READ_BF_AC  0  1
   WRITE_DATA  1  0
   READ_DATA   1  1
*/

#define WRITE_INST 0x00    //write instruction to instruction register (IR)
#define READ_BF_AC 0x01    //read busy flag (BF) and address counter (AC)
#define WRITE_DATA 0x02    //write data to data register (DR)
#define READ_DATA  0x03    //read data to data register (DR)

/* CONTROL FLAGS */

int1 IS_VALID = 0;      //flag used to indicate there's been a valid initialization
int1 IS_FLAG_SET = 0;   //check if flags have been set
int1 IS_GRAPHIC_MODE = 0;  //check if it os working with the graphic mode
int8 FLAG_RS;  //register select  LOW instrucciones
int8 FLAG_RW;  //read and write
int8 FLAG_E;   //enabled
int8 FLAG_RST; //reset

/* LIMITS FOR THE GLCD */
int8 TEXT_MAX_CHARS = 32;

/* DATA BUS FOR GLCD FROM DB0 to DB7 */

int8 PIN_DB0 = 0;
int8 PIN_DB1 = 0;
int8 PIN_DB2 = 0;
int8 PIN_DB3 = 0;
int8 PIN_DB4 = 0;
int8 PIN_DB5 = 0;
int8 PIN_DB6 = 0;
int8 PIN_DB7 = 0;

/* FUNCTIONS DECLARATIONS */

int8 ReadData(int8 modo, int8 direccion);
void SetCTextAt_GLCD(int8 x, int8 y,char character);
void GetCText_GLCD(int8 x, int8 y);
void TextGotoxy_GLCD(int8 x, int8 y);
void SendWord_GLCD(int8 modo,int8 instruccion);
void Set_GLCD_Flags(int8 rs,int8 rw,int8 e,int8 rst,int8 db0,int8 db1,int8 db2,int8 db3,int8 db4,int8 db5,int8 db6,int8 db7);
int1 Init_GLCD();


/* FUNCTIONS */

void Set_GLCD_Flags(int8 rs,int8 rw,int8 e,int8 rst,int8 db0,int8 db1,int8 db2,int8 db3,int8 db4,int8 db5,int8 db6,int8 db7) {
   FLAG_RS    = rs;
   FLAG_RW    = rw;
   FLAG_E     = e;
   FLAG_RST   = rst;
   
   PIN_DB0  = db0;
   PIN_DB1  = db1;
   PIN_DB2  = db2;
   PIN_DB3  = db3;
   PIN_DB4  = db4;
   PIN_DB5  = db5;
   PIN_DB6  = db6;
   PIN_DB7  = db7;
   IS_FLAG_SET = 1;
}

int1 Init_GLCD(){

   output_low(FLAG_RST);   //deja en 0 el reset
   if(IS_FLAG_SET) {
      output_low(PIN_B0);
      delay_ms(50);                    //espera > 40ms despues de energizada la pantalla
      SendWord_GLCD(WRITE_INST,0x30);  //FUNCTION SET   0b0011 0000
      delay_us(110);                   //espera > 100us
      SendWord_GLCD(WRITE_INST,0x30);  //FUNCTION SET
      delay_us(40);                    //espera > 37us
      SendWord_GLCD(WRITE_INST,0x0C);  //DISPLAY ON/OFF CONTROL 0b0000 1111
      delay_us(110);                   //espera > 100us
      SendWord_GLCD(WRITE_INST,0x01);  //DISPLAY CLEAR
      delay_ms(20);                    //espera > 10ms
      SendWord_GLCD(WRITE_INST,0x06);  //ENTRY MODE SET    0b0000 0110
      delay_ms(100);                   //espera > 10ms
      IS_VALID = 1;
      output_high(PIN_B0);
   }
   
   return IS_VALID;
}

void SendWord_GLCD(int8 modo,int8 instruccion) {
   if(IS_FLAG_SET){
      output_bit(FLAG_RW, (modo & 1));
      output_bit(FLAG_RS, (modo & 2) >> 1);
      output_bit(PIN_DB0, (instruccion & 1));
      output_bit(PIN_DB1, (instruccion & 2) >> 1);
      output_bit(PIN_DB2, (instruccion & 4) >> 2);
      output_bit(PIN_DB3, (instruccion & 8) >> 3);
      output_bit(PIN_DB4, (instruccion & 16) >> 4);
      output_bit(PIN_DB5, (instruccion & 32) >> 5);
      output_bit(PIN_DB6, (instruccion & 64) >> 6);
      output_bit(PIN_DB7, (instruccion & 128) >> 7);
     
      output_high(FLAG_E);
      delay_ms(1);
      output_low(FLAG_E);
   }
}

/**
*  Get the char set at the given x and y position.
*  Index y starts at 0 and limits to 15 
*  Index x starts at 0 and limits to 3
**/
char GetCText_GLCD(int8 x, int8 y){
   char ret = 0x20;
   
   if(IS_GRAPHIC_MODE == 0){
      
   }
   
   return ret;
}


void TextGotoxy_GLCD(int8 x, int8 y){
   if(IS_GRAPHIC_MODE == 0) {
      
   }   
}

void SetCTextAt_GLCD(int8 x, int8 y,char character){

}

int8 ReadData(int8 modo, int8 direccion) {
   if(IS_FLAG_SET){
      output_bit(FLAG_RW, (modo & 1));
      output_bit(FLAG_RS, (modo & 2) >> 1);
      
      if(modo == READ_DATA){
         output_bit(PIN_DB0, (direccion & 1));
         output_bit(PIN_DB1, (direccion & 2) >> 1);
         output_bit(PIN_DB2, (direccion & 4) >> 2);
         output_bit(PIN_DB3, (direccion & 8) >> 3);
         output_bit(PIN_DB4, (direccion & 16) >> 4);
         output_bit(PIN_DB5, (direccion & 32) >> 5);
         output_bit(PIN_DB6, (direccion & 64) >> 6);
         output_bit(PIN_DB7, (direccion & 128) >> 7);
         
      output_high(FLAG_E);
      delay_ms(1);
      output_low(FLAG_E);
      }
   }
}
