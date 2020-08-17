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
GCOL_Colour_t GCOL_White ={			.r = 1.0f,		.g = 1.0f,		.b = 1.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Red ={			.r = 1.0f,		.g = 0.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Green ={			.r = 0.0f,		.g = 1.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Blue ={			.r = 0.0f,		.g = 0.0f,		.b = 1.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Yellow ={		.r = 1.0f,		.g = 1.0f,		.b = 0.0f,		.a = 1.0f};

GCOL_Colour_t GCOL_Red_3Quarter ={	.r = 0.27f,		.g = 0.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Green_3Quarter ={.r = 0.0f,		.g = 0.27f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Blue_3Quarter ={	.r = 0.0f,		.g = 0.0f,		.b = 0.75f,		.a = 1.0f};
GCOL_Colour_t GCOL_Yellow_3Quarter ={.r = 0.27f,		.g = 0.27f,		.b = 0.0f,		.a = 1.0f};

GCOL_Colour_t GCOL_Red_Half ={		.r = 0.5f,		.g = 0.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Green_Half ={	.r = 0.0f,		.g = 0.5f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Blue_Half ={		.r = 0.0f,		.g = 0.0f,		.b = 0.5f,		.a = 1.0f};
GCOL_Colour_t GCOL_Yellow_Half ={	.r = 0.5f,		.g = 0.5f,		.b = 0.0f,		.a = 1.0f};

GCOL_Colour_t GCOL_Red_Quarter ={	.r = 0.25f,		.g = 0.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Green_Quarter ={	.r = 0.0f,		.g = 0.25f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Blue_Quarter ={	.r = 0.0f,		.g = 0.0f,		.b = 0.25f,		.a = 1.0f};
GCOL_Colour_t GCOL_Yellow_Quarter ={.r = 0.25f,		.g = 0.25f,		.b = 0.0f,		.a = 1.0f};

GCOL_Colour_t GCOL_Black ={			.r = 0.0f,		.g = 0.0f,		.b = 0.0f,		.a = 1.0f};
GCOL_Colour_t GCOL_Grey_3Quarter ={	.r = 0.75f,		.g = 0.75f,		.b = 0.75f,		.a = 1.0f};
GCOL_Colour_t GCOL_Grey_Half ={		.r = 0.5f,		.g = 0.5f,		.b = 0.5f,		.a = 1.0f};
GCOL_Colour_t GCOL_Grey_Quarter ={	.r = 0.25f,		.g = 0.25f,		.b = 0.25f,		.a = 1.0f};

GCOL_Colour_t *GCOL_AllColoursVector[]=
{
		&GCOL_White,
		&GCOL_Red,
		&GCOL_Green,
		&GCOL_Blue,
		&GCOL_Yellow,

		&GCOL_Red_3Quarter,
		&GCOL_Green_3Quarter,
		&GCOL_Blue_3Quarter,
		&GCOL_Yellow_3Quarter,

		&GCOL_Red_Half,
		&GCOL_Green_Half,
		&GCOL_Blue_Half,
		&GCOL_Yellow_Half,

		&GCOL_Red_Quarter,
		&GCOL_Green_Quarter,
		&GCOL_Blue_Quarter,
		&GCOL_Yellow_Quarter,

		&GCOL_Black,
		&GCOL_Grey_3Quarter,
		&GCOL_Grey_Half,
		&GCOL_Grey_Quarter
};

const uint16_t GCOL_PredefinedColoursNo = sizeof(GCOL_AllColoursVector)/sizeof(GCOL_Colour_t*);

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
