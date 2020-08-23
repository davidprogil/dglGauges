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
#define SCAR_MFD_NO (2)

/* types------------------------------------------------------------------------*/
typedef struct _SCAR_CarSimulation_t_
{
	bool_t isRunning;
	bool_t isShowing;

	/* for simulation */
	float32_t direction;
	float32_t pedal;
	uint8_t  left;
	uint8_t  right;

	float32_t tank1;
	float32_t tank2;
	float32_t directionSign;
	float32_t pedalSign;
	float32_t totalFuel;
	float32_t fuelSign;

	SMFD_CarMfd_t carMfd[SCAR_MFD_NO];

	/* for PSU */
	float32_t swVolt[2];
	float32_t swCurr[2];
	float32_t swOvp[2];
	float32_t swOcp[2];
	float32_t hwVolt[2];
	float32_t hwCurr[2];
	float32_t hwOvp[2];
	float32_t hwOcp[2];

}SCAR_CarSimulation_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SCAR_Init(SCAR_CarSimulation_t *this);
void SCAR_Execute(SCAR_CarSimulation_t *this);
void SCAR_Start(SCAR_CarSimulation_t *this);
void SCAR_SetLeftIndicator(void *thisVoid);
void SCAR_SetRightIndicator(void *thisVoid);


/* end */
#endif /* SCAR_CarSimulation_H */

