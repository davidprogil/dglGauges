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
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GPAN_MAX_INSTRUMENTS_NO (64)
#define GPAN_MAX_SIDE_BUTTONS (8)
#define GPAN_MAX_PANELS_NO (8)
/* types------------------------------------------------------------------------*/
typedef  void (*GPAN_SideFunctions_t)(void*);
typedef struct _GPAN_PanelSet_t_
{
	void* panels[GPAN_MAX_PANELS_NO]; /* use for GPAN_Panel_t pointer */
	uint8_t panelsNo;
	uint8_t currentPanel;
}GPAN_PanelSet_t;

typedef struct _GPAN_Panel_t_
{
	GCNV_Canvas_t canvas;
	GLAB_Label_t titleLabel;

	shortText_t sideButtonsLabels[GPAN_MAX_SIDE_BUTTONS];
	GPAN_SideFunctions_t sideButtonsFunctions[GPAN_MAX_SIDE_BUTTONS];
	void*		sideButtonData[GPAN_MAX_SIDE_BUTTONS];

	/* support for subPanels */
	GPAN_PanelSet_t panelSet;//TODO initialisation and so on

	GCNV_Canvas_t *childCanvas[GPAN_MAX_INSTRUMENTS_NO*GPAN_MAX_INSTRUMENTS_NO];
	uint16_t	   childCanvasNo;

	bool_t 		showTitle;
}GPAN_Panel_t;



/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GPAN_Init(GPAN_Panel_t *this,char *title);
void GPAN_SetPosition(GPAN_Panel_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow);
void GPAN_AddInstrument(GPAN_Panel_t *this,GCNV_Canvas_t *instrument);
void GPAN_SetButtonNameAndFunction(GPAN_Panel_t *this,uint16_t buttonIx,char *text,GPAN_SideFunctions_t callback,void *data);
void GPAN_ButtonCallback(GPAN_Panel_t *this,uint16_t buttonIx);
void GPAN_SetShowTitle(GPAN_Panel_t *this,bool_t showTitle);

//for panel set
void GPAN_InitSet(GPAN_PanelSet_t *this);
void GPAN_AddPanel(GPAN_Panel_t *this,GPAN_Panel_t *panel);
bool_t GPANS_IsShowingMenu(GPAN_PanelSet_t *this);



/* end */
#endif /* GPAN_Panel_H */

