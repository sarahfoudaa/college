//Sarah tarek gouda fouda 18104349
//Nadia fahmy medra 18101664


#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

#include<windows.h>                  //GLUT toolkit
#include <time.h>
#define INIT_VIEW_X 0.0    //Define initial camera position and viewing window values
#define INIT_VIEW_Y 0.0
#define INIT_VIEW_Z -4.5
#define VIEW_LEFT -2.0
#define VIEW_RIGHT 2.0
#define VIEW_BOTTOM -2.0
#define VIEW_TOP 2.0
#define VIEW_NEAR 1.0
#define VIEW_FAR 200.0
float step=0;
float counter=0.0;
float rotation=0;
void timer(int);
GLfloat AmbientLight[]={0.3,0.3,0.3,1.0};                  //Initialization values for lighting
GLfloat DiffuseLight[] ={0.8,0.8,0.8,1.0};
GLfloat SpecularLight[] ={1.0,1.0,1.0,1.0};
GLfloat SpecRef[] = {0.7,0.7,0.7,1.0};
GLfloat LightPos[] = {-50.0,50.0,100.0,1.0};
GLint Shine =128;
int translateX=0,translateY=0,translateZ=0;

void idleFunc (void)
{  // for rotation
   glutPostRedisplay();
   rotation += -0.1;
}
  // to move by keyboard
void keyboard(unsigned char Key,int x,int y)
{
    switch(Key){
    case 'k' : translateX++; // move up x axis
    break;
    case 'j' : translateX--;  // move down x axis
    break;
    case 'i' : translateY++;  // move right y axis
    break;
    case 'm' : translateY--;  // move left y axis
    break;
    case 'p': translateZ++;   // move front z axis
    break;
    case 'U': translateZ--;  // move behind or back z axis
    break;
    case 'f' : glutFullScreen(); // full screen
    break;
    case 27 : exit(0);   // end program
    break;

}

}
void eyeright()
{
    //function for the right eye
    glPushMatrix();
    glTranslatef(.17,1.1,.75);     //Specify the coordinates for the right eye
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);            //Specify the size of the right eye
    glColor3f(1.0,1.0,1.0);       //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}
