/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <GGI2_MultiChart.h>

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
void G2CH_Execute(void *thisVoid);
void G2CH_Render(void *thisVoid);
void G2CH_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
void G2CH_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back);

/* public functions -----------------------------------------------------------*/
void G2CH_Init(G2CH_MultiChart_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{

	//DEBUG printf("G2CH_Init\n");


	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,G2CH_Render,G2CH_Execute,G2CH_Reshape,G2CH_Recolour,this);
	GCNV_SetColour(&this->canvas,&GCOL_Green,&GCOL_Green_Half,M_FALSE);



	for (uint16_t indicatorIx=0;indicatorIx<G2CH_INDICATOR_MAX_NO;indicatorIx++)
	{
		/* indicator*/
		GIND_Init(&this->indicator[indicatorIx]);

		/* labels */
		GLAB_Init(&this->titleLabel[indicatorIx],&this->canvas.realWindow,	0.0f, 0.9f,		1.0f,  0.1f,title,	GLAB_JUSTIFICATION_CENTER);
		GLAB_Init(&this->valueLabel[indicatorIx],&this->canvas.realWindow,	0.0f, 0.8f,		1.0f,  0.1f,(char*)"-",		GLAB_JUSTIFICATION_CENTER);
		GLAB_SetCharSizeType(&this->titleLabel[indicatorIx],GLAB_TEXT_SIZE_FIXED,0.02f);
		GLAB_SetCharSizeType(&this->valueLabel[indicatorIx],GLAB_TEXT_SIZE_FIXED,0.02f);
		GLAB_SetVerticalAlignment(&this->titleLabel[indicatorIx], GLAB_ALIGN_CENTER);
		GLAB_SetVerticalAlignment(&this->valueLabel[indicatorIx], GLAB_ALIGN_CENTER);
		/* title */
		GLAB_SetText(&this->titleLabel[indicatorIx],title);
		GLAB_SetText(&this->valueLabel[indicatorIx],(char*)"-");
		//	GCNV_SetRenderFlags(&this->titleLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
		//	GCNV_SetRenderFlags(&this->valueLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
		//	GCNV_SetRenderFlags(&this->canvas,M_TRUE,M_FALSE,M_FALSE);

		/* values */
		this->value[indicatorIx]=0;
		this->samplesNo[indicatorIx]=0;
	}

	/* instrumentLabels[GIGG_LABELS_MAX_NO] */
	GLAB_Init(&this->instrumentLabels[0],&this->canvas.realWindow,	0.0f, 0.5f,		1.0f,  0.1f,"-",		GLAB_JUSTIFICATION_CENTER);
	GLAB_Init(&this->instrumentLabels[1],&this->canvas.realWindow,	0.0f, 0.4f,		1.0f,  0.1f,"P/DIV",	GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->instrumentLabels[0],GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->instrumentLabels[1],GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetVerticalAlignment(&this->instrumentLabels[0], GLAB_ALIGN_CENTER);
	GLAB_SetVerticalAlignment(&this->instrumentLabels[1], GLAB_ALIGN_CENTER);
	GLAB_SetColour(&this->instrumentLabels[0],&this->canvas.backColour,&this->canvas.fillColour,M_FALSE);
	GLAB_SetColour(&this->instrumentLabels[1],&this->canvas.backColour,&this->canvas.fillColour,M_FALSE);

	GLAB_Init(&this->originLabel,&this->canvas.realWindow,	0.0f, 0.0f,		1.0f,  0.1f,"-",		GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->originLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetVerticalAlignment(&this->originLabel, GLAB_ALIGN_CENTER);
	GLAB_SetColour(&this->originLabel,&this->canvas.backColour,&this->canvas.fillColour,M_FALSE);


	G2CH_SetScale(this,0.0f,10.0f);

	G2CH_Reshape(this,&this->canvas.realWindow);
}

void G2CH_SetIndicatorName(G2CH_MultiChart_t *this,uint16_t indicatorId,char *title)
{
	GLAB_SetText(&this->titleLabel[indicatorId],title);
}

void G2CH_SetScale(G2CH_MultiChart_t *this,float32_t origin,float32_t scale)
{
	this->origin=origin;
	this->scale=scale;

	char tempText[80];
	snprintf(&tempText[0],80,"%4.3f",this->scale/G2CH_DIVS_NO);
	GLAB_SetText(&this->instrumentLabels[0],&tempText[0]);

	snprintf(&tempText[0],80,"%4.3f",this->origin);
	GLAB_SetText(&this->originLabel,&tempText[0]);
}


/* local functions ------------------------------------------------------------*/
void G2CH_Execute(void *thisVoid)
{
	//printf("G2CH_Execute\n");
	if (thisVoid==NULL) return;
	G2CH_MultiChart_t *this=(G2CH_MultiChart_t*)thisVoid;

	for (uint16_t indicatorIx=0;indicatorIx<G2CH_INDICATOR_MAX_NO;indicatorIx++)
	{
		GIND_Execute(&this->indicator[indicatorIx]);
		//printf("G2CH_Execute %d %p %d\n",indicatorIx,this->indicator[indicatorIx].inputData,this->indicator[indicatorIx].isInitialised);
		/* value */
		if (GIND_GetDataFloat32(&this->indicator[indicatorIx],&this->value[indicatorIx]))
		{
			//printf("G2CH_Execute xxx \n");
			char tempText[10];
			snprintf(&tempText[0],10,"%3.2f",this->value[indicatorIx]);
			GLAB_SetText(&this->valueLabel[indicatorIx],&tempText[0]);

			if (this->samplesNo[indicatorIx]<G2CH_SEGMENTS_NO)
			{
				this->values[indicatorIx][this->samplesNo[indicatorIx]]=this->value[indicatorIx];
				this->samplesNo[indicatorIx]++;
			}
			else
			{
				//rotate values
				for (uint16_t sampleIx=0;sampleIx<G2CH_SEGMENTS_NO-1;sampleIx++)
				{
					this->values[indicatorIx][sampleIx]=this->values[indicatorIx][sampleIx+1];
				}
				this->values[indicatorIx][G2CH_SEGMENTS_NO-1]=this->value[indicatorIx];
			}
		}
	}
}

void G2CH_Render(void *thisVoid)
{
	//printf("G2CH_Render\n");
	if (thisVoid==NULL) return;
	G2CH_MultiChart_t *this=(G2CH_MultiChart_t*)thisVoid;
	uint16_t indicatorsNo=0;
	float32_t labelWidth=1.0f;

	/* background */
	GCOL_SetRenderColour(&this->canvas.backColour);
	//GLNS_Render(&this->lineAround);
	for (uint16_t lineIx=0;lineIx<G2CH_DIVS_NO;lineIx++)
	{
		GLNS_Render(&this->lineDis[lineIx]);
	}

	/* labels */
	GCNV_Render(&this->instrumentLabels[0].canvas);
	GCNV_Render(&this->instrumentLabels[1].canvas);
	GCNV_Render(&this->originLabel.canvas);

	/* count no indicators */
	for (uint16_t indicatorIx=0;indicatorIx<G2CH_INDICATOR_MAX_NO;indicatorIx++)
	{
		if (GIND_IsInitialised(&this->indicator[indicatorIx]))
		{
			indicatorsNo++;
		}
	}
	if (indicatorsNo>=0)
	{
		labelWidth=1.0f/(1.0f*indicatorsNo);
	}

	/* labels */
	for (uint16_t indicatorIx=0;indicatorIx<indicatorsNo;indicatorIx++)
	{
		/* set position */
		GCNV_SetPosition(&this->titleLabel[indicatorIx].canvas,
				0.0f+indicatorIx*labelWidth,	this->titleLabel[indicatorIx].canvas.window.origin.y,
				labelWidth,						this->titleLabel[indicatorIx].canvas.window.length.y,
				&this->canvas.realWindow);
		GCNV_SetPosition(&this->valueLabel[indicatorIx].canvas,
						0.0f+indicatorIx*labelWidth,	this->valueLabel[indicatorIx].canvas.window.origin.y,
						labelWidth,						this->valueLabel[indicatorIx].canvas.window.length.y,
						&this->canvas.realWindow);

		GCNV_Render(&this->titleLabel[indicatorIx].canvas);
		GCNV_Render(&this->valueLabel[indicatorIx].canvas);


		if (this->samplesNo[indicatorIx]>1)
		{
			//GLNS_LineStrip_t valueStrip;
			//GLNS_LineStrip_t pointsValueStrip[G2CH_SEGMENTS_NO];
			GLNS_Init(&this->valueStrip[indicatorIx],&this->pointsValueStrip[indicatorIx][0]);
			for (uint16_t sampleIx=0;sampleIx<this->samplesNo[indicatorIx];sampleIx++)
			{
				GLNS_AddPoint(&this->valueStrip[indicatorIx],
						sampleIx*1.0f/((this->samplesNo[indicatorIx]-1)*1.0f),
						(this->values[indicatorIx][sampleIx]-this->origin)/this->scale);
				GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsValueStrip[indicatorIx][sampleIx]);
			}
			GLNS_Render(&this->valueStrip[indicatorIx]);
		}
	}

	/* axis */
	GLNS_Render(&this->originV);
	GLNS_Render(&this->originH);

}
void G2CH_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	G2CH_MultiChart_t *this=(G2CH_MultiChart_t*)thisVoid;
	float32_t lineFloat;
	//GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	//GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
	for (uint16_t lineIx=0;lineIx<G2CH_DIVS_NO;lineIx++)
	{
		GLNS_Init(&this->lineDis[lineIx],&this->pointsDivs[lineIx*2]);
		lineFloat=(lineIx+1)*1.0f/G2CH_DIVS_NO;
		GLNS_AddPoint(&this->lineDis[lineIx],0.0f,lineFloat);
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2]);
		GLNS_AddPoint(&this->lineDis[lineIx],1.0f,lineFloat);
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2+1]);
	}
	//	GLNS_LineStrip_t originV;
	//	GPNT_Point_t pointsOriginV[2];
	GLNS_Init(&this->originV,&this->pointsOriginV[0]);
	GLNS_AddPoint(&this->originV,0.0f,0.0f);
	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginV[0]);
	GLNS_AddPoint(&this->originV,0.0f,1.0f);
	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginV[1]);

	//	GLNS_LineStrip_t originH;
	//	GPNT_Point_t pointsOriginH[2];
	GLNS_Init(&this->originH,&this->pointsOriginH[0]);
	GLNS_AddPoint(&this->originH,0.0f,0.0f);
	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginH[0]);
	GLNS_AddPoint(&this->originH,1.0f,0.0f);
	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginH[1]);

	for (uint16_t indicatorIx=0;indicatorIx<G2CH_INDICATOR_MAX_NO;indicatorIx++)
	{
		//GLAB_Label_t  titleLabel;
		GCNV_Reshape(&this->titleLabel[indicatorIx].canvas,&this->canvas.realWindow);
		//GLAB_Label_t  valueLabel;
		GCNV_Reshape(&this->valueLabel[indicatorIx].canvas,&this->canvas.realWindow);
	}
	//GLAB_Label_t  instrumentLabels[2];
	GCNV_Reshape(&this->instrumentLabels[0].canvas,&this->canvas.realWindow);
	GCNV_Reshape(&this->instrumentLabels[1].canvas,&this->canvas.realWindow);
	//GLAB_Label_t  originLabel;
	GCNV_Reshape(&this->originLabel.canvas,&this->canvas.realWindow);
}

void G2CH_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	if (thisVoid==NULL) return;
	G2CH_MultiChart_t *this=(G2CH_MultiChart_t*)thisVoid;
	for (uint16_t indicatorIx=0;indicatorIx<G2CH_INDICATOR_MAX_NO;indicatorIx++)
	{
		GCNV_Recolour(&this->titleLabel[indicatorIx].canvas,fore,back);
		GCNV_Recolour(&this->valueLabel[indicatorIx].canvas,fore,back);
	}
	GCNV_Recolour(&this->instrumentLabels[0].canvas,back,back);
	GCNV_Recolour(&this->instrumentLabels[1].canvas,back,back);
	GCNV_Recolour(&this->originLabel.canvas,back,back);

}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
