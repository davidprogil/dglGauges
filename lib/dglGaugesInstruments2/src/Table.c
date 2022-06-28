/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* application includes--------------------------------------------------------*/
#include <GGI2_Table.h>

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
void G2TB_Execute(void *thisVoid);
void G2TB_Render(void *thisVoid);
void G2TB_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
void G2TB_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back);

/* public functions -----------------------------------------------------------*/
void G2TB_Init(G2TB_Table_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//printf("G2TB_Init\n");
	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,G2TB_Render,G2TB_Execute,G2TB_Reshape,G2TB_Recolour,this);
	GCNV_SetColour(&this->canvas,GCOL_FORE_COLOUR,GCOL_BACK_COLOUR,M_FALSE);

	this->injestedRowsCounter=0;
	this->totalRowsNo=0;
	this->startRow=0;
	this->endRow=0;
	this->rowsNo=G2TB_ROW_MAX_NB;
	this->linesNo=G2TB_LINES_PER_ROW_MAX_NB;
	this->isInverseOrder=M_FALSE;
	for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
	{
		this->colsNo[lIx]=G2TB_COLS_MAX_NB;
		for (uint16_t cIx=0;cIx<G2TB_COLS_MAX_NB;cIx++)
		{
			this->sizes[lIx][cIx]=1.0/G2TB_COLS_MAX_NB;
		}
	}
	for (uint16_t lIx=0;lIx<G2TB_LINESTEXT_MAX_NB;lIx++)
	{
		this->linesText[lIx].isDefined=M_FALSE;
	}


}


void G2TB_Init2(G2TB_Table_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{

	GLAB_Label_t *thisLabel;
	float32_t sizeV=1.0f/this->rowsNo/this->linesNo;
	float32_t gap=0.01f;
	shortText_t idText;
	float32_t posH;
	strcpy(idText,"\0");
	float32_t sign=1.0f;
	if (this->isInverseOrder) sign=-1.0f;

	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
		{
			posH=0.0;
			for (uint16_t cIx=0;cIx<this->colsNo[lIx];cIx++)
			{
				thisLabel=&this->row[rIx].line[lIx].col[cIx];
				//sprintf(idText,"R%dL%dI%d",rIx,lIx,cIx);//DEBUG
				GLAB_Init(thisLabel,&this->canvas.realWindow,
						posH, 1.0-sign*(rIx*G2TB_LINES_PER_ROW_MAX_NB+lIx*sign+1.0)*sizeV-(1.0-sign)/2.0*(1.0),
						this->sizes[lIx][cIx]-gap, sizeV-gap,
						idText,	GLAB_JUSTIFICATION_CENTER);
				GLAB_SetVerticalAlignment(thisLabel, GLAB_ALIGN_CENTER);

				posH+=this->sizes[lIx][cIx];
			}
		}
	}
}

