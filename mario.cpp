
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

GLfloat x,y,z, ang, paso, dtx, dtz, incremento,ejex,ejey,ejez;
GLfloat angcuad;

const GLfloat light_ambient[]   = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat light_diffuse[]   = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[]  = {0.0f, 0.0f, 0.0f, 0.0f};
const GLfloat light_position[]  = {2.0f, 5.0f, 5.0f, 0.0f};

const GLfloat mat_ambient[]     = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[]     = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[]    = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[]  = {100.0f};

#define ANCHOL 4
#define LARGOL 6

void idleevent()
{
   angcuad += 1;
   glutPostRedisplay();
}

/*void carga()
{
  GLuint textura = 0;
  //SDL_Surface * screen = SDL_SetVideoMode(800, 600, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
  SDL_Surface* imagen = IMG_Load("pasto.jpg");

  glGenTextures(1, &textura);                             //crea nombres de texturas, recibe cantidad y recibe el arreglo en el cuál guardará los nombres de las texturas
  glBindTexture(GL_TEXTURE_2D, textura);                  //une un target con una textura, en este caso el target es GL_TEXTURE_2D y textura la textura que le unirá

  int Mode = GL_RGB;

  if(imagen->format->BytesPerPixel == 4)
  {
      Mode = GL_RGBA;
  }

  glTexImage2D(GL_TEXTURE_2D, 0, Mode, imagen->w, imagen->h, 0, Mode, GL_UNSIGNED_BYTE, imagen->pixels);   //especifica una imagen de textura de 2 dimensiones, recibe el target de la textura, el nivel de detalle en número; 0 es el nivel base, el número de colores que componen a la textura en este caso todos los que existan en RGB,  el ancho de la textura, el alto de la textura, el borde el cuál siempre debe ser 0, el formato del pixel, el tipo de dato del pixel, el puntero hacia la imagen que será utilizada

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //establece los parámetross de la textura, el target de la textura, nombre simbólico de un parámetro de un solo valor de la textura, especifica el valor del parámetro anterior
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


  glDeleteTextures(1, &textura);
}*/

/*void carga2()
{
  GLuint textura = 0;
  //SDL_Surface * screen = SDL_SetVideoMode(800, 600, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
  SDL_Surface* imagen = IMG_Load("cielo.jpg");

  glGenTextures(1, &textura);                             //crea nombres de texturas, recibe cantidad y recibe el arreglo en el cuál guardará los nombres de las texturas
  glBindTexture(GL_TEXTURE_2D, textura);                  //une un target con una textura, en este caso el target es GL_TEXTURE_2D y textura la textura que le unirá

  int Mode = GL_RGB;

  if(imagen->format->BytesPerPixel == 4)
  {
      Mode = GL_RGBA;
  }

  glTexImage2D(GL_TEXTURE_2D, 0, Mode, imagen->w, imagen->h, 0, Mode, GL_UNSIGNED_BYTE, imagen->pixels);   //especifica una imagen de textura de 2 dimensiones, recibe el target de la textura, el nivel de detalle en número; 0 es el nivel base, el número de colores que componen a la textura en este caso todos los que existan en RGB,  el ancho de la textura, el alto de la textura, el borde el cuál siempre debe ser 0, el formato del pixel, el tipo de dato del pixel, el puntero hacia la imagen que será utilizada

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //establece los parámetross de la textura, el target de la textura, nombre simbólico de un parámetro de un solo valor de la textura, especifica el valor del parámetro anterior
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
*/

