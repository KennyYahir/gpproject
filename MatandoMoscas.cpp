#include <time.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define For(x,a,b) for(int x=(a); x<(b); x++)
#define N 9
#define M 7
#define MODX 17*N
#define MODY 9*N
using namespace std;

int arr_randsx[20], arr_randsy[20], arr_randsz[20];

float mat[20][5], obj_width = 0.4;

bool eliminado[20] = {false};

GLfloat x,y,z, paso, dtx, dtz, incremento,ejex,ejey,ejez, xx, yy;
int ang;
GLfloat angcuad;

const GLfloat light_ambient[]   = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat light_diffuse[]   = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[]  = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat light_position[]  = {2.0f, 5.0f, 5.0f, 0.0f};

const GLfloat mat_ambient[]     = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[]     = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[]    = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[]  = {100.0f};

float a =  4.3, b=2.8;
float xr[20];
float yr[20];

#define ANCHOL 4
#define LARGOL 6

void idleevent()
{
   angcuad += 1;
   glutPostRedisplay();
}

void guardaPos(float x, float y, int i)
{
  mat[i][0] = x - obj_width/2;

  mat[i][1] = x + obj_width/2;
  mat[i][2] = y - obj_width/2;
  mat[i][3] = y + obj_width/2;  
}


void displayevent(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glRotatef( ang, 0,0,0 );
 glTranslatef( -2, 0, -15 );

 //LUCES
 glClearColor(1,1,1,1);
 glEnable(GL_CULL_FACE);
 glCullFace(GL_BACK);

 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LESS);

 glEnable(GL_LIGHT0);
 glEnable(GL_NORMALIZE);
 glEnable(GL_COLOR_MATERIAL);
 glEnable(GL_LIGHTING);

 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
 glLightfv(GL_LIGHT0, GL_POSITION, light_position);

 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_POSITION, high_shininess);

 //FIN LUCES        
                
//Fondo
        glColor3f(0,1,1);
        glPushMatrix();
        glTranslatef(2.5,2.5,-.9);
        glRotated(0,0,0,0);
        glScalef(13,7,.2);
        glutSolidCube(1);
        glPopMatrix();

//Piso
         glPushMatrix();
         glColor3f(.67,.40,.20);
         glTranslatef(2.6,-1.1,0);
         glRotated(0,0,0,0);
         glScalef(15.2,.1,5);
         glutSolidCube(1);
         glPopMatrix();


//Techo segundo nivel
         glPushMatrix();
         glColor3f(1,0,0);
         glTranslatef(3.6,1.1,0);
         glRotated(0,0,0,0);
         glScalef(5,.2,2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito abajo
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(-1.4,-1,-.9);
         glRotated(0,0,0,0);
         glScalef(.4,.4,.2);
         glutSolidCube(1);
         glPopMatrix();

//Palito
         glColor3f(0,1,0);
         glPushMatrix();
         glTranslatef(-1.4,2.2,-.9);
         glRotated(0,0,0,0);
         glScalef(.1,6,.1);
         glutSolidCube(1);
         glPopMatrix();

//Punta de Palito
         glColor3f(0,1,0);
         glPushMatrix();
         glTranslatef(-1.4,5.2,-.9);
         glRotated(0,0,0,0);
         glScalef(.15,.15,.15);
         glutSolidCube(1);
         glPopMatrix();


//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(1.9,3.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(2.9,3.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(3.9,3.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(4.9,3.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(5.9,3.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Cubito arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(5.9,2.6,-.9);
         glRotated(0,0,0,0);
         glScalef(.5,.5,.2);
         glutSolidCube(1);
         glPopMatrix();

//Pared trasera arriba
         glColor3f(1,0,0);
         glPushMatrix();
         glTranslatef(3.9,2.3,-.9);
         glRotated(0,0,0,0);
         glScalef(4.5,2,.2);
         glutSolidCube(1);
         glPopMatrix();

//Puerta 1 segundo nivel

        glPopMatrix();
        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(2.7,1.8,.9);
        glRotated(0,0,0,0);
        glScalef(.6,.8,.2);
        glutSolidCube(1);

 //Puerta 2 segundo nivel

        glPopMatrix();
        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(4.6,1.8,.9);
        glRotated(0,0,0,0);
        glScalef(.6,.8,.2);
        glutSolidCube(1);

  //Puerta primer nivel

        glPopMatrix();
        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(3.5,0,.95);
        glRotated(0,0,0,0);
        glScalef(.6,.8,.2);
        glutSolidCube(1);

 //Frente planta baja
        glPopMatrix();
        glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(3.6,0,.9);
        glRotated(0,0,0,0);
        glScalef(5,2,.2);
        glutSolidCube(1);
        glPopMatrix();

//objetivos
        int inix = -6, iniy = -3, iniz = -1;
        
        For(t,0,16)
        {
          if(!mat[t][4])
            mat[t][4] = iniz;

          guardaPos(inix + arr_randsx[t]/(float)N,iniy + arr_randsy[t]/(float)N,t);

          //glColor3f(0, 0, 0);
          
          glColor3f(0.6, 0, 0.6);

          glPushMatrix();
          glTranslatef((float)inix + (float)arr_randsx[t]/(float)N, (float)iniy + (float)arr_randsy[t]/(float)N, mat[t][4]);          
          glRotated(0,0,0,0);
          glScalef(obj_width, obj_width, obj_width);
          glutSolidCube(1);
          glPopMatrix();
        }


       //rayo       
       /*glPushMatrix();
       glColor3f(0.5,0.5,0.5);
       glTranslatef(2.1,ejey +.1, ejez + 12);
       glRotatef((GLfloat)ang,0,1,0);
       glScalef(0.05,0.05,0.4);
       glutSolidCube(1);
       glPopMatrix();*/


        glPushMatrix ();
         glColor3f(.6,.6,.6);
         glTranslatef(ejex+2,ejey+.1,ejez + 12);
         glRotatef((GLfloat)ang,0,1,0);
         glScalef(0.1,0.1,0.4);
         glutSolidCube(1);
         glPopMatrix ();

         glPushMatrix ();
         glColor3f(.6,.6,.6);
         glTranslatef(ejex+2,ejey,ejez+.1 + 12);
         glRotatef((GLfloat)ang,0,1,0);
         glScalef(0.1,0.1,0.1);
         glutSolidCube(1);
         glPopMatrix ();

         glPushMatrix ();
         glColor3f(.6,.6,.6);
         glTranslatef(ejex+2,ejey+.15,ejez+.1 + 12);
         glRotatef((GLfloat)ang,0,1,0);
         glScalef(0.05,0.05,0.05);
         glutSolidCube(1);
         glPopMatrix ();



       glPushMatrix ();
       //glColor3f(1,1,0);
       glColor3f(0,0,0);
       glTranslatef(xx,yy,-0.9);       
       //glScalef(0.04,0.04,0.04);
       glScalef(0.1,0.1,0.1);
       glutSolidCube(1);
       glPopMatrix ();

      glutSwapBuffers();

}

