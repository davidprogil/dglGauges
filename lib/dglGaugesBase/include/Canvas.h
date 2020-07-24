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
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GCNV_MAX_CHILDREN (100)

/* types------------------------------------------------------------------------*/
typedef struct _GCNV_Canvas_t_
{
	/* is shown */
	bool_t isShown;
	/* is paused (no update)*/
	bool_t isUpdated;
	/* is show border */
	bool_t isShowBorder;

	/* window (start and dimensions) */
	GWIN_Window_t window;

	/* background colour */
	GCOL_Colour_t backColour;

	/* foreground colour */
	GCOL_Colour_t foreColour;

	/* function to render */
	//todo

	/* function to update contents */
	//todo

	/* main label */
	GLAB_Label_t label;

	/* children */
	void* children;
	uint8_t noChildren;

}GCNV_Canvas_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GCNV_Init(GCNV_Canvas_t *this);
void GCNV_Execute(GCNV_Canvas_t *this);


/* end */
#endif /* GCNV_Canvas_H */