void eyeleft()
{   //function for the left eye
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);     //Specify the position for the left eye
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);          //Specify the size of the left eye
    glColor3f(1.0,1.0,1.0);      //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void legleft()
{   //function for the left leg
    glPushMatrix();
    glTranslatef(.3,-.5,0);     //Specify the position for the left leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void legright()
{    //function for the right leg
    glPushMatrix();
    glTranslatef(-.3,-.5,0);     //Specify the position for the right leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}




void armleft()
{    //function for the arm left
    glPushMatrix();
    glTranslatef(-.82,0,.1);     //Specify the position for the left arm
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void armright()
{   //function for the arm right
    glPushMatrix();
    glTranslatef(.82,0,.1);      //Specify the position for the right arm
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void handleft()
{   //function for the hand left
    glPushMatrix();
    glTranslatef(.82,0,.1);     //Specify the position for the left hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}
void handright()
{    //function for the hand right
    glPushMatrix();
    glTranslatef(-.82,0,.1);    //Specify the position for the right hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void mouth()
{  //function for the mouth
    glPushMatrix();
    glTranslatef(0,.78,.74);   //Specify the position
    glScalef(.4,.4,.1);
    glColor3f(1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void teeth()
{    //function for the teeth
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76); //Specify the position
    glTranslatef(.055,0,.005 ); //Specify the position
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();
}

void eyebrowleft()
{   //function for the eyebrow left
    glPushMatrix();
    // animation
    if(counter==0.0)
        glTranslatef(-.3,1.5,.97); //Specify the position
        else
        glTranslatef(-.3,1.6,.97);  //Specify the position


    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void eyebrowright()
{  //function for the eyebrow right
    glPushMatrix();
    // animation
    if(counter==0.0)
        glTranslatef(.3,1.6,.97); //Specify the position
        else
        glTranslatef(.3,1.5,.97); //Specify the position

    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void neckring()
{   //function for the neck ring
    glPushMatrix();
    glTranslatef(0,.5,0);  //Specify the position
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}




void head()
{    //function for the head
    glPushMatrix();
    glTranslatef(0,1.2,0);  //Specify the position
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
}

void hatmain()
{   //function for the hat main
    glPushMatrix();
    glTranslatef(0,1.3,0); //Specify the position
    glScalef(.98,.98,.98);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
}

void maintopball()
{  //function for the main top ball
    glPushMatrix();
    glTranslatef(0,2.2,0);//Specify the position
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;
}


void hatring()
{   //function for hat ring
    glPushMatrix();
    glTranslatef(0,1.4,0); //Specify the position
    glScalef(.84,.84,.84);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}

void footleft()
{    //function for foot left
    glPushMatrix();
    glTranslatef(-.3,-.5,0); //Specify the position
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void footright()
{    //function for foot right
    glPushMatrix();
    glTranslatef(.3,-.5,0); //Specify the position
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}


void coatline()
{   //function for coat line
    glPushMatrix();
    glTranslatef(0,.12,.67); //Specify the position
    glRotatef(-17.0,1,0,0);
    glScalef(.05,.7,.1);
    glutSolidCube(1);
    glPopMatrix();
}

void bellyCoatbottom()
{   //function for belly Coat bottom
    glPushMatrix();
    glTranslatef(0,-.2,0); //Specify the position
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();
}

void BellyCoat()
{   //function for belly Coat
    glPushMatrix();
    glTranslatef(0,.5,0); //Specify the position
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}

void pupilleft()
{  //function for pupil left
    glPushMatrix();
    // animation
    if(counter==0.0)
        glTranslatef(-.17,1.1,.88); //Specify the position
        else
        glTranslatef(-.19,1.1,.88); //Specify the position

    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void pupilright()
{   //function for pupil right
    glPushMatrix();
    // animation
     if(counter==0.0)
        glTranslatef(.17,1.1,.88);  //Specify the position
        else
        glTranslatef(.19,1.1,.88);  //Specify the position

    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void topbutton()
{   //function for top button
    glPushMatrix();
    glTranslatef(-.1,.4,.85);  //Specify the position
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void middlebutton()
{   //function for middle button
    glPushMatrix()  ;
    glTranslatef(-.1,.15,.98);  //Specify the position
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void bottombutton()
{   //function for bottom button
    glPushMatrix();
    glTranslatef(-.1,-.1,.92);  //Specify the position
    glScalef(1.9,1.9,1.9);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void tree()
{
    //  function for tree
    glPushMatrix();//cone
    glColor3f(0.5f, 0.2f, 0.0f); // brown
    glTranslated(-0.5,-0.6,-4); //Specify the position
    glRotated(270,1,0,0);
    glutSolidCone(0.4,2,20,20);
    glPopMatrix();
    // cone
    glPushMatrix();//green
    glColor3f(0.2, 0.54, 0.18);
    glTranslated(-0.5,-0,-4);  //Specify the position
    glRotated(270,1,0,0);
    glutSolidCone(0.7,2.1,20,20);
    glPopMatrix();

}
void cartoon (){
    glPushMatrix();
    glTranslatef(-3,0,-6);  //Specify the position
    eyeright(); // eye right
    eyeleft();  // eye left
    glColor3f(0.0,0.0,1.0);
    legleft();   //left leg
    legright();  // right leg
    hatmain();    // hat
    glColor3ub(160,82,45);
    armleft();    // left arm
    armright();   // right arm
    mouth();      // mouth
    teeth();     // teeth
    eyebrowleft();
    eyebrowright();
    head();
    glColor3f(1.0,0.0,0.0);
    maintopball();
    hatring();
    neckring();
    handleft();
    handright();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    coatline();
    pupilleft();
    pupilright();
    glColor3ub(160,82,45);
    BellyCoat();
    bellyCoatbottom();
    glPopMatrix();
}
void cartoon_two(){
    glPushMatrix();
    glTranslatef(1.5,0,-6);  //Specify the position
    eyeright();
    eyeleft();
    glColor3f(0.0,0.0,0.0);
    pupilleft();
    pupilright();
    glColor3f(0.5,0.2,0.4);
    legright();
    legleft();
    glPushMatrix();                                    //*Arm left*
    glTranslatef(-.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-45,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();
    glPushMatrix();                                   //*Arm right*
    glTranslatef(.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-135,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();
    glPushMatrix();                                    //*Hand left*
    glTranslatef(.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //*Hand right*
    glTranslatef(-.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //*Mouth*
    glTranslatef(0,.78,.8);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
    glPushMatrix();                                    //*Teeth*
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.817 );
    glutSolidCube(.035);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glTranslatef(.055,0,-.005 );
    glutSolidCube(.035);
    glPopMatrix();
    glPushMatrix();                                    //*Head*
    glTranslatef(0,1,0);
    glScalef(.9,.7,.9);
    glColor3ub(255,222,173);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
    glPushMatrix();                                    //*Hat main*
    glTranslatef(0,1,0);
    glScalef(.9,.9,.9);
    glColor3ub(30,144,255);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
    glColor3f(1.0,1.0,0.0);
    hatring();
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    glPushMatrix();                                    //*BellyCoat*
    glTranslatef(0,.1,0) ;
    glScalef(1,.6,1);
    glColor3f(1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();


}
void dog(){
    glPushMatrix();       //body
    glColor3f(0.737, 0.561, 0.176); // brown
    glTranslated(5,-0.0,-6);  //Specify the position
    glutSolidSphere(1.0,20,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.737, 0.561, 0.176);  // brown
    glTranslated(4.6,0.55,-5);  //Specify the position
    glutSolidSphere(0.7,20,20);
    glPopMatrix();

    glPushMatrix(); // right white eye
    glColor3f(1, 1, 1);
    glTranslated(4.6,0.75,-4);  //Specify the position
    glutSolidSphere(0.3,20,20);
    glPopMatrix();

    glPushMatrix();// left white eye
    glColor3f(1, 1, 1);
    glTranslated(3.9,0.75,-4);  //Specify the position
    glutSolidSphere(0.3,20,20);
    glPopMatrix();

    glPushMatrix();// right black eye
    glColor3f(0,0,0);
    // animation
        if(counter==0.0)
        glTranslated(4.2,0.75,-3); //Specify the position
        else
        glTranslated(4.26,0.77,-3);  //Specify the position
        glutSolidSphere(0.09,20,20);
    glPopMatrix();

    glPushMatrix();// left black eye
    glColor3f(0,0,0);
      // animation
        if(counter==0.0)
        glTranslated(3.5,0.75,-3);  //Specify the position
        else
        glTranslated(3.56,0.77,-3); //Specify the position
        glutSolidSphere(0.09,20,20);
    glPopMatrix();

    glPushMatrix();//nose
    glColor3f(0,0,0);
    glTranslated(3.9,0.3,-3);   //Specify the position
    glutSolidSphere(0.14,20,20);
    glPopMatrix();

    glPushMatrix();// left foot
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(3.5,-0.7,-3);  //Specify the position
    glutSolidSphere(0.27,20,20);
    glPopMatrix();

    glPushMatrix();//right foot
    glColor3f(0.737, 0.561, 0.176);
    glTranslated(4.3,-0.7,-3);  //Specify the position
    glutSolidSphere(0.27,20,20);
    glPopMatrix();

    glPushMatrix();   //hat
    glColor3f(1, 0, 0);
    // move by keyboard
    glTranslated(4.5+translateX,1.1+translateY,-5+translateZ); //Specify the position
    glRotated(267,1,0,0);
    glutSolidCone(0.55,1.2,20,20);
    glPopMatrix();



}
void doghome(){

//glRotated(rotation,0,1,0);
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      //Specify the position
      glVertex3f( 4.0f,  0.5f, 0.5f);
      glVertex3f(4.75f, 1.25f, 0.5f);
      glVertex3f(5.25f,  0.5f, 0.5f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      //Specify the position
      glVertex3f(5.25f,  0.5f, -0.5f);
      glVertex3f(4.0f,  0.5f,  0.5f);
      glVertex3f(4.75f, 1.25f, 0.5f);

      // Left
      glColor3f(1.0f,0.0f,0.0f);       //  Red
      //Specify the position
      glVertex3f(5.25f, 0.5f,  0.5f);
      glVertex3f(4.0f,  0.5f, -0.5f);
      glVertex3f(4.75f, 1.25f, 0.5f);

      // Back
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      //Specify the position
      glVertex3f(4.0f,  0.5f, -0.5f);
      glVertex3f( 5.25f,  0.5f, -0.5f);
      glVertex3f(4.75f, 1.25f, 0.5f);
   glEnd();   // Done drawing the pyramid
  // Door For dog hime
  glBegin(GL_QUADS);

  // Front face
      glColor3f(1.0f, 0.65f, 0.0f);     // Orange
      //Specify the position
      glVertex3f( 4.95f,  0.15f, 0.5f);
      glVertex3f(4.3f,  0.15f, 0.5f);
      glVertex3f(4.3f, -0.5f, 0.5f);
      glVertex3f( 4.95f, -0.5f, 0.5f);

      glEnd();
// morb3 for home
glBegin(GL_QUADS);

      // Back face
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      //Specify the position
      glVertex3f( 5.25f, -0.5f, -0.5f);
      glVertex3f(4.0f, -0.5f, -0.5f);
      glVertex3f(4.0f,  0.5f, -0.5f);
      glVertex3f( 5.25f,  0.5f, -0.5f);

      // Left face
      glColor3f(1.0f, 1.0f, 0.0f);     // yellow
      //Specify the position
      glVertex3f(5.25f, 0.5f,  0.5f);
      glVertex3f(4.0f,  0.5f, -0.5f);
      glVertex3f(4.0f, -0.5f, -0.5f);
      glVertex3f(5.25f, -0.5f,  0.5f);

      // Right face
      glColor3f(1.0f, 1.0f, 0.0f);     // yellow
      //Specify the position
      glVertex3f(5.25f,  0.5f, -0.5f);
      glVertex3f(4.0f,  0.5f,  0.5f);
      glVertex3f(4.0f, -0.5f,  0.5f);
      glVertex3f(5.25f, -0.5f, -0.5f);

      // Front face
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      //Specify the position
      glVertex3f( 5.25f,  0.5f, 0.5f);
      glVertex3f(4.0f,  0.5f, 0.5f);
      glVertex3f(4.0f, -0.5f, 0.5f);
      glVertex3f( 5.25f, -0.5f, 0.5f);
      // Top face
      glColor3f(1.0f, 1.0f, 0.0f);     // yellow
      //Specify the position
      glVertex3f( 5.25f, 0.5f, -0.5f);
      glVertex3f(4.0f, 0.5f, -0.5f);
      glVertex3f(4.0f, 0.5f,  0.5f);
      glVertex3f( 5.25f, 0.5f,  0.5f);

      // Bottom face
      glColor3f(1.0f, 1.0f, 0.0f);     // yellow
      //Specify the position
      glVertex3f( 5.25f, -0.5f,  0.5f);
      glVertex3f(4.0f, -0.5f,  0.5f);
      glVertex3f(4.0f, -0.5f, -0.5f);
      glVertex3f( 5.25f, -0.5f, -0.5f);

   glEnd();
// end home

}
//------------------------------  display   -------------------------------
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the window
    glColor3ub(50, 50, 150);//Change the draw color to slate blue
    glPushMatrix();//Save viewing matrix state
    tree();
    cartoon();
    cartoon_two();

    dog();
    doghome();


    glPopMatrix();
    glPopMatrix();                                     //*Restore matrix state*
    glutSwapBuffers();                             //*Flush drawing commands*
}



void SetupRend()
{
    glClearColor(0.7,0.7,1.0,1.0);
    glEnable(GL_DEPTH_TEST);         //Enable depth testing
    glEnable(GL_LIGHTING);             //Enable lighting
    glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);//Set up and enable light zero
    glLightfv(GL_LIGHT0,GL_DIFFUSE,DiffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,SpecularLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//Set material to follow
    glMaterialfv(GL_FRONT,GL_SPECULAR,SpecRef);//Set specular reflectivity and shine
    glMateriali(GL_FRONT,GL_SHININESS,Shine);
}



//------------------------------  reshapeFunc  ---------------------------------
void myReshape(int w, int h)
{
    GLfloat Ratio;
    glViewport(0,0,w,h);
    Ratio=1.0*w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,Ratio,VIEW_NEAR,VIEW_FAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(INIT_VIEW_X,INIT_VIEW_Y,INIT_VIEW_Z);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}


    int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,1200);

    glutCreateWindow(" 18104349 - 18101664 ");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(Display);
   // glutIdleFunc(Display);

    glutIdleFunc(idleFunc);
    // for music
    // sndPlaySound("2.wav", SND_ASYNC);
     glutKeyboardFunc(keyboard);
     // function for animation
    glutTimerFunc(0,timer,0);

    SetupRend();
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return EXIT_SUCCESS;
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
