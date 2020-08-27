/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GLNS_LineStrip_H
#define GLNS_LineStrip_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

#include <Point.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GLNS_LineStrip_t_
{
	uint16_t pointsNo;
	GPNT_Point_t *points;
}GLNS_LineStrip_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GLNS_Init(GLNS_LineStrip_t *this,GPNT_Point_t *points);
void GLNS_Execute(GLNS_LineStrip_t *this);
void GLNS_Render(GLNS_LineStrip_t *this);
void GLNS_RenderFill(GLNS_LineStrip_t *this);
void GLNS_AddPoint(GLNS_LineStrip_t *this,float32_t x,float32_t y);
/* end */
#endif /* GLNS_LineStrip_H */

