#include "move_object.h"


void rotate_cube(int direction) {
    printf("callback rotate cube");
    ROTATE_CUBE = (GLdouble) direction;
    printf("RCUBE : %f", ROTATE_CUBE);
}

void rotate_pyramid(int direction) {
    printf("callback rotate pyramid");
    ROTATE_PYRAMID = (GLdouble) direction;
    printf("RPYRAMID : %f", ROTATE_PYRAMID);
}
