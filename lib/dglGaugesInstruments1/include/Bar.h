/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GIBR_Bar_H
#define GIBR_Bar_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Canvas.h>
#include <Label.h>
#include <Colour.h>
#include <Indicator.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GIBR_INDICATOR_TYPE (GIND_TYPE_FLOAT32)

/* types------------------------------------------------------------------------*/
typedef struct _GIBR_Bar_t_
{
	bool_t isVertical;
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator;
	GWIN_Window_t barContour;
	GWIN_Window_t barValue;
	GLAB_Label_t  mainLabel;
	GLAB_Label_t  minLabel;
	GLAB_Label_t  maxLabel;
	GLAB_Label_t  valueLabel;

	float32_t value;
	float32_t min;
	float32_t max;
	float32_t reference;
	uint16_t nDivs;

	GCOL_Colour_t fore;
	GCOL_Colour_t back;

}GIBR_Bar_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GIBR_Init(GIBR_Bar_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GIBR_SetMinMaxNDiv(GIBR_Bar_t *this,float32_t min,float32_t max,float32_t reference,uint16_t nDivs);
void GIBR_SetColour(GIBR_Bar_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back);
void GIBR_Execute(void *thisVoid);
void GIBR_Render(void *thisVoid);

/* end */
#endif /* GIBR_Bar_H */

