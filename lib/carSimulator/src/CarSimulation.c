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
	//DEBUG printf("SCAR_Init\n");

	this->isRunning=M_FALSE;
	this->isShowing=M_FALSE;

	this->direction=0.0f;
	this->directionSign=1.0f;
	this->pedal=0.0f;
	this->pedalSign=1.0f;
	this->left=0;
	this->right=0;
	this->tank1=0.0f;
	this->tank2=0.0f;
	this->totalFuel=0.0f;
	this->fuelSign=1.0f;

	/* psu */
	this->swVolt[0]=3.3f;
	this->swCurr[0]=0.51f;
	this->swOvp[0]=3.4f;
	this->swOcp[0]=0.5f;

	this->swVolt[1]=5.0f;
	this->swCurr[1]=0.51f;
	this->swOvp[1]=5.1f;
	this->swOcp[1]=0.5f;

	for (uint16_t mfdIx=0;mfdIx<SCAR_MFD_NO;mfdIx++)
	{
		/* initialise MFD */
		SMFD_Init(&this->carMfd[mfdIx]);

		/* initialise vars of indicators */
		GIND_SetData(&this->carMfd[mfdIx].carDirectionBar.indicator,		GIND_TYPE_FLOAT32,	&this->direction,	GIBR_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].carPedalBar.indicator,			GIND_TYPE_FLOAT32,	&this->pedal,		GIBR_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].carLeftIndicatorLed.indicator,	GIND_TYPE_UINT8,	&this->left,		GISG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].carRightIndicatorLed.indicator,	GIND_TYPE_UINT8,	&this->right,		GISG_INDICATOR_TYPE);

		GIND_SetData(&this->carMfd[mfdIx].carTank1.indicator,		GIND_TYPE_FLOAT32,	&this->tank1,		GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].carTank2.indicator,		GIND_TYPE_FLOAT32,	&this->tank2,		GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].carTotalFuel.indicator,	GIND_TYPE_FLOAT32,	&this->totalFuel,	GIGG_INDICATOR_TYPE);

		/* initialise buttons */
		GPAN_SetButtonNameAndFunction(&this->carMfd[mfdIx].carActuatorsPanel,0,(char*)"RIGHT",SCAR_SetRightIndicator,this);
		GPAN_SetButtonNameAndFunction(&this->carMfd[mfdIx].carActuatorsPanel,4,(char*)"LEFT",SCAR_SetLeftIndicator,this);

		/* for PSU */
		for (uint16_t chIx=0;chIx<2;chIx++)
		{
			/* set 1 */
			/* volt */
			GIND_SetData(&this->carMfd[mfdIx].col2Label[0][1][chIx].indicator,GIND_TYPE_FLOAT32,&this->swVolt[chIx],GIND_TYPE_FLOAT32);
			GIND_SetData(&this->carMfd[mfdIx].col3Label[0][1][chIx].indicator,GIND_TYPE_FLOAT32,&this->swOvp[chIx],GIND_TYPE_FLOAT32);
			/* curr */
			GIND_SetData(&this->carMfd[mfdIx].col2Label[0][2][chIx].indicator,GIND_TYPE_FLOAT32,&this->swCurr[chIx],GIND_TYPE_FLOAT32);
			GIND_SetData(&this->carMfd[mfdIx].col3Label[0][2][chIx].indicator,GIND_TYPE_FLOAT32,&this->swOcp[chIx],GIND_TYPE_FLOAT32);

			/* set 2 */
			/* volt */
			GIND_SetData(&this->carMfd[mfdIx].col2Label[1][1][chIx].indicator,GIND_TYPE_FLOAT32,&this->hwVolt[chIx],GIND_TYPE_FLOAT32);
			GIND_SetData(&this->carMfd[mfdIx].col3Label[1][1][chIx].indicator,GIND_TYPE_FLOAT32,&this->hwOvp[chIx],GIND_TYPE_FLOAT32);
			/* curr */
			GIND_SetData(&this->carMfd[mfdIx].col2Label[1][2][chIx].indicator,GIND_TYPE_FLOAT32,&this->hwCurr[chIx],GIND_TYPE_FLOAT32);
			GIND_SetData(&this->carMfd[mfdIx].col3Label[1][2][chIx].indicator,GIND_TYPE_FLOAT32,&this->hwOcp[chIx],GIND_TYPE_FLOAT32);

		}
		GIND_SetData(&this->carMfd[mfdIx].psuVGauge[0].indicator,	GIND_TYPE_FLOAT32,	&this->hwVolt[0],	GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].psuVGauge[1].indicator,	GIND_TYPE_FLOAT32,	&this->hwVolt[1],	GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].psuIGauge[0].indicator,	GIND_TYPE_FLOAT32,	&this->hwCurr[0],	GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].psuIGauge[1].indicator,	GIND_TYPE_FLOAT32,	&this->hwCurr[1],	GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].psuIChart[0].indicator,	GIND_TYPE_FLOAT32,	&this->hwCurr[0],	GIGG_INDICATOR_TYPE);
		GIND_SetData(&this->carMfd[mfdIx].psuIChart[1].indicator,	GIND_TYPE_FLOAT32,	&this->hwCurr[1],	GIGG_INDICATOR_TYPE);


		GPAN_SetButtonNameAndFunction(&this->carMfd[mfdIx].psuPanel,1,(char*)"OFF",SCAR_SetRightIndicator,this);
		GPAN_SetButtonNameAndFunction(&this->carMfd[mfdIx].psuPanel,2,(char*)"ON",SCAR_SetRightIndicator,this);
		GPAN_SetButtonNameAndFunction(&this->carMfd[mfdIx].psuPanel,3,(char*)"SET",SCAR_SetRightIndicator,this);
		/* end of PSU*/

	}


	GMFD_SetPosition(&this->carMfd[0].mfd,-0.55f,0.0f,1.0f,1.0f);
	GMFD_SetPosition(&this->carMfd[1].mfd, 0.55f,0.0f,1.0f,1.0f);

	GMFD_SetColour(&this->carMfd[1].mfd,&GCOL_Red,&GCOL_Red_Half);

	//GMFD_SetPosition(&this->carMfd[0].mfd, 0.0f,0.0f,0.5f,0.5f);
	//GMFD_SetPosition(&this->carMfd[1].mfd, 0.5f,0.0f,0.5f,0.5f);

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
		//		this->direction=rand()*1.0/RAND_MAX*90.0f-45.0f;
		//		this->pedal=rand()*1.0/RAND_MAX*1.0f-0.0f;
		//		this->tank1+=rand()*1.0/RAND_MAX*3.0f-1.5f;
		//		this->tank2+=rand()*1.0/RAND_MAX*3.0f-1.5f;
		//		this->totalFuel=(this->tank1+this->tank2);
		//
		//		if (this->totalFuel>100.0f)
		//		{
		//			this->tank1=0.0f;
		//			this->tank2=0.0f;
		//			this->totalFuel=0.0f;
		//		}

		this->direction+=rand()*1.0/RAND_MAX*1.0f-0.5f+0.5f*this->directionSign;
		if (this->direction>45.0f)
		{
			this->directionSign=-1.0f;
		}
		else if (this->direction<-45.0f)
		{
			this->directionSign=1.0f;
		}

		this->pedal+=rand()*1.0/RAND_MAX*0.01f-0.005f+0.005f*this->pedalSign;
		if (this->pedal<0.0f)
		{
			this->pedalSign=1.0f;
		}
		else if (this->pedal>1.0f)
		{
			this->pedalSign=-1.0f;
		}

		this->tank1+=rand()*1.0/RAND_MAX*1.0f-0.5f+0.5f*this->fuelSign;
		this->tank2+=rand()*1.0/RAND_MAX*1.0f-0.5f+0.5f*this->fuelSign;
		this->totalFuel=(this->tank1+this->tank2);

		if ((this->tank1>50.0f)||(this->tank2>50.0f))
		{
			this->fuelSign=-1.0f;
		}
		else if ((this->tank1<0.0f)||(this->tank2<0.0f))
		{
			this->fuelSign=1.0f;
		}

		/* PSU */
		this->hwVolt[0]=3.3f+rand()*1.0/RAND_MAX*0.2f+0.1f;
		this->hwCurr[0]=rand()*1.0/RAND_MAX*0.5f+0.25f;
		this->hwOvp[0]=3.4f;
		this->hwOcp[0]=0.5f;

		this->hwVolt[1]=5.0f+rand()*1.0/RAND_MAX*0.2f+0.1f;
		this->hwCurr[1]=rand()*1.0/RAND_MAX*0.5f+0.25f;
		this->hwOvp[1]=5.1f;
		this->hwOcp[1]=0.5f;
	}

	SMFD_Execute(&this->carMfd[0]);
	SMFD_Execute(&this->carMfd[1]);
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
