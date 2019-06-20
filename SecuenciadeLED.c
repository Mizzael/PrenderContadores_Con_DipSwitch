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
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   
  int ContadorAnilloLSB=0x01;
  int ContadorAnilloMSB=0x80;
 
   while(1)
   {
      ContadorAnilloLSB=ContadorAnilloLSB>1;
      if(ContadorAnilloLSB==0x80)
      {
         ContadorAnilloLSB=0x01;
      }
      
      
      ContadorAnilloMSB=ContadorAnilloMSB>>1;
      
      if(ContadorAnilloMSB==0x00)
      {
         ContadorAnilloMSB=0X80;
      }
      output_c(ContadorAnilloMSB);
      delay_ms(100);
      
      
      //Aqui usamos mascaras
      /*if((ContadorAnilloLSB&0x20)==0x20)
      {
         output_c(ContadorAnilloLSB);
      }
      if((ContadorAnilloLSB&0x20)!=0x20)
      {
         output_c(0);
      }*/
   }
}
