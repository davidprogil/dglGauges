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
#include <Mfd.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
#define GMFD_MARGIN_FOR_BUTTONS (0.1f)

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
bool_t GMFD_IsShowingMenu(GMFD_Mfd_t *this);
void GMFD_AddCanvas(GMFD_Mfd_t *this,GCNV_Canvas_t *newCanvas);
GPAN_PanelSet_t* GMFD_GetCurrentPanelSet(GMFD_Mfd_t *this);
void GMFD_ProcessMouseClick(GMFD_Mfd_t *this);
void GMFD_RenderButtonsWithLabels(GMFD_Mfd_t *this,GPAN_PanelSet_t* thisPanelSet);

/* public functions -----------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this)
{
	//DEBUG printf("GMFD_Init\n");
	/* canvas */
	GCNV_Init(			&this->canvas);
	GCNV_SetPosition(	&this->canvas,
			GMFD_MARGIN_FOR_BUTTONS				,GMFD_MARGIN_FOR_BUTTONS,
			1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f	,1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f,
			&this->canvas.realWindow);

	this->childCanvasNo=0;
	this->childCanvas[0]=NULL;

	this->mouseClick=M_FALSE;
	/* panels */
	GPAN_InitSet(&this->panelSet);
	this->currentLevel=0;

	this->currentForeColourIx=3;
	this->currentBackColourIx=11;

	/* info label */
	GLAB_Init(&this->infoLabel,&this->canvas.realWindow,	0.0f,				-0.1f,
			1.0f,				0.1f,
			(char*)"-",GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->infoLabel,GLAB_TEXT_SIZE_FIXED,0.025f);
	GMFD_AddCanvas(this,&this->infoLabel.canvas);


	/* side buttons and buttons labels */
	float32_t buttonWidth=1.0f/(GMFD_MAX_SIDE_BUTTONS*1.0f);
	float32_t labelWidth=buttonWidth*3.75f;
	float32_t yButton=0.0f;
	float32_t xButton=0.0f;
	float32_t labelSign=0.0f;
	float32_t buttonSign=0.0f;
	GLAB_TextJustification_t just;
	for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_SIDE_BUTTONS;buttonIx++)
	{
		yButton=(buttonIx%(GMFD_MAX_SIDE_BUTTONS/2))/(GMFD_MAX_SIDE_BUTTONS/2.0f)+buttonWidth/2.0f;
		//printf("yButton %f\n",yButton);//TODO debug
		if (buttonIx<GMFD_MAX_SIDE_BUTTONS/2)
		{
			xButton=1.0f;
			labelSign=-1.0f;
			buttonSign=0.0f;
			just=GLAB_JUSTIFICATION_RIGHT;
		}
		else
		{
			xButton=0.0f;
			labelSign=0.0f;
			buttonSign=-1.0f;
			just=GLAB_JUSTIFICATION_LEFT;
		}
		//xButton=0.0f;//TODO DEBUG
		//labelSign=0.0f;//TODO DEBUG
		//buttonSign=0.0f;//TODO DEBUG
		GBUT_Init(&this->buttons[buttonIx],		&this->canvas.realWindow,
				xButton+buttonSign*buttonWidth,
				yButton,
				buttonWidth,
				buttonWidth,(char*)"-");
		GLAB_Init(&this->buttonLabels[buttonIx],&this->canvas.realWindow,
				xButton+labelSign*labelWidth,
				yButton,
				labelWidth,
				buttonWidth,(char*)"-",just);

		GLAB_SetCharSizeType(&this->buttonLabels[buttonIx],GLAB_TEXT_SIZE_FIXED,0.05f);
		this->buttons[buttonIx].canvas.isShowBorder=M_TRUE;//TODO DEBUG
		this->buttonLabels[buttonIx].canvas.isShowBorder=M_TRUE;//TODO DEBUG

		GMFD_AddCanvas(this,&this->buttons[buttonIx].canvas);
		GMFD_AddCanvas(this,&this->buttonLabels[buttonIx].canvas);
	}

	/* up button */
	GBUT_Init(&this->upButton,		&this->canvas.realWindow,
			1.0f,
			-buttonWidth,
			buttonWidth,
			buttonWidth,(char*)"X");

	GMFD_AddCanvas(this,&this->upButton.canvas);
}

void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel)
{
	//printf("GMFD_AddPanel %d\n",this->panelsNo);
	this->panelSet.panels[this->panelSet.panelsNo]=panel;
	GCNV_Reshape(&panel->canvas,&this->canvas.realWindow);
	GMFD_AddCanvas(this,&panel->canvas);
	this->panelSet.panelsNo++;
}

void GMFD_Execute(GMFD_Mfd_t *this)
{
	//printf("GMFD_Execute\n");
	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Execute(this->childCanvas[canvasIx]);
	}
}



