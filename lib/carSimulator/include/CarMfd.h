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
#include <Sign.h>
#include <Bar.h>
#include <Gauge.h>
#include <Chart.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _SMFD_CarMfd_t_
{
	GMFD_Mfd_t mfd;

	GPAN_Panel_t actuatorsPanel;
	GIBR_Bar_t directionBar;
	GIBR_Bar_t pedalBar;
	GISG_Sign_t leftIndicatorLed;
	GISG_Sign_t rightIndicatorLed;//TODO change to instrument
	GLAB_Label_t cautionLabel;

	GPAN_Panel_t fuelPanel;
	GIGG_Gauge_t tank1;
	GIGG_Gauge_t tank2;
	GICH_Chart_t totalFuel;

}SMFD_CarMfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SMFD_Init(SMFD_CarMfd_t *this);
void SMFD_Execute(SMFD_CarMfd_t *this);


/* end */
#endif /* SMFD_CarMfd_H */

