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
/* none */

/* public functions -----------------------------------------------------------*/
void GMFD_Init(GMFD_Mfd_t *this)
{
	printf("GMFD_Init\n");
	/* canvas */
	GCNV_Init(			&this->myCanvas);
	GCNV_SetPosition(	&this->myCanvas,
			GMFD_MARGIN_FOR_BUTTONS				,GMFD_MARGIN_FOR_BUTTONS,
			1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f	,1.0f-GMFD_MARGIN_FOR_BUTTONS*2.0f,
			&this->myCanvas.realWindow);


	this->panels[0]=NULL;
	this->panelsNo=0;
}

void GMFD_AddPanel(GMFD_Mfd_t *this,GPAN_Panel_t *panel)
{
	this->panels[this->panelsNo]=panel;
	GPAN_ApplyParentWindow(panel,&this->myCanvas.realWindow);
	this->panelsNo++;
}

void GMFD_Execute(GMFD_Mfd_t *this)
{
	printf("GMFD_Execute\n");
	for (uint16_t panelIx=0;panelIx<this->panelsNo;panelIx++)
	{
		GPAN_Execute(this->panels[panelIx]);
	}
}

void GMFD_Render(GMFD_Mfd_t *this)
{
	//DEBUG printf("GMFD_Render\n");
	GCNV_Render(&this->myCanvas);

	//TODO needs to be active panel, not all panels
	for (uint16_t panelIx=0;panelIx<this->panelsNo;panelIx++)
	{
		GPAN_Render(this->panels[panelIx]);
	}
}
/* local functions ------------------------------------------------------------*/
/* none */

/* end */
