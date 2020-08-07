/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

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
bool_t GMFD_IShowingMenu(GMFD_Mfd_t *this);

/* public functions -----------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this)
{
	printf("GMFD_Init\n");
	/* canvas */
	GCNV_Init(			&this->canvas);
	GCNV_SetPosition(	&this->canvas,
			GMFD_MARGIN_FOR_BUTTONS				,GMFD_MARGIN_FOR_BUTTONS,
			1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f	,1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f,
			&this->canvas.realWindow);

	/* navigation */
	this->currentLevel=0;
	this->currentPanel[0]=GMFD_MAX_PANELS_NO;

	/* panels */
	this->panels[0]=NULL;
	this->panelsNo=0;

	/* info label */
	GLAB_Init(&this->infoLabel,&this->canvas.realWindow,	0.0f,				-0.1f,
			1.0f,				0.1f,
			(char*)"-",GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->infoLabel,GLAB_TEXT_SIZE_FIXED,0.025f);



	/* side buttons and buttons labels */
	float32_t buttonWidth=1.0f/(GMFD_MAX_PANELS_NO*1.0f);
	float32_t labelWidth=buttonWidth*3.75f;
	float32_t yButton=0.0f;
	float32_t xButton=0.0f;
	float32_t labelSign=0.0f;
	float32_t buttonSign=0.0f;
	GLAB_TextJustification_t just;
	for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_PANELS_NO;buttonIx++)
	{
		yButton=(buttonIx%(GMFD_MAX_PANELS_NO/2))/(GMFD_MAX_PANELS_NO/2.0f)+buttonWidth/2.0f;
		//printf("yButton %f\n",yButton);//TODO debug
		if (buttonIx<GMFD_MAX_PANELS_NO/2)
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
	}

	/* up button */
	GBUT_Init(&this->upButton,		&this->canvas.realWindow,
			1.0f,
			-buttonWidth,
			buttonWidth,
			buttonWidth,(char*)"X");
}

void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel)
{
	printf("GMFD_AddPanel %d\n",this->panelsNo);
	this->panels[this->panelsNo]=panel;
	GPAN_ApplyParentWindow(this->panels[this->panelsNo],&this->canvas.realWindow);
	this->panelsNo++;
}

void GMFD_Execute(GMFD_Mfd_t *this)
{
	//printf("GMFD_Execute\n");
	for (uint16_t panelIx=0;panelIx<this->panelsNo;panelIx++)
	{
		GPAN_Execute(this->panels[panelIx]);
	}
}

void GMFD_Render(GMFD_Mfd_t *this)
{
	//DEBUG printf("GMFD_Render\n");
	GCNV_Render(&this->canvas);

	/* render a menu */
	if (GMFD_IShowingMenu(this))
	{
		uint16_t currentPanel=0;
		for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_PANELS_NO;buttonIx++)
		{
			/* render button labels */
			if (buttonIx<this->panelsNo)
			{
				GLAB_SetText(&this->buttonLabels[buttonIx],&this->panels[buttonIx]->titleLabel.text[0]);
				GCNV_Render(&this->buttonLabels[buttonIx].canvas);

				if (currentPanel<GMFD_MAX_PANELS_NO/2)
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
	else /* render a panel */
	{
		uint16_t currentPanelIx = this->currentPanel[this->currentLevel];
		GPAN_Render(this->panels[currentPanelIx]);

		//printf("render panel no %d\n",currentPanelIx);//DEBUG
		/* side buttons */
		for (uint16_t sideIx=0;sideIx<GPAN_MAX_SIDE_BUTTONS;sideIx++)
		{
			GLAB_SetText(&this->buttons[sideIx].title,this->panels[currentPanelIx]->sideButtonsLabels[sideIx]);
		}
	}

	/* render side buttons */
	for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_PANELS_NO;buttonIx++)
	{

		GCNV_Render(&this->buttons[buttonIx].canvas);
	}

	/* render info label */
	GCNV_Render(&this->infoLabel.canvas);

	/* up button */
	GCNV_Render(&this->upButton.canvas);

}

void GMFD_MouseClick(GMFD_Mfd_t *this,float32_t x,float32_t y)
{
	shortText_t labelText;
	//printf("GMFD_MouseClick %f %f\n",x,y);//DEBUG
	//snprintf(&labelText[0],sizeof(labelText),"click %4.3f %4.3f",x,y);
	//GLAB_SetText(&this->infoLabel,&labelText[0]);
	GPNT_Point_t checkPoint;

	//GWIN_Print(&this->buttons[0].canvas.realWindow);//DEBUG
	/* create check point*/
	checkPoint.x=x;		checkPoint.y=y;

	/* check if inside up button */
	if (GBUT_IsPointInside(&this->upButton,&checkPoint))
	{
		this->currentLevel=0;
		this->currentPanel[this->currentLevel]=GMFD_MAX_PANELS_NO;

		//snprintf(&labelText[0],sizeof(labelText),"Congrats you hit button X");//DEBUG
		//GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG
	}
	else {
		/* check if inside any side button */
		for (uint16_t buttonIx=0;buttonIx<GMFD_MAX_PANELS_NO;buttonIx++)
		{
			if (GBUT_IsPointInside(&this->buttons[buttonIx],&checkPoint))
			{
				//snprintf(&labelText[0],sizeof(labelText),"Congrats you hit button %d",buttonIx);//DEBUG
				//GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG
				//printf("GMFD_MouseClick HIT %f %f\n",x,y);//DEBUG
				if (GMFD_IShowingMenu(this))
				{
					if (buttonIx<this->panelsNo)
					{
						this->currentPanel[this->currentLevel]=buttonIx;
						//TODO this->currentLevel++;

						snprintf(&labelText[0],sizeof(labelText),"Panel %d",buttonIx);//DEBUG
						GLAB_SetText(&this->infoLabel,&labelText[0]);//DEBUG

					}

				}
				else
				{
					/*forward to panel */
					GPAN_ButtonCallback(this->panels[this->currentPanel[this->currentLevel]],buttonIx);
				}
			}
		}
	}

}
/* local functions ------------------------------------------------------------*/
bool_t GMFD_IShowingMenu(GMFD_Mfd_t *this)
{
	return (this->currentPanel[this->currentLevel]==GMFD_MAX_PANELS_NO);
}

/* end */
