/********************************************************************************
* led_vector.c: Innehåller definitioner av associerade funktioner för strukten
*               led_vector, som används för implementering av dynamiska vektorer 
*               som möjliggör lagring och styrning av multipla lysdioder.
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
* led_vector_clear: Tömmer angiven led-vektor.
*
*                   - self: Pekare till vektorn som ska tömmas.
********************************************************************************/
void led_vector_clear(struct led_vector* self)
{
   free(self->data);
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* led_vector_push: Lägger till en ny lysdiod längst bak i angiven vektor.
*                  Ifall tillägget lyckas returneras 0, annars felkod 1.
*
*                  - self   : Pekare till vektorn som lysdioden ska läggas i.
*                  - new_led: Pekare till den nya lysdiod som ska läggas till.
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
* led_vector_on: Tänder samtliga lysdioder lagrade i angiven vektor.
*
*                - self: Pekare till vektorn vars lysdioder ska tändas.
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
* led_vector_off: Släcker samtliga lysdioder lagrade i angiven vektor.
*
*                 - self: Pekare till vektorn vars lysdioder ska släckas.
********************************************************************************/
void led_vector_off(struct led_vector* self)
{
   /* Implementeras nästa lektion. */
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
   /* Implementeras nästa lektion. */
}

/********************************************************************************
* led_vector_blink_sequentially: Blinkar samtliga lysdioder lagrade i angiven
*                                vektor framåt i en sekvens en efter en med
*                                angiven blinkhastighet.
*
*                                - self          : Pekare till vektorn.
*                                - blink_speed_ms: Blinkhastigheteh i ms.
********************************************************************************/
void led_vector_blink_sequentially(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
   /* Implementeras nästa lektion. */
}