#include<windows.h>
//#include<MMSYSTEM.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


float angle = 0.0, x=-4;
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font3=(int)GLUT_BITMAP_8_BY_13;
char s[30];
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void station()
{

glPushMatrix();  //building
   glColor3f(0.435294,0.258824,0.258824); glTranslated(0,0.5,0); glScaled(2,1,1); glutSolidCube(1);
   glColor3f(0.65, 0.49,0.24); glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //door
   glColor3f(1,1,0.678431); glTranslated(0,0.3,0); glScaled(0.3,0.6,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //door
   glColor3f(1,1,0.678431); glTranslated(0,0.4,0); glScaled(0.3,0.4,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //door
   glColor3f(1,1,0.678431); glTranslated(0.7,0.4,0); glScaled(0.3,0.4,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //door
   glColor3f(1,1,0.678431); glTranslated(-0.7,0.4,0); glScaled(0.3,0.4,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //tower
   glColor3f( 0.435294,0.258824,0.258824); glTranslated(0,1.3,0); glScaled(0.2,0.5,1); glutSolidCube(1);
   glColor3f(0.65, 0.49,0.24); glutWireCube(1);
   glPopMatrix();
	glPushMatrix(); //tower plate
   glColor3f(0.65, 0.49,0.24); glTranslated(0,1.6,0); glScaled(0.3,0.1,1); glutSolidCube(1);
   glColor3f(0.65, 0.49,0.24); glutWireCube(1);
   glPopMatrix();
   //tower cap
	glBegin(GL_TRIANGLES);
glColor3f( 0, 0, 0 );
glVertex2f( -0.2,1.6 );
glColor3f( 0, 0, 0 );
glVertex2f( 0, 1.9 );
glColor3f( 0, 0, 0 );
glVertex2f( 0.2, 1.6 );
glEnd();

   //main roof
   glBegin(GL_TRIANGLES);
glColor3f( 0, 0, 0 );
glVertex2f( -0.8, 1 );
glColor3f( 0, 0, 0 );
glVertex2f( 0.8, 1 );
glColor3f( 0, 0, 0 );
glVertex2f( 0, 1.3 );
glEnd();


}


void train()
{
   glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1); glTranslated(0.75,-0.5, -0.5);
   glRotated(angle,0,0,1); glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1); glTranslated(-0.75,-0.5, -0.5);
   glRotated(angle,0,0,1); glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Train BOX
   glColor3f(0, 0.498039,0.67256); glScaled(2,1,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0); glTranslated(1,-0.35,0);
   glScaled(1,0.09,0.09); glutSolidCube(1);
   glPopMatrix();

   glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1); glTranslated(0.75,-0.5, 0.5);
   glRotated(angle,0,0,1); glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1); glTranslated(-0.75,-0.5, 0.5);
   glRotated(angle,0,0,1); glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   angle-=0.2;
}

void tree()
{
   glPushMatrix();
   	glColor3b(102,100,70);
   	glScaled(0.5,4,0.2);
  	glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
     	glColor3b(48,124,66);
     	glTranslated(0,1.1,0);
    	glutSolidSphere(1,8,8);
    	glColor3f(0,1,0);
    	glutWireSphere(1,8,8);
    	glPopMatrix();
}

