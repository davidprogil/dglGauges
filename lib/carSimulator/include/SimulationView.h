/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef SVIW_SimulationView_H
#define SVIW_SimulationView_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Wrapper2D.h>
#include <CarSimulation.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SVIW_SimulationView_t_
{
	bool_t isEnabled;
	D2DW_Wrapper2D_t wrapper2D;
	SCAR_CarSimulation_t *carSimulation;
}SVIW_SimulationView_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SVIW_Init(SVIW_SimulationView_t *this,SCAR_CarSimulation_t *carSimulation,void *keyboardFunction);
void SVIW_Execute();
void SVIW_Enable(bool_t isEnabled);
void SVIW_Start();

/* end */
#endif /* SVIW_SimulationView_H */

