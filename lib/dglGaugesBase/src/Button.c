/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Button.h>

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
void GBUT_Init(GBUT_Button_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text)
{
	printf("GBUT_Init\n");
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,ox,oy,dx,dy,parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GBUT_Render,GBUT_Execute,this);

	GLAB_Init(&this->title,&this->canvas.realWindow,0.0f,0.0f,1.0f,1.0f,text,GLAB_ALIGN_CENTER);
	GLAB_SetCharSizeType(&this->title,GLAB_TEXT_SIZE_FIXED,0.03f);
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

	//printf("GBUT_Render\n");//DEBUG
	GCNV_Render(&this->title.canvas);
}

bool_t GBUT_IsPointInside(GBUT_Button_t *this,GPNT_Point_t *point)
{
	return GWIN_IsPointInside(&this->canvas.realWindow,point);
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
