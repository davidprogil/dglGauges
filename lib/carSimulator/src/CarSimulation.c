/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <CarSimulation.h>

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
void SCAR_Init(SCAR_CarSimulation_t *this)
{
	printf("SCAR_Init\n");

	this->isRunning=M_FALSE;
	this->isShowing=M_FALSE;

	this->direction=0.0f;
	this->pedal=0.0f;
	this->left=0;
	this->right=0;
	this->tank1=0.0f;
	this->tank2=0.0f;
	this->totalFuel=0.0f;

	/* initialise MFD */
	SMFD_Init(&this->carMfd);

	/* initialise vars of indicators */
	GIND_SetData(&this->carMfd.directionBar.indicator,		GIND_TYPE_FLOAT32,	&this->direction,	GIBR_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.pedalBar.indicator,			GIND_TYPE_FLOAT32,	&this->pedal,		GIBR_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.leftIndicatorLed.indicator,	GIND_TYPE_UINT8,	&this->left,		GISG_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.rightIndicatorLed.indicator,	GIND_TYPE_UINT8,	&this->right,		GISG_INDICATOR_TYPE);

	GIND_SetData(&this->carMfd.tank1.indicator,		GIND_TYPE_FLOAT32,	&this->tank1,		GIGG_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.tank2.indicator,		GIND_TYPE_FLOAT32,	&this->tank2,		GIGG_INDICATOR_TYPE);
	GIND_SetData(&this->carMfd.totalFuel.indicator,	GIND_TYPE_FLOAT32,	&this->totalFuel,	GIGG_INDICATOR_TYPE);

	/* initialise buttons */
	GPAN_SetButtonNameAndFunction(&this->carMfd.actuatorsPanel,0,(char*)"RIGHT",SCAR_SetRightIndicator,this);
	GPAN_SetButtonNameAndFunction(&this->carMfd.actuatorsPanel,4,(char*)"LEFT",SCAR_SetLeftIndicator,this);

}

void SCAR_Start(SCAR_CarSimulation_t *this)
{
	this->isRunning=M_TRUE;
}
void SCAR_Execute(SCAR_CarSimulation_t *this)
{
	//printf("SCAR_Execute\n");//DEBUG

	if (this->isRunning)
	{
		this->direction=rand()*1.0/RAND_MAX*90.0f-45.0f;
		this->pedal=rand()*1.0/RAND_MAX*1.0f-0.0f;
		//this->left=rand()*1.0/RAND_MAX*3.0f-0.0f;
		//this->right=rand()*1.0/RAND_MAX*3.0f-0.0f;
		this->tank1=this->tank1+rand()*1.0/RAND_MAX*3.0f-1.0f;
		this->tank2=this->tank2+rand()*1.0/RAND_MAX*3.0f-1.0f;
		//if (this->tank1>50.0f) this->tank1=0.0f;
		//if (this->tank2>50.0f) this->tank2=0.0f;
		this->totalFuel=(this->tank1+this->tank2);

		if (this->totalFuel>100.0f)
		{
			this->tank1=0.0f;
			this->tank2=0.0f;
			this->totalFuel=0.0f;
		}
	}

	SMFD_Execute(&this->carMfd);
}

void SCAR_SetLeftIndicator(void *thisVoid)
{
	if (thisVoid==NULL) return;
	SCAR_CarSimulation_t *this=(SCAR_CarSimulation_t*)thisVoid;
	this->left++;
	if (this->left>2) this->left=0;

	printf("SCAR_SetLeftIndicator %d\n",this->left);

}
void SCAR_SetRightIndicator(void *thisVoid)
{
	if (thisVoid==NULL) return;
	SCAR_CarSimulation_t *this=(SCAR_CarSimulation_t*)thisVoid;
	this->right++;
	if (this->right>2) this->right=0;

	printf("SCAR_SetRightIndicator %d\n",this->right);
}



/* local functions ------------------------------------------------------------*/
/* none */

/* end */
