/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GICH_Chart_H
#define GICH_Chart_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include "../../../lib/dglGaugesBase/include/Indicator.h"
#include "../../../lib/dglGaugesBase/include/Label.h"

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GICH_DIVS_NO (10)
#define GICH_SEGMENTS_NO (100)

/* types------------------------------------------------------------------------*/
typedef struct _GICH_Chart_t_
{
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator;

	GLAB_Label_t  titleLabel;
	GLAB_Label_t  valueLabel;
	GLAB_Label_t  instrumentLabels[2];
	GLAB_Label_t  originLabel;

	float32_t value;
	float32_t values[GICH_SEGMENTS_NO];
	float32_t origin;
	float32_t scale;
	uint32_t samplesNo;

	GLNS_LineStrip_t valueStrip;
	GPNT_Point_t pointsValueStrip[GICH_SEGMENTS_NO];

	GLNS_LineStrip_t lineDis[GICH_DIVS_NO];
	GPNT_Point_t pointsDivs[GICH_DIVS_NO*2];

	GLNS_LineStrip_t originV;
	GPNT_Point_t pointsOriginV[2];
	GLNS_LineStrip_t originH;
	GPNT_Point_t pointsOriginH[2];
}GICH_Chart_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GICH_Init(GICH_Chart_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GICH_SetScale(GICH_Chart_t *this,float32_t origin,float32_t scale);

/* end */
#endif /* GICH_Chart_H */

