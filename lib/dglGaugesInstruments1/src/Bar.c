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
void GIBR_RecalculateGeometry(GIBR_Bar_t *this);

/* public functions -----------------------------------------------------------*/
void GIBR_Init(GIBR_Bar_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy,bool_t isFromCenter)
{
	printf("GIBR_Init\n");

	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	0.25f,0.65f,0.5f,0.2f,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GIBR_Render,GIBR_Execute,this);

	this->isFromCenter=isFromCenter;

	/* values */
	this->min=0.0f;
	this->max=1.0f;
	this->nDivs=0;
	this->value=0.5f;

	/* initalise sub elements*/
	GLAB_Init(&this->mainLabel,&this->canvas.realWindow,	0.0f, 0.8f,	1.0f, 0.2f,title,GLAB_JUSTIFICATION_CENTER);
	GLAB_Init(&this->minLabel,&this->canvas.realWindow,		0.0f, 0.1f,	0.33f, 0.2f,"-",GLAB_JUSTIFICATION_LEFT);
	GLAB_Init(&this->valueLabel,&this->canvas.realWindow,	0.33f, 0.0f,	0.33f, 0.2f,"-",GLAB_JUSTIFICATION_CENTER);
	GLAB_Init(&this->maxLabel,&this->canvas.realWindow,		0.66f, 0.1f,	0.33f, 0.2f,"-",GLAB_JUSTIFICATION_RIGHT);

	GIBR_SetColour(this,&GCOL_Green,&GCOL_Green_Half);


	GIBR_RecalculateGeometry(this);
}

void GIBR_SetColour(GIBR_Bar_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	GCOL_CopyFrom(&this->fore,fore);
	GCOL_CopyFrom(&this->back,back);
	GLAB_SetColour(&this->mainLabel,&GCOL_Green,&GCOL_Green_Half,M_FALSE);
	GLAB_SetColour(&this->minLabel,&GCOL_Green_Half,&GCOL_Green_Half,M_FALSE);
	GLAB_SetColour(&this->maxLabel,&GCOL_Green_Half,&GCOL_Green_Half,M_FALSE);
	GLAB_SetColour(&this->valueLabel,&GCOL_Green,&GCOL_Green_Half,M_FALSE);
}

void GIBR_SetMinMaxNDiv(GIBR_Bar_t *this,float32_t min,float32_t max,uint16_t nDivs)
{
	char tempText[80];
	this->min=min;
	this->max=max;
	this->nDivs=nDivs;

	snprintf(&tempText[0],80,"%f",min);
	GLAB_SetText(&this->minLabel,&tempText[0]);
	snprintf(&tempText[0],80,"%f",max);
	GLAB_SetText(&this->maxLabel,&tempText[0]);
}

void GIBR_Execute(void *thisVoid)
{
	if (thisVoid==NULL) return;
	printf("GIBR_Execute\n");
}

void GIBR_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//printf("GIBR_Render\n");
	GIBR_Bar_t *this=(GIBR_Bar_t*)thisVoid;

	/* contour */
	GCOL_SetRenderColour(&this->canvas.backColour);
	GWIN_Render(&this->barContour);

	/* labels */
	GLAB_Render(&this->mainLabel);
	GLAB_Render(&this->minLabel);
	GLAB_Render(&this->maxLabel);
	GLAB_Render(&this->valueLabel);

	/* for divisions */
	GCOL_SetRenderColour(&this->canvas.backColour);
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	GLNS_Init(&ls1,&ps1[0]);
	float32_t divStep=this->barContour.length.x/this->nDivs;
	GLNS_AddPoint(&ls1,0.0f,1.0f);
	GLNS_AddPoint(&ls1,1.0f,1.0f);


	if (M_TRUE == this->isVertical)
	{
		divStep=0.8/this->nDivs;
		//TODO
	}
	else
	{
		divStep=0.8f/this->nDivs;
		for (uint16_t divIx=0;divIx<=this->nDivs;divIx++)
		{
			ps1[0].x=0.1f+divStep*divIx;			ps1[1].x=ps1[0].x;
			ps1[0].y=0.4f-0.1f;
			ps1[1].y=0.6f+0.1f;
			GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&ps1[0]);
			GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&ps1[1]);
			GLNS_Render(&ls1);
		}

	}
}

/* local functions ------------------------------------------------------------*/
void GIBR_RecalculateGeometry(GIBR_Bar_t *this)
{
	/* assumes canvas initalised */
	if (this->canvas.window.length.y>=this->canvas.window.length.x)
	{
		this->isVertical = M_TRUE;
		//TODO
	}
	else
	{
		this->isVertical = M_FALSE;
		GWIN_Init(&this->barContour,0.1f,0.4f,0.8f,0.2f);
	}

	/* apply canvas to subelements */
	GWIN_ApplyParentWindow(&this->barContour,&this->canvas.realWindow);
	GLAB_ApplyParentWindow(&this->mainLabel,&this->canvas.realWindow);
	GLAB_ApplyParentWindow(&this->minLabel,&this->canvas.realWindow);
	GLAB_ApplyParentWindow(&this->maxLabel,&this->canvas.realWindow);
	GLAB_ApplyParentWindow(&this->valueLabel,&this->canvas.realWindow);

}

/* end */
