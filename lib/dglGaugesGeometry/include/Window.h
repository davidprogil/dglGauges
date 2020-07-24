/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GWIN_Window_H
#define GWIN_Window_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Point.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GWIN_Window_t_
{
	GPNT_Point_t origin;
	GPNT_Point_t length;
}GWIN_Window_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GWIN_Init(GWIN_Window_t *this);
void GWIN_Execute(GWIN_Window_t *this);


/* end */
#endif /* GWIN_Window_H */

