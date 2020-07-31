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
	GPAN_AddInstrument(&this->actuatorsPanel,&this->cautionLabel.canvas);

	//GCNV_Canvas_t leftIndicatorLed;//TODO change to instrument
	GCNV_Init(&this->leftIndicatorLed);
	GCNV_SetPosition(&this->leftIndicatorLed,	0.1f,0.15f,0.2f,0.2f,	&this->actuatorsPanel.canvas.realWindow);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->leftIndicatorLed);

	//GCNV_Canvas_t rightIndicatorLed;//TODO change to instrument
	GCNV_Init(&this->rightIndicatorLed);
	GCNV_SetPosition(&this->rightIndicatorLed,	0.7f,0.15f,0.2f,0.2f,	&this->actuatorsPanel.canvas.realWindow);
	GPAN_AddInstrument(&this->actuatorsPanel,&this->rightIndicatorLed);

	//
	//	//GPAN_Panel_t fuelPanel;
	//	GPAN_Init(&this->fuelPanel);
	//	//GPAN_Panel_t sensorsPanel;
	//	GPAN_Init(&this->sensorsPanel);
	//	//GPAN_Panel_t dashboardPanel;
	//	GPAN_Init(&this->dashboardPanel);

}

void SMFD_Execute(SMFD_CarMfd_t *this)
{
	//printf("SMFD_Execute\n");
	GIBR_Execute(&this->directionBar);
	GIBR_Execute(&this->pedalBar);
}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
