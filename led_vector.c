/********************************************************************************
* led_vector.c: Inneh�ller definitioner av associerade funktioner f�r strukten
*               led_vector, som anv�nds f�r implementering av dynamiska vektorer 
*               som m�jligg�r lagring och styrning av multipla lysdioder.
********************************************************************************/
#include "led_vector.h"

/********************************************************************************
* led_vector_init: Initierar ny tom led-vektor.
*
*                  - self: Pekare till vektorn som ska initieras.
********************************************************************************/
void led_vector_init(struct led_vector* self)
{
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* led_vector_clear: T�mmer angiven led-vektor.
*
*                   - self: Pekare till vektorn som ska t�mmas.
********************************************************************************/
void led_vector_clear(struct led_vector* self)
{
   free(self->data);
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* led_vector_push: L�gger till en ny lysdiod l�ngst bak i angiven vektor.
*                  Ifall till�gget lyckas returneras 0, annars felkod 1.
*
*                  - self   : Pekare till vektorn som lysdioden ska l�ggas i.
*                  - new_led: Pekare till den nya lysdiod som ska l�ggas till.
********************************************************************************/
int led_vector_push(struct led_vector* self,
                    struct led* new_led)
{
   struct led* copy = (struct led*)realloc(self->data, sizeof(struct led) * (self->size + 1));
   if (!copy) return 1; 
   copy[self->size++] = *new_led; 
   self->data = copy; 
   return 0;
}

/********************************************************************************
* led_vector_on: T�nder samtliga lysdioder lagrade i angiven vektor.
*
*                - self: Pekare till vektorn vars lysdioder ska t�ndas.
********************************************************************************/
void led_vector_on(struct led_vector* self)
{
   for (size_t i = 0; i < self->size; ++i)
   {
      led_on(&self->data[i]);
   }
   return;
}

/********************************************************************************
* led_vector_off: Sl�cker samtliga lysdioder lagrade i angiven vektor.
*
*                 - self: Pekare till vektorn vars lysdioder ska sl�ckas.
********************************************************************************/
void led_vector_off(struct led_vector* self)
{
   /* Implementeras n�sta lektion. */
}

/********************************************************************************
* led_vector_blink_collectively: Blinkar samtliga lysdioder lagrade i angiven
*                                vektor med angiven blinkhastighet.
*
*                                - self          : Pekare till vektorn.
*                                - blink_speed_ms: Blinkhastigheteh i ms.
********************************************************************************/
void led_vector_blink_collectively(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
   /* Implementeras n�sta lektion. */
}

/********************************************************************************
* led_vector_blink_sequentially: Blinkar samtliga lysdioder lagrade i angiven
*                                vektor fram�t i en sekvens en efter en med
*                                angiven blinkhastighet.
*
*                                - self          : Pekare till vektorn.
*                                - blink_speed_ms: Blinkhastigheteh i ms.
********************************************************************************/
void led_vector_blink_sequentially(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
   /* Implementeras n�sta lektion. */
}