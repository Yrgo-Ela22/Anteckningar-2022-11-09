
#ifndef LED_VECTOR_H_
#define LED_VECTOR_H_

/* Inkluderingsdirektiv: */
#include "misc.h"
#include "led.h"

struct led_vector
{
   struct led* data; /* Pekare till dynamiskt fält innehållande lysdioder. */
   size_t size;      /* Antalet lysdioder i fältet. */
};

/********************************************************************************
* led_vector_init: Initierar ny tom led-vektor. 
*
*                  - self: Pekare till vektorn som ska initieras.
********************************************************************************/
void led_vector_init(struct led_vector* self);

/********************************************************************************
* led_vector_clear: Tömmer angiven led-vektor.
*
*                   - self: Pekare till vektorn som ska tömmas.
********************************************************************************/
void led_vector_clear(struct led_vector* self);

/********************************************************************************
* led_vector_push: Lägger till en ny lysdiod längst bak i angiven vektor.
*                  Ifall tillägget lyckas returneras 0, annars felkod 1.
*
*                  - self   : Pekare till vektorn som lysdioden ska läggas i.
*                  - new_led: Pekare till den nya lysdiod som ska läggas till.
********************************************************************************/
int led_vector_push(struct led_vector* self,
                    struct led* new_led);

/********************************************************************************
* led_vector_on: Tänder samtliga lysdioder lagrade i angiven vektor.
*
*                - self: Pekare till vektorn vars lysdioder ska tändas.
********************************************************************************/
void led_vector_on(struct led_vector* self);

/********************************************************************************
* led_vector_off: Släcker samtliga lysdioder lagrade i angiven vektor.
*
*                 - self: Pekare till vektorn vars lysdioder ska släckas.
********************************************************************************/
void led_vector_off(struct led_vector* self);

/********************************************************************************
* led_vector_blink_collectively: Blinkar samtliga lysdioder lagrade i angiven
*                                vektor med angiven blinkhastighet.
*
*                                - self          : Pekare till vektorn.
*                                - blink_speed_ms: Blinkhastigheteh i ms.
********************************************************************************/
void led_vector_blink_collectively(struct led_vector* self,
                                   const uint16_t blink_speed_ms);

/********************************************************************************
* led_vector_blink_sequentially: Blinkar samtliga lysdioder lagrade i angiven
*                                vektor framåt i en sekvens en efter en med
*                                angiven blinkhastighet.
*
*                                - self          : Pekare till vektorn.
*                                - blink_speed_ms: Blinkhastigheteh i ms.
********************************************************************************/
void led_vector_blink_sequentially(struct led_vector* self,
                                   const uint16_t blink_speed_ms);

#endif /* LED_VECTOR_H_ */