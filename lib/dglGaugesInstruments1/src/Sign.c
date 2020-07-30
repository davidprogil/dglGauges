/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Sign.h>

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
void GISG_Init(GISG_Sign_t *this)
{
	printf("GISG_Init\n");


}

void GISG_Execute(void *thisVoid)
{
	printf("GISG_Execute\n");
	//GISG_Sign_t *this=(GISG_Sign_t*)thisVoid;
}

void GISG_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	printf("GISG_Render\n");
	//GISG_Sign_t *this=(GISG_Sign_t*)thisVoid;


}
/* local functions ------------------------------------------------------------*/
/* none */

/* end */
