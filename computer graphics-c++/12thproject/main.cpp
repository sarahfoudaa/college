#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;
float step=0;
float counter=0.0;
float rotation=0;

void display();
void reshape(int w,int h);
void timer(int);
int translateX=0,translateY=0,translateZ=0;
void init(){
   glClearColor(1.0,1.0,1.0,1.0);
}
void idleFunc (void)
{
   glutPostRedisplay();
   rotation += -0.3;
}
void texture(void){
    const GLfloat light_ambient[] = {0.0f,0.0f,0.0f,1.0f};
    const GLfloat light_diffuse[] = {1.0f,1.0f,1.0f,1.0f};
    const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
    const GLfloat light_position[] = {2.0f,5.0f,5.0f,0.0f};
    const GLfloat mat_ambient[]= {0.7f,0.7f,0.7f,1.0f};
    const GLfloat mat_diffuse[]={0.8f,0.8f,0.8f,1.0f};
    const GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    const GLfloat high_shininess[]={100.0f};
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION, light_position);
    glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS, high_shininess);
}
/////control
void keyboard(unsigned char Key,int x,int y)
{
    switch(Key){
    case 'k' : translateX++;
    break;
    case 'j' : translateX--;
    break;
    case 'i' : translateY++;
    break;
    case 'm' : translateY--;
    break;
    case 'p': translateZ++;
    break;
    case 'U': translateZ--;
    break;
    case 'f' : glutFullScreen();
    break;
    case 27 : exit(0);
    break;

}

}

