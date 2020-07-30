/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Canvas.h>

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
	printf("GCNV_Init\n");
	/* is shown */
	this->isShowing=M_TRUE;
	/* is paused (no update)*/
	this->isExecutioning=M_FALSE;
	/* is show border */
	this->isShowBorder=M_TRUE;//TODO debug
	/* is show border */
	this->isFill=M_TRUE;//TODO debug

	/* window (start and dimensions) */
	GWIN_Init(&this->window,0.0f,0.0f,1.0f,1.0f);
	/* window (start and dimensions) */
	GWIN_Init(&this->realWindow,0.0f,0.0f,1.0f,1.0f);

	/* fill colour */
	GCOL_CopyFrom(&this->fillColour,&GCOL_Green_Quarter);

	/* background colour */
	GCOL_CopyFrom(&this->backColour,&GCOL_Green_Half);

	/* foreground colour */
	GCOL_CopyFrom(&this->foreColour,&GCOL_White);

	/* function to render */
	this->renderFunction=NULL;

	/* function to update contents */
	this->updateInstrument=NULL;

	/* instrument object */
	this->instrument=NULL;

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
		if (this->isShowBorder)
		{
			GCOL_SetRenderColour(&this->backColour);
			GWIN_Render(&this->realWindow);
		}
		if (NULL != this->renderFunction)
		{
			this->renderFunction(this->instrument);
		}
	}

}

void GCNV_SetPosition(GCNV_Canvas_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow)
{
	GWIN_Init(&this->window,ox,oy,dx,dy);
	GCNV_ApplyParentWindow(this,parentWindow);
	//printf("GCNV_SetPosition2 %f %f\n",this->realWindow.origin.x,this->realWindow.origin.y);
}

void GCNV_SetParentFunctions(GCNV_Canvas_t *this,void (*renderFunction)(void*),void (*updateInstrument)(void*),void *instrument)
{
	this->instrument=instrument;
	this->renderFunction=renderFunction;
	this->updateInstrument=updateInstrument;
}

void GCNV_ApplyParentWindow(GCNV_Canvas_t *this,GWIN_Window_t *parentWindow)
{
	//GWIN_ApplyParentWindow(&this->realWindow,parentWindow);
	//DEBUG printf("GCNV_ApplyParentWindow\n");
	float32_t scaleX=parentWindow->length.x;
	float32_t scaleY=parentWindow->length.y;
	GWIN_SetPosition(&this->realWindow,
			parentWindow->origin.x+this->window.origin.x*scaleX,
			parentWindow->origin.y+this->window.origin.y*scaleY,
			this->window.length.x*scaleX,
			this->window.length.y*scaleY);
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