void GMFD_Render(GMFD_Mfd_t *this)
{
	GCNV_Render(&this->canvas);
	//DEBUG printf("GMFD_Render\n");
	GMFD_ProcessMouseClick(this);

	//printf("GMFD_Render1 %d %d\n",this->currentLevel,this->panelSet.currentPanel);
	GPAN_PanelSet_t* thisPanelSet=GMFD_GetCurrentPanelSet(this);
	//printf("GMFD_Render2 %d %d\n",this->currentLevel,thisPanelSet->currentPanel);

	/* render a menu */
	if (GPANS_IsShowingMenu(thisPanelSet))
	{
		GMFD_RenderButtonsWithLabels(this,thisPanelSet);
	}
	else /* render a panel */
	{
		//printf("render panel\n");
		uint16_t currentPanelIx = thisPanelSet->currentPanel;
		GPAN_Panel_t *thisPanel=(GPAN_Panel_t *)thisPanelSet->panels[currentPanelIx];
		GCNV_Render(&thisPanel->canvas);

		//printf("render panel no %d\n",currentPanelIx);//DEBUG
		/* side buttons */
		for (uint16_t sideIx=0;sideIx<GPAN_MAX_SIDE_BUTTONS;sideIx++)
		{
			if (thisPanel->isShowBigButtons==M_FALSE)
			{
				GLAB_SetText(&this->buttons[sideIx].title,thisPanel->sideButtonsLabels[sideIx]);
			}
			else
			{
				if (strlen(&thisPanel->sideButtonsLabels[sideIx][0])>1)
				{
					GLAB_SetText(&this->buttonLabels[sideIx],&thisPanel->sideButtonsLabels[sideIx][0]);
					GCNV_Render(&this->buttonLabels[sideIx].canvas);

					if (sideIx<GMFD_MAX_SIDE_BUTTONS/2)
					{
						GLAB_SetText(&this->buttons[sideIx].title,(char*)"<");
					}
					else
					{
						GLAB_SetText(&this->buttons[sideIx].title,(char*)">");
					}
				}
				else
				{
					GLAB_SetText(&this->buttons[sideIx].title,(char*)" ");
				}
			}
		}
	}



	/* render side buttons */
	for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_SIDE_BUTTONS;buttonIx++)
	{
		GCNV_Render(&this->buttons[buttonIx].canvas);
	}

	/* render info label */
	GCNV_Render(&this->infoLabel.canvas);

	/* render up button */
	GCNV_Render(&this->upButton.canvas);

}

void GMFD_SetPosition(GMFD_Mfd_t *this,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//DEBUG printf("GMFD_SetPosition\n");
	GCNV_Init(			&this->canvas);
	GCNV_SetPosition(	&this->canvas,
			GMFD_MARGIN_FOR_BUTTONS+ox				,GMFD_MARGIN_FOR_BUTTONS+oy,
			(1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f)*dx	,(1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f)*dy,
			&this->canvas.realWindow);


	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Reshape(this->childCanvas[canvasIx],&this->canvas.realWindow);
	}
}

void GMFD_SetColour(GMFD_Mfd_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	GCNV_Recolour(&this->canvas,fore,back);
	for (uint16_t canvasIx=0;canvasIx<this->childCanvasNo;canvasIx++)
	{
		GCNV_Recolour(this->childCanvas[canvasIx],fore,back);
	}
}

void GMFD_RotateForeColour(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GMFD_Mfd_t *this=(GMFD_Mfd_t*)thisVoid;
	this->currentForeColourIx++;
	GMFD_SetColour(this,GCOL_AllColoursVector[this->currentForeColourIx%GCOL_PredefinedColoursNo],&this->canvas.backColour);
}

void GMFD_RotateBackColour(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GMFD_Mfd_t *this=(GMFD_Mfd_t*)thisVoid;
	this->currentBackColourIx++;
	GMFD_SetColour(this,&this->canvas.foreColour,GCOL_AllColoursVector[this->currentBackColourIx%GCOL_PredefinedColoursNo]);
}



