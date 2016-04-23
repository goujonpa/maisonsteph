#include "draw_object.h"
#include "math.h"

int get_normal(Point a, Point b, Point c, Point w) {
    // calculates the normal vector at the point b
    // and stores it into w

    int i;
    GLdouble norm;
    // u and v are the vectors BA and BC
    Point u; // BA
    Point v; // BC

    // AB and BC coordinates calculation
    // BAi = Ai - Bi
    u[0] = a[0] - b[0];
    u[1] = a[1] - b[1];
    u[2] = a[2] - b[2];
    u[3] = 1;
    printf("u : [ %f , %f, %f, %f ]\n", u[0], u[1], u[2], u[3]);

    v[0] = c[0] - b[0];
    v[1] = c[1] - b[1];
    v[2] = c[2] - b[2];
    v[3] = 1;
    printf("v : [ %f , %f, %f, %f ]\n", v[0], v[1], v[2], v[3]);

    // cross product calculation
    w[0] = u[2]*v[3] - u[3]*v[2];
    w[1] = u[3]*v[1] - u[1]*v[3];
    w[2] = u[1]*v[2] - u[2]*v[1];
    w[3] = 1;
    printf("w : [ %f , %f, %f, %f ]\n", w[0], w[1], w[2], w[3]);

    // normalisation :
    norm = sqrt(w[0]*w[0] + w[1]*w[1] + w[2]*w[2]);
    for (i = 0; i < 3; i++) w[i] /= norm;
    printf("norm : %f\n", norm);
    printf("w : [ %f , %f, %f, %f ]\n", w[0], w[1], w[2], w[3]);

    return 1;
}

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
    Point normal;

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
            Point a = {1,1,1,1};
            Point b = {1,1,-1,1};
            Point c = {1,-1,-1,1};
            Point d = {1,-1,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);
        glEnd();
        // right
        glBegin(GL_POLYGON);
            Point e = {1,1,1,1};
            Point f = {-1,1,1,1};
            Point g = {-1,1,-1,1};
            Point h = {1,1,-1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,1);
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(1,1,-1);
        glEnd();
        // back
        glBegin(GL_POLYGON);
            Point i = {-1,1,1,1};
            Point j = {-1,1,-1,1};
            Point k = {-1,-1,-1,1};
            Point l = {-1,-1,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,-1,1);
        glEnd();
        // left
        glBegin(GL_POLYGON);
            Point m = {1,1,1,1};
            Point n = {1,1,-1,1};
            Point o = {1,-1,-1,1};
            Point p = {1,-1,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);
        glEnd();
        // bottom
        glBegin(GL_POLYGON);
            Point q = {1,1,-1,1};
            Point r = {1,-1,-1,1};
            Point s = {-1,-1,-1,1};
            Point t = {-1,1,-1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,1,-1);
        glEnd();
        // top
        glBegin(GL_POLYGON);
            Point u = {1,1,1,1};
            Point v = {1,-1,1,1};
            Point w = {-1,-1,1,1};
            Point x = {-1,1,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
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

    Point normal;
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
            Point a = {1,1,0,1};
            Point b = {-1,1,0,1};
            Point c = {-1,-1,0,1};
            Point d = {1,-1,0,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,0);
            glVertex3d(-1,1,0);
            glVertex3d(-1,-1,0);
            glVertex3d(1,-1,0);
        glEnd();
        // front
        glBegin(GL_POLYGON);
            Point e = {1,1,0,1};
            Point f = {1,-1,0,1};
            Point g = {0,0,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,0);
            glVertex3d(1,-1,0);
            glVertex3d(0,0,1);
        glEnd();
        // right
        glBegin(GL_POLYGON);
            Point h = {1,1,0,1};
            Point i = {-1,1,0,1};
            Point j = {0,0,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(1,1,0);
            glVertex3d(-1,1,0);
            glVertex3d(0,0,1);
        glEnd();
        // back
        glBegin(GL_POLYGON);
            Point k = {-1,1,0,1};
            Point l = {-1,-1,0,1};
            Point m = {0,0,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(-1,1,0);
            glVertex3d(-1,-1,0);
            glVertex3d(0,0,1);
        glEnd();
        // left
        glBegin(GL_POLYGON);
            Point n = {-1,-1,0,1};
            Point o = {1,-1,0,1};
            Point p = {0,0,1,1};
            switch (MODE) {
                case 1:
                    get_normal(a,b,c, normal);
                    glNormal3dv(normal);
                    break;
            }
            glVertex3d(-1,-1,0);
            glVertex3d(1,-1,0);
            glVertex3d(0,0,1);
        glEnd();

    // save current transfo state
    glGetDoublev(GL_MODELVIEW_MATRIX, pyramid_matrix);

    glPopMatrix();
}
