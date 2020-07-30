/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef SCAR_CarSimulation_H
#define SCAR_CarSimulation_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <CarMfd.h>
/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SCAR_CarSimulation_t_
{
	bool_t isRunning;
	bool_t isShowing;

	/* for simulation */
	float32_t direction;

	SMFD_CarMfd_t carMfd;
}SCAR_CarSimulation_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SCAR_Init(SCAR_CarSimulation_t *this);
void SCAR_Execute(SCAR_CarSimulation_t *this);



/* end */
#endif /* SCAR_CarSimulation_H */

