#include "draw_object.h"

void draw_axis() {
    // draws the orthonormed system axis

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        // shape drawing
        glBegin(GL_LINES); // GL_LINES : pairs of points = segments
            glColor3f(1,1,1); // white
            glVertex3d(0,0,0);
            glVertex3d(10,0,0);
            glVertex3d(0,0,0);
            glVertex3d(0,10,0);
            glVertex3d(0,0,0);
            glVertex3d(0,0,10);
        glEnd();
    glPopMatrix();
}

void draw_quad(GLdouble height, GLdouble width) {
    // draws a quad

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3d(0.5,1,0.5); // green
            glVertex2d(-width/2,-height/2);
            glVertex2d(width/2,-height/2);
            glVertex2d(width/2,-(height/2-0.1*height));
            glVertex2d(-width/2,-(height/2-0.1*height));
        glEnd();
    glPopMatrix();
}

void draw_cube() {
    // draws a cube

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    if (!INIT) {
        glLoadMatrixd(cube_matrix);
    }

    if (ROTATE_CUBE != 0) {
        GLdouble angle = (GLdouble) 5. * ROTATE_CUBE;
        glRotated(angle, 0, 0, 1);
        ROTATE_CUBE = 0;
    }

        // shape drawing
        // front
        glBegin(GL_POLYGON);
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);
        glEnd();
        // right
        glBegin(GL_POLYGON);
            glVertex3d(1,1,1);
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(1,1,-1);
        glEnd();
        // back
        glBegin(GL_POLYGON);
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,-1,1);
        glEnd();
        // left
        glBegin(GL_POLYGON);
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);
        glEnd();
        // bottom
        glBegin(GL_POLYGON);
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,1,-1);
        glEnd();
        // top
        glBegin(GL_POLYGON);
            glVertex3d(1,1,1);
            glVertex3d(1,-1,1);
            glVertex3d(-1,-1,1);
            glVertex3d(-1,1,1);
        glEnd();

    glGetDoublev(GL_MODELVIEW_MATRIX, cube_matrix);
    glPopMatrix();
}

void draw_pyramid() {
    // draws a pyramid

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // if first time we draw, translate, else load anterior
    // transfo matrix
    if (INIT) {
        glTranslatef(0, 0, 2);
    }
    else {
        glLoadMatrixd(pyramid_matrix);
    }

    // if rotation, rotate
    if (ROTATE_PYRAMID != 0) {
        GLdouble angle = (GLdouble) 5 * ROTATE_PYRAMID;
        glRotated(angle, 0, 0, 1);
        ROTATE_PYRAMID = 0;
    }

        // bottom
        glBegin(GL_POLYGON);
            glVertex3d(1,1,0);
            glVertex3d(-1,1,0);
            glVertex3d(-1,-1,0);
            glVertex3d(1,-1,0);
        glEnd();
        // front
        glBegin(GL_POLYGON);
            glVertex3d(1,1,0);
            glVertex3d(1,-1,0);
            glVertex3d(0,0,1);
        glEnd();
        // right
        glBegin(GL_POLYGON);
            glVertex3d(1,1,0);
            glVertex3d(-1,1,0);
            glVertex3d(0,0,1);
        glEnd();
        // back
        glBegin(GL_POLYGON);
            glVertex3d(-1,1,0);
            glVertex3d(-1,-1,0);
            glVertex3d(0,0,1);
        glEnd();
        // left
        glBegin(GL_POLYGON);
            glVertex3d(-1,-1,0);
            glVertex3d(1,-1,0);
            glVertex3d(0,0,1);
        glEnd();
    int i = 0;

    // save current transfo state
    glGetDoublev(GL_MODELVIEW_MATRIX, pyramid_matrix);

    for (i = 0; i < 16; i++) {
        printf("%f | ", pyramid_matrix[i]);
    }
    glPopMatrix();
}