void background()
{
   glColor3f(0.419608,0.556863,0.137255 );glRecti(-3,-2,3,0); //grass
  	glColor3f(0.184314,0.184314,0.309804);glRecti(-3,0,3,2); //sky


   glPushMatrix();
   glTranslated(1.7,0.6,0);glScaled(0.3,0.3,0.1);tree();
   glPopMatrix();
   glPushMatrix();
   glTranslated(-1.8,0.4,0);glScaled(0.3,0.3,0.1);tree();
   glPopMatrix();
   glPushMatrix();
     	glTranslated(1.9,0.6,0);glScaled(0.3,0.3,0.1);tree();
    	glPopMatrix();

    	 glPushMatrix();
     	glTranslated(2.2,0.6,0);glScaled(0.3,0.3,0.1);tree();
    	glPopMatrix();
   glPushMatrix();
     	glTranslated(-1.6,0.4,0);glScaled(0.23,0.23,0.1);tree();
    	glPopMatrix();
   glPushMatrix();
     	glTranslated(-1.6,-1,0);glScaled(0.23,0.23,0.1);tree();
    	glPopMatrix();
    	glPushMatrix();
   glTranslated(-1.7,-1.6,0);glScaled(0.3,0.3,0.1);tree();
   glPopMatrix();
   glPushMatrix();
     	glTranslated(-2,-1.2,0);glScaled(0.23,0.23,0.1);tree();
    	glPopMatrix();

 station();
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);

 // star 1
 glVertex2f(0.8,1.5);
 glVertex2f(1,1.6);
 glVertex2f(1,1.5);
 glVertex2f(0.8,1.6);
//star 2
 glVertex2f(1.1,1.78);
 glVertex2f(1.2,1.88);

 glVertex2f(1.2,1.78);
 glVertex2f(1.1,1.88);

 // star 3
  glVertex2f(2.2,1.8);
 glVertex2f(2.3,2);

 glVertex2f(2.3,1.8);
 glVertex2f(2.2,2);

 glVertex2f(2.5,.96);
 glVertex2f(2.6,1);

 glVertex2f(2.6,.96);
 glVertex2f(2.5,1);
 //star 4
 glVertex2f(-2.2,1.5);
 glVertex2f(-2.3,1.7);

 glVertex2f(-2.3,1.5);
 glVertex2f(-2.2,1.7);

 //star 5

glVertex2f(-0.9,1.6);
 glVertex2f(-1.1,1.7);
 glVertex2f(-1.1,1.6);
 glVertex2f(-0.9,1.7);
//star 6
 glVertex2f(-1,1.76);
 glVertex2f(-1.3,1.9);

 glVertex2f(-1.3,1.76);
 glVertex2f(-1,1.9);
//star 7

//8
 glVertex2f(-1.5,.96);
 glVertex2f(-1.6,1);

 glVertex2f(-1.6,.96);
 glVertex2f(-1.5,1);
 //9
glVertex2f(-2.5,.96);
 glVertex2f(-2.6,1);

 glVertex2f(-2.6,.96);
 glVertex2f(-2.5,1);

 glEnd();

 glColor3f(0.0,0.0,1.0);

 glVertex2f(0.9,0.3);
 glVertex2f(0.6,0.3);


 glColor3f(0.000, 0.000, 1.000);
        renderBitmapString(1,-1.4,(void *)font3,"Submitted By:");
        renderBitmapString(1.4,-1.6,(void *)font1,"Nowsheen-Parisa-Mahidul");
}
void renderScene (void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode (GL_PROJECTION); glLoadIdentity();
   glOrtho (-3,3,-2,2,-4,4);  background ();
   glRotatef(10,1.0,1.0,0.0); //
   glPushMatrix (); glColor3f(0,0,0); //Rail
   glTranslated (0,-0.4,0); glScaled (9,0.1,0.1);
   glutWireCube(1);
   glPopMatrix();
   glTranslatef(-x,0,0); // move train
   glScaled(0.5,0.5,0.5);

   glPushMatrix();
   glTranslated (-2.4,0,0); train();
   glPopMatrix();
   glPushMatrix();
   glTranslated (0,0,0); train();
   glPopMatrix();
   glPushMatrix();
   glTranslated (2.4,0,0); train();
   glPopMatrix();
   if (x<6)
  	x+=0.01;  //train speed
   else
  	x=-6;


   glutSwapBuffers();
   }

int main(int argc,char** argv) {
    glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition (10,10);
glutInitWindowSize (1200,600);
glutCreateWindow("Animated by Roll 05-12-22");
glutDisplayFunc(renderScene);
glutIdleFunc (renderScene);
glClearColor(1,1,1,1);
glutMainLoop();
//PlaySound(TEXT("I am Rider song.wav"), NULL, SND_FILENAME | SND_SYNC);
return 0;
}
