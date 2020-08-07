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
#include <Panel.h>
#include <Button.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GMFD_MAX_LEVELS (5)
#define GMFD_MAX_PANELS_NO (8)
#define GMFD_MAX_SIDE_BUTTONS (GMFD_MAX_PANELS_NO)
/* types------------------------------------------------------------------------*/
typedef struct _GMFD_Mfd_t_
{
	/* canvas */
	GCNV_Canvas_t canvas;

	/* sub panels */
	GPAN_Panel_t* panels[GMFD_MAX_PANELS_NO];
	uint8_t panelsNo;

	/* side buttons and labels */
	GBUT_Button_t buttons[GMFD_MAX_SIDE_BUTTONS];
	GLAB_Label_t  buttonLabels[GMFD_MAX_SIDE_BUTTONS];

	/* info label */
	GLAB_Label_t infoLabel;

	/* up button */
	GBUT_Button_t upButton;

	/* panel navigation */
	uint8_t currentPanel[GMFD_MAX_LEVELS];
	uint8_t currentLevel;
}GMFD_Mfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this);
void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel);
void GMFD_Execute(GMFD_Mfd_t *this);
void GMFD_Render(GMFD_Mfd_t *this);
void GMFD_MouseClick(GMFD_Mfd_t *this,float x,float y);
/* end */
#endif /* GMFD_Mfd_H */

