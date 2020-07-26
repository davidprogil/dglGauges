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
#define GMFD_MAX_PANELS_NO (8)
/* types------------------------------------------------------------------------*/
typedef struct _GMFD_Mfd_t_
{
	GCNV_Canvas_t myCanvas;

	GPAN_Panel_t* panels[GMFD_MAX_PANELS_NO];
	uint8_t panelsNo;

	uint8_t currentPanel[GMFD_MAX_LEVELS];
}GMFD_Mfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this);
void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel);
void GMFD_Execute(GMFD_Mfd_t *this);
void GMFD_Render(GMFD_Mfd_t *this);

/* end */
#endif /* GMFD_Mfd_H */

