/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GBUT_Button_H
#define GBUT_Button_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <Canvas.h>
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GBUT_Button_t_
{
	GCNV_Canvas_t canvas;
	GLAB_Label_t  title;
	bool_t isClicked;
}GBUT_Button_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GBUT_Init(GBUT_Button_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text);
void GBUT_Execute(void *thisVoid);
void GBUT_Render(void *thisVoid);

bool_t GBUT_IsPointInside(GBUT_Button_t *this,GPNT_Point_t *point);
void GBUT_SetClicked(GBUT_Button_t *this);
/* end */
#endif /* GBUT_Button_H */

