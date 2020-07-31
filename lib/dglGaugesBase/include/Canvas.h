/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GCNV_Canvas_H
#define GCNV_Canvas_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Window.h>
#include <Colour.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GCNV_MAX_CHILDREN (100)

/* types------------------------------------------------------------------------*/
typedef struct _GCNV_Canvas_t_
{
	/* is shown */
	bool_t isShowing;
	/* is paused (no update)*/
	bool_t isExecutioning;
	/* is show border */
	bool_t isShowBorder;
	/* is fill */
	bool_t isFill;

	/* window (start and dimensions) */
	GWIN_Window_t window;
	/* real window*/
	GWIN_Window_t realWindow;

	/* background colour */
	GCOL_Colour_t backColour;

	/* fill colour */
	GCOL_Colour_t fillColour;

	/* foreground colour */
	GCOL_Colour_t foreColour;

	/* function to render */
	void (*renderFunction)(void*);

	/* function to update contents */
	void (*updateInstrument)(void*);

	/* instrument object */
	void *instrument;

	/* type */
	//TODO

	/* children */
	void* children;
	uint8_t noChildren;

}GCNV_Canvas_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GCNV_Init(GCNV_Canvas_t *this);
void GCNV_SetPosition(GCNV_Canvas_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow);
void GCNV_SetParentFunctions(GCNV_Canvas_t *this,void (*renderFunction)(void*),void (*updateInstrument)(void*),void *instrument);
void GCNV_Execute(GCNV_Canvas_t *this);
void GCNV_Render(GCNV_Canvas_t *this);
void GCNV_ApplyParentWindow(GCNV_Canvas_t *this,GWIN_Window_t *parentWindow);
void GCNV_SetColour(GCNV_Canvas_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back,bool_t isBorderShown);

/* end */
#endif /* GCNV_Canvas_H */


