/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef G2BM_Bitmap_H
#define G2BM_Bitmap_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define G2BM_ROWS_MAX_NB (640)
#define G2BM_COLS_MAX_NB (480)
#define G2BM_COLORS_NO (3)
#define G2BM_PIXEL_COLOR_NB (1)

/* types------------------------------------------------------------------------*/
typedef struct _G2BM_Pixel_t_
{
	float32_t r;
	float32_t g;
	float32_t b;
}G2BM_Pixel_t;

typedef struct _G2BM_Bitmap_t_
{
	GCNV_Canvas_t canvas;

	uint16_t rowsNo;
	uint16_t colsNo;
	G2BM_Pixel_t bitmap[G2BM_ROWS_MAX_NB][G2BM_COLS_MAX_NB];

}G2BM_Bitmap_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void G2BM_Init(G2BM_Bitmap_t *this,GWIN_Window_t *parentWindow,char *title,uint16_t rowsNo,uint16_t colsNo,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void G2BM_SetPixelColour(G2BM_Bitmap_t *this,uint16_t rowIx, uint16_t colIx, float32_t r,float32_t g,float32_t b);

/* end */
#endif /* G2BM_Bitmap_H */

