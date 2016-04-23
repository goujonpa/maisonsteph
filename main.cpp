/*
 * GLUT Midterm training
 *
 * Written by Paul GOUJON Apr 2016
 *
 */
/*
#include "main.h"

void display() {
    int i = 0;
    printf("rcube %f\n", ROTATE_CUBE);
    printf("rpyarmid %f\n",ROTATE_PYRAMID);

    // reset color buffer (always before redisplaying)
    glClearColor(0,0,0,0); // set clear color
    glClear(GL_COLOR_BUFFER_BIT); // clear frame buffer
    glClear(GL_DEPTH_BUFFER_BIT); // clear z buffer

    // drawing the orthonormed system
    draw_axis();

    // draw cube for house's body
    glColor3f(0.8, 0.8, 0.8);
    draw_cube();

    // drawing a quad
    // draw_quad(HEIGHT, WIDTH);

    // drawing a pyramid on top of the cube
    glColor3f(0.4, 0.4, 0.4);
    draw_pyramid();

    if (INIT == true) INIT = false;
    printf("matrix");
    for (i = 0; i < 16; i++) {
        printf("%f, ", pyramid_matrix[i]);
    }
    glutSwapBuffers();
}

void reshape(int width, int heigth) {
    // fixes potential display problems when resizing the main window

    // first we have to fix the viewport
    glViewport(0, 0, (GLsizei) width, (GLsizei) heigth);
/*
    // then to reset the perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 1.0, 0.1, 100);

    // and the display
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYEX, EYEY, EYEZ, CENTERX, CENTERY, CENTERZ, UPX, UPY, UPZ);
}
*//*
void keyboard(unsigned char key, int x, int y) {
    // adds some keys interactions

    switch(key) {
        case 27:
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void special_keyboard(int key, int x, int y) {
    // adds some special keys interactions

    switch(key) {
        case GLUT_KEY_DOWN:
            rotate_cube(1);
            break;
        case GLUT_KEY_UP:
            rotate_cube(-1);
            break;
        case GLUT_KEY_RIGHT:
            rotate_pyramid(1);
            break;
        case GLUT_KEY_LEFT:
            rotate_pyramid(-1);
            break;
    }
    glutPostRedisplay();
}

void idle() {
    // called function after any event
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    //NOTE : global vars initialised in main.h

    // general initialisation GLUT
    glutInit(&argc, argv);

    // init display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // init window
    glutInitWindowPosition(10,10);
    glutInitWindowSize(HEIGHT,WIDTH);
    glutCreateWindow("La maison de Steph");

    // display function
    glutDisplayFunc(display);

    // reshape
    glutReshapeFunc(reshape);

    // idle

    // keyboard
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keyboard);

    // Initial parameters
    // set projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90,1.0,0.1,100) ;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Loads the camera's parameters into the MODELVIEW matrix
    // global vars are initialised in main.h
    gluLookAt(EYEX, EYEY, EYEZ, CENTERX, CENTERY, CENTERZ, UPX, UPY, UPZ);

    // enable Z buffer
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return EXIT_SUCCESS;
}
*/
