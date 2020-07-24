/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GPAN_Panel_H
#define GPAN_Panel_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Canvas.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GPAN_Panel_t_
{
	GCNV_Canvas_t myCanvas;

	void *children;
	uint8_t noChildren;
}GPAN_Panel_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GPAN_Init(GPAN_Panel_t *this);
void GPAN_Execute(GPAN_Panel_t *this);


/* end */
#endif /* GPAN_Panel_H */

