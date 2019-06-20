#include <18F4620.h>
#fuses HS,NOWDT,NOMCLR
#use delay(clock=16 MHZ)

//Aqui deben ir las interfaces tales como la rs-232, I^2C
/*
#define _DEBUG_SERIAL_

#ifdef _DEBUG_SERIAL_
   #define TX_232    PIN_C6
   #define RX_232    PIN_C7
   #use RS232(BAUD=9600,XMIT=TX_232,BITS=8,PARITY=N,STOP=1,UART1,RCV=RX_232)
   #use fast_io(c)
#endif
*/

//Aqui deben ir la IsR's interrupciones
   //int_rda
   //int_timer0

//variables globales

//aqui el void main(void)
void main(void)
{
   set_tris_a(0x3F);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   
  int ContadorAnilloPortB=0x01;
  int ContadorAnilloPortC=0x80;
  int ContadorAnilloPortD=0x03;
  
  int Opcion=input_a();
 
   while(1)
   {
     
     
      if((Opcion&0x04)==0x04||(Opcion&0x01)==0x01)
      {
         ContadorAnilloPortB=ContadorAnilloPortB<<1;
         if(ContadorAnilloPortB==0x80)
         {
            ContadorAnilloPortB=0x01;
         }
         output_b(ContadorAnilloPortB);   
      }
      
      ContadorAnilloPortC=ContadorAnilloPortC>>1;
      
      if(ContadorAnilloPortC==0x00)
      {
         ContadorAnilloPortC=0X80;
      }
      output_c(ContadorAnilloPortC);
      delay_ms(100);
   
      ContadorAnilloPortD=ContadorAnilloPortD<<2;
      if(ContadorAnilloPortD==0xC0)
      {
         ContadorAnilloPortD=0x03;
      }
      output_d(ContadorAnilloPortD);
   }
}
