/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* application includes--------------------------------------------------------*/
#include <Colour.h>
#include <Wrapper2D.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
 GCOL_Colour_t GCOL_White =
{
		.r = 1.0f,
		.g = 1.0f,
		.b = 1.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Red =
{
		.r = 1.0f,
		.g = 0.0f,
		.b = 0.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Green =
{
		.r = 0.0f,
		.g = 1.0f,
		.b = 0.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Blue =
{
		.r = 0.0f,
		.g = 0.0f,
		.b = 1.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Red_half =
{
		.r = 0.5f,
		.g = 0.0f,
		.b = 0.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Green_half =
{
		.r = 0.0f,
		.g = 0.5f,
		.b = 0.0f,
		.a = 1.0f
};
 GCOL_Colour_t GCOL_Blue_half =
{
		.r = 0.0f,
		.g = 0.0f,
		.b = 0.5f,
		.a = 1.0f
};
/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
void GCOL_Init(GCOL_Colour_t *this)
{
	printf("GCOL_Init\n");
}

void GCOL_Execute(GCOL_Colour_t *this)
{
	printf("GCOL_Execute\n");
}

void GCOL_CopyFrom(GCOL_Colour_t *this,GCOL_Colour_t *source)
{
	memcpy(this,source,sizeof(GCOL_Colour_t));
}

void GCOL_SetRenderColour(GCOL_Colour_t *this)
{
	//DEBUG printf("GCOL_SetRenderColour %f %f %f\n",this->r,this->g,this->b);
	D2DW_SetColour(this->r,this->g,this->b);
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
