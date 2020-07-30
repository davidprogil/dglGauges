/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GISG_Sign_H
#define GISG_Sign_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Canvas.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _GISG_Sign_t_
{
	GCNV_Canvas_t canvas;

}GISG_Sign_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GISG_Init(GISG_Sign_t *this);
void GISG_Execute(void *thisVoid);
void GISG_Render(void *thisVoid);

/* end */
#endif /* GISG_Sign_H */

