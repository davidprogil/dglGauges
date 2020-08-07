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
#include <Wrapper2D.h>

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
void SKBM_Init(SKBM_KeyboardAndMouse_t *this,SCAR_CarSimulation_t *carSimulation)
{
	printf("SKBM_Init\n");
	thisKeyboardAndMouse=this;
	thisKeyboardAndMouse->carSimulation=carSimulation;
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

void SKBM_MouseClick(int button, int state, int x, int y)
{
	//printf("SKBM_MouseClick %d %d %d %d\n",button,state,x,y);
	if ((NULL != thisKeyboardAndMouse)&&(state==0))
	{
		float32_t xFloat; float32_t yFloat;
		D2DW_Pixel2View(x,y,&xFloat,&yFloat);
		GMFD_MouseClick(&thisKeyboardAndMouse->carSimulation->carMfd[0].mfd,xFloat,yFloat);
		GMFD_MouseClick(&thisKeyboardAndMouse->carSimulation->carMfd[1].mfd,xFloat,yFloat);
	}
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
