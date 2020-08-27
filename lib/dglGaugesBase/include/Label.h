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
/* none */

/* component includes----------------------------------------------------------*/
#include <Canvas.h>
#include <Indicator.h>

/* macros-----------------------------------------------------------------------*/
#define GLAB_MAX_TEXT_LENGTH (80)
#define GLAB_DEFAULT_FIXED_CHAR_HEIGHT (0.02f)
/* types------------------------------------------------------------------------*/
typedef enum _GLAB_TextJustification_t
{
	GLAB_JUSTIFICATION_LEFT=0,
	GLAB_JUSTIFICATION_RIGHT,
	GLAB_JUSTIFICATION_CENTER
}GLAB_TextJustification_t;

typedef enum _GLAB_VerticalAlignment_t
{
	GLAB_ALIGN_TOP=0,
	GLAB_ALIGN_BOTTOM,
	GLAB_ALIGN_CENTER
}GLAB_VerticalAlignment_t;

typedef enum _GLAB_TextSizeType_t
{
	GLAB_TEXT_SIZE_AUTO=0,
	GLAB_TEXT_SIZE_FIXED,
}GLAB_TextSizeType_t;

typedef struct _GLAB_Label_t_
{
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator;
	GIND_AnyValue_t value;
	char text[GLAB_MAX_TEXT_LENGTH];
	GLAB_TextJustification_t justification;
	GLAB_TextSizeType_t textSizeType;
	float32_t textSizeWhenFixed;
	float32_t charWidth;
	GLAB_VerticalAlignment_t alignment;
}GLAB_Label_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GLAB_Init(GLAB_Label_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text,GLAB_TextJustification_t justification);
void GLAB_Execute(void *thisVoid);
void GLAB_Render(void *thisVoid);
void GLAB_SetText(GLAB_Label_t *this,char *text);

void GLAB_ApplyParentWindow(GLAB_Label_t *this,GWIN_Window_t *parentWindow);
void GLAB_SetColour(GLAB_Label_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back,bool_t isBorderShown);
void GLAB_SetCharSizeType(GLAB_Label_t *this,GLAB_TextSizeType_t type,float32_t charHeight);
void GLAB_SetVerticalAlignment(GLAB_Label_t *this, GLAB_VerticalAlignment_t alignment);
/* end */
#endif /* GLAB_Label_H */

