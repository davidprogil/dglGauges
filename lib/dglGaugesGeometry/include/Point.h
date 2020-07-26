/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GPNT_Point_H
#define GPNT_Point_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GPNT_Point_t_
{
	float x;
	float y;
}GPNT_Point_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GPNT_Init(GPNT_Point_t *this, float x, float y);
void GPNT_SetPosition(GPNT_Point_t *this, float x, float y);
void GPNT_Execute(GPNT_Point_t *this);
void GPNT_Render(GPNT_Point_t *this);

/* end */
#endif /* GPNT_Point_H */

