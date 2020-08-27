/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GCOL_Colour_H
#define GCOL_Colour_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GCOL_Colour_t_
{
	float32_t r;
	float32_t g;
	float32_t b;
	float32_t a;
}GCOL_Colour_t;

/* public variables-------------------------------------------------------------*/
extern  GCOL_Colour_t GCOL_White;
extern  GCOL_Colour_t GCOL_Grey_Half;
extern  GCOL_Colour_t GCOL_Grey_Quarter;
extern  GCOL_Colour_t GCOL_Black;
extern  GCOL_Colour_t GCOL_Red;
extern  GCOL_Colour_t GCOL_Green;
extern  GCOL_Colour_t GCOL_Yellow;
extern  GCOL_Colour_t GCOL_Blue;
extern  GCOL_Colour_t GCOL_Cyan;
extern  GCOL_Colour_t GCOL_Red_3Quarter;
extern  GCOL_Colour_t GCOL_Green_3Quarter;
extern  GCOL_Colour_t GCOL_Blue_3Quarter;
extern  GCOL_Colour_t GCOL_Yellow_3Quarter;
extern  GCOL_Colour_t GCOL_Red_Half;
extern  GCOL_Colour_t GCOL_Green_Half;
extern  GCOL_Colour_t GCOL_Blue_Half;
extern  GCOL_Colour_t GCOL_Yellow_Half;
extern  GCOL_Colour_t GCOL_Cyan_Hald;
extern  GCOL_Colour_t GCOL_Red_Quarter;
extern  GCOL_Colour_t GCOL_Green_Quarter;
extern  GCOL_Colour_t GCOL_Blue_Quarter;
extern  GCOL_Colour_t GCOL_Yellow_Quarter;
extern  GCOL_Colour_t GCOL_Cyan_Quarter;


extern GCOL_Colour_t *GCOL_AllColoursVector[];
extern const uint16_t GCOL_PredefinedColoursNo;
/* public functions--------------------------------------------------------------*/
void GCOL_Init(GCOL_Colour_t *this);
void GCOL_Execute(GCOL_Colour_t *this);
void GCOL_CopyFrom(GCOL_Colour_t *this,GCOL_Colour_t *source);
void GCOL_SetRenderColour(GCOL_Colour_t *this);
/* end */
#endif /* GCOL_Colour_H */

