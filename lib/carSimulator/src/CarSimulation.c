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

	/* initialise MFD */
	SMFD_Init(&this->carMfd);

	/* initialise vars of indicators */
	GIND_SetData(&this->carMfd.directionBar.indicator,	GIND_TYPE_FLOAT32,&this->direction,	GIBR_BAR_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.pedalBar.indicator,		GIND_TYPE_FLOAT32,&this->pedal,		GIBR_BAR_INDICATOR_TYPE);
}

void SCAR_Start(SCAR_CarSimulation_t *this)
{
	this->isRunning=M_TRUE;
}
void SCAR_Execute(SCAR_CarSimulation_t *this)
{
	//printf("SCAR_Execute\n");//DEBUG

	if (this->isRunning)
	{
		this->direction=rand()*1.0/RAND_MAX*90.0f-45.0f;
		this->pedal=rand()*1.0/RAND_MAX*1.0f-0.0f;
	}

	SMFD_Execute(&this->carMfd);
}




/* local functions ------------------------------------------------------------*/
/* none */

/* end */
