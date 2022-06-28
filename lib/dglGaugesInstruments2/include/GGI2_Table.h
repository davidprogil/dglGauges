/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef G2TB_Table_H
#define G2TB_Table_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>
#include <Label.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define G2TB_LINES_PER_ROW_MAX_NB (2)
#define G2TB_ROW_MAX_NB (10)
#define G2TB_COLS_MAX_NB (4)
#define G2TB_LINESTEXT_MAX_NB (20)

/* types------------------------------------------------------------------------*/
typedef struct _G2TB_Line_t_
{
	GLAB_Label_t col[G2TB_COLS_MAX_NB];
}G2TB_Line_t;

typedef struct _G2TB_LineText_t_
{
	shortText_t text[G2TB_COLS_MAX_NB];
	bool_t isDefined;
}G2TB_LineText_t;

typedef struct _G2TB_Row_t_
{
	G2TB_Line_t line[G2TB_LINES_PER_ROW_MAX_NB];
}G2TB_Row_t;

typedef struct _G2TB_Table_t_
{
	GCNV_Canvas_t canvas;
	G2TB_Row_t row[G2TB_ROW_MAX_NB];

	uint16_t colsNo[G2TB_LINES_PER_ROW_MAX_NB];
	uint16_t rowsNo;
	uint16_t linesNo;
	float32_t sizes[G2TB_LINES_PER_ROW_MAX_NB][G2TB_COLS_MAX_NB];

	G2TB_LineText_t linesText[G2TB_LINESTEXT_MAX_NB];
	uint16_t totalRowsNo;
	uint16_t injestedRowsCounter;
	int16_t startRow,endRow;
	bool_t isInverseOrder;
}G2TB_Table_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void G2TB_Init(G2TB_Table_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void G2TB_Init2(G2TB_Table_t *this,GWIN_Window_t *parentWindow,char *title,float32_t ox,float32_t oy,float32_t dx,float32_t dy);
void G2TB_AddLine(G2TB_Table_t *this,shortText_t *text);


/* end */
#endif /* G2TB_Table_H */

