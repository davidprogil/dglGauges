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

	/* car */
	GPAN_Panel_t carRootPanel;
	GPAN_Panel_t carActuatorsPanel;
	GIBR_Bar_t carDirectionBar;
	GIBR_Bar_t carPedalBar;
	GISG_Sign_t carLeftIndicatorLed;
	GISG_Sign_t carRightIndicatorLed;//TODO change to instrument
	GLAB_Label_t carCautionLabel;

	GPAN_Panel_t carFuelPanel;
	GIGG_Gauge_t carTank1;
	GIGG_Gauge_t carTank2;
	GICH_Chart_t carTotalFuel;

	/* aeroplane */
	GPAN_Panel_t airRootPanel;
	GPAN_Panel_t airActuatorsPanel;
	GPAN_Panel_t airFuelPanel;
	GPAN_Panel_t airPrimaryPanel;
}SMFD_CarMfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SMFD_Init(SMFD_CarMfd_t *this);
void SMFD_Execute(SMFD_CarMfd_t *this);


/* end */
#endif /* SMFD_CarMfd_H */

