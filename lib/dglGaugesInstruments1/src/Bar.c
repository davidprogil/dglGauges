/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Bar.h>

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
void GIBR_Execute(void *thisVoid);
void GIBR_Render(void *thisVoid);
void GIBR_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
/* public functions -----------------------------------------------------------*/
void GIBR_Init(GIBR_Bar_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//DEBUG printf("GIBR_Init\n");

	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GIBR_Render,GIBR_Execute,GIBR_Reshape,this);

	/* indicator*/
	GIND_Init(&this->indicator);

	/* values */
	this->min=0.0f;
	this->max=1.0f;
	this->reference=0.0f;
	this->nDivs=0;
	this->value=0.5f;

	/* assumes canvas initalised */
	if (this->canvas.window.length.y>=this->canvas.window.length.x)
	{ 	/* VERTICAL */
		this->isVertical = M_TRUE;
		GWIN_Init(&this->barContour,	0.4f,	0.12f,	0.2f,	0.58f);
		GWIN_Init(&this->barValue,		0.4f,	0.12f,	0.2f,	0.58f);

		/* initalise sub elements*/
		GLAB_Init(&this->mainLabel,	&this->canvas.realWindow,	0.0f,  0.9f,	1.0f,  0.1f,(char*)"-",GLAB_JUSTIFICATION_CENTER);
		GLAB_Init(&this->valueLabel,&this->canvas.realWindow,	0.0f,  0.8f,	1.0f,  0.1f,(char*)"-",GLAB_JUSTIFICATION_CENTER);

		GLAB_Init(&this->maxLabel,	&this->canvas.realWindow,	0.0f, 0.7f,		1.0f, 0.1f,	(char*)"-",GLAB_JUSTIFICATION_CENTER);
		GLAB_Init(&this->minLabel,	&this->canvas.realWindow,	0.0f, 0.02f,	1.0f, 0.1f,	(char*)"-",GLAB_JUSTIFICATION_CENTER);

	}
	else
	{	/* HORIZONTAL */
		this->isVertical = M_FALSE;
		GWIN_Init(&this->barContour,	0.1f,	0.3f,	0.8f,	0.2f);
		GWIN_Init(&this->barValue,		0.1f,	0.3f,	0.8f,	0.2f);

		/* initalise sub elements*/
		GLAB_Init(&this->mainLabel,	&this->canvas.realWindow,	0.0f, 	0.8f,	1.0f,  0.1f,(char*)"-",GLAB_JUSTIFICATION_CENTER);
		GLAB_Init(&this->valueLabel,&this->canvas.realWindow,	0.33f, 	0.6f,	0.33f, 0.1f,(char*)"-",GLAB_JUSTIFICATION_CENTER);
		GLAB_Init(&this->minLabel,	&this->canvas.realWindow,	0.0f, 	0.08f,	0.33f, 0.1f,(char*)"-",GLAB_JUSTIFICATION_LEFT);
		GLAB_Init(&this->maxLabel,	&this->canvas.realWindow,	0.66f, 	0.08f,	0.33f, 0.1f,(char*)"-",GLAB_JUSTIFICATION_RIGHT);
	}

	GLAB_SetCharSizeType(&this->mainLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->minLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->valueLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->maxLabel,GLAB_TEXT_SIZE_FIXED,0.02f);

	GIBR_Reshape(this,&this->canvas.realWindow);

	/* title */
	GLAB_SetText(&this->mainLabel,title);

	GIBR_SetColour(this,&GCOL_Green,&GCOL_Green_Half);


}

void GIBR_SetColour(GIBR_Bar_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	GCOL_CopyFrom(&this->fore,fore);
	GCOL_CopyFrom(&this->back,back);
	GLAB_SetColour(&this->mainLabel,fore,back,M_FALSE);
	GLAB_SetColour(&this->minLabel,back,back,M_FALSE);
	GLAB_SetColour(&this->maxLabel,back,back,M_FALSE);
	GLAB_SetColour(&this->valueLabel,fore,back,M_FALSE);
	GCNV_SetColour(&this->canvas,fore,back,M_TRUE);
}

void GIBR_SetMinMaxNDiv(GIBR_Bar_t *this,float32_t min,float32_t max,float32_t reference,uint16_t nDivs)
{
	char tempText[80];
	this->min=min;
	this->max=max;
	this->reference=reference;
	this->nDivs=nDivs;
	this->value=reference;

	snprintf(&tempText[0],80,"%4.3f",min);
	GLAB_SetText(&this->minLabel,&tempText[0]);
	snprintf(&tempText[0],80,"%4.3f",max);
	GLAB_SetText(&this->maxLabel,&tempText[0]);
}

