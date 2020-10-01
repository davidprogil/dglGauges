/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include "../../../lib/dglGaugesBase/include/Canvas.h"

#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/

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
void GCNV_Init(GCNV_Canvas_t *this)
{
	//printf("GCNV_Init\n");
	/* is shown */
	this->isShowing=M_TRUE;
	/* is paused (no update)*/
	this->isExecutioning=M_TRUE;
	/* is show border */
	this->isShowBorder=M_TRUE;//TODO debug
	/* is show border */
	this->isFill=M_TRUE;//TODO debug
	//
	/* window (start and dimensions) */
	GWIN_Init(&this->window,0.0f,0.0f,1.0f,1.0f);
	/* window (start and dimensions) */
	GWIN_Init(&this->realWindow,0.0f,0.0f,1.0f,1.0f);

	/* fill colour */
	GCOL_CopyFrom(&this->fillColour,&GCOL_FILL_COLOUR);

	/* background colour */
	GCOL_CopyFrom(&this->backColour,&GCOL_BACK_COLOUR);

	/* foreground colour */
	GCOL_CopyFrom(&this->foreColour,&GCOL_FORE_COLOUR);

	/* function to render */
	this->renderFunction=NULL;

	/* function to update contents */
	this->updateInstrument=NULL;

	/* instrument object */
	this->instrument=NULL;

	this->reshapeFunction=NULL;

	/* type */
	//TODO

	/* main label */
	//TODO		GLAB_Label_t label;

	/* children */
	this->children=NULL;
	this->noChildren=0;
}

void GCNV_Execute(GCNV_Canvas_t *this)
{
	//DEBUG printf("GCNV_Execute\n");
	if (this->isExecutioning)
	{
		if (NULL != this->updateInstrument)
		{
			this->updateInstrument(this->instrument);
		}
	}
}

void GCNV_Render(GCNV_Canvas_t *this)
{
	//DEBUG printf("GCNV_Render\n");
	if (this->isShowing)
	{
		if (this->isFill)
		{
			GCOL_SetRenderColour(&this->fillColour);
			GWIN_RenderFill(&this->realWindow);
		}
		if (NULL != this->renderFunction)
		{
			this->renderFunction(this->instrument);
		}
		if (this->isShowBorder)
		{
			GCOL_SetRenderColour(&this->backColour);
			GWIN_Render(&this->realWindow);
		}
	}
}

void GCNV_SetPosition(GCNV_Canvas_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow)
{
	GWIN_Init(&this->window,ox,oy,dx,dy);
	GCNV_Reshape(this,parentWindow);
	//printf("GCNV_SetPosition2 %f %f\n",this->realWindow.origin.x,this->realWindow.origin.y);
}

void GCNV_SetParentFunctions(GCNV_Canvas_t *this,void (*renderFunction)(void*),void (*updateInstrument)(void*),GCNV_ReshapeFunction_t reshapeFunction,GCNV_RecolourFunction_t recolourFunction,void *instrument)
{
	this->instrument	   = instrument;
	this->renderFunction   = renderFunction;
	this->reshapeFunction  = reshapeFunction;
	this->recolourFunction = recolourFunction;
	this->updateInstrument = updateInstrument;
}

void GCNV_Reshape(GCNV_Canvas_t *this,GWIN_Window_t *parentWindow)
{
	float32_t scaleX=parentWindow->length.x;
	float32_t scaleY=parentWindow->length.y;
	GWIN_SetPosition(&this->realWindow,
			parentWindow->origin.x+this->window.origin.x*scaleX,
			parentWindow->origin.y+this->window.origin.y*scaleY,
			this->window.length.x*scaleX,
			this->window.length.y*scaleY);

	if (this->reshapeFunction!=NULL)
	{
		this->reshapeFunction(this->instrument,parentWindow);
	}
}


void GCNV_SetColour(GCNV_Canvas_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back,bool_t isBorderShown)
{
	this->isShowBorder=isBorderShown;

	GCOL_CopyFrom(&this->foreColour,fore);
	GCOL_CopyFrom(&this->backColour,back);
	GCNV_SetFillColour(this,M_FALSE);
}

void GCNV_Recolour(GCNV_Canvas_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	GCOL_CopyFrom(&this->foreColour,fore);
	GCOL_CopyFrom(&this->backColour,back);
	GCNV_SetFillColour(this,M_FALSE);

	if (this->recolourFunction!=NULL)
	{
		this->recolourFunction(this->instrument,fore,back);
	}
}

void GCNV_SetRenderFlags(GCNV_Canvas_t *this,bool_t isShowing,bool_t isShowBorder,bool_t isFill)
{
	this->isShowing=isShowing;
	this->isShowBorder=isShowBorder;
	this->isFill=isFill;
}

void GCNV_SetFillColour(GCNV_Canvas_t *this,bool_t highLight)
{
	GCOL_Colour_t newFilColour;
	if (highLight)
	{
		GCOL_CopyFrom(&this->fillColour,&this->backColour);
	}
	else
	{
		GCOL_CopyFrom(&newFilColour,&this->backColour);
		newFilColour.r/=2.0f;	newFilColour.g/=2.0f;	newFilColour.b/=2.0f;
		GCOL_CopyFrom(&this->fillColour,&newFilColour);
	}
}
/* local functions ------------------------------------------------------------*/
/* none */

/* end */
