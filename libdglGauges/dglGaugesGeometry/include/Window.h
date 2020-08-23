/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GWIN_Window_H
#define GWIN_Window_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <LineStrip.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define GWIN_POINTS_NO (5)

/* types------------------------------------------------------------------------*/
typedef struct _GWIN_Window_t_
{
	GPNT_Point_t origin;
	GPNT_Point_t length;
	GLNS_LineStrip_t lineStrip;
	GPNT_Point_t points[GWIN_POINTS_NO];
}GWIN_Window_t;

/* public variables-------------------------------------------------------------*/
extern GWIN_Window_t GWIN_Identity;

/* public functions--------------------------------------------------------------*/
void GWIN_Init(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GWIN_SetPosition(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GWIN_Execute(GWIN_Window_t *this);
void GWIN_Render(GWIN_Window_t *this);
void GWIN_RenderFill(GWIN_Window_t *this);
void GWIN_ApplyParentWindow(GWIN_Window_t *this,GWIN_Window_t *parentWindow);
void GWIN_ApplyThisWindowToPoint(GWIN_Window_t *this,GPNT_Point_t *point);
void GWIN_Print(GWIN_Window_t *this);
bool_t GWIN_IsPointInside(GWIN_Window_t *this,GPNT_Point_t *point);
/* end */
#endif /* GWIN_Window_H */

