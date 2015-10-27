//
//  main.cpp
//  harryglb
//
//  Created by student on 10/27/15.
//  Copyright © 2015 harrymike. All rights reserved.
//

/*
 * Copyright (c) 2009, 2014 University of Michigan, Ann Arbor.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of Michigan, Ann Arbor. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Authors: Manoj Rajagopalan, Sugih Jamin
 */
#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define NENDS 6           /* number of end "points" to draw */

GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
int ends[NENDS][2];       /* array of 2D points */


/* Program initialization NOT OpenGL/GLUT dependent,
 as we haven't created a GLUT window yet */
void
init(void)
{
    width  = 1280.0;                 /* initial window width and height, */
    height = 800.0;                  /* within which we draw. */
    ends[0][0] = (int)(0.25*width);  /* (0,0) is the lower left corner */
    ends[0][1] = (int)(0.75*height);
    
    ends[1][0] = (int)(0.75*width);
    ends[1][1] = (int)(0.25*height);
    
    ends[2][0] = (int)(0.25*width);
    ends[2][1] = (int)(0.25*height);
    
    ends[3][0] = (int)(0.45*width);
    ends[3][1] = (int)(0.85*height);
    
    ends[4][0] = (int)(0.25*width);
    ends[4][1] = (int)(0.25*height);
    
    ends[5][0] = (int)(0.75*width);
    ends[5][1] = (int)(0.75*height);
    
    return;
}


/* Callback functions for GLUT */

/* Draw the window - this is where all the GL actions are */
void
display(void)
{
    int i;
    
    /* clear the screen to white */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* draw a black line */
    glBegin(GL_LINES);     // <== not modern,  according to opengl-tutorial.org
      for (i = 0; i < NENDS; ++i) {
        glVertex2iv((GLint *) ends[i]);     /// ?? what is iv ?
      }
    glEnd();
    glFlush();
    
    return;
}


/* Called when window is resized,
 also when window is first created,
 before the first call to display(). */
void
reshape(int w, int h)
{
    /* save new screen dimensions */
    width = (GLdouble) w;
    height = (GLdouble) h;
    
    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    
    /* do an orthographic parallel projection with the coordinate
     system set to first quadrant, limited by screen/window size */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f);
    
    return;
}


/* 
 Experiment to move the endpoints when 'd' is pressed;
 Note: resizing the window forces a redraw!
*/
void
wiggle(  ) {
    for (int i = 0; i < NENDS; ++i) {
        ends[i][0] = (int) (ends[i][0] * 0.5 );
        ends[i][1] = (int) (ends[i][1] * 0.3 );
    }
    
}




void
kbd(unsigned char key, int x, int y)
{
    switch((char)key) {
        case 'q':
        case 27:    /* ESC */
            glutDestroyWindow(wd);      // <-- deprecated in os x 10.9
            exit(0);
        
        case 'd':
            wiggle( );
            break;
            
        default:
            break;
    }
    
    return;
}


int
main(int argc, char *argv[])
{
    /* perform initialization NOT OpenGL/GLUT dependent,
     as we haven't created a GLUT window yet */
    init( );
    
    /* initialize GLUT, let it extract command-line
     GLUT options that you may provide
     - NOTE THE '&' BEFORE argc */
    glutInit(&argc, argv);// <-- deprecated in os x 10.9
    
    /* specify the display to be single
     buffered and color as RGBA values */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// <-- deprecated in os x 10.9
    
    /* set the initial window size */
    glutInitWindowSize((int) width, (int) height);// <-- deprecated in os x 10.9
    
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Experiment with line drawing" /* title */ );// <-- deprecated in os x 10.9
    
    /* --- register callbacks with GLUT --- */
    
    /* register function to handle window resizes */
    glutReshapeFunc(reshape);// <-- deprecated in os x 10.9
    
    /* register keyboard event processing function */
    glutKeyboardFunc(kbd);// <-- deprecated in os x 10.9
    
    /* register function that draws in the window */
    glutDisplayFunc(display);// <-- deprecated in os x 10.9
    
    /* init GL */
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    
    /* start the GLUT main loop */
    glutMainLoop();// <-- deprecated in os x 10.9
    
    exit(0);
}