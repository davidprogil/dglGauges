/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GLAB_Label_H
#define GLAB_Label_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Window.h>
#include <Colour.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GLAB_MAX_TEXT_LENGTH (80)

/* types------------------------------------------------------------------------*/
typedef enum _GLAB_TextJustification_t
{
	GLAB_JUSTIFICATION_LEFT=0,
	GLAB_JUSTIFICATION_RIGHT,
	GLAB_JUSTIFICATION_CENTER
}GLAB_TextJustification_t;

typedef enum _GLAB_TextSizeType_t
{
	GLAB_TEXT_SIZE_AUTO=0,
	GLAB_TEXT_SIZE_FIXED,
}GLAB_TextSizeType_t;

typedef struct _GLAB_Label_t_
{
	GWIN_Window_t myWindow;
	char text[GLAB_MAX_TEXT_LENGTH];
	GLAB_TextJustification_t justification;
	GLAB_TextSizeType_t textSizeType;
	float32_t textSizeWhenFixed;
	bool_t isBorderShown;
	GCOL_Colour_t colour;
	GCOL_Colour_t backColour;

}GLAB_Label_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GLAB_Init(GLAB_Label_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text,GLAB_TextJustification_t justification);
void GLAB_Execute(GLAB_Label_t *this);
void GLAB_Render(GLAB_Label_t *this);
void GLAB_SetText(GLAB_Label_t *this,char *text);

void GLAB_ApplyParentWindow(GLAB_Label_t *this,GWIN_Window_t *parentWindow);
void GLAB_SetColour(GLAB_Label_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back,bool_t isBorderShown);

/* end */
#endif /* GLAB_Label_H */

