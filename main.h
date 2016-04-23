#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

// glut base libs
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

// custom includes
#include "draw_object.h"
#include "external.h"
// mode
extern int MODE;

// used to see at which state of the execution we are
extern bool INIT;

// shapes parameters
extern int SLICES;
extern int STACKS;

// Should we rotate ?
// 0, 1 or -1 (no, yes direction 1, yes direction 2)
extern GLdouble ROTATE_CUBE;
extern GLdouble ROTATE_PYRAMID;

// maths
// identity matrix as a vector
extern GLdouble IDENTITY[16];

// storing the cube's transformations
extern GLdouble cube_matrix[16];
extern GLdouble pyramid_matrix[16];


// window size
GLdouble HEIGHT = 640;
GLdouble WIDTH = 480;

// lookat
GLdouble EYEX = 5;
GLdouble EYEY = 5;
GLdouble EYEZ = 5;
GLdouble CENTERX = 0;
GLdouble CENTERY = 0;
GLdouble CENTERZ = 0;
GLdouble UPX = 0;
GLdouble UPY = 0;
GLdouble UPZ = 1;

// prototypes
int main(int argc, char *argv[]);
void display();
void reshape();

#endif // MAIN_H_INCLUDED
