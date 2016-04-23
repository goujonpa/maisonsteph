#ifndef MOVE_OBJECT_H_INCLUDED
#define MOVE_OBJECT_H_INCLUDED

// glut base libs
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <stdio.h>

extern int MODE;
extern bool INIT;
extern GLdouble ROTATE_PYRAMID;
extern GLdouble ROTATE_CUBE;

// movement
void rotate_cube(int direction);
void rotate_pyramid(int direction);


#endif // MOVE_OBJECT_H_INCLUDED
