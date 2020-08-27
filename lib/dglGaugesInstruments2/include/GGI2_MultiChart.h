/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef G2CH_MultiChart_H
#define G2CH_MultiChart_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Indicator.h>
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define G2CH_DIVS_NO (10)
#define G2CH_SEGMENTS_NO (100)
#define G2CH_INDICATOR_TYPE (GIND_TYPE_FLOAT32)
#define G2CH_INDICATOR_MAX_NO (4)
/* types------------------------------------------------------------------------*/
typedef struct _G2CH_MultiChart_t_t_
{
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator[G2CH_INDICATOR_MAX_NO];

	GLAB_Label_t  titleLabel[G2CH_INDICATOR_MAX_NO];
	GLAB_Label_t  valueLabel[G2CH_INDICATOR_MAX_NO];
	GLAB_Label_t  instrumentLabels[2];
	GLAB_Label_t  originLabel;

	float32_t value[G2CH_INDICATOR_MAX_NO];
	float32_t values[G2CH_INDICATOR_MAX_NO][G2CH_SEGMENTS_NO];
	float32_t origin;
	float32_t scale;
	uint32_t samplesNo[G2CH_INDICATOR_MAX_NO];

	GLNS_LineStrip_t valueStrip[G2CH_INDICATOR_MAX_NO];
	GPNT_Point_t pointsValueStrip[G2CH_INDICATOR_MAX_NO][G2CH_SEGMENTS_NO];

	GLNS_LineStrip_t lineDis[G2CH_DIVS_NO];
	GPNT_Point_t pointsDivs[G2CH_DIVS_NO*2];

	GLNS_LineStrip_t originV;
	GPNT_Point_t pointsOriginV[2];
	GLNS_LineStrip_t originH;
	GPNT_Point_t pointsOriginH[2];
}G2CH_MultiChart_t;
/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void G2CH_Init(G2CH_MultiChart_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void G2CH_SetScale(G2CH_MultiChart_t *this,float32_t origin,float32_t scale);
void G2CH_SetIndicatorName(G2CH_MultiChart_t *this,uint16_t indicatorId,char *title);
/* end */
#endif /* G2CH_MultiChart_H */