void displayevent(void)
{
 //carga();
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glRotatef( ang, 0,1,0 );
 glTranslatef( -ANCHOL/2.0+x, y, z );

 //TEXTURAS
 /*glEnable(GL_TEXTURE_2D);
 glEnable( GL_DEPTH_TEST );
 glBegin(GL_QUADS);
 glTexCoord2f( 0.0f, 5.0f );
 glVertex3f( -20, -1, 20 );
 glTexCoord2f( 7.0f, 5.0f );
 glVertex3f(  20, -1, 20 );
 glTexCoord2f( 7.0f, 0.0f );
 glVertex3f(  20,-0.9, -20 );
 glTexCoord2f( 0.0f, 0.0f );
 glVertex3f( -20,-0.9,-20);
 glEnd();

 //carga2();*/
 /*glColor3f(0,1,1);
 glBegin(GL_QUADS);
      glTexCoord2f( 0.0f, 1.0f );
      glVertex3f( -20, 11, 20 );
      glTexCoord2f( 1.0f, 1.0f );
      glVertex3f(  20, 11, 20 );
      glTexCoord2f( 1.0f, 0.0f );
      glVertex3f(  20,11.1, -20 );
      glTexCoord2f( 0.0f, 0.0f );
      glVertex3f( -20,11.1,-20);
    glEnd();
 glColor3f(0,1,1);
 glBegin(GL_QUADS);
      glTexCoord2f( 0.0f, 1.0f );
      glVertex3f( -20, -1, 20 );
      glTexCoord2f( 1.0f, 1.0f );
      glVertex3f(  -20, 11.1, 20 );
      glTexCoord2f( 1.0f, 0.0f );
      glVertex3f(  -20,11.1, -20.2 );
      glTexCoord2f( 0.0f, 0.0f );
      glVertex3f( -20,-1,-20.2);
    glEnd();
 glColor3f(0,1,1);
 glBegin(GL_QUADS);
      glTexCoord2f( 0.0f, 1.0f );
      glVertex3f( 20, -1, 20 );
      glTexCoord2f( 1.0f, 1.0f );
      glVertex3f(  20, 11.1, 20 );
      glTexCoord2f( 1.0f, 0.0f );
      glVertex3f(  20,11.1, -20.2 );
      glTexCoord2f( 0.0f, 0.0f );
      glVertex3f( 20,-1,-20.2);
    glEnd();
 glColor3f(0,1,1);
 glBegin(GL_QUADS);
      glTexCoord2f( 0.0f, 1.0f );
      glVertex3f( -20, -1, -20 );
      glTexCoord2f( 1.0f, 1.0f );
      glVertex3f(  20, -1, -20 );
      glTexCoord2f( 1.0f, 0.0f );
      glVertex3f(  20,11.1, -20);
      glTexCoord2f( 0.0f, 0.0f );
      glVertex3f( -20,11.1,-20);
    glEnd();
*/
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
//objetivo
        //For(t,0,20)
        {
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-1,-1,-.9);
        glRotated(0,0,0,0);
        glScalef(.2,.2,.2);
        glutSolidCube(1);
        glPopMatrix();
       	}

//Pistola:

 glPushMatrix ();
 glColor3f(.6,.6,.6);
 glTranslatef(ejex+2,ejey+.1,ejez + 12);
 glScalef(0.1,0.1,0.4);
 glutSolidCube(1);
 glPopMatrix ();

 glPushMatrix ();
 glColor3f(.6,.6,.6);
 glTranslatef(ejex+2,ejey,ejez+.1 + 12);
 glScalef(0.1,0.1,0.1);
 glutSolidCube(1);
 glPopMatrix ();

 glPushMatrix ();
 glColor3f(.6,.6,.6);
 glTranslatef(ejex+2,ejey+.15,ejez+.1 + 12);
 glScalef(0.05,0.05,0.05);
 glutSolidCube(1);
 glPopMatrix ();

glutSwapBuffers();

}


float dtr( float d )
{
  return d*3.141592/180;
}

void specialkeyevent( int key, int Xx, int Yy )
{
 float angrad;
 switch ( key ) {
 case GLUT_KEY_UP:
      x-=dtx;
      ejex+=dtx;
      z+=dtz;
       ejez-=dtz;      
      break;
 case GLUT_KEY_DOWN:
      x+=dtx;
        ejex-=dtx;
      z-=dtz;
        ejez+=dtz;
      break;
 case GLUT_KEY_LEFT:
    ang -= 2;
    angrad = dtr(ang);
    dtx = paso * sin(angrad);
    ejex-= paso * cos(angrad);
    dtz = paso * cos(angrad);
    ejez-= paso * sin(angrad);
    break;
 case GLUT_KEY_RIGHT:
    ang += 2;
    angrad = dtr(ang);
    dtx = paso * sin(angrad);
     ejex+= paso * cos(angrad);
    dtz = paso * cos(angrad);
     ejez+= paso * sin(angrad);
    break;
 case GLUT_KEY_HOME:
  y += 0.1;
  ejey-= 0.1;
  break;
 case GLUT_KEY_END:
  y -= 0.1;
  ejey+= 0.1;
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
   glutInit( &argc, argv );

   glutInitWindowSize( 1100, 700 );
   glutInitWindowPosition( 100, 100 );
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
   glutCreateWindow( "" );
   glutSetWindowTitle(" Mario Bros ");

   ang = 0;
   angcuad = 0;
   x = 0;
   y = 0;
   z = -3 -12; // Tenia -3
   paso = 0.1;
   dtx = 0;
   dtz = paso;

   glEnable( GL_DEPTH_TEST );
   glutReshapeFunc (reshapeevent);
   glutDisplayFunc( displayevent );
   
   glutSpecialFunc( specialkeyevent );
   glutIdleFunc( idleevent );

   glutMainLoop();

   return 0;
}
