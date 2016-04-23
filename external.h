#ifndef EXTERNAL_H_INCLUDED
#define EXTERNAL_H_INCLUDED

// glut base libs
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

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


#endif // EXTERNAL_H_INCLUDED
