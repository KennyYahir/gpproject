#include <stdlib.h>
#include <GL/glut.h>
/*#include <GL/glu.h>*/
#include "SOIL.h"
#define alto 400
#define ancho 400
#define OrigenX 100
#define OrigenY 100

void loadTexture(GLuint* texture, char* filename){
    *texture = SOIL_load_OGL_texture(filename,
                                     SOIL_LOAD_AUTO,
                                     SOIL_CREATE_NEW_ID,
                                     SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
                                    );
    if(*texture == NULL){
        printf("[Texture loader] \"%s\" failed to load!\n", filename);
    }
}

void drawTexturedRect(int x, int y, int w, int h, GLuint texture){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
        glColor3f(255,255,255);
        glTexCoord2f(0,0);
        glVertex2f(x,y);
        glTexCoord2f(1,0);
        glVertex2f(x+w,y);
        glTexCoord2f(0,1);
        glVertex2f(x,y+h);
        glTexCoord2f(1,1);
        glVertex2f(x+w,y+h);
        glTexCoord2f(0,1);
        glVertex2f(x,y+h);
    glEnd();
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
}

int main(int argc, char **argv)
{
	
	GLuint texture;
	int width = 250, height = 250;

	float pixels[] = {
    0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);

	unsigned char* image =
    SOIL_load_image("mario.jpg", &width, &height, 0, SOIL_LOAD_RGB);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
              GL_UNSIGNED_BYTE, image);

	return 0;
}