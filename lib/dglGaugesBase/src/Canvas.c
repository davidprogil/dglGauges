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
	this->isShowing=M_FALSE;
	/* is paused (no update)*/
	this->isExecutioning=M_FALSE;
	/* is show border */
	this->isShowBorder=M_TRUE;//TODO debug

	/* window (start and dimensions) */
	GWIN_Init(&this->window,0.0f,0.0f,1.0f,1.0f);
	/* window (start and dimensions) */
	GWIN_Init(&this->realWindow,0.0f,0.0f,1.0f,1.0f);

	/* background colour */
	GCOL_CopyFrom(&this->backColour,&GCOL_Green_half);

	/* foreground colour */
	GCOL_CopyFrom(&this->foreColour,&GCOL_White);

	//		/* function to render */
	//		//todo
	//
	//		/* function to update contents */
	//		//todo
	//
	//		/* instrument object */
	//		//TODO
	//
	//		/* type */
	//		//TODO
	//
	//		/* main label */
	//		GLAB_Label_t label;
	//
	/* children */
	this->children=NULL;
	this->noChildren=0;
}

void GCNV_Execute(GCNV_Canvas_t *this)
{
	//DEBUG printf("GCNV_Execute\n");
}

void GCNV_Render(GCNV_Canvas_t *this)
{
	//DEBUG printf("GCNV_Render\n");
	if (this->isShowBorder)
	{
		GCOL_SetRenderColour(&this->backColour);

		GWIN_Render(&this->realWindow);
	}
}

void GCNV_SetPosition(GCNV_Canvas_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow)
{
	GWIN_Init(&this->window,ox,oy,dx,dy);
	GCNV_ApplyParentWindow(this,parentWindow);
	//printf("GCNV_SetPosition2 %f %f\n",this->realWindow.origin.x,this->realWindow.origin.y);
}

void GCNV_ApplyParentWindow(GCNV_Canvas_t *this,GWIN_Window_t *parentWindow)
{
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
