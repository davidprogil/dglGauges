/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef DRDW_WrapperRayTrace_H
#define DRDW_WrapperRayTrace_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _DRDW_WrapperRayTrace_t_
{

}DRDW_WrapperRayTrace_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void DRDW_Init(DRDW_WrapperRayTrace_t *this);
void DRDW_Execute(DRDW_WrapperRayTrace_t *this);


/* end */
#endif /* DRDW_WrapperRayTrace_H */

