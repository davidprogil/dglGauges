/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include "../../../lib/dglGaugesGeometry/include/Point.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* application includes--------------------------------------------------------*/
#include "../../../lib/dglRenderWrapper/include/Wrapper2D.h"
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
void GPNT_Init(GPNT_Point_t *this, float32_t x, float32_t y)
{
	//DEBUG printf("GPNT_Init\n");
	this->x=x;
	this->y=y;
}

void GPNT_Execute(GPNT_Point_t *this)
{
	//DEBUG printf("GPNT_Execute\n");
}

void GPNT_Render(GPNT_Point_t *this)
{
	//DEBUG printf("GPNT_Render %f %f\n",this->x,this->y);
	D2DW_RenderPoint(this->x,this->y);
}

void GPNT_SetPosition(GPNT_Point_t *this, float32_t x, float32_t y)
{
	this->x=x;
	this->y=y;
}

void GPNT_CopyFrom(GPNT_Point_t *this,GPNT_Point_t *source)
{
	memcpy(this,source,sizeof(GPNT_Point_t));
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
