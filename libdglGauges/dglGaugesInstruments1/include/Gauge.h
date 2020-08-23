/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GIGG_Gauge_H
#define GIGG_Gauge_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Label.h>
#include <Indicator.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GIGG_INDICATOR_TYPE (GIND_TYPE_FLOAT32)
#define GIGG_LABELS_MAX_NO (2)
#define GIGG_SEGMENTS_NO (48)
#define GIGG_DIVS_NO (10)
/* types------------------------------------------------------------------------*/
typedef struct _GIGG_Gauge_t_
{
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator;

	GLAB_Label_t  titleLabel;
	GLAB_Label_t  valueLabel;
	GLAB_Label_t  instrumentLabels[GIGG_LABELS_MAX_NO];
	float32_t value;
	float32_t origin;
	float32_t scale;

	GLNS_LineStrip_t pointer;
	GPNT_Point_t	pointerPoints[2];

	GLNS_LineStrip_t lineAround;
	GPNT_Point_t pointsAround[GIGG_SEGMENTS_NO+1];

	GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
}GIGG_Gauge_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GIGG_Init(GIGG_Gauge_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GIGG_SetScale(GIGG_Gauge_t *this,float32_t origin,float32_t scale);

/* end */
#endif /* GIGG_Gauge_H */

