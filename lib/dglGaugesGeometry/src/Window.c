/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Window.h>

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
void GWIN_calculateLineStrip(GWIN_Window_t *this);

/* public functions -----------------------------------------------------------*/
void GWIN_Init(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	printf("GWIN_Init\n");
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
	GLNS_Render(&this->lineStrip);
}

void GWIN_SetPosition(GWIN_Window_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	GPNT_SetPosition(&this->origin,ox,oy);
	GPNT_SetPosition(&this->length,dx,dy);
	GWIN_calculateLineStrip(this);
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