void G2TB_AddLine(G2TB_Table_t *this,shortText_t *text)
{

	uint16_t tIx=0;
	uint16_t adjustedIndex=this->injestedRowsCounter%G2TB_LINESTEXT_MAX_NB;
	for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
	{
		for (uint16_t cIx=0;cIx<this->colsNo[lIx];cIx++)
		{
			strcpy(&this->linesText[adjustedIndex].text[tIx][0],text[tIx]);
			tIx++;
		}
	}
	this->linesText[adjustedIndex].isDefined=M_TRUE;
	this->injestedRowsCounter++;

	//if still space in storage
	if (this->totalRowsNo<G2TB_LINESTEXT_MAX_NB)
	{
		this->totalRowsNo++;
	}

	/* if still room to see */
	if (this->totalRowsNo<G2TB_ROW_MAX_NB)
	{
		this->startRow=0;
		this->endRow=this->injestedRowsCounter;
	}
	else
	{
		this->startRow=this->injestedRowsCounter-G2TB_ROW_MAX_NB;
		this->endRow=this->injestedRowsCounter;

	}

	//printf("totalRowsNo %d\n",this->totalRowsNo);
}
/* local functions ------------------------------------------------------------*/
void G2TB_Execute(void *thisVoid)
{
	//printf("G2TB_Execute\n");
	if (thisVoid==NULL) return;
	//G2TB_Table_t *this=(G2TB_Table_t*)thisVoid;


	//float32_t min=FLOAT32_MAX;
	//float32_t max=FLOAT32_MIN;

	//	for (uint16_t indicatorIx=0;indicatorIx<G2TB_INDICATOR_MAX_NO;indicatorIx++)
	//	{
	//		GIND_Execute(&this->indicator[indicatorIx]);
	//		//printf("G2TB_Execute %d %p %d\n",indicatorIx,this->indicator[indicatorIx].inputData,this->indicator[indicatorIx].isInitialised);
	//		/* value */
	//		if (GIND_GetDataFloat32(&this->indicator[indicatorIx],&this->value[indicatorIx]))
	//		{
	//			//printf("G2TB_Execute xxx \n");
	//			char tempText[10];
	//			snprintf(&tempText[0],10,"%3.2f",this->value[indicatorIx]);
	//			GLAB_SetText(&this->valueLabel[indicatorIx],&tempText[0]);
	//
	//			if (this->samplesNo[indicatorIx]<G2TB_SEGMENTS_NO)
	//			{
	//				this->values[indicatorIx][this->samplesNo[indicatorIx]]=this->value[indicatorIx];
	//				this->samplesNo[indicatorIx]++;
	//			}
	//			else
	//			{
	//				//rotate values
	//				for (uint16_t sampleIx=0;sampleIx<G2TB_SEGMENTS_NO-1;sampleIx++)
	//				{
	//					this->values[indicatorIx][sampleIx]=this->values[indicatorIx][sampleIx+1];
	//				}
	//				this->values[indicatorIx][G2TB_SEGMENTS_NO-1]=this->value[indicatorIx];
	//			}
	//		}
	//		if (this->isAutoScale)
	//		{
	//			//printf("min %f max %f\n",min,max);
	//			for (uint16_t sampleIx=0;sampleIx<this->samplesNo[indicatorIx];sampleIx++)
	//			{
	//				min=DGUH_Float32_Min(min,this->values[indicatorIx][sampleIx]);
	//				max=DGUH_Float32_Max(max,this->values[indicatorIx][sampleIx]);
	//			}
	//			G2TB_SetScale(this,min,sqrt((max-min)*(max-min)));
	//		}
	//	}
}