int main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE |GLUT_DEPTH);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(700,700);
    glutCreateWindow("16100197");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    init();
    texture();
    glutMainLoop();

}
////////////decoration
void decoration()
{
     glPushMatrix();   //centerdecor
     glColor3f(1, 0, 0);
     glTranslated(0.2, 1.8, -6);
     glRotated(267,1,0,0);
     glutSolidCone(0.2,0.5,20,20);
     glPopMatrix();

     glPushMatrix();   //centerdecor
     glColor3d(1,0,0);
     glTranslated(0.2, 1.8, -6);
     glScaled(0.2, 0.2, 0.2);
     glutSolidDodecahedron();
     glPopMatrix();
}
////////snowman
void snowman(){
     glColor3d(1,1,1);
     glPushMatrix();
     glTranslated(-1.5,0.2,-5);   //firstbody
     glutSolidSphere(0.3,20,20);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-1.5,-0.5,-5);   //secondbody
     glutSolidSphere(0.5,20,20);
     glPopMatrix();

     glPushMatrix(); //righteye
     glColor3d(0,0,0);
     glTranslated(-1.1,0.2,-4);
     glutSolidSphere(0.04,20,20);
     glPopMatrix();

     glPushMatrix();      //lefteye
     glColor3d(0,0,0);
     glTranslated(-1.3,0.2,-4);
     glutSolidSphere(0.04,20,20);
     glPopMatrix();

     glPushMatrix();   //nose
     glColor3d(1,0,0);
     glTranslated(-1.20,0.1,-4);
     glutSolidCone(0.04,0.04,20,20);
     glPopMatrix();

    glPushMatrix();     //hat
    glColor3d(1,0,0);
    glTranslated(-1.2,0.4,-4);
    glutSolidSphere(0.06,20,20);
    glPopMatrix();
}
///////////////dog
void dog(){
    glPushMatrix();//body
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(0,-0.5,-6);
    glutSolidSphere(0.5,20,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(0,-0.25,-5);
    glutSolidSphere(0.3,20,20);
    glPopMatrix();

    glPushMatrix(); //white eye
    glColor3f(1, 1, 1);
    glTranslated(0.15,-0.1,-4);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glPushMatrix();//white eye
    glColor3f(1, 1, 1);
    glTranslated(-0.15,-0.1,-4);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glPushMatrix();//black eye
    glColor3f(0,0,0);
        if(counter==0.0)
        glTranslated(0.13,-0.05,-3);
        else
        glTranslated(0.1,-0.07,-3);
        glutSolidSphere(0.02,20,20);
    glPopMatrix();

    glPushMatrix();//black eye
    glColor3f(0,0,0);
        if(counter==0.0)
        glTranslated(-0.08,-0.05,-3);
        else
        glTranslated(-0.1,-0.07,-3);
        glutSolidSphere(0.02,20,20);
    glPopMatrix();

    glPushMatrix();//nose
    glColor3f(0,0,0);
    glTranslated(0,-0.2,-3);
    glutSolidSphere(0.04,20,20);
    glPopMatrix();

    glPushMatrix();//foot
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(0.2,-0.4,-3);
    glutSolidSphere(0.07,20,20);
    glPopMatrix();

    glPushMatrix();//foot
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(-0.2,-0.4,-3);
    glutSolidSphere(0.07,20,20);
    glPopMatrix();

    glPushMatrix();   //hat
    glColor3f(1, 0, 0);
    glTranslated(0.01+translateX,0.0+translateY,-5);
    glRotated(267,1,0,0);
    glutSolidCone(0.2,0.5,20,20);
    glPopMatrix();
}
/////////////tree
void tree()
{

    glPushMatrix();//cone
    glColor3f(0.5f, 0.2f, 0.0f);
    glTranslated(0.9,-0.6,-4);
    glRotated(270,1,0,0);
    glutSolidCone(0.15,1,20,20);
    glPopMatrix();

    glPushMatrix();//green
    glColor3f(0.2, 0.54, 0.18);
    glTranslated(0.9,-0.2,-4);
    glRotated(270,1,0,0);
    glutSolidCone(0.3,1.1,20,20);
    glPopMatrix();

 if(counter==0.0){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(1.2,1,-5);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(1.05,1,-5);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
 }
}





void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


   decoration();
   snowman();
   dog();
   tree();

   glTranslatef(3.5f, -0.5, -7.0f);
      glPushMatrix();     //leftdecoration
      glColor3d(0.0f, 1.0f, 0.0f);
      glTranslated(1.8,0.6,-4);
      glutSolidSphere(0.2,20,20);
      glPopMatrix();

      glPushMatrix();     //rightdecoration
      glColor3d(0.0f, 1.0f, 0.0f);
      glTranslated(2,0.6,-4);
      glutSolidSphere(0.2,20,20);
      glPopMatrix();

      glRotated(rotation,0,1,0);

      glBegin(GL_QUADS);
      // Top face
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 0.5f, 0.5f, -0.5f);
      glVertex3f(-0.5f, 0.5f, -0.5f);
      glVertex3f(-0.5f, 0.5f,  0.5f);
      glVertex3f( 0.5f, 0.5f,  0.5f);

      // Bottom face
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 0.5f, -0.5f,  0.5f);
      glVertex3f(-0.5f, -0.5f,  0.5f);
      glVertex3f(-0.5f, -0.5f, -0.5f);
      glVertex3f( 0.5f, -0.5f, -0.5f);

      // Front face
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.5f,  0.5f, 0.5f);
      glVertex3f(-0.5f,  0.5f, 0.5f);
      glVertex3f(-0.5f, -0.5f, 0.5f);
      glVertex3f( 0.5f, -0.5f, 0.5f);

      // Back face
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.5f, -0.5f, -0.5f);
      glVertex3f(-0.5f, -0.5f, -0.5f);
      glVertex3f(-0.5f,  0.5f, -0.5f);
      glVertex3f( 0.5f,  0.5f, -0.5f);

      // Left face
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-0.5f, 0.5f,  0.5f);
      glVertex3f(-0.5f,  0.5f, -0.5f);
      glVertex3f(-0.5f, -0.5f, -0.5f);
      glVertex3f(-0.5f, -0.5f,  0.5f);

      // Right face
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(0.5f,  0.5f, -0.5f);
      glVertex3f(0.5f,  0.5f,  0.5f);
      glVertex3f(0.5f, -0.5f,  0.5f);
      glVertex3f(0.5f, -0.5f, -0.5f);

   glEnd();
   glutSwapBuffers();

}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)w/(GLdouble)h,0.5,40);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();

    glutTimerFunc(30000/60,timer,0);
    if(counter==1.0){
        counter--;
     }
     else{
        counter++;
     }



}
