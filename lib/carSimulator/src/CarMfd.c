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
	//printf("SMFD_Init\n");//DEBUG
	GMFD_Init(&this->mfd);

	//this->mfd.panelSet.currentPanel=2;//TODO remove DEBUG

	/* CAR PANEL ROOT *******************************************************************************************/
	GPAN_Init(&this->carRootPanel,"CAR");
	GMFD_AddPanel(&this->mfd,&this->carRootPanel);

	/* CAR ACTUATORS PANEL ***************************************/
	//GPAN_Panel_t actuatorsPanel;
	GPAN_Init(&this->carActuatorsPanel,"Actuators");
	GPAN_AddPanel(&this->carRootPanel,&this->carActuatorsPanel);

	//GCNV_Canvas_t directionBar;
	GIBR_Init(&this->carDirectionBar,&this->carActuatorsPanel.canvas.realWindow,"DIRECTION (DEG)",0.25f,0.65f,0.5f,0.2f);
	GIBR_SetMinMaxNDiv(&this->carDirectionBar,-45.0f,45.0f,0.0f,4);
	GIBR_SetColour(&this->carDirectionBar,&GCOL_Yellow,&GCOL_Yellow_Half);
	GPAN_AddInstrument(&this->carActuatorsPanel,&this->carDirectionBar.canvas);

	//GCNV_Canvas_t pedalBar;
	GIBR_Init(&this->carPedalBar,&this->carActuatorsPanel.canvas.realWindow,"PEDAL",0.4f,0.0f,0.2f,0.5f);
	GIBR_SetMinMaxNDiv(&this->carPedalBar,0.0f,1.0f,0.0f,10);
	GIBR_SetColour(&this->carPedalBar,&GCOL_Yellow,&GCOL_Yellow_Half);
	GPAN_AddInstrument(&this->carActuatorsPanel,&this->carPedalBar.canvas);

	//GLAB_Label_t cautionLabel;
	GLAB_Init(&this->carCautionLabel,&GWIN_Identity,	0.0f, 0.55f,	1.0f,  0.05f,"CAUTION",GLAB_JUSTIFICATION_CENTER);
	GCNV_SetRenderFlags(&this->carCautionLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	GPAN_AddInstrument(&this->carActuatorsPanel,&this->carCautionLabel.canvas);

	//GCNV_Canvas_t leftIndicatorLed;
	GISG_Init(&this->carLeftIndicatorLed,&this->carActuatorsPanel.canvas.realWindow,"LEFT",0.1f,0.15f,0.2f,0.2f);
	GISG_AddDecoder(&this->carLeftIndicatorLed,"LOW",0, &GCOL_Black, &GCOL_Green);
	GISG_AddDecoder(&this->carLeftIndicatorLed,"MED",1, &GCOL_Black, &GCOL_Yellow);
	GISG_AddDecoder(&this->carLeftIndicatorLed,"HIGH",2, &GCOL_Yellow, &GCOL_Red);
	GPAN_AddInstrument(&this->carActuatorsPanel,&this->carLeftIndicatorLed.canvas);

	//GCNV_Canvas_t rightIndicatorLed;
	GISG_Init(&this->carRightIndicatorLed,&this->carActuatorsPanel.canvas.realWindow,"RIGHT",0.7f,0.15f,0.2f,0.2f);
	GISG_AddDecoder(&this->carRightIndicatorLed,"LOW",0, &GCOL_Black, &GCOL_Green);
	GISG_AddDecoder(&this->carRightIndicatorLed,"MED",1, &GCOL_Black, &GCOL_Yellow);
	GISG_AddDecoder(&this->carRightIndicatorLed,"HIGH",2, &GCOL_Yellow, &GCOL_Red);
	GPAN_AddInstrument(&this->carActuatorsPanel,&this->carRightIndicatorLed.canvas);

	/* CAR FUEL PANEL ***************************************/
	//	//GPAN_Panel_t fuelPanel;
	GPAN_Init(&this->carFuelPanel,"Fuel");
	GPAN_AddPanel(&this->carRootPanel,&this->carFuelPanel);

	//GIGG_Gauge_t tank1;
	GIGG_Init(&this->carTank1,&this->carFuelPanel.canvas.realWindow,"TANK1(L)",0.0f,0.45f,0.49f,0.45f);
	GIGG_SetScale(&this->carTank1,0.0f,50.0f);
	GPAN_AddInstrument(&this->carFuelPanel,&this->carTank1.canvas);

	//GIGG_Gauge_t tank2;
	GIGG_Init(&this->carTank2,&this->carFuelPanel.canvas.realWindow,"TANK2(L)",0.5f,0.45f,0.49f,0.45f);
	GIGG_SetScale(&this->carTank2,0.0f,50.0f);
	GPAN_AddInstrument(&this->carFuelPanel,&this->carTank2.canvas);

	//GICH_Chart_t totalFuel;
	GICH_Init(&this->carTotalFuel,&this->carFuelPanel.canvas.realWindow,"TOTAL(L)",0.01f,0.01f,0.98f,0.38f);
	GICH_SetScale(&this->carTotalFuel,0.0f,100.0f);
	GPAN_AddInstrument(&this->carFuelPanel,&this->carTotalFuel.canvas);

	/* AIR PANEL ROOT *******************************************************************************************/
	GPAN_Init(&this->airRootPanel,"Aeroplane");
	GMFD_AddPanel(&this->mfd,&this->airRootPanel);

	//GPAN_Panel_t airRootPanel;
	/* AIR ACTUATORS PANEL ***************************************/
	GPAN_Init(&this->airActuatorsPanel,"Actuators");
	GPAN_AddPanel(&this->airRootPanel,&this->airActuatorsPanel);
	/* AIR FUEL PANEL ***************************************/
	GPAN_Init(&this->airFuelPanel,"Fuel");
	GPAN_AddPanel(&this->airRootPanel,&this->airFuelPanel);
	/*AIR  PRIMARY PANEL ***************************************/
	GPAN_Init(&this->airPrimaryPanel,"Primary");
	GPAN_AddPanel(&this->airRootPanel,&this->airPrimaryPanel);

	/* TEST PANEL ROOT *******************************************************************************************/
	GPAN_Init(&this->testRootPanel,"Test");
	GMFD_AddPanel(&this->mfd,&this->testRootPanel);
	/*PSU PANEL ***************************************/
	GPAN_Init(&this->psuPanel,"PSU");
	GPAN_AddPanel(&this->testRootPanel,&this->psuPanel);
	GCNV_SetRenderFlags(&this->psuPanel.titleLabel.canvas,M_FALSE,M_FALSE,M_FALSE);/*dont show title */

	for (uint16_t setIx=0;setIx<PSU_CHANNELS_SETS_NO;setIx++)
	{
		float32_t xLength1=0.1f;
		float32_t xLength2=0.2f;
		float32_t yLength=0.04f;
		for (uint16_t lineIx=0;lineIx<PSU_ROWS_NO;lineIx++)
		{

			float32_t y=(0.9f-yLength)-(yLength*1.01f)*lineIx-setIx*(yLength*1.1f)*PSU_ROWS_NO;

			//GLAB_Label_t psuChanelNameLabel[PSU_CHANNELS_NO];
			if ((setIx==0)&&(lineIx<=1))
			{
				if ((lineIx==0)) 	GLAB_Init(&this->psuChanelNameLabel[lineIx],&this->psuPanel.canvas.realWindow,	0.0f, 0.0f,	0.5f,  1.0f,"CH1",GLAB_JUSTIFICATION_CENTER);
				if ((lineIx==1))	GLAB_Init(&this->psuChanelNameLabel[lineIx],&this->psuPanel.canvas.realWindow,	0.5f, 0.0f,	0.5f,  1.0f,"CH2",GLAB_JUSTIFICATION_CENTER);
				GCNV_SetRenderFlags(&this->psuChanelNameLabel[lineIx].canvas,M_TRUE,M_TRUE,M_FALSE);
				GLAB_SetVerticalAlignment(&this->psuChanelNameLabel[lineIx], GLAB_ALIGN_TOP);
				GLAB_SetCharSizeType(&this->psuChanelNameLabel[lineIx],GLAB_TEXT_SIZE_FIXED,0.09f);
				GPAN_AddInstrument(&this->psuPanel,&this->psuChanelNameLabel[lineIx].canvas);
			}

			//GLAB_Label_t col1Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO];
			for (uint16_t chIx=0;chIx<PSU_CHANNELS_NO;chIx++)
			{
				float32_t x=0.0f+chIx*0.5f;
				if ((lineIx==0)&&(setIx==0)) GLAB_Init(&this->col1Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,	x, y,	xLength1,  yLength,"SW",GLAB_JUSTIFICATION_CENTER);
				if ((lineIx==0)&&(setIx==1)) GLAB_Init(&this->col1Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,	x, y,	xLength1,  yLength,"HW",GLAB_JUSTIFICATION_CENTER);
				if ((lineIx==1)) GLAB_Init(&this->col1Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,				x, y,	xLength1,  yLength,"(V)",GLAB_JUSTIFICATION_CENTER);
				if ((lineIx==2)) GLAB_Init(&this->col1Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,				x, y,	xLength1,  yLength,"(A)",GLAB_JUSTIFICATION_CENTER);
				if ((lineIx!=0)) GCNV_SetColour(&this->col1Label[setIx][lineIx][chIx].canvas,&GCOL_Green_Half,&GCOL_Green_Half,M_FALSE);
				GCNV_SetRenderFlags(&this->col1Label[setIx][lineIx][chIx].canvas,M_TRUE,M_FALSE,M_FALSE);
				GPAN_AddInstrument(&this->psuPanel,&this->col1Label[setIx][lineIx][chIx].canvas);
				x+=xLength1;

				//GLAB_Label_t col2Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO];
				GLAB_Init(&this->col2Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,	x, y,	xLength2,  yLength,"SET",GLAB_JUSTIFICATION_CENTER);
				if (lineIx==0) GCNV_SetColour(&this->col2Label[setIx][lineIx][chIx].canvas,&GCOL_Green_Half,&GCOL_Green_Half,M_FALSE);
				GCNV_SetRenderFlags(&this->col2Label[setIx][lineIx][chIx].canvas,M_TRUE,M_FALSE,M_FALSE);
				GPAN_AddInstrument(&this->psuPanel,&this->col2Label[setIx][lineIx][chIx].canvas);
				x+=xLength2;

				//GLAB_Label_t col3Label[PSU_CHANNELS_SETS_NO][PSU_ROWS_NO];
				GLAB_Init(&this->col3Label[setIx][lineIx][chIx],&this->psuPanel.canvas.realWindow,	x, y,	xLength2,  yLength,"PROT",GLAB_JUSTIFICATION_CENTER);
				if (lineIx==0) GCNV_SetColour(&this->col3Label[setIx][lineIx][chIx].canvas,&GCOL_Green_Half,&GCOL_Green_Half,M_FALSE);
				GCNV_SetRenderFlags(&this->col3Label[setIx][lineIx][chIx].canvas,M_TRUE,M_FALSE,M_FALSE);
				GPAN_AddInstrument(&this->psuPanel,&this->col3Label[setIx][lineIx][chIx].canvas);
				x+=xLength2;
			}

			if ((setIx==0)&&(lineIx<=1))
			{
				//GIGG_Gauge_t psuVGauge[PSU_CHANNELS_NO];
				GIGG_Init(&this->psuVGauge[lineIx],&this->psuPanel.canvas.realWindow,"V(V)",0.0f+0.5f*lineIx,0.40f,0.24f,0.24f);
				GIGG_SetScale(&this->psuVGauge[lineIx],0.0f,10.0f);
				GPAN_AddInstrument(&this->psuPanel,&this->psuVGauge[lineIx].canvas);
				//GIGG_Gauge_t psuIGauge[PSU_CHANNELS_NO];
				GIGG_Init(&this->psuIGauge[lineIx],&this->psuPanel.canvas.realWindow,"CURR(A)",0.25f+0.5f*lineIx,0.40f,0.24f,0.24f);
				GIGG_SetScale(&this->psuIGauge[lineIx],0.0f,10.0f);
				GPAN_AddInstrument(&this->psuPanel,&this->psuIGauge[lineIx].canvas);
				//GICH_Chart_t psuIChart[PSU_CHANNELS_NO];
				GICH_Init(&this->psuIChart[lineIx],&this->psuPanel.canvas.realWindow,"CURR(I)",0.01f+0.5f*lineIx,0.01f,0.48f,0.38f);
				GICH_SetScale(&this->psuIChart[lineIx],0.0f,1.0f);
				GPAN_AddInstrument(&this->psuPanel,&this->psuIChart[lineIx].canvas);
			}
		}
	}
}

void SMFD_Execute(SMFD_CarMfd_t *this)
{
	//printf("SMFD_Execute\n");
	GMFD_Execute(&this->mfd);
}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
