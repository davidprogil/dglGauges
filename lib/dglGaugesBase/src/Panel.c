/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Panel.h>

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
void GPAN_RecalculateGeometry(GPAN_Panel_t *this);

/* public functions -----------------------------------------------------------*/
void GPAN_Init(GPAN_Panel_t *this,char *title)
{
	printf("GPAN_Init\n");
	/* canvas */
	GCNV_Init(&this->canvas);

	/* instruments */
	this->instrumentsNo=0;
	this->instruments[0]=NULL;

	/* label */
	GLAB_Init(&this->titleLabel,&this->canvas.realWindow,	0.0f, 0.9f,		1.0f,  0.1,title,GLAB_JUSTIFICATION_CENTER);

	GPAN_RecalculateGeometry(this);
}

void GPAN_AddInstrument(GPAN_Panel_t *this,GCNV_Canvas_t *instrument)
{
	this->instruments[this->instrumentsNo]=instrument;
	GCNV_ApplyParentWindow(instrument,&this->canvas.realWindow);
	this->instrumentsNo++;
}

void GPAN_ApplyParentWindow(GPAN_Panel_t *this,GWIN_Window_t *parentWindow)
{
	GCNV_ApplyParentWindow(&this->canvas,parentWindow);
	GPAN_RecalculateGeometry(this);
}

void GPAN_Execute(GPAN_Panel_t *this)
{
	printf("GPAN_Execute\n");
}
void GPAN_Render(GPAN_Panel_t *this)
{
	//debug printf("GPAN_Render\n");
	GCNV_Render(&this->canvas);

	/* render instruments */
	for (uint16_t ix=0;ix<this->instrumentsNo;ix++)
	{
		GCNV_Render(this->instruments[ix]);
	}

	/* label */
	GCNV_Render(&this->titleLabel.canvas);
}

void GPAN_SetPosition(GPAN_Panel_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy,GWIN_Window_t *parentWindow)
{
	GCNV_SetPosition(&this->canvas,ox,oy,dx,dy,parentWindow);
	GPAN_RecalculateGeometry(this);
}

/* local functions ------------------------------------------------------------*/
void GPAN_RecalculateGeometry(GPAN_Panel_t *this)
{
	GLAB_ApplyParentWindow(&this->titleLabel,&this->canvas.realWindow);
}

/* end */
