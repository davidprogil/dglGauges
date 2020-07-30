/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

/* application includes--------------------------------------------------------*/
#include <SimulationControl.h>

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
void SCRT_Init(SCRT_SimulationControl_t *this)
{
	printf("SCRT_Init\n");

	this->isRunning=M_FALSE;
	this->isShowing=M_FALSE;

	SCAR_Init(&this->car);
	SKBM_Init(&this->interaction);
	SVIW_Init(&this->view,&this->car,SKBM_Keyboard);



}

void *SCRT_Execute(void *thisVoid)
{
	printf("SCRT_Execute\n");
	SCRT_SimulationControl_t *this=(SCRT_SimulationControl_t *)thisVoid;

	while (this->isRunning)
	{
		SCAR_Execute(&this->car);

		sleep(1);
	}
	return NULL;
}

void SCRT_Render(SCRT_SimulationControl_t *this)
{
	//TODO not used
	printf("SCRT_Render\n");
	if (this->isShowing)
	{
		SVIW_Execute();
	}
}

void SCRT_Start(SCRT_SimulationControl_t *this,bool_t isShowing)
{
	printf("SCRT_Start\n");
	this->isRunning=M_TRUE;
	this->isShowing=isShowing;
	SVIW_Enable(isShowing);
	pthread_create(&this->thread_id, NULL, SCRT_Execute, this);
	SVIW_Start();

}

void SCRT_Stop(SCRT_SimulationControl_t *this)
{
	printf("SCRT_Stop\n");
	this->isRunning=M_FALSE;
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