/* local functions ------------------------------------------------------------*/
void GIBR_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	//printf("GIBR_Execute\n");
	GIBR_Bar_t *this=(GIBR_Bar_t*)thisVoid;

	/* assumes canvas initalised */
	if (this->canvas.window.length.y>=this->canvas.window.length.x)
	{ 	/* VERTICAL */
		this->isVertical = M_TRUE;
		GWIN_Init(&this->barContour,	0.4f,	0.12f,	0.2f,	0.58f);
		GWIN_Init(&this->barValue,		0.4f,	0.12f,	0.2f,	0.58f);

	}
	else
	{	/* HORIZONTAL */
		this->isVertical = M_FALSE;
		GWIN_Init(&this->barContour,	0.1f,	0.3f,	0.8f,	0.2f);
		GWIN_Init(&this->barValue,		0.1f,	0.3f,	0.8f,	0.2f);
	}



	/* apply canvas to subelements */
	GWIN_ApplyParentWindow(&this->barContour,&this->canvas.realWindow);

	//GWIN_Window_t barValue;
	//GLAB_Label_t  mainLabel;
	GCNV_Reshape(&this->mainLabel.canvas,&this->canvas.realWindow);
	//GLAB_Label_t  minLabel;
	GCNV_Reshape(&this->minLabel.canvas,&this->canvas.realWindow);
	//GLAB_Label_t  maxLabel;
	GCNV_Reshape(&this->maxLabel.canvas,&this->canvas.realWindow);
	//GLAB_Label_t  valueLabel;
	GCNV_Reshape(&this->valueLabel.canvas,&this->canvas.realWindow);

	//GIBR_SetMinMaxNDiv(GIBR_Bar_t *this,float32_t min,float32_t max,float32_t reference,uint16_t nDivs)
	GIBR_SetMinMaxNDiv(this,this->min,this->max,this->reference,this->nDivs);
}


void GIBR_Execute(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//printf("GIBR_Execute\n");
	GIBR_Bar_t *this=(GIBR_Bar_t*)thisVoid;

	GIND_Execute(&this->indicator);
}

void GIBR_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//printf("GIBR_Render\n");
	GIBR_Bar_t *this=(GIBR_Bar_t*)thisVoid;

	/* contour */
	GCOL_SetRenderColour(&this->back);
	GWIN_Render(&this->barContour);

	if (GIND_GetDataFloat32(&this->indicator,&this->value))
	{
		char tempText[80];
		snprintf(&tempText[0],80,"%4.3f",this->value);
		GLAB_SetText(&this->valueLabel,&tempText[0]);
	}

	/* labels */
	GCNV_Render(&this->mainLabel.canvas);
	GCNV_Render(&this->minLabel.canvas);
	GCNV_Render(&this->maxLabel.canvas);
	GCNV_Render(&this->valueLabel.canvas);


	/* for divisions */
	if (this->nDivs>0)
	{
		GCOL_SetRenderColour(&this->back);
		GLNS_LineStrip_t ls1;
		GPNT_Point_t ps1[2];
		GLNS_Init(&ls1,&ps1[0]);
		float32_t divStep=this->barContour.length.x/this->nDivs;
		GLNS_AddPoint(&ls1,0.0f,1.0f);
		GLNS_AddPoint(&ls1,1.0f,1.0f);

		if (M_TRUE == this->isVertical)
		{
			divStep=this->barContour.length.y/this->nDivs;
			ps1[0].x=this->barContour.origin.x-this->barContour.length.x*0.2f;
			ps1[1].x=ps1[0].x+this->barContour.length.x*1.4f;
			for (uint16_t divIx=0;divIx<=this->nDivs;divIx++)
			{
				if ((divIx!=0)&&(divIx!=this->nDivs))
				{
					ps1[0].y=this->barContour.origin.y+divStep*divIx;
					ps1[1].y=ps1[0].y;
					GLNS_Render(&ls1);
				}
			}
		}
		else
		{
			divStep=this->barContour.length.x/this->nDivs;
			ps1[0].y=this->barContour.origin.y-this->barContour.length.y*0.2f;
			ps1[1].y=ps1[0].y+this->barContour.length.y*1.4f;
			for (uint16_t divIx=0;divIx<=this->nDivs;divIx++)
			{
				if ((divIx!=0)&&(divIx!=this->nDivs))
				{
					ps1[0].x=this->barContour.origin.x+divStep*divIx;
					ps1[1].x=ps1[0].x;
					GLNS_Render(&ls1);
				}
			}

		}
	}/* end of divisions */

	/* value bar */
	if (this->value!=this->reference)
	{
		float32_t length=(this->value-this->reference)/(this->max-this->min);
		float32_t refPos=(this->reference-this->min)/(this->max-this->min);
		if (M_TRUE == this->isVertical)
		{
			GWIN_SetPosition(&this->barValue,	0.0f,refPos,1.0,length);
			GWIN_ApplyParentWindow(&this->barValue,&this->barContour);
		}
		else
		{
			GWIN_SetPosition(&this->barValue,refPos,0.0f,length,1.0f);
			GWIN_ApplyParentWindow(&this->barValue,&this->barContour);
		}
		GCOL_SetRenderColour(&this->fore);
		GWIN_RenderFill(&this->barValue);
	}
}


/* end */