void G2TB_Render(void *thisVoid)
{
	//printf("G2TB_Render\n");
	if (thisVoid==NULL) return;
	G2TB_Table_t *this=(G2TB_Table_t*)thisVoid;

	uint16_t tIx;
	uint16_t adjustedIndex;
	GLAB_Label_t *thisLabel;
	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		tIx=0;
		adjustedIndex=(rIx+this->startRow)%G2TB_LINESTEXT_MAX_NB;
		//printf("adjustedIndex %d startRow %d\n",adjustedIndex,this->startRow);
		if (this->linesText[adjustedIndex].isDefined)
		{
			for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
			{
				for (uint16_t cIx=0;cIx<this->colsNo[lIx];cIx++)
				{
					thisLabel=&this->row[rIx].line[lIx].col[cIx];
					strcpy(thisLabel->text,this->linesText[adjustedIndex].text[tIx++]);
					GCNV_Render(&thisLabel->canvas);
				}
			}
		}
	}
	//printf("totalRowsNo %d\n",this->totalRowsNo);
	//	uint16_t indicatorsNo=0;
	//	float32_t labelWidth=1.0f;
	//
	//	/* background */
	//	GCOL_SetRenderColour(&this->canvas.backColour);
	//	//GLNS_Render(&this->lineAround);
	//	for (uint16_t lineIx=0;lineIx<G2TB_DIVS_NO;lineIx++)
	//	{
	//		GLNS_Render(&this->lineDis[lineIx]);
	//	}
	//
	//	/* labels */
	//	GCNV_Render(&this->instrumentLabels[0].canvas);
	//	GCNV_Render(&this->instrumentLabels[1].canvas);
	//	GCNV_Render(&this->originLabel.canvas);
	//
	//	/* count no indicators */
	//	for (uint16_t indicatorIx=0;indicatorIx<G2TB_INDICATOR_MAX_NO;indicatorIx++)
	//	{
	//		if (GIND_IsInitialised(&this->indicator[indicatorIx]))
	//		{
	//			indicatorsNo++;
	//		}
	//	}
	//	if (indicatorsNo>=0)
	//	{
	//		labelWidth=1.0f/(1.0f*indicatorsNo);
	//	}
	//
	//	/* labels */
	//	for (uint16_t indicatorIx=0;indicatorIx<indicatorsNo;indicatorIx++)
	//	{
	//		/* set position */
	//		GCNV_SetPosition(&this->titleLabel[indicatorIx].canvas,
	//				0.0f+indicatorIx*labelWidth,	this->titleLabel[indicatorIx].canvas.window.origin.y,
	//				labelWidth,						this->titleLabel[indicatorIx].canvas.window.length.y,
	//				&this->canvas.realWindow);
	//		GCNV_SetPosition(&this->valueLabel[indicatorIx].canvas,
	//				0.0f+indicatorIx*labelWidth,	this->valueLabel[indicatorIx].canvas.window.origin.y,
	//				labelWidth,						this->valueLabel[indicatorIx].canvas.window.length.y,
	//				&this->canvas.realWindow);
	//
	//		GCNV_Render(&this->titleLabel[indicatorIx].canvas);
	//		GCNV_Render(&this->valueLabel[indicatorIx].canvas);
	//
	//
	//		if (this->samplesNo[indicatorIx]>1)
	//		{
	//			//GLNS_LineStrip_t valueStrip;
	//			//GLNS_LineStrip_t pointsValueStrip[G2TB_SEGMENTS_NO];
	//			GLNS_Init(&this->valueStrip[indicatorIx],&this->pointsValueStrip[indicatorIx][0]);
	//			for (uint16_t sampleIx=0;sampleIx<this->samplesNo[indicatorIx];sampleIx++)
	//			{
	//				GLNS_AddPoint(&this->valueStrip[indicatorIx],
	//						sampleIx*1.0f/((this->samplesNo[indicatorIx]-1)*1.0f),
	//						(this->values[indicatorIx][sampleIx]-this->origin)/this->scale);
	//				GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsValueStrip[indicatorIx][sampleIx]);
	//			}
	//			GLNS_Render(&this->valueStrip[indicatorIx]);
	//		}
	//	}
	//
	//	GCOL_SetRenderColour(&this->canvas.foreColour);
	//	/* axis */
	//	GLNS_Render(&this->originV);
	//	GLNS_Render(&this->originH);

}
void G2TB_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	G2TB_Table_t *this=(G2TB_Table_t*)thisVoid;

	GLAB_Label_t *thisLabel;
	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
		{
			for (uint16_t cIx=0;cIx<this->colsNo[lIx];cIx++)
			{
				thisLabel=&this->row[rIx].line[lIx].col[cIx];
				GCNV_Reshape(&thisLabel->canvas,&this->canvas.realWindow);
			}
		}
	}
	//	float32_t lineFloat;
	//	//GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	//	//GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
	//	for (uint16_t lineIx=0;lineIx<G2TB_DIVS_NO;lineIx++)
	//	{
	//		GLNS_Init(&this->lineDis[lineIx],&this->pointsDivs[lineIx*2]);
	//		lineFloat=(lineIx+1)*1.0f/G2TB_DIVS_NO;
	//		GLNS_AddPoint(&this->lineDis[lineIx],0.0f,lineFloat);
	//		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2]);
	//		GLNS_AddPoint(&this->lineDis[lineIx],1.0f,lineFloat);
	//		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2+1]);
	//	}
	//
	//	//	GLNS_LineStrip_t originV;
	//	//	GPNT_Point_t pointsOriginV[2];
	//	GLNS_Init(&this->originV,&this->pointsOriginV[0]);
	//	GLNS_AddPoint(&this->originV,0.0f,0.0f);
	//	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginV[0]);
	//	GLNS_AddPoint(&this->originV,0.0f,1.0f);
	//	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginV[1]);
	//
	//	//	GLNS_LineStrip_t originH;
	//	//	GPNT_Point_t pointsOriginH[2];
	//	GLNS_Init(&this->originH,&this->pointsOriginH[0]);
	//	GLNS_AddPoint(&this->originH,0.0f,0.0f);
	//	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginH[0]);
	//	GLNS_AddPoint(&this->originH,1.0f,0.0f);
	//	GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsOriginH[1]);
	//
	//	float32_t charSizeFactor=this->canvas.realWindow.length.y*4.0f;
	//	for (uint16_t indicatorIx=0;indicatorIx<G2TB_INDICATOR_MAX_NO;indicatorIx++)
	//	{
	//		//GLAB_Label_t  titleLabel;
	//		GCNV_Reshape(&this->titleLabel[indicatorIx].canvas,&this->canvas.realWindow);
	//		//GLAB_Label_t  valueLabel;
	//		GCNV_Reshape(&this->valueLabel[indicatorIx].canvas,&this->canvas.realWindow);
	//
	//		GLAB_SetCharSizeType(&this->titleLabel[indicatorIx],GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
	//		GLAB_SetCharSizeType(&this->valueLabel[indicatorIx],GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
	//	}
	//	//GLAB_Label_t  instrumentLabels[2];
	//	GCNV_Reshape(&this->instrumentLabels[0].canvas,&this->canvas.realWindow);
	//	GCNV_Reshape(&this->instrumentLabels[1].canvas,&this->canvas.realWindow);
	//	GLAB_SetCharSizeType(&this->instrumentLabels[0],GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
	//	GLAB_SetCharSizeType(&this->instrumentLabels[1],GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
	//	//GLAB_Label_t  originLabel;
	//	GCNV_Reshape(&this->originLabel.canvas,&this->canvas.realWindow);
	//	GLAB_SetCharSizeType(&this->originLabel,GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
	//	GLAB_SetCharSizeType(&this->originLabel,GLAB_TEXT_SIZE_FIXED,0.02f*charSizeFactor);
}

void G2TB_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	if (thisVoid==NULL) return;
	G2TB_Table_t *this=(G2TB_Table_t*)thisVoid;
	//	for (uint16_t indicatorIx=0;indicatorIx<G2TB_INDICATOR_MAX_NO;indicatorIx++)
	//	{
	//		GCNV_Recolour(&this->titleLabel[indicatorIx].canvas,fore,back);
	//		GCNV_Recolour(&this->valueLabel[indicatorIx].canvas,fore,back);
	//	}
	//	GCNV_Recolour(&this->instrumentLabels[0].canvas,back,back);
	//	GCNV_Recolour(&this->instrumentLabels[1].canvas,back,back);
	//	GCNV_Recolour(&this->originLabel.canvas,back,back);

	GLAB_Label_t *thisLabel;
	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		for (uint16_t lIx=0;lIx<this->linesNo;lIx++)
		{
			for (uint16_t cIx=0;cIx<this->colsNo[lIx];cIx++)
			{
				thisLabel=&this->row[rIx].line[lIx].col[cIx];
				GCNV_Reshape(&thisLabel->canvas,&this->canvas.realWindow);
				GCNV_Recolour(&thisLabel->canvas,fore,back);
			}
		}
	}
}


/* end */
