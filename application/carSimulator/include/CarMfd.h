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
#include <Bar.h>
#include <Chart.h>
#include <Gauge.h>
#include <Sign.h>
#include <GGI2_MultiChart.h>
#include <GGI2_Table.h>
#include <GGI2_Bitmap.h>
/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define PSU_CHANNELS_NO (2)
#define PSU_ROWS_NO (PSU_CHANNELS_NO+1)
#define PSU_CHANNELS_SETS_NO (2)
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
	G2CH_MultiChart_t airFuelChart;
	GPAN_Panel_t airPrimaryPanel;

	/* test */
	GPAN_Panel_t testRootPanel;
	GPAN_Panel_t psuPanel;
	GLAB_Label_t psuChanelNameLabel[PSU_CHANNELS_NO];
	GLAB_Label_t col1Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO][PSU_CHANNELS_NO];
	GLAB_Label_t col2Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO][PSU_CHANNELS_NO];
	GLAB_Label_t col3Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO][PSU_CHANNELS_NO];
	GIGG_Gauge_t psuVGauge[PSU_CHANNELS_NO];
	GIGG_Gauge_t psuIGauge[PSU_CHANNELS_NO];
	GICH_Chart_t psuIChart[PSU_CHANNELS_NO];

	GPAN_Panel_t configPanel;

	GPAN_Panel_t tablePanel;
	G2TB_Table_t table;

	GPAN_Panel_t bitmapPanel;
	G2BM_Bitmap_t bitmap;

}SMFD_CarMfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void SMFD_Init(SMFD_CarMfd_t *this);
void SMFD_Execute(SMFD_CarMfd_t *this);


/* end */
#endif /* SMFD_CarMfd_H */

