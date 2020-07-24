/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GMFD_Mfd_H
#define GMFD_Mfd_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Canvas.h>
#include <Panel.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GMFD_MAX_LEVELS (5)

/* types------------------------------------------------------------------------*/
typedef struct _GMFD_Mfd_t_
{
	GCNV_Canvas_t myCanvas;

	GPAN_Panel_t* panels;
	uint8_t noPanels;

	uint8_t currentPanel[GMFD_MAX_LEVELS];
}GMFD_Mfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this);
void GMFD_Execute(GMFD_Mfd_t *this);


/* end */
#endif /* GMFD_Mfd_H */