int atina(float x, float y)
{
  for(int i=0; i<20; i++)
  {
    if(mat[i][0] <= x && mat[i][1] >= x)
      if(mat[i][2] <= y && mat[i][3] >= y)
        eliminado[i] = true; // Si le dio al objeto
  }
  return 0;  
}


float dtr( float d )
{
  return d*3.141592/180;
}

void specialkeyevent( int key, int Xx, int Yy )
{
 float angrad;
 switch ( key ) {
   
   case GLUT_KEY_LEFT:      
        ang = (ang + 1) % 100;      
        xx-= 0.1;  
      break;
   
   case GLUT_KEY_RIGHT:
      ang = (ang - 1) % 100;
      xx += 0.1;
      break;
   
   case GLUT_KEY_UP:
    y -= 0.01;
    ejey+= 0.01;
    yy += 0.055;
    break;
   
    case GLUT_KEY_DOWN:
    y += 0.01;
    ejey-= 0.01;
    yy -= 0.055;
    break;
    
    case GLUT_KEY_F1:
    
    int a=atina(xx,yy);
    //printf("%d\n",a);

    for(int i=0; i<20; i++)
      if(eliminado[i] == true)
        mat[i][4] = 20;//Solo lo alejamos de la escena

    break;
 }

  glutPostRedisplay();
}

void reshapeevent(GLsizei width, GLsizei height)
{

 glViewport(0,0,width,height);

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();

 gluPerspective(45,(GLfloat)width/(GLfloat)height,  0.01, 100);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}

int main(int argc, char** argv)
{
   //srand(2);
  srand(time(NULL));

   For(i,0,20)arr_randsx[i] = rand()%MODX , arr_randsy[i] = rand()%(MODY);
   //printf("%.2f %.2f\n", arr_randsx[i]/(float)N, arr_randsy[i]/(float)N);
   


   glutInit( &argc, argv );
   //srand (time(NULL));

   glutInitWindowSize( 1100, 700 );
   glutInitWindowPosition( 100, 100 );
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
   glutCreateWindow( "" );
   glutSetWindowTitle("Matando Moscas");

   ang = 0;
   angcuad = 0;
   x = 0;
   y = 0;
   z = - 3 - 12;
   paso = 0.1;
   dtx = 0;
   dtz = paso;
   yy=0;
   xx=2.5;

   glEnable( GL_DEPTH_TEST );
   glutReshapeFunc (reshapeevent);
   glutDisplayFunc( displayevent );
   
   glutSpecialFunc( specialkeyevent );
   glutIdleFunc( idleevent );

   glutMainLoop();

   return 0;
}