void GMFD_MouseClick(GMFD_Mfd_t *this,float32_t x,float32_t y)
{
	this->mouseClick=M_TRUE;
	this->mouseClick_x=x;
	this->mouseClick_y=y;
}
void GMFD_ProcessMouseClick(GMFD_Mfd_t *this)
{
	if (this->mouseClick==M_TRUE)
	{
		this->mouseClick=M_FALSE;
		//printf("GMFD_MouseClick %f %f\n",x,y);//DEBUG
		//snprintf(&labelText[0],sizeof(labelText),"click %4.3f %4.3f",x,y);
		//GLAB_SetText(&this->infoLabel,&labelText[0]);
		GPNT_Point_t checkPoint;

		//GWIN_Print(&this->buttons[0].canvas.realWindow);//DEBUG
		/* create check point*/
		checkPoint.x=this->mouseClick_x;		checkPoint.y=this->mouseClick_y;
		GPAN_PanelSet_t* thisPanelSet=GMFD_GetCurrentPanelSet(this);
		/* check if inside up button */
		if (GBUT_IsPointInside(&this->upButton,&checkPoint))
		{
			//printf("home x 1--------------------------\n");
			/* if showing menu, decrease the level*/
			if (GMFD_IsShowingMenu(this))
			{
				if (this->currentLevel>0)
				{
					this->currentLevel--;
					//printf("home x 2\n");
					thisPanelSet=GMFD_GetCurrentPanelSet(this);
				}
			}
			thisPanelSet->currentPanel=GPAN_MAX_PANELS_NO;

			//snprintf(&labelText[0],sizeof(labelText),"Congrats you hit button X");//DEBUG
			//GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG
		}
		else {
			/* check if inside any side button */
			for (uint16_t buttonIx=0;buttonIx<GPAN_MAX_PANELS_NO;buttonIx++)
			{
				if (GBUT_IsPointInside(&this->buttons[buttonIx],&checkPoint))
				{
					//snprintf(&labelText[0],sizeof(labelText),"Congrats you hit button %d",buttonIx);//DEBUG
					//GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG
					//printf("GMFD_MouseClick HIT %f %f\n",checkPoint.x,checkPoint.y);//DEBUG

					if (GPANS_IsShowingMenu(thisPanelSet))
					{
						if (buttonIx<thisPanelSet->panelsNo)
						{
							thisPanelSet->currentPanel=buttonIx;
							/*another menu?*/
							GPAN_Panel_t *thisPanel=(GPAN_Panel_t *)thisPanelSet->panels[buttonIx];
							if (thisPanel->panelSet.panelsNo>0)
							{
								this->currentLevel++;
							}

						}

					}
					else
					{
						/*forward to panel */
						GPAN_ButtonCallback(thisPanelSet->panels[thisPanelSet->currentPanel],buttonIx);
					}
				}
			}
		}
	}

}
/* local functions ------------------------------------------------------------*/
GPAN_PanelSet_t* GMFD_GetCurrentPanelSet(GMFD_Mfd_t *this)
{
	uint8_t currentLevel=this->currentLevel;
	GPAN_PanelSet_t* returnValue=&this->panelSet;
	uint8_t searchLevel=0;
	bool_t isFound=M_FALSE;
	uint8_t currentPanelIx;
	shortText_t labelText;
	shortText_t temp;

	strcpy(&labelText[0],"");

	while (isFound!=M_TRUE)
	{
		currentPanelIx=returnValue->currentPanel;
		snprintf(&temp[0],sizeof(temp),"/%d",currentPanelIx);//DEBUG
		strcat(&labelText[0],&temp[0]);

		if (currentLevel==searchLevel)
		{
			//printf("1\n");
			isFound=M_TRUE;
		}
		else if (currentPanelIx<GPAN_MAX_PANELS_NO)
		{
			//printf("2\n");
			returnValue=&((GPAN_Panel_t*)returnValue->panels[currentPanelIx])->panelSet;
		}
		searchLevel++;
	}
	//printf("level %d path:%s %p\n",currentLevel,&labelText[0],returnValue);
	GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG
	return returnValue;
}
void GMFD_AddCanvas(GMFD_Mfd_t *this,GCNV_Canvas_t *newCanvas)
{
	this->childCanvas[this->childCanvasNo]=newCanvas;
	this->childCanvasNo++;
}
bool_t GMFD_IsShowingMenu(GMFD_Mfd_t *this)
{
	return GPANS_IsShowingMenu(GMFD_GetCurrentPanelSet(this));
}
void GMFD_RenderButtonsWithLabels(GMFD_Mfd_t *this,GPAN_PanelSet_t* thisPanelSet)
{
	for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_SIDE_BUTTONS;buttonIx++)
	{
		/* render button labels */
		if (buttonIx<thisPanelSet->panelsNo)
		{
			GLAB_SetText(&this->buttonLabels[buttonIx],&((GPAN_Panel_t*)thisPanelSet->panels[buttonIx])->titleLabel.text[0]);
			GCNV_Render(&this->buttonLabels[buttonIx].canvas);

			if (buttonIx<GMFD_MAX_SIDE_BUTTONS/2)
			{
				GLAB_SetText(&this->buttons[buttonIx].title,(char*)"<");
			}
			else
			{
				GLAB_SetText(&this->buttons[buttonIx].title,(char*)">");
			}
		}
		else
		{
			GLAB_SetText(&this->buttons[buttonIx].title,(char*)" ");
		}
	}
}
/* end */
