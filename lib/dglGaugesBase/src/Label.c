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
#include <Label.h>

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
void GLAB_Render_0(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_1(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_2(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_3(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_4(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_5(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_6(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_7(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_8(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_9(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_dot(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_A(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_B(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_C(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_D(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_E(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_F(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_G(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_H(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_I(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_J(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_K(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_L(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_M(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_N(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_O(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_P(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_Q(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_R(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_S(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_T(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_U(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_V(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_W(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_X(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_Y(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_Z(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_space(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_minus(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_plus(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_parLeft(GLAB_Label_t *this,GWIN_Window_t *window);
void GLAB_Render_parRight(GLAB_Label_t *this,GWIN_Window_t *window);

typedef void (*GLAB_CharRenderFunction)(GLAB_Label_t *this,GWIN_Window_t *window);
typedef struct _GLAB_CharRenderFunctionElement_t
{
	char chare;
	GLAB_CharRenderFunction function;
}GLAB_CharRenderFunctionElement_t;

GLAB_CharRenderFunctionElement_t GLAB_charRenderLut[]=
{
		{'0',GLAB_Render_0},
		{'1',GLAB_Render_1},
		{'2',GLAB_Render_2},
		{'3',GLAB_Render_3},
		{'4',GLAB_Render_4},
		{'5',GLAB_Render_5},
		{'6',GLAB_Render_6},
		{'7',GLAB_Render_7},
		{'8',GLAB_Render_8},
		{'9',GLAB_Render_9},
		{'.',GLAB_Render_dot},
		{'A',GLAB_Render_A},
		{'B',GLAB_Render_B},
		{'C',GLAB_Render_C},
		{'D',GLAB_Render_D},
		{'E',GLAB_Render_E},
		{'F',GLAB_Render_F},
		{'G',GLAB_Render_G},
		{'H',GLAB_Render_H},
		{'I',GLAB_Render_I},
		{'J',GLAB_Render_J},
		{'K',GLAB_Render_K},
		{'L',GLAB_Render_L},
		{'M',GLAB_Render_M},
		{'N',GLAB_Render_N},
		{'O',GLAB_Render_O},
		{'P',GLAB_Render_P},
		{'Q',GLAB_Render_Q},
		{'R',GLAB_Render_R},
		{'S',GLAB_Render_S},
		{'T',GLAB_Render_T},
		{'U',GLAB_Render_U},
		{'V',GLAB_Render_V},
		{'W',GLAB_Render_W},
		{'X',GLAB_Render_X},
		{'Y',GLAB_Render_Y},
		{'Z',GLAB_Render_Z},
		{' ',GLAB_Render_space},
		{'-',GLAB_Render_minus},
		{'+',GLAB_Render_plus},
		{'(',GLAB_Render_parLeft},
		{')',GLAB_Render_parRight}
};

#define GLAB_NCHARS_CAN_RENDER sizeof(GLAB_charRenderLut)/sizeof(GLAB_CharRenderFunctionElement_t)

/* public functions -----------------------------------------------------------*/
void GLAB_Init(GLAB_Label_t *this,GWIN_Window_t *parentWindow,float32_t ox,float32_t oy,float32_t dx,float32_t dy,char *text,GLAB_TextJustification_t justification)
{
	//printf("GLAB_Init\n");//DEBUG
	GCNV_Init(&this->canvas);
	GCNV_SetPosition(&this->canvas,ox,oy,dx,dy,parentWindow);
	GCNV_SetParentFunctions(&this->canvas,GLAB_Render,GLAB_Execute,this);
	GLAB_SetText(this,text);
	this->justification=justification;
	this->textSizeType=GLAB_TEXT_SIZE_AUTO;
	this->textSizeWhenFixed=0.05f;/* of the total screen size*/
	this->charWidth=GLAB_DEFAULT_FIXED_CHAR_HEIGHT*0.8f;
	this->alignment=GLAB_JUSTIFICATION_CENTER;

	GCNV_SetRenderFlags(&this->canvas,M_TRUE,M_FALSE,M_FALSE);
}


void GLAB_SetColour(GLAB_Label_t *this,GCOL_Colour_t *fore,GCOL_Colour_t *back,bool_t isBorderShown)
{
	GCNV_SetColour(&this->canvas,fore,back,isBorderShown);

}

void GLAB_Execute(void *thisVoid)
{
	if (thisVoid==NULL) return;
	//printf("GLAB_Execute\n");//TODO debug
	//GLAB_Label_t *this=(GLAB_Label_t*)thisVoid;
}

void GLAB_Render(void *thisVoid)
{
	if (thisVoid==NULL) return;
	GLAB_Label_t *this=(GLAB_Label_t*)thisVoid;
	//printf("GLAB_Render\n");
	/* render border */
	GCOL_SetRenderColour(&this->canvas.backColour);

	/* render character */
	uint16_t nChars=strlen(this->text);

	/* calculate charWindow*/
	GWIN_Window_t charWindow;
	float32_t charWidth;
	GWIN_Init(&charWindow,
			this->canvas.realWindow.origin.x,
			this->canvas.realWindow.origin.y,
			this->canvas.realWindow.length.x,
			this->canvas.realWindow.length.y);

	if (this->textSizeType==GLAB_TEXT_SIZE_AUTO)
	{
		charWidth=this->canvas.realWindow.length.y*0.8;
		charWindow.length.y=this->canvas.realWindow.length.y;
		charWindow.length.x=charWidth;
	}
	else
	{
		charWidth=this->charWidth*0.8f;
		charWindow.length.y=this->charWidth;
		charWindow.length.x=charWidth;
	}

	if (this->alignment==GLAB_ALIGN_TOP)
	{
		charWindow.origin.y=this->canvas.realWindow.origin.y+this->canvas.realWindow.length.y-charWindow.length.y;
	}
	else if (this->alignment==GLAB_ALIGN_CENTER)
	{
		charWindow.origin.y=this->canvas.realWindow.origin.y+this->canvas.realWindow.length.y/2.0f-charWindow.length.y/2.0f;
	}

	/* justification */
	float32_t projectedLenght=charWidth*nChars;
	if (projectedLenght>=this->canvas.realWindow.length.x)
	{
		//text longer than label, no justification needed
	}
	else
	{
		if (this->justification==GLAB_JUSTIFICATION_LEFT)
		{
			//left, no justification needed
		}
		else if (this->justification==GLAB_JUSTIFICATION_RIGHT)
		{
			charWindow.origin.x=this->canvas.realWindow.origin.x+this->canvas.realWindow.length.x-projectedLenght;
		}
		else //centered
		{
			charWindow.origin.x=this->canvas.realWindow.origin.x+0.5f*(this->canvas.realWindow.length.x-projectedLenght);
		}

	}

	//debug
	//GWIN_Render(&charWindow);

	/* render */
	GCOL_SetRenderColour(&this->canvas.foreColour);
	float32_t charWidthAccum=0.0f;
	for (uint16_t charIx=0;charIx<nChars;charIx++)
	{
		//printf("Render %c\n",this->text[charIx]);//DEBUG
		for (uint16_t functionIx=0;functionIx<GLAB_NCHARS_CAN_RENDER;functionIx++)
		{
			if (this->text[charIx]==GLAB_charRenderLut[functionIx].chare)
			{
				/*calculate charWindow*/
				(GLAB_charRenderLut[functionIx].function)(this,&charWindow);
				charWindow.origin.x=charWindow.origin.x+charWidth;
				break;
			}
		}
		charWidthAccum+=charWidth;
		if (charWidthAccum+charWidth>this->canvas.realWindow.length.x)
		{
			break;
		}

	}
}

void GLAB_SetText(GLAB_Label_t *this,char *text)
{
	strcpy(&this->text[0],text);
	/* convert text to caps*/
	for (uint16_t charIx=0;charIx<strlen(text);charIx++)
	{
		if ((this->text[charIx]>='a')&&(this->text[charIx]<='z'))
		{
			this->text[charIx]=this->text[charIx]-'a'+'A';
		}
	}

}

void GLAB_ApplyParentWindow(GLAB_Label_t *this,GWIN_Window_t *parentWindow)
{
	GCNV_ApplyParentWindow(&this->canvas,parentWindow);
}

void GLAB_SetCharSizeType(GLAB_Label_t *this,GLAB_TextSizeType_t type,float32_t charHeight)
{
	this->textSizeType=type;
	if (GLAB_TEXT_SIZE_AUTO!=type)
	{
		this->charWidth=charHeight;
	}
}

void GLAB_SetVerticalAlignment(GLAB_Label_t *this, GLAB_TextJustification_t alignment)
{
	this->alignment=alignment;
}
/* local functions ------------------------------------------------------------*/
/* to use in points*/
#define P08 (0.0f)
#define P18 (1.0f/8.0f)
#define P28 (2.0f/8.0f)
#define P38 (3.0f/8.0f)
#define P48 (4.0f/8.0f)
#define P58 (5.0f/8.0f)
#define P68 (6.0f/8.0f)
#define P78 (7.0f/8.0f)
#define P88 (1.0f)

void GLAB_Render_0(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_1(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P28,P58);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_2(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_3(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_4(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P58,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_5(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_6(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_7(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P38,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_8(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_9(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_dot(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P38,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P58,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P38,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}

void GLAB_Render_A(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_B(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[8];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P58);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_C(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);

	GLNS_Render(&ls1);
}
void GLAB_Render_D(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[7];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P58);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P38);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_E(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_F(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_G(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_H(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_I(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_J(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_K(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_L(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_M(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_N(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_O(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_P(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);

	GLNS_Render(&ls1);
}
void GLAB_Render_Q(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_R(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[6];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P58);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_S(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[8];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P28,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P58);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P28,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P68,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P38);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P68,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_T(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_U(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_V(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_W(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[5];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P38);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_X(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_Y(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[3];
	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);

	pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_Z(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P18,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_space(GLAB_Label_t *this,GWIN_Window_t *window)
{

}
void GLAB_Render_minus(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P18,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P78,P48);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_plus(GLAB_Label_t *this,GWIN_Window_t *window)
{
	GLAB_Render_minus(this,window);
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[2]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P48,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_parLeft(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P58,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P68);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P58,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}
void GLAB_Render_parRight(GLAB_Label_t *this,GWIN_Window_t *window)
{
	uint16_t pointIx=0;
	GLNS_LineStrip_t ls1;
	GPNT_Point_t ps1[4]; pointIx=0;
	GLNS_Init(&ls1,&ps1[0]);
	GLNS_AddPoint(&ls1,P38,P78);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P68);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P48,P28);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_AddPoint(&ls1,P38,P18);GWIN_ApplyThisWindowToPoint(window,&ps1[pointIx++]);
	GLNS_Render(&ls1);
}

/* end */
