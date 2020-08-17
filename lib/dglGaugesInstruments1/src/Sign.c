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
/* none */

/* component includes----------------------------------------------------------*/
#include <Sign.h>

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
void GISG_Execute(void *thisVoid);
void GISG_Render(void *thisVoid);
void GISG_Reshape(void *thisVoid,GWIN_Window_t *parentWindow);

/* public functions -----------------------------------------------------------*/
void GISG_Init(GISG_Sign_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy)
{
	//DEBUG printf("GISG_Init\n");

	/* initalise canvas */
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,	ox,oy,dx,dy,	parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GISG_Render,GISG_Execute,GISG_Reshape,this);
	GISG_SetColour(this,&GCOL_Green,&GCOL_Green_Half);

	/* indicator*/
	GIND_Init(&this->indicator);

	/* values */
	this->value=0;
	this->decoder.levelsNo=0;

	/* labels */
	GLAB_Init(&this->titleLabel,&this->canvas.realWindow,	0.0f, 0.5f,		1.0f,  0.5,title,	GLAB_JUSTIFICATION_CENTER);
	GLAB_Init(&this->valueLabel,&this->canvas.realWindow,	0.0f, 0.0f,		1.0f,  0.5,(char*)"-",		GLAB_JUSTIFICATION_CENTER);
	GLAB_SetCharSizeType(&this->titleLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetCharSizeType(&this->valueLabel,GLAB_TEXT_SIZE_FIXED,0.02f);
	GLAB_SetVerticalAlignment(&this->titleLabel, GLAB_ALIGN_CENTER);
	GLAB_SetVerticalAlignment(&this->valueLabel, GLAB_ALIGN_CENTER);
	GCNV_SetRenderFlags(&this->titleLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	GCNV_SetRenderFlags(&this->valueLabel.canvas,M_TRUE,M_FALSE,M_FALSE);
	GCNV_SetRenderFlags(&this->canvas,M_TRUE,M_FALSE,M_FALSE);

	/* title */
	GLAB_SetText(&this->titleLabel,title);
	GLAB_SetText(&this->valueLabel,(char*)"-");


	GISG_Reshape(this,&this->canvas.realWindow);

}



void GISG_SetColour(GISG_Sign_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back)
{
	GLAB_SetColour(&this->titleLabel,fore,back,M_FALSE);
	GLAB_SetColour(&this->valueLabel,fore,back,M_FALSE);
	GCNV_SetColour(&this->canvas,fore,back,M_FALSE);
}
void GISG_AddDecoder(GISG_Sign_t *this,char *name,uint32_t threshold, GCOL_Colour_t *fore, GCOL_Colour_t *back)
{
	GISG_ValueDecoderElement_t *element=&this->decoder.decoder[this->decoder.levelsNo];
	element->threshold=threshold;
	strcpy(&element->name[0],name);
	GCOL_CopyFrom(&element->fore,fore);
	GCOL_CopyFrom(&element->back,back);
	this->decoder.levelsNo++;
}
/* local functions ------------------------------------------------------------*/
void GISG_Reshape(void *thisVoid,GWIN_Window_t *parentWindow)
{
	if (thisVoid==NULL) return;
	GISG_Sign_t *this=(GISG_Sign_t*)thisVoid;

	GLAB_ApplyParentWindow(&this->titleLabel,&this->canvas.realWindow);
	GLAB_ApplyParentWindow(&this->valueLabel,&this->canvas.realWindow);
}

void GISG_Execute(void *thisVoid)
{
	//printf("GISG_Execute\n");
	if (thisVoid==NULL) return;
	GISG_Sign_t *this=(GISG_Sign_t*)thisVoid;
	GIND_Execute(&this->indicator);
}

void GISG_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//printf("GISG_Render\n");
	GISG_Sign_t *this=(GISG_Sign_t*)thisVoid;

	/* decode */
	if (GIND_GetDataUint32(&this->indicator,&this->value))
	{
		GISG_ValueDecoderElement_t *decoder;
		for (int16_t levelIx=this->decoder.levelsNo-1;levelIx>=0;levelIx--)
		{
			decoder=&this->decoder.decoder[levelIx];
			//printf("GISG_Render %d %d\n",this->value,decoder->threshold);//DEBUG
			if (this->value>=decoder->threshold)
			{
				GISG_SetColour(this,&decoder->fore,&decoder->back);
				GLAB_SetText(&this->valueLabel,&decoder->name[0]);
				//printf("GISG_Render XXXX %d %d\n",this->value,decoder->threshold);//DEBUG
				break;
			}

		}
	}
	GCOL_SetRenderColour(&this->canvas.backColour);
	GWIN_RenderFill(&this->canvas.realWindow);

	/* labels */
	GCNV_Render(&this->titleLabel.canvas);
	GCNV_Render(&this->valueLabel.canvas);

}

/* end */
