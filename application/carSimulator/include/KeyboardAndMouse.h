/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef SKBM_KeyboardAndMouse_H
#define SKBM_KeyboardAndMouse_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <CarSimulation.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SKBM_KeyboardAndMouse_t_
{
	SCAR_CarSimulation_t *carSimulation;
}SKBM_KeyboardAndMouse_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SKBM_Init(SKBM_KeyboardAndMouse_t *this,SCAR_CarSimulation_t *carSimulation);
void SKBM_Execute();
void SKBM_Keyboard(int key, int x, int y);
void SKBM_MouseClick(int button, int state, int x, int y);


/* end */
#endif /* SKBM_KeyboardAndMouse_H */

