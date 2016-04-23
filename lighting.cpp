//***************************************************************************//
// Fichier C+                 TD Machine SY32                                //
//                                     Universite Technologique de Compiegne //
//                                                                           //
//  Interface OpenGL (GLUT, GLU, GL)                                         //
//  Librairies DLL : glut.dll                                                //
//                   glut32.dll                                              //
//                   opengl.dll										         //
//																		     //
//   facetisation d'une sphere : subdivision recursive						//
//			mode = 0	Filaire												//
// 			mode = 1    Flat												//
//			mode = 2	Gouraud sans lissage								//
//			mode = 3	Gouraud avec lissage								 //
//***************************************************************************//

//******************//
//Fichiers inclus : //
//******************//
/*

#include <math.h>
#include <stdio.h>
// glut base libs
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <stdlib.h>


GLdouble MatObjet[16]; // Matrice de transformation liee    la sphere
typedef double point[4];  // point ou vecteur :coord homog nes



point tetra[4] = {	{0., 0., 1.,1.},
						{0., .942809, -0.333333,1.},
						{-.816497,-.471405,-.3333333,1.},
						{0.816497,-.471405,-0.333333,1.}};

int mode = 0;




void dessine_repere(){
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    glVertex3d(0,0,0);
    glVertex3d(10,0,0);
    glColor3f(1, 0, 0);
    glVertex3d(0,0,0);
    glVertex3d(0,10,0);
    glColor3f(1, 0, 0);
    glVertex3d(0,0,0);
    glVertex3d(0,0,10);
    glEnd();

}
void normalise(point v)
{
	float n=0;
	int i;
	for(i=0; i<3; i++)
	{
		n+=v[i]*v[i];
	}

	n=sqrt(n);
	for(i=0; i<3; i++)
	{
		v[i] /=n;
	}
}

void AfficheTriangle(point a, point b, point c){
	 point n;
     point na, nb, nc;


    switch (mode) {
        case 0 :
            glBegin(GL_LINE_LOOP);
            n[0]=(a[0]+b[0]+c[0])/3;
            n[1]=(a[1]+b[1]+c[1])/3;
            n[2]=(a[2]+b[2]+c[2])/3;
            normalise(n);

            glNormal3dv(n);
            glColor3f(1, 0, 0);
            glVertex3dv(a);
            glColor3f(1, 0, 0);
            glVertex3dv(b);
            glColor3f(1, 0, 0);
            glVertex3dv(c);
        case 1 :
            glBegin(GL_POLYGON);
            glColor3f(1,0,0);
            n[0]=(a[0]+b[0]+c[0])/3;
            n[1]=(a[1]+b[1]+c[1])/3;
            n[2]=(a[2]+b[2]+c[2])/3;
            normalise(n);

            glNormal3dv(n);
            glVertex3dv(a);
            glVertex3dv(b);
            glVertex3dv(c);
        case 2 :
            glBegin(GL_POLYGON);
            glColor3f(1,0,0);

            n[0]=(a[0]+b[0]+c[0])/3;
            n[1]=(a[1]+b[1]+c[1])/3;
            n[2]=(a[2]+b[2]+c[2])/3;
            normalise(n);

            glNormal3dv(n);
            glVertex3dv(a);
            glVertex3dv(b);
            glVertex3dv(c);
        case 3 :
            glBegin(GL_POLYGON);
            na[0]=a[0];
            na[1]=a[1];
            na[2]=a[2];
            nb[0]=b[0];
            nb[1]=b[1];
            nb[2]=b[2];
            nc[0]=c[0];
            nc[1]=c[1];
            nc[2]=c[2];
            normalise(na);
            normalise(nb);
            normalise(nc);
            glColor3f(1,0,0);
            glNormal3dv(na);
            glVertex3dv(a);
            glNormal3dv(nb);
            glVertex3dv(b);
            glNormal3dv(nc);
            glVertex3dv(c);
    }


     glEnd();

}

void diviseTriangle(point p1, point p2, point p3,int n){
	point M12, M13, M23;
	int i;
	if (n==0){
		AfficheTriangle(p1,p2,p3);
	}else{
		for (i=0; i<3; i++){
			M12[i]=p1[i]+p2[i];
			M13[i]=p1[i]+p3[i];
			M23[i]=p2[i]+p3[i];
		}
		normalise(M12);
		normalise(M13);
		normalise(M23);
		diviseTriangle(p1, M12, M13, n-1);
		diviseTriangle(M12,p2,M23, n-1);
		diviseTriangle(M13,M23,p3, n-1);
		diviseTriangle(M12, M23, M13,n-1);
	}

}



void sphere(point a, point b, point c, point d, int n) {

	diviseTriangle(a,b,c,n);
	diviseTriangle(a,c,d,n);
	diviseTriangle(a,d,b,n);
	diviseTriangle(b,d,c,n);
}



void def_sources(void)
{
	// definition d'une source GL_LIGHT0
  GLfloat props[4];    // tableau des proprietes de la source

    //GLenum source;

    {
      props[ 0] = 0.1;
      props[ 1] = 0.1;
      props[ 2] = 0.1;
      props[ 3] = 1.;


      glLightfv(GL_LIGHT0,GL_AMBIENT,props);


      props[ 0] = 0.9 ;
      props[ 1] = 0.9;
      props[ 2] = 0.9;
      props[ 3] = 1.;
      glLightfv(GL_LIGHT0,GL_DIFFUSE,props);
      glLightfv(GL_LIGHT0,GL_SPECULAR,props);

      props[ 0] = 6;
      props[ 1] = 6;
      props[ 2] = 6;
      props[ 3] = 1;
      glLightfv(GL_LIGHT0,GL_POSITION,props);

      glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,180.0);
      glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,10);

      props[ 0] =-1 ;
      props[ 1] = -1;
      props[ 2] = -1 ;
      props[ 3] = sqrt(3.);
      glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,props);

      glEnable(GL_LIGHT0);
    }
}

void def_modele(void)
{
  GLfloat props[4];
  props[ 0] = 1;
  props[ 1] = 1;
  props[ 2] = 1;
  props[ 3] = 1 ;
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT,props);

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

}

void def_matiere(void)
{
   GLfloat props[4];

    GLubyte shiny_obj = 10;
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    props[ 0] = .1;
      props[ 1] = 0. ;
      props[ 2] = 0. ;
      props[ 3] = 1.;
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, props);

      props[ 0] = .9;
      props[ 1] = .2;
      props[ 2] = .1;
      props[ 3] = 1.;
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, props);

      props[ 0] = .9;
      props[ 1] = .9;
      props[ 2] = .9;
      props[ 3] = 1.;
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, props);


      glMateriali(GL_FRONT_AND_BACK, GL_SHININESS,shiny_obj);

      props[ 0] = 0.;
      props[ 1] = 0.;
      props[ 2] = 0.;
      props[ 3] = 0.;
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, props);

}




void dessineScene(void)
{
    dessine_repere();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
   // glMultMatrixd(MatObjet);  //a rajouter si animation par
    sphere(tetra[0],tetra[1],tetra[2],tetra[3], 3);
    glPopMatrix();
}



void touche_clavier(unsigned char key, int x, int y)  // A COMPLETER
{

  switch (key) {
  case '0' :
	  mode =0;
	  break;
  case '1' :
	  mode =1;
	  break;
  case '2' :
	  mode =2;
	  break;
  case '3' :
	  mode =3;
	  break;
  case 27:
    exit(0);
  }

    // A FAIRE Definir les modes d'eclairage en fonction de la variable mode
    switch (mode) {
     case 0:
            glDisable(GL_LIGHTING);
          //  glEnable(GL_LIGHTING);
            break;// pas de modele d'eclairage fixer une couleur
     case 1 :
            glEnable(GL_LIGHTING);
            glShadeModel(GL_FLAT);
            break;
            // utiliser le mod le d' clairage  modele constant
     case 2 :
            glEnable(GL_LIGHTING);
            glShadeModel(GL_SMOOTH);
            break;// utiliser le mod le d' clairage modele gouraud sans lissage
        case 3 :
            glEnable(GL_LIGHTING);
            glShadeModel(GL_SMOOTH);
            break;// utiliser le mod le d' clairage modele gouraud avec lissage
     }

  glutPostRedisplay();
}



void reshapeFunction(int width, int height)
{
 	glViewport(0,0,(GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(70,width/height,0.1,100) ;

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(3,1,1,0,0,0,0,0,1);
}


void displayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	dessineScene();
	glutSwapBuffers();

}


int main(int argc, char **argv)
{

	// A FAIRE saisie du nombre de subdivisions pour la fonction tetrahedre()

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(460,460);
	glutCreateWindow("TD SY32");

	// initialisations diverses
	glClearColor(0.1, 0.1,0.1,0);   //couleur de fond
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutReshapeFunc(reshapeFunction);
	glutDisplayFunc(displayFunction);
	//glutSpecialFunc(touche_special_appuye);

	//glutMouseFunc(click_souris);
	//glutMotionFunc(click_dep_souris);
	glEnable(GL_DEPTH_TEST);
  //  glEnable(GL_LIGHTING);
    glutKeyboardFunc(touche_clavier);

	def_modele();
	def_sources();
	def_matiere();
	glutMainLoop();
    return 0;
}

