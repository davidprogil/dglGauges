/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GISG_Sign_H
#define GISG_Sign_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
/* none */

/* component includes----------------------------------------------------------*/
#include <Label.h>
#include <Indicator.h>


/* macros-----------------------------------------------------------------------*/
#define GISG_INDICATOR_TYPE (GIND_TYPE_UINT32)
#define GISG_DECODER_MAX_NO (10)

/* types------------------------------------------------------------------------*/
typedef struct _GISG_ValueDecoderElement_t_
{
	char name[GLAB_MAX_TEXT_LENGTH];
	GCOL_Colour_t	fore;
	GCOL_Colour_t	back;
	uint32_t		threshold;
}GISG_ValueDecoderElement_t;

typedef struct _GISG_ValueDecoder_t_
{
	GISG_ValueDecoderElement_t decoder[GISG_DECODER_MAX_NO];
	uint16_t levelsNo;

}GISG_ValueDecoder_t;

typedef struct _GISG_Sign_t_
{
	GCNV_Canvas_t canvas;
	GIND_Indicator_t indicator;

	GLAB_Label_t  titleLabel;
	GLAB_Label_t  valueLabel;
	uint32_t value;

	GISG_ValueDecoder_t decoder;

}GISG_Sign_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GISG_Init(GISG_Sign_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void GISG_Execute(void *thisVoid);
void GISG_Render(void *thisVoid);
void GISG_SetColour(GISG_Sign_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back);
void GISG_AddDecoder(GISG_Sign_t *this,char *name,uint32_t threshold, GCOL_Colour_t *fore, GCOL_Colour_t *back);

/* end */
#endif /* GISG_Sign_H */

