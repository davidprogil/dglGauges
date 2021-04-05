/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <LineStrip.h>

#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Wrapper2D.h>
/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
void GLNS_Init(GLNS_LineStrip_t *this,GPNT_Point_t *points)
{
	//DEBUG printf("GLNS_Init\n");
	this->pointsNo=0;
	this->points=points;
}

void GLNS_Execute(GLNS_LineStrip_t *this)
{
	//DEBUG printf("GLNS_Execute\n");
}

void GLNS_Render(GLNS_LineStrip_t *this)
{
	//DEBUG printf("GLNS_Render\n");
	D2DW_StartLineStrip();
	for (uint16_t pIx=0;pIx<this->pointsNo;pIx++)
	{
		GPNT_Render(&this->points[pIx]);
	}
	D2DW_EndLineStrip();
}
void GLNS_RenderFill(GLNS_LineStrip_t *this)
{
	//DEBUG printf("GLNS_Render\n");
	D2DW_StartPolygon();
	for (uint16_t pIx=0;pIx<this->pointsNo-1;pIx++)
	{
		GPNT_Render(&this->points[pIx]);
	}
	D2DW_EndPolygon();
}
void GLNS_AddPoint(GLNS_LineStrip_t *this,float32_t x,float32_t y)
{
	//printf("GLNS_AddPoint %f %f\n",x,y);
	GPNT_Init(&this->points[this->pointsNo],  x,  y);
	this->pointsNo++;
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
