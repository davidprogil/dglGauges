/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include "../../../lib/dglGaugesBase/include/Indicator.h"

#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/

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
	//DEBUG printf("GIND_Init\n");
	this->isInitialised=M_FALSE;
	this->inputData=NULL;
}

void GIND_SetData(GIND_Indicator_t *this,GIND_DataType_t inputType,void* data,GIND_DataType_t outputType)
{
	//printf("GIND_SetData %d\n",inputType);//DEBUG
	this->inputData=data;
	this->inputType=inputType;
	this->outputType=outputType;
	this->isInitialised=M_TRUE;
}

bool_t GIND_IsInitialised(GIND_Indicator_t *this)
{
	return this->isInitialised;
}

void GIND_Execute(GIND_Indicator_t *this)
{
	//printf("GIND_Execute 1 %d\n",this->isInitialised);//DEBUG
	if (this->isInitialised)
	{
		//printf("GIND_Execute 2 %d\n",this->isInitialised);//DEBUG
		this->isInitialised=M_FALSE;
		if (this->inputData!=NULL)
		{
			//printf("GIND_Execute 3 %p %d\n",this,this->inputType);//DEBUG
			if (this->inputType==GIND_TYPE_UINT8)
			{
				//printf("GIND_Execute 4 %d\n",this->isInitialised);//DEBUG
				if (this->outputType==GIND_TYPE_UINT32)
				{
					this->value.uint32=(uint32_t)*(uint8_t*)this->inputData;
					this->isInitialised=M_TRUE;
					//printf("Indicator %d %d\n",this->value.uint32,(uint32_t)*(uint8_t*)this->inputData);
					//printf("GIND_Execute uint32 uint32 %d\n",this->isInitialised);
				}
				else if (this->outputType==GIND_TYPE_FLOAT32)
				{
					this->value.float32=(float32_t)*(uint8_t*)this->inputData;
					this->isInitialised=M_TRUE;
				}
			}
			else if (this->inputType==GIND_TYPE_UINT32)
			{
				//printf("GIND_Execute 4 %d\n",this->isInitialised);//DEBUG
				if (this->outputType==GIND_TYPE_UINT32)
				{
					this->value.uint32=(uint32_t)*(uint32_t*)this->inputData;
					this->isInitialised=M_TRUE;
					//printf("GIND_Execute uint32 uint32 %d\n",this->isInitialised);
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
bool_t GIND_GetDataUint32(GIND_Indicator_t *this,uint32_t *output)
{
	bool_t outputValue=M_FALSE;

	if (this->isInitialised)
	{
		if (this->inputData!=NULL)
		{
			*output=this->value.uint32;
			outputValue=M_TRUE;
		}
	}

	return outputValue;
}
bool_t GIND_GetDataUint8(GIND_Indicator_t *this,uint8_t *output)
{
	bool_t outputValue=M_FALSE;

	if (this->isInitialised)
	{
		if (this->inputData!=NULL)
		{
			*output=this->value.uint8;
			outputValue=M_TRUE;
		}
	}
	return outputValue;
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
