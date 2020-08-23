/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include "../../../lib/dglGaugesGeometry/include/Window.h"

#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
GWIN_Window_t GWIN_Identity =
{
		.origin.x=0.0f,	.origin.y=0.0f,
		.length.x=1.0f,	.length.y=1.0f,
		.lineStrip.pointsNo =0
};

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
void GWIN_calculateLineStrip(GWIN_Window_t *this);

/* public functions -----------------------------------------------------------*/
void GWIN_Init(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//printf("GWIN_Init\n");//DEBUG
	GPNT_Init(&this->origin,ox,oy);
	GPNT_Init(&this->length,dx,dy);
	GLNS_Init(&this->lineStrip,this->points);
	GWIN_calculateLineStrip(this);
}

void GWIN_Execute(GWIN_Window_t *this)
{
	//DEBUG printf("GWIN_Execute\n");
}

void GWIN_Render(GWIN_Window_t *this)
{
	//DEBUG printf("GWIN_Render\n");
	if (this->lineStrip.pointsNo==0)
	{
		GWIN_Init(this,this->origin.x,this->origin.y,this->length.x,this->length.y);
		GWIN_calculateLineStrip(this);
	}
	GLNS_Render(&this->lineStrip);
}

void GWIN_RenderFill(GWIN_Window_t *this)
{
	//DEBUG printf("GWIN_RenderFill\n");
	GLNS_RenderFill(&this->lineStrip);
}

void GWIN_SetPosition(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	GPNT_SetPosition(&this->origin,ox,oy);
	GPNT_SetPosition(&this->length,dx,dy);
	GWIN_calculateLineStrip(this);
}

void GWIN_ApplyParentWindow(GWIN_Window_t *this,GWIN_Window_t *parentWindow)
{
	float32_t scaleX=parentWindow->length.x;
	float32_t scaleY=parentWindow->length.y;
	GWIN_SetPosition(this,
			parentWindow->origin.x+this->origin.x*scaleX,
			parentWindow->origin.y+this->origin.y*scaleY,
			this->length.x*scaleX,
			this->length.y*scaleY);
	GWIN_calculateLineStrip(this);
	//printf("GWIN_ApplyParentWindow %f\n",this->lineStrip.points[0].x);//TODO remove

}
void GWIN_ApplyThisWindowToPoint(GWIN_Window_t *this,GPNT_Point_t *point)
{
	float32_t scaleX=this->length.x;
	float32_t scaleY=this->length.y;
	point->x=point->x*scaleX+this->origin.x;
	point->y=point->y*scaleY+this->origin.y;
}

void GWIN_Print(GWIN_Window_t *this)
{
	printf("GWIN_Print: %f %f %f %f\n",this->origin.x,this->origin.y,this->length.x,this->length.y);
}

bool_t GWIN_IsPointInside(GWIN_Window_t *this,GPNT_Point_t *point)
{
	bool_t returnValue = M_FALSE;

	if ((point->x>=this->origin.x)&&(point->x<=this->origin.x+this->length.x)&&
		(point->y>=this->origin.y)&&(point->y<=this->origin.y+this->length.y))
	{
		returnValue = M_TRUE;
	}

	return returnValue;
}

/* local functions ------------------------------------------------------------*/
void GWIN_calculateLineStrip(GWIN_Window_t *this)
{
	GLNS_Init(&this->lineStrip,&this->points[0]);
	GLNS_AddPoint(&this->lineStrip,this->origin.x				,this->origin.y);
	GLNS_AddPoint(&this->lineStrip,this->origin.x+this->length.x,this->origin.y);
	GLNS_AddPoint(&this->lineStrip,this->origin.x+this->length.x,this->origin.y+this->length.y);
	GLNS_AddPoint(&this->lineStrip,this->origin.x				,this->origin.y+this->length.y);
	GLNS_AddPoint(&this->lineStrip,this->origin.x				,this->origin.y);

}

/* end */
