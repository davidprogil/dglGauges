/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Chart.h>

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
void GICH_Execute(void *thisVoid);
void GICH_Render(void *thisVoid);
void GICH_Reshape(void *thisVoid);

/* public functions -----------------------------------------------------------*/
void GICH_Init(GICH_Chart_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	printf("GICH_Init\n");

	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GICH_Render,GICH_Execute,this);
	GCNV_SetColour(&this->canvas,&GCOL_Green,&GCOL_Green_Half,M_FALSE);

	/* indicator*/
	GIND_Init(&this->indicator);


	/* labels */
	GLAB_Init(&this->titleLabel,&this->canvas.realWindow,	0.0f, 0.9f,		1.0f,  0.1f,title,	GLAB_JUSTIFICATION_CENTER);
	GLAB_Init(&this->valueLabel,&this->canvas.realWindow,	0.0f, 0.8f,		1.0f,  0.1f,(char*)"-",		GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->titleLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->valueLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetVerticalAlignment(&this->titleLabel, GLAB_ALIGN_CENTER);
	GLAB_SetVerticalAlignment(&this->valueLabel, GLAB_ALIGN_CENTER);
	//	GCNV_SetRenderFlags(&this->titleLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	//	GCNV_SetRenderFlags(&this->valueLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	//	GCNV_SetRenderFlags(&this->canvas,M_TRUE,M_FALSE,M_FALSE);

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

	/* title */
	GLAB_SetText(&this->titleLabel,title);
	GLAB_SetText(&this->valueLabel,(char*)"-");

	/* title */
	GLAB_SetText(&this->titleLabel,title);
	GLAB_SetText(&this->valueLabel,(char*)"-");

	/* values */
	this->value=0;
	this->samplesNo=0;
	GICH_SetScale(this,0.0f,10.0f);

	GICH_Reshape(this);
}

void GICH_SetScale(GICH_Chart_t *this,float32_t origin,float32_t scale)
{
	this->origin=origin;
	this->scale=scale;

	char tempText[80];
	snprintf(&tempText[0],80,"%4.3f",this->scale/GICH_DIVS_NO);
	GLAB_SetText(&this->instrumentLabels[0],&tempText[0]);

	snprintf(&tempText[0],80,"%4.3f",this->origin);
	GLAB_SetText(&this->originLabel,&tempText[0]);
}


/* local functions ------------------------------------------------------------*/
void GICH_Execute(void *thisVoid)
{
	//printf("GICH_Execute\n");
	if (thisVoid==NULL) return;
	GICH_Chart_t *this=(GICH_Chart_t*)thisVoid;
	GIND_Execute(&this->indicator);
}

void GICH_Render(void *thisVoid)
{
	//printf("GICH_Render\n");
	if (thisVoid==NULL) return;
	GICH_Chart_t *this=(GICH_Chart_t*)thisVoid;

	/* background */
	GCOL_SetRenderColour(&this->canvas.backColour);
	//GLNS_Render(&this->lineAround);
	for (uint16_t lineIx=0;lineIx<GICH_DIVS_NO;lineIx++)
	{
		GLNS_Render(&this->lineDis[lineIx]);
	}

	/* labels */
	GCNV_Render(&this->instrumentLabels[0].canvas);
	GCNV_Render(&this->instrumentLabels[1].canvas);
	GCNV_Render(&this->originLabel.canvas);

	/* labels */
	GCNV_Render(&this->titleLabel.canvas);
	GCNV_Render(&this->valueLabel.canvas);
	/* value */
	if (GIND_GetDataFloat32(&this->indicator,&this->value))
	{
		char tempText[80];
		snprintf(&tempText[0],80,"%3.2f",this->value);
		GLAB_SetText(&this->valueLabel,&tempText[0]);

		if (this->samplesNo<GICH_SEGMENTS_NO)
		{
			this->values[this->samplesNo]=this->value;
			this->samplesNo++;
		}
		else
		{
			//rotate values
			for (uint16_t sampleIx=0;sampleIx<GICH_SEGMENTS_NO-1;sampleIx++)
			{
				this->values[sampleIx]=this->values[sampleIx+1];
			}
			this->values[GICH_SEGMENTS_NO-1]=this->value;
		}


		if (this->samplesNo>1)
		{
			//GLNS_LineStrip_t valueStrip;
			//GLNS_LineStrip_t pointsValueStrip[GICH_SEGMENTS_NO];
			GLNS_Init(&this->valueStrip,&this->pointsValueStrip[0]);
			for (uint16_t sampleIx=0;sampleIx<this->samplesNo;sampleIx++)
			{
				GLNS_AddPoint(&this->valueStrip,
						sampleIx*1.0f/((this->samplesNo-1)*1.0f),
						(this->values[sampleIx]-this->origin)/this->scale);
				GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsValueStrip[sampleIx]);
			}
			GLNS_Render(&this->valueStrip);
		}
	}

	/* axis */
	GLNS_Render(&this->originV);
	GLNS_Render(&this->originH);

}

void GICH_Reshape(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GICH_Chart_t *this=(GICH_Chart_t*)thisVoid;
	float32_t lineFloat;
	//GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	//GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
	for (uint16_t lineIx=0;lineIx<GICH_DIVS_NO;lineIx++)
	{
		GLNS_Init(&this->lineDis[lineIx],&this->pointsDivs[lineIx*2]);
		lineFloat=(lineIx+1)*1.0f/GICH_DIVS_NO;
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
}

/* end */
