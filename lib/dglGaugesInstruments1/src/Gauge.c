/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* application includes--------------------------------------------------------*/
#include <Gauge.h>

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
void GIGG_Execute(void *thisVoid);
void GIGG_Render(void *thisVoid);
void GIGG_Reshape(void *thisVoid);

/* public functions -----------------------------------------------------------*/
void GIGG_Init(GIGG_Gauge_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	printf("GIGG_Init\n");

	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GIGG_Render,GIGG_Execute,this);
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
	/* title */
	GLAB_SetText(&this->titleLabel,title);
	GLAB_SetText(&this->valueLabel,(char*)"-");

	/* values */
	this->value=0.0f;
	GIGG_SetScale(this,0.0f,10.0f);

	GIGG_Reshape(this);

}

void GIGG_SetScale(GIGG_Gauge_t *this,float32_t origin,float32_t scale)
{
	this->origin=origin;
	this->scale=scale;

	char tempText[80];
	snprintf(&tempText[0],80,"%4.3f",this->scale/GIGG_DIVS_NO);
	GLAB_SetText(&this->instrumentLabels[0],&tempText[0]);

}

void GIGG_Execute(void *thisVoid)
{
	//printf("GIGG_Execute\n");
	if (thisVoid==NULL) return;
	GIGG_Gauge_t *this=(GIGG_Gauge_t*)thisVoid;
	GIND_Execute(&this->indicator);
}

void GIGG_Render(void *thisVoid)
{
	//printf("GIGG_Render\n");
	if (thisVoid==NULL) return;
	GIGG_Gauge_t *this=(GIGG_Gauge_t*)thisVoid;

	/* background */
	GCOL_SetRenderColour(&this->canvas.backColour);
	GLNS_Render(&this->lineAround);
	for (uint16_t lineIx=0;lineIx<GIGG_DIVS_NO;lineIx++)
	{
		GLNS_Render(&this->lineDis[lineIx]);
	}

	/* labels */
	GCNV_Render(&this->instrumentLabels[0].canvas);
	GCNV_Render(&this->instrumentLabels[1].canvas);

	/* labels */
	GCNV_Render(&this->titleLabel.canvas);
	if (GIND_GetDataFloat32(&this->indicator,&this->value))
	{
		char tempText[80];
		snprintf(&tempText[0],80,"%f",this->value);
		GLAB_SetText(&this->valueLabel,&tempText[0]);
	}
	GCNV_Render(&this->valueLabel.canvas);

	/* pointer */
	float32_t lineFloat;
	if (GIND_GetDataFloat32(&this->indicator,&this->value))
	{
		GLNS_Init(&this->pointer,&this->pointerPoints[0]);
		lineFloat=((this->value-this->origin)/this->scale)*360.0f;
		GLNS_AddPoint(&this->pointer,0.5f,0.5f);
		GLNS_AddPoint(&this->pointer,0.5f+0.49f*sin(DGL_DEG2RAD(lineFloat)),0.5f+0.49f*cos(DGL_DEG2RAD(lineFloat)));
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointerPoints[0]);
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointerPoints[1]);

		GLNS_Render(&this->pointer);
	}


}

void GIGG_Reshape(void *thisVoid)
{
	//printf("GIGG_Reshape\n");
	if (thisVoid==NULL) return;
	GIGG_Gauge_t *this=(GIGG_Gauge_t*)thisVoid;

	//GLNS_LineStrip_t lineAround;
	GLNS_Init(&this->lineAround,&this->pointsAround[0]);
	//GPNT_Point_t pointsAround[GWIN_POINTS_NO+1];
	float lineFloat=0.0f;
	for (uint16_t lineIx=0;lineIx<GIGG_SEGMENTS_NO+1;lineIx++)
	{
		lineFloat=lineIx*1.0f/GIGG_SEGMENTS_NO*360.0f;
		GLNS_AddPoint(&this->lineAround,0.5f+0.49f*sin(DGL_DEG2RAD(lineFloat)),0.5f+0.49f*cos(DGL_DEG2RAD(lineFloat)));
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsAround[lineIx]);
	}

	//GLNS_LineStrip_t lineDis[GIGG_DIVS_NO];
	//GPNT_Point_t pointsDivs[GIGG_DIVS_NO*2];
	for (uint16_t lineIx=0;lineIx<GIGG_DIVS_NO;lineIx++)
	{
		GLNS_Init(&this->lineDis[lineIx],&this->pointsDivs[lineIx*2]);
		lineFloat=lineIx*1.0f/GIGG_DIVS_NO*360.0f;
		GLNS_AddPoint(&this->lineDis[lineIx],0.5f+0.49f*sin(DGL_DEG2RAD(lineFloat)),0.5f+0.49f*cos(DGL_DEG2RAD(lineFloat)));
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2]);
		GLNS_AddPoint(&this->lineDis[lineIx],0.5f+0.35f*sin(DGL_DEG2RAD(lineFloat)),0.5f+0.35f*cos(DGL_DEG2RAD(lineFloat)));
		GWIN_ApplyThisWindowToPoint(&this->canvas.realWindow,&this->pointsDivs[lineIx*2+1]);
	}
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
