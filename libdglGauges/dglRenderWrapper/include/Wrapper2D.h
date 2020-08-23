/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef D2DW_Wrapper2D_H
#define D2DW_Wrapper2D_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _D2DW_Wrapper2D_t_
{
	float32_t aspect;
	uint16_t sizeX;
	uint16_t sizeY;
	float32_t viewOx;
	float32_t viewOy;
	float32_t viewDx;
	float32_t viewDy;
}D2DW_Wrapper2D_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void D2DW_Init(D2DW_Wrapper2D_t *this,	void *renderFuntion,void *keyboardFuntion,void *mouseClickFuntion,
										uint16_t sizeX,uint16_t sizeY);
void D2DW_Execute();
void D2DW_RenderSample();
void D2DW_RenderSampleView();
void UpdateView();
void D2DW_Start();
void D2DW_Timer(void *function,uint16_t msecs);

void D2DW_StartView();
void D2DW_StartLineStrip();
void D2DW_EndLineStrip();
void D2DW_StartPolygon();
void D2DW_EndPolygon();
void D2DW_RenderPoint(float32_t x,float32_t y);
void D2DW_Flush();
void D2DW_Flush();
void D2DW_SetColour(float32_t r,float32_t g,float32_t b);
void D2DW_Pixel2View(int x, int y, float32_t* xfloat, float32_t* yfloat);

/* end */
#endif /* D2DW_Wrapper2D_H */

