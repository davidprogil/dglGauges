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
#include <GGI2_Bitmap.h>

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
void G2BM_Execute(void *thisVoid);
void G2BM_Render(void *thisVoid);
void G2BM_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
void G2BM_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back);

/* public functions -----------------------------------------------------------*/
void G2BM_Init(G2BM_Bitmap_t *this,GWIN_Window_t *parentWindow,char *title,uint16_t rowsNo,uint16_t colsNo,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//printf("G2BM_Init\n");
	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,G2BM_Render,G2BM_Execute,G2BM_Reshape,G2BM_Recolour,this);
	GCNV_SetColour(&this->canvas,GCOL_FORE_COLOUR,GCOL_BACK_COLOUR,M_TRUE);

	this->rowsNo=rowsNo;
	this->colsNo=colsNo;
	G2BM_Pixel_t *pix;
	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		for (uint16_t lIx=0;lIx<this->colsNo;lIx++)
		{
			pix=&this->bitmap[rIx][lIx];
			pix->r=(rIx+lIx+0)%3*255/3;
			pix->g=(rIx+lIx+1)%3*255/3;
			pix->b=(rIx+lIx+2)%3*255/3;
		}
	}
}

void G2BM_SetPixelColour(G2BM_Bitmap_t *this,uint16_t rowIx, uint16_t colIx, uint8_t r,uint8_t g,uint8_t b)
{
	if ((rowIx<this->rowsNo)&&(colIx<this->colsNo))
	{
		this->bitmap[rowIx][colIx].r=r;
		this->bitmap[rowIx][colIx].g=g;
		this->bitmap[rowIx][colIx].b=b;
	}
}

/* local functions ------------------------------------------------------------*/
void G2BM_Execute(void *thisVoid)
{
	//printf("G2BM_Execute\n");
	if (thisVoid==NULL) return;

}

void G2BM_Render(void *thisVoid)
{
	//printf("G2BM_Render\n");
	if (thisVoid==NULL) return;
	G2BM_Bitmap_t *this=(G2BM_Bitmap_t*)thisVoid;
	G2BM_Pixel_t *pix;
	GCOL_Colour_t colour;
	GLNS_LineStrip_t square;
	GPNT_Point_t points[5];
	float32_t x,y;
	float32_t dx=this->canvas.realWindow.length.x/this->rowsNo;
	float32_t dy=this->canvas.realWindow.length.y/this->colsNo;
	for (uint16_t rIx=0;rIx<this->rowsNo;rIx++)
	{
		x=this->canvas.realWindow.origin.x+dx*rIx;
		for (uint16_t lIx=0;lIx<this->colsNo;lIx++)
		{
			y=this->canvas.realWindow.origin.y+dy*lIx;

			pix=&this->bitmap[rIx][lIx];
			//colour
			colour.r=pix->r;	colour.g=pix->g; 	colour.b=pix->b;	colour.a=1.0;
			GCOL_SetRenderColour(&colour);
			//geometry
			GLNS_Init(&square,points);
			GLNS_AddPoint(&square,x,y);
			GLNS_AddPoint(&square,x+dx,y);
			GLNS_AddPoint(&square,x+dx,y+dy);
			GLNS_AddPoint(&square,x,y+dy);
			GLNS_AddPoint(&square,x,y);
			GLNS_RenderFill(&square);
		}
	}

	//printf("totalRowsNo %d\n",this->totalRowsNo);
	//	uint16_t indicatorsNo=0;
	//	float32_t labelWidth=1.0f;
	//
	//	/* background */
	//	GCOL_SetRenderColour(&this->canvas.backColour);
	//	//GLNS_Render(&this->lineAround);
	//	for (uint16_t lineIx=0;lineIx<G2BM_DIVS_NO;lineIx++)
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
	//	for (uint16_t indicatorIx=0;indicatorIx<G2BM_INDICATOR_MAX_NO;indicatorIx++)
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
	//			//GLNS_LineStrip_t pointsValueStrip[G2BM_SEGMENTS_NO];
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
void G2BM_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	G2BM_Bitmap_t *this=(G2BM_Bitmap_t*)thisVoid;
	(void)this;
	//	float32_t lineFloat;
	//	//GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	//	//GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
	//	for (uint16_t lineIx=0;lineIx<G2BM_DIVS_NO;lineIx++)
	//	{
	//		GLNS_Init(&this->lineDis[lineIx],&this->pointsDivs[lineIx*2]);
	//		lineFloat=(lineIx+1)*1.0f/G2BM_DIVS_NO;
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
	//	for (uint16_t indicatorIx=0;indicatorIx<G2BM_INDICATOR_MAX_NO;indicatorIx++)
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

void G2BM_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	if (thisVoid==NULL) return;
	G2BM_Bitmap_t *this=(G2BM_Bitmap_t*)thisVoid;
	(void)this;
	//	for (uint16_t indicatorIx=0;indicatorIx<G2BM_INDICATOR_MAX_NO;indicatorIx++)
	//	{
	//		GCNV_Recolour(&this->titleLabel[indicatorIx].canvas,fore,back);
	//		GCNV_Recolour(&this->valueLabel[indicatorIx].canvas,fore,back);
	//	}
	//	GCNV_Recolour(&this->instrumentLabels[0].canvas,back,back);
	//	GCNV_Recolour(&this->instrumentLabels[1].canvas,back,back);
	//	GCNV_Recolour(&this->originLabel.canvas,back,back);

}


/* end */
