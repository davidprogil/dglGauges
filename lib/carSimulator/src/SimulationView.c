/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>


/* application includes--------------------------------------------------------*/
#include <SimulationView.h>
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
static SVIW_SimulationView_t *thisView=NULL; /* singleton */

/* local prototypes -----------------------------------------------------------*/
void SVIW_Execute();

/* public functions -----------------------------------------------------------*/
void SVIW_Init(SVIW_SimulationView_t *this,SCAR_CarSimulation_t *carSimulation,void *keyboardFunction,void *MouseFunction)
{
	printf("SVIW_Init\n");
	thisView=this;
	thisView->isEnabled = M_FALSE;
	thisView->carSimulation=carSimulation;
	D2DW_Init(&this->wrapper2D,SVIW_Execute,keyboardFunction,MouseFunction,640,480);


}

void SVIW_Enable(bool_t isEnabled)
{
	printf("SVIW_Enable\n");
	thisView->isEnabled=isEnabled;
	UpdateView();
}

void SVIW_Start()
{
	printf("SVIW_Start\n");
	D2DW_Start();
}


/* AKA render */
void SVIW_Execute()
{
	//printf("SVIW_Execute\n");//DEBUG
	if ((thisView!=NULL) && (thisView->isEnabled))
	{
		//D2DW_RenderSampleView();//TODO remove

		D2DW_StartView();
		//D2DW_RenderSample();

		if (NULL!=thisView->carSimulation)
		{
			/* render car */
			//TODO

			/* render mfd */
			GMFD_Render(&thisView->carSimulation->carMfd.mfd);
		}

		D2DW_Flush();
	}
	D2DW_Timer(SVIW_Execute,1000/*msecs*/);
}



/* local functions ------------------------------------------------------------*/
/* none */

/* end */
