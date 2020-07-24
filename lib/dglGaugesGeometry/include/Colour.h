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
/* none */

/* public functions--------------------------------------------------------------*/
void GCOL_Init(GCOL_Colour_t *this);
void GCOL_Execute(GCOL_Colour_t *this);


/* end */
#endif /* GCOL_Colour_H */

