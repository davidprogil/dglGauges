/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <Wrapper2D.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
D2DW_Wrapper2D_t *thisWrapper2D; /* singleton */

/* local prototypes -----------------------------------------------------------*/
void D2DW_reshape(GLsizei width, GLsizei height);
void D2DW_UpdateAspect();

/* public functions -----------------------------------------------------------*/
void D2DW_Init(	D2DW_Wrapper2D_t *this,
		void *renderFuntion,
		void *keyboardFuntion,
		void *mouseClickFuntion,
		uint16_t sizeX,uint16_t sizeY)
{
	printf("D2DW_Init\n");
	int argc = 0;
	char **argv = NULL;

	thisWrapper2D=this;
	thisWrapper2D->sizeX=sizeX;
	thisWrapper2D->sizeY=sizeY;
	D2DW_UpdateAspect();

	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(sizeX,sizeY);
	glViewport(0, 0, sizeX, sizeY);


	// Create window
	glutCreateWindow("Car Simulator");

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	// Enable Z-buffer depth test
	//glEnable(GL_DEPTH_TEST);
	thisWrapper2D->viewOx=0.0f;thisWrapper2D->viewOy=0.0f;
	thisWrapper2D->viewDx=1.0f;thisWrapper2D->viewDy=1.0f;
	//printf("ORTHO %f %f\n",thisWrapper2D->viewOy,thisWrapper2D->viewDy);//DEBUG
	gluOrtho2D(0.0, 1.0, 0.0, 1.0); // Set clipping area's left, right, bottom, top

	// Callback functions
	glutDisplayFunc(renderFuntion);//TODO remove from parameters if not necessary
	glutSpecialFunc(keyboardFuntion);
	glutMouseFunc(mouseClickFuntion);
	glutReshapeFunc(D2DW_reshape);       // Register callback handler for window re-size event


}

void D2DW_Execute()
{
	printf("D2DW_Execute\n");
	//TODO remove if not needed
}

void D2DW_RenderSample()
{
	// Draw a Red 1x1 Square centered at origin
		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex2f( 0.0f, 0.0f);    // x, y
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f( 1.0f,  0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f( 1.0f,  1.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f( 0.0f,  1.0f);
		glEnd();
}
void D2DW_RenderSampleView()
{
	printf("D2DW_RenderSampleView\n");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f( 0.0f, 0.0f);    // x, y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f( 1.0f,  0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f( 1.0f,  1.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f( 0.0f,  1.0f);
	glEnd();

	glFlush();  // Render now
}

void UpdateView()
{
	glutPostRedisplay();
}

void D2DW_Start()
{
	printf("D2DW_Start\n");
	// Pass control to GLUT for events
	glutMainLoop();
}

void D2DW_Timer(void *function,uint16_t msecs)
{
	glutTimerFunc(msecs, function, 1 );
}
void D2DW_Pixel2View(int x, int y, float32_t* xFloat, float32_t* yFloat)
{
	int xOrigin=0;
	int yOrigin=0;
	float32_t scaleX=1.0f;
	float32_t scaleY=1.0f;
	if (thisWrapper2D->aspect>1.0f)
	{
		xOrigin=(thisWrapper2D->sizeX-thisWrapper2D->sizeY)/2;
		scaleX=1.0f/thisWrapper2D->aspect;
	}
	else
	{
		yOrigin=(thisWrapper2D->sizeY-thisWrapper2D->sizeX)/2;
		scaleY=1.0f*thisWrapper2D->aspect;
	}
	*xFloat=(x-xOrigin)*1.0f/(thisWrapper2D->sizeX*scaleX)*(thisWrapper2D->viewDx)+thisWrapper2D->viewOx;
	*yFloat=(thisWrapper2D->sizeY-y-yOrigin)*1.0f/(thisWrapper2D->sizeY*scaleY)*(thisWrapper2D->viewDy)+thisWrapper2D->viewOy;
}

/* local functions ------------------------------------------------------------*/
void D2DW_reshape(GLsizei width, GLsizei height)
{  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	thisWrapper2D->sizeX=width;
	thisWrapper2D->sizeY=height;
	D2DW_UpdateAspect();


	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * thisWrapper2D->aspect, 1.0 * thisWrapper2D->aspect, -1.0, 1.0);
	} else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / thisWrapper2D->aspect, 1.0 / thisWrapper2D->aspect);
	}
}

void D2DW_StartView()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glColor3f(1.0f, 0.0f, 0.0f); // Red 	//TODO remove this stuff
}

void D2DW_UpdateAspect()
{
	thisWrapper2D->aspect = (GLfloat)thisWrapper2D->sizeX / (GLfloat)thisWrapper2D->sizeY;
}

void D2DW_StartLineStrip()//TODO inline
{
	//DEBUG printf("D2DW_StartLineStrip\n");
	glBegin(GL_LINE_STRIP);
}
void D2DW_EndLineStrip()//TODO inline
{
	//DEBUG printf("D2DW_EndLineStrip\n");
	glEnd();
}

void D2DW_StartPolygon()//TODO inline
{
	//DEBUG printf("D2DW_StartLineStrip\n");
	glBegin(GL_POLYGON);
}
void D2DW_EndPolygon()//TODO inline
{
	//DEBUG printf("D2DW_EndLineStrip\n");
	glEnd();
}
void D2DW_RenderPoint(float32_t x,float32_t y)//TODO inline
{
	//DEBUG printf("D2DW_RenderPoint %f %f\n",x,y);
	glVertex2f( x,  y);
}

void D2DW_Flush()//TODO inline
{
	glFlush();  // Render now
}

void D2DW_SetColour(float32_t r,float32_t g,float32_t b) //TODO inline
{
	//DEBUG printf("D2DW_SetColour %f %f %f\n",r,g,b);
	glColor3f(r,g,b);
}
/* end */
