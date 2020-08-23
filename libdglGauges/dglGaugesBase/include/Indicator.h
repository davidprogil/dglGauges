/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef GIND_Indicator_H
#define GIND_Indicator_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef enum _GIND_DataType_t
{
	GIND_TYPE_UINT8=0,
	GIND_TYPE_UINT32,
	GIND_TYPE_FLOAT32,
}GIND_DataType_t;

typedef union _GIND_AnyValue_t
{
	uint8_t uint8;
	uint32_t uint16;
	uint32_t uint32;
	float32_t float32;
}GIND_AnyValue_t;

typedef struct _GIND_Indicator_t_
{
	bool_t isInitialised;
	GIND_AnyValue_t value;
	GIND_DataType_t inputType;
	GIND_DataType_t outputType;
	void *inputData;
}GIND_Indicator_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void GIND_Init(GIND_Indicator_t *this);
void GIND_Execute(GIND_Indicator_t *this);
bool_t GIND_IsInitialised(GIND_Indicator_t *this);
void GIND_SetData(GIND_Indicator_t *this,GIND_DataType_t inputType,void* data,GIND_DataType_t outputType);
bool_t GIND_GetDataFloat32(GIND_Indicator_t *this,float32_t *output);
bool_t GIND_GetDataUint32(GIND_Indicator_t *this,uint32_t *output);
bool_t GIND_GetDataUint8(GIND_Indicator_t *this,uint8_t *output);

/* end */
#endif /* GIND_Indicator_H */

