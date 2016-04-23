#include "external.h"

// mode
int MODE = 0;

// used to see at which state of the execution we are
bool INIT = true;

// shapes slices & stacks
int SLICES = 16;
int STACKS = 16;

// Should we rotate ?
// 0, 1 or -1 (no, yes direction 1, yes direction 2)
GLdouble ROTATE_CUBE = 0.;
GLdouble ROTATE_PYRAMID = 0.;

// maths
// identity matrix as a vector
GLdouble IDENTITY[16] = {1., 0., 0., 0.,
    0., 1., 0., 0.,
    0., 0., 1., 0.,
    0., 0., 0., 1.
};
GLdouble cube_matrix[16] = {1., 0., 0., 0.,
    0., 1., 0., 0.,
    0., 0., 1., 0.,
    0., 0., 0., 1.
};
GLdouble pyramid_matrix[16] = {1., 0., 0., 0.,
    0., 1., 0., 0.,
    0., 0., 1., 0.,
    0., 0., 0., 1.
};

