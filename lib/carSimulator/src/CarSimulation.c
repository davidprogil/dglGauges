/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <CarSimulation.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
void SCAR_Init(SCAR_CarSimulation_t *this)
{
	printf("SCAR_Init\n");

	this->isRunning=M_FALSE;
	this->isShowing=M_FALSE;

	this->direction=0.0f;

	SMFD_Init(&this->carMfd);
}

void SCAR_Execute(SCAR_CarSimulation_t *this)
{
	printf("SCAR_Execute\n");

	if (this->isRunning)
	{
		this->direction=rand()*90.0f-45.0f;
	}
}




/* local functions ------------------------------------------------------------*/
/* none */

/* end */
