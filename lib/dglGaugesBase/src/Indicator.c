/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Indicator.h>

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
/* none */

/* public functions -----------------------------------------------------------*/
void GIND_Init(GIND_Indicator_t *this)
{
	printf("GIND_Init\n");
	this->isInitialised=M_FALSE;
}

void GIND_SetData(GIND_Indicator_t *this,GIND_DataType_t inputType,void* data,GIND_DataType_t outputType)
{
	printf("GIND_SetData\n");
	this->inputData=data;
	this->inputType=inputType;
	this->outputType=outputType;
	this->isInitialised=M_TRUE;
}

void GIND_Execute(GIND_Indicator_t *this)
{
	//printf("GIND_Execute %d\n",this->isInitialised);
	if (this->isInitialised)
	{
		this->isInitialised=M_FALSE;
		if (this->inputData!=NULL)
		{
			if (this->inputType==GIND_TYPE_UINT32)
			{
				if (this->outputType==GIND_TYPE_UINT32)
				{
					this->value.uint32=*(uint32_t*)this->inputData;
					this->isInitialised=M_TRUE;
				}
				else if (this->outputType==GIND_TYPE_FLOAT32)
				{
					this->value.float32=(float32_t)*(uint32_t*)this->inputData;
					this->isInitialised=M_TRUE;
				}
			}
			else if (this->inputType==GIND_TYPE_FLOAT32)
			{
				if (this->outputType==GIND_TYPE_FLOAT32)
				{
					this->value.float32=*(float32_t*)this->inputData;
					this->isInitialised=M_TRUE;
				}
				else if (this->outputType==GIND_TYPE_UINT32)
				{
					this->value.uint32=(uint32_t)*(float32_t*)this->inputData;
					this->isInitialised=M_TRUE;
				}
			}
		}
	}
}

bool_t GIND_GetDataFloat32(GIND_Indicator_t *this,float32_t *output)
{
	bool_t outputValue=M_FALSE;

	if (this->isInitialised)
	{
		if (this->inputData!=NULL)
		{
			*output=this->value.float32;
			outputValue=M_TRUE;
		}
	}

	return outputValue;
}
/* local functions ------------------------------------------------------------*/
/* none */

/* end */
