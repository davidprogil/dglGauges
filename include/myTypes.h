/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/
#ifndef MYTYPES_H
#define MYTYPES_H

/* system includes-------------------------------------------------------------*/
#include<stdlib.h>

/* application includes--------------------------------------------------------*/
/* none */

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define M_FALSE (0)
#define M_TRUE (1)

#define DGL_DEG2RAD(x) ((x)*3.1415f/180.0f)

/* types------------------------------------------------------------------------*/
typedef int8_t bool_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
//TODO typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;

typedef float float32_t;
typedef double float64_t;

typedef char shortText_t[40];
typedef char mediumText_t[255];
typedef char longText_t[1024];

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
/* none */


/* end */
#endif /* MYTYPES_H */
