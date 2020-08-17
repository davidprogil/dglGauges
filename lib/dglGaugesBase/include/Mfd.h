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
#define GMFD_MAX_SIDE_BUTTONS (8)
/* types------------------------------------------------------------------------*/
typedef struct _GMFD_Mfd_t_
{
	/* canvas */
	GCNV_Canvas_t canvas;

	/* sub panels */
	GPAN_PanelSet_t panelSet;
	uint8_t	currentLevel;
	bool_t mouseClick;
	float32_t mouseClick_x;
	float32_t mouseClick_y;

	/* side buttons and labels */
	GBUT_Button_t buttons[GMFD_MAX_SIDE_BUTTONS];
	GLAB_Label_t  buttonLabels[GMFD_MAX_SIDE_BUTTONS];

	/* info label */
	GLAB_Label_t infoLabel;

	/* up button */
	GBUT_Button_t upButton;


	/* canvas */
	GCNV_Canvas_t *childCanvas[GPAN_MAX_INSTRUMENTS_NO*2];
	uint16_t	   childCanvasNo;
}GMFD_Mfd_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this);
void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel);
void GMFD_Execute(GMFD_Mfd_t *this);
void GMFD_Render(GMFD_Mfd_t *this);
void GMFD_MouseClick(GMFD_Mfd_t *this,float x,float y);
void GMFD_SetPosition(GMFD_Mfd_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GMFD_SetColour(GMFD_Mfd_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back);

/* end */
#endif /* GMFD_Mfd_H */

