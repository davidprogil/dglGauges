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

/* types------------------------------------------------------------------------*/
typedef struct _GPAN_Panel_t_
{
	GCNV_Canvas_t canvas;
	GLAB_Label_t titleLabel;
	//TODO support for subPanels

	void *instruments[GPAN_MAX_INSTRUMENTS_NO];
	uint8_t instrumentsNo;
}GPAN_Panel_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GPAN_Init(GPAN_Panel_t *this,char *title);
void GPAN_Execute(GPAN_Panel_t *this);
void GPAN_Render(GPAN_Panel_t *this);
void GPAN_SetPosition(GPAN_Panel_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow);
void GPAN_ApplyParentWindow(GPAN_Panel_t *this,GWIN_Window_t *parentWindow);
void GPAN_AddInstrument(GPAN_Panel_t *this,GCNV_Canvas_t *instrument);
/* end */
#endif /* GPAN_Panel_H */

