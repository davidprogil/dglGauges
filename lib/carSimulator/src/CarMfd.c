/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <CarMfd.h>

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
void SMFD_Init(SMFD_CarMfd_t *this)
{
	printf("SMFD_Init\n");
	GMFD_Init(&this->mfd);

	//this->mfd.currentPanel[0]=1;//TODO remove DEBUG

	/* ACTUATORS PANEL ***************************************/
	//GPAN_Panel_t actuatorsPanel;
	GPAN_Init(&this->actuatorsPanel,"Actuators");
	GMFD_AddPanel(&this->mfd,&this->actuatorsPanel);

	//GCNV_Canvas_t directionBar;
	GIBR_Init(&this->directionBar,&this->actuatorsPanel.canvas.realWindow,"DIRECTION (DEG)",0.25f,0.65f,0.5f,0.2f);
	GIBR_SetMinMaxNDiv(&this->directionBar,-45.0f,45.0f,0.0f,4);
	GIBR_SetColour(&this->directionBar,&GCOL_Yellow,&GCOL_Yellow_Half);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->directionBar.canvas);

	//GCNV_Canvas_t pedalBar;
	GIBR_Init(&this->pedalBar,&this->actuatorsPanel.canvas.realWindow,"PEDAL",0.4f,0.0f,0.2f,0.5f);
	GIBR_SetMinMaxNDiv(&this->pedalBar,0.0f,1.0f,0.0f,10);
	GIBR_SetColour(&this->pedalBar,&GCOL_Yellow,&GCOL_Yellow_Half);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->pedalBar.canvas);

	//GLAB_Label_t cautionLabel;
	GLAB_Init(&this->cautionLabel,&GWIN_Identity,	0.0f, 0.55f,	1.0f,  0.05f,"CAUTION",GLAB_JUSTIFICATION_CENTER);
	GCNV_SetRenderFlags(&this->cautionLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->cautionLabel.canvas);

	//GCNV_Canvas_t leftIndicatorLed;
	GISG_Init(&this->leftIndicatorLed,&this->actuatorsPanel.canvas.realWindow,"LEFT",0.1f,0.15f,0.2f,0.2f);
	GISG_AddDecoder(&this->leftIndicatorLed,"LOW",0, &GCOL_Black, &GCOL_Green);
	GISG_AddDecoder(&this->leftIndicatorLed,"MED",1, &GCOL_Black, &GCOL_Yellow);
	GISG_AddDecoder(&this->leftIndicatorLed,"HIGH",2, &GCOL_Yellow, &GCOL_Red);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->leftIndicatorLed.canvas);

	//GCNV_Canvas_t rightIndicatorLed;
	GISG_Init(&this->rightIndicatorLed,&this->actuatorsPanel.canvas.realWindow,"RIGHT",0.7f,0.15f,0.2f,0.2f);
	GISG_AddDecoder(&this->rightIndicatorLed,"LOW",0, &GCOL_Black, &GCOL_Green);
	GISG_AddDecoder(&this->rightIndicatorLed,"MED",1, &GCOL_Black, &GCOL_Yellow);
	GISG_AddDecoder(&this->rightIndicatorLed,"HIGH",2, &GCOL_Yellow, &GCOL_Red);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->rightIndicatorLed.canvas);

	/* FUEL PANEL ***************************************/
	//	//GPAN_Panel_t fuelPanel;
	GPAN_Init(&this->fuelPanel,"Fuel");
	GMFD_AddPanel(&this->mfd,&this->fuelPanel);

	//GIGG_Gauge_t tank1;
	GIGG_Init(&this->tank1,&this->fuelPanel.canvas.realWindow,"TANK1(L)",0.0f,0.45f,0.49f,0.45f);
	GIGG_SetScale(&this->tank1,0.0f,50.0f);
	GPAN_AddInstrument(&this->fuelPanel,&this->tank1.canvas);

	//GIGG_Gauge_t tank2;
	GIGG_Init(&this->tank2,&this->fuelPanel.canvas.realWindow,"TANK2(L)",0.5f,0.45f,0.49f,0.45f);
	GIGG_SetScale(&this->tank2,0.0f,50.0f);
	GPAN_AddInstrument(&this->fuelPanel,&this->tank2.canvas);

	//GICH_Chart_t totalFuel;
	GICH_Init(&this->totalFuel,&this->fuelPanel.canvas.realWindow,"TOTAL(L)",0.01f,0.01f,0.98f,0.38f);
	GICH_SetScale(&this->totalFuel,0.0f,100.0f);
	GPAN_AddInstrument(&this->fuelPanel,&this->totalFuel.canvas);

}

void SMFD_Execute(SMFD_CarMfd_t *this)
{
	//printf("SMFD_Execute\n");
	GMFD_Execute(&this->mfd);
}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
