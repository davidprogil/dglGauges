
/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.

/* application includes--------------------------------------------------------*/
#include<myTypes.h>
#include<SimulationControl.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
SCRT_SimulationControl_t myCarSimulator;

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
int main(void)
{

	printf("DGL Gauges - Example \n");

	/* logic */
	/* MFD
	 * - Panel 1
	 * 	- instr 1 1
	 * 	- instr 1 2
	 * - Panel 2
	 * 	- instr 2 1
	 * 	- instr 2 2
	 */

	SCRT_Init(&myCarSimulator);

	/* pass application control to simulator */
	SCRT_Start(&myCarSimulator,M_TRUE);


	return EXIT_SUCCESS;
}
/* local functions ------------------------------------------------------------*/


/* end */





