/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <KeyboardAndMouse.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
SKBM_KeyboardAndMouse_t *thisKeyboardAndMouse=NULL; /* singleton */

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
void SKBM_Init(SKBM_KeyboardAndMouse_t *this)
{
	printf("SKBM_Init\n");
	thisKeyboardAndMouse=this;
}

void SKBM_Execute(SKBM_KeyboardAndMouse_t *this)
{
	printf("SKBM_Execute\n");
	if (NULL != thisKeyboardAndMouse)
	{

	}
}

void SKBM_Keyboard(int key, int x, int y)
{
	printf("SKBM_Keyboard\n");
	if (NULL != thisKeyboardAndMouse)
	{

	}
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
