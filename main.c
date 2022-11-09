/********************************************************************************
* main.c: Demonstration av dynamisk vektor för lagring och styrning av
*         multipla lysdioder
********************************************************************************/
#include "led.h"
#include "button.h"
#include "led_vector.h"

/********************************************************************************
* main: Ansluter tre lysdioder till pin 8 - 10 och lagrar i en dynamisk vektor.
*       En tryckknapp ansluts till pin 13. Koden är ännu ej komplett, men vid 
*       nedtryckning av tryckknappen ska lysdioderna blinka i en slinga var 
*       100:e millisekund, annars ska de blinka kollektivt var 500:e millisekund.
********************************************************************************/
int main(void)
{
   struct led l1, l2, l3;
   struct button b1;
   struct led_vector v1;

   led_init(&l1, 8);
   led_init(&l2, 9);
   led_init(&l3, 10);

   button_init(&b1, 13);
   led_vector_init(&v1);

   led_vector_push(&v1, &l1); 
   led_vector_push(&v1, &l2);
   led_vector_push(&v1, &l3);

   while (1)
   {
      if (button_is_pressed(&b1))
      {
         led_vector_blink_sequentially(&v1, 100);
      }
      else
      {
         led_vector_blink_collectively(&v1, 500);
      }
   }

   return 0;
}

