/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef SCRT_SimulationControl_H
#define SCRT_SimulationControl_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
#include <CarSimulation.h>
#include <KeyboardAndMouse.h>
#include <SimulationView.h>

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SCRT_SimulationControl_t_
{
	bool_t isRunning;
	bool_t isShowing;

	SCAR_CarSimulation_t 	car;
	SKBM_KeyboardAndMouse_t interaction;
	SVIW_SimulationView_t 	view;

}SCRT_SimulationControl_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SCRT_Init(SCRT_SimulationControl_t *this);
void SCRT_Execute(SCRT_SimulationControl_t *this);
void SCRT_Render(SCRT_SimulationControl_t *this);
void SCRT_Start(SCRT_SimulationControl_t *this,bool_t isShowing);
void SCRT_Stop(SCRT_SimulationControl_t *this);


/* end */
#endif /* SCRT_SimulationControl_H */

