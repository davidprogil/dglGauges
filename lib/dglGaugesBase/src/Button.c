/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include "../../../lib/dglGaugesBase/include/Button.h"

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
void GBUT_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
void GBUT_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back);
/* public functions -----------------------------------------------------------*/
void GBUT_Init(GBUT_Button_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text)
{
	//printf("GBUT_Init\n");//DEBUG
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,ox,oy,dx,dy,parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GBUT_Render,GBUT_Execute,GBUT_Reshape,GBUT_Recolour,this);

	GLAB_Init(&this->title,&this->canvas.realWindow,0.0f,0.0f,1.0f,1.0f,text,GLAB_ALIGN_CENTER);
	GLAB_SetCharSizeType(&this->title,GLAB_TEXT_SIZE_FIXED,0.03f);

	this->isClicked=M_FALSE;
}

void GBUT_Execute(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//GBUT_Button_t *this=(GBUT_Button_t*)thisVoid;
	//printf("GBUT_Execute\n");//DEBUG
}

void GBUT_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GBUT_Button_t *this=(GBUT_Button_t*)thisVoid;

//	if (this->isClicked==M_TRUE)
//	{
//		GCNV_SetFillColour(&this->canvas,M_TRUE);
//		this->isClicked=M_FALSE;
//	}
//	else
//	{
		GCNV_SetFillColour(&this->canvas,M_FALSE);
//	}

	//printf("GBUT_Render\n");//DEBUG
	GCNV_Render(&this->title.canvas);
}

bool_t GBUT_IsPointInside(GBUT_Button_t *this,GPNT_Point_t *point)
{
	bool_t isClicked=M_FALSE;
	if (GWIN_IsPointInside(&this->canvas.realWindow,point))
	{
		GBUT_SetClicked(this);
		isClicked=M_TRUE;
	}
	return isClicked;
}

void GBUT_SetClicked(GBUT_Button_t *this)
{
	this->isClicked=M_TRUE;
	GCNV_SetFillColour(&this->canvas,M_TRUE);
}

/* local functions ------------------------------------------------------------*/
void GBUT_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	GBUT_Button_t *this=(GBUT_Button_t*)thisVoid;

	GCNV_Reshape(&this->title.canvas,&this->canvas.realWindow);
}
void GBUT_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	if (thisVoid==NULL) return;
	GBUT_Button_t *this=(GBUT_Button_t*)thisVoid;

	GCNV_Recolour(&this->title.canvas,fore,back);
}

/* end */
