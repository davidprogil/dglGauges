/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef SMFD_CarMfd_H
#define SMFD_CarMfd_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Mfd.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SMFD_CarMfd_t_
{
	GMFD_Mfd_t mfd;
	GPAN_Panel_t actuatorsPanel;
	GCNV_Canvas_t directionBar;//TODO change to instrument
	GCNV_Canvas_t pedalBar;//TODO change to instrument
	GCNV_Canvas_t leftIndicatorLed;//TODO change to instrument
	GCNV_Canvas_t rightIndicatorLed;//TODO change to instrument
	GPAN_Panel_t fuelPanel;
	GPAN_Panel_t sensorsPanel;
	GPAN_Panel_t dashboardPanel;
}SMFD_CarMfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SMFD_Init(SMFD_CarMfd_t *this);
void SMFD_Execute(SMFD_CarMfd_t *this);


/* end */
#endif /* SMFD_CarMfd_H */

