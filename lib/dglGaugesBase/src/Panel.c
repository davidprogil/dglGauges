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
void GPAN_Execute(void *thisVoid);
void GPAN_Render(void *thisVoid);
void GPAN_AddCanvas(GPAN_Panel_t *this,GCNV_Canvas_t *newCanvas);
void GPAN_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);
void GPAN_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back);

/* public functions -----------------------------------------------------------*/
void GPAN_Init(GPAN_Panel_t *this,char *title)
{
	//DEBUG printf("GPAN_Init\n");
	/* canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetParentFunctions(&this->canvas,GPAN_Render,GPAN_Execute,GPAN_Reshape,GPAN_Recolour,this);

	this->childCanvasNo=0;
	this->childCanvas[0]=NULL;

	this->isShowBigButtons=M_FALSE;

	/* side buttons */
	for (uint16_t sideIx=0;sideIx<GPAN_MAX_SIDE_BUTTONS;sideIx++)
	{
		strcpy((char*)&this->sideButtonsLabels[sideIx][0]," ");
		this->sideButtonsFunctions[sideIx]=NULL;
		this->sideButtonData[sideIx]=NULL;
	}


	/* sub panels */
	GPAN_InitSet(&this->panelSet);

	/* label */
	GLAB_Init(&this->titleLabel,&this->canvas.realWindow,	0.0f, 0.9f,		1.0f,  0.1,title,GLAB_JUSTIFICATION_CENTER);
	GCNV_SetRenderFlags(&this->titleLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	GPAN_AddCanvas(this,&this->titleLabel.canvas);

	this->showTitle=M_TRUE;

	GPAN_Reshape(this,&this->canvas.realWindow);
}

void GPAN_InitSet(GPAN_PanelSet_t *this)
{
	this->panels[0]=NULL;
	this->panelsNo=0;
	this->currentPanel=GPAN_MAX_PANELS_NO;
}
void GPAN_AddPanel(GPAN_Panel_t *this,GPAN_Panel_t *panel)
{
	this->panelSet.panels[this->panelSet.panelsNo]=panel;
	GCNV_Reshape(&panel->canvas,&this->canvas.realWindow);
	GPAN_AddCanvas(this,&panel->canvas);
	this->panelSet.panelsNo++;
}
bool_t GPANS_IsShowingMenu(GPAN_PanelSet_t *this)
{
	if (this->panelsNo==0)
	{
		this->currentPanel=0;
	}
	return (this->currentPanel==GPAN_MAX_PANELS_NO);
}

void GPAN_AddInstrument(GPAN_Panel_t *this,GCNV_Canvas_t *instrument)
{
	GCNV_Reshape(instrument,&this->canvas.realWindow);
	GPAN_AddCanvas(this,instrument);
}

void GPAN_SetButtonNameAndFunction(GPAN_Panel_t *this,uint16_t buttonIx,char *text,GPAN_SideFunctions_t callback,void *data)
{
	strcpy(&this->sideButtonsLabels[buttonIx][0],text);
	this->sideButtonData[buttonIx]=data;
	this->sideButtonsFunctions[buttonIx]=callback;
}
void GPAN_ButtonCallback(GPAN_Panel_t *this,uint16_t buttonIx)
{
	if (this->sideButtonsFunctions[buttonIx]!=NULL)
	{
		this->sideButtonsFunctions[buttonIx](this->sideButtonData[buttonIx]);
	}
}

void GPAN_SetShowTitle(GPAN_Panel_t *this,bool_t showTitle)
{
	this->showTitle=showTitle;
}

/* local functions ------------------------------------------------------------*/
void GPAN_AddCanvas(GPAN_Panel_t *this,GCNV_Canvas_t *newCanvas)
{
	this->childCanvas[this->childCanvasNo++]=newCanvas;
}


void GPAN_Execute(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GPAN_Panel_t *this=(GPAN_Panel_t*)thisVoid;
	//printf("GPAN_Execute\n");
	/* execute instruments */
	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Execute(this->childCanvas[canvasIx]);
	}

}
void GPAN_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GPAN_Panel_t *this=(GPAN_Panel_t*)thisVoid;
	bool_t isToRender=M_TRUE;

	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		isToRender=M_TRUE;
		if (this->childCanvas[canvasIx]==&this->titleLabel.canvas)
		{
			isToRender=this->showTitle;
		}
		else
		{
			isToRender=M_TRUE;
		}

		if (isToRender)
		{
			GCNV_Render(this->childCanvas[canvasIx]);
		}

	}

}
void GPAN_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	GPAN_Panel_t *this=(GPAN_Panel_t*)thisVoid;
	//DEBUG printf("GPAN_Reshape\n");
	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Reshape(this->childCanvas[canvasIx],&this->canvas.realWindow);
	}
}

void GPAN_Recolour(void *thisVoid,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	if (thisVoid==NULL) return;
	GPAN_Panel_t *this=(GPAN_Panel_t*)thisVoid;
	//DEBUG printf("GPAN_Recolour\n");
	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Recolour(this->childCanvas[canvasIx],fore,back);
	}
}

/* end */
