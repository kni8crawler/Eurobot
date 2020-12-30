#include<stdlib.h>
#include<GL/glut.h>
GLint p;
//lighting attributes
GLfloat mat_specular[] =
{0.628281, 0.555802, 0.366065, 1};
GLfloat mat_ambient[] =
{0.24725, 0.1995, 0.0745, 1};
GLfloat mat_diffuse[] =
{0.75164, 0.60648, 0.22648, 1};
GLfloat mat_shininess[] =
{128 * 0.4};




GLfloat mat_specular5[] =
{0.60, 0.60, 0.50};
GLfloat mat_ambient5[] =
{0, 0, 0};
GLfloat mat_diffuse5[] =
{0.5, 0.5, 0};
GLfloat mat_shininess5[] =
{128 * 0.25};


void
SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_SHININESS, shin);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}


//text printing

void output(int X, int Y, float R, float G, float B, void* font, char *string)
{
  glColor3f( R, G, B );
  glRasterPos2f(X, Y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

  
GLint x=0,y=0,z=0,flag=2;
GLfloat vertices [][3] = {{-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1}, {-1,-1,1}, {1,-1,1}, {1,1,1}, {-1,1,1}};
void polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glNormal3fv(vertices[a]);
glVertex3fv(vertices[a]);
glNormal3fv(vertices[b]);
glVertex3fv(vertices[b]);
glNormal3fv(vertices[c]);
glVertex3fv(vertices[c]);
glNormal3fv(vertices[d]);
glVertex3fv(vertices[d]);
glEnd();
}
void colorcube(void)
{
polygon(0,3,2,1);
polygon(2,3,7,6);
polygon(0,4,7,3);
polygon(1,2,6,5);
polygon(4,5,6,7);
polygon(0,1,5,4);
}
 




static GLfloat movz=0,l=1;
static GLdouble viewer[]={1,0.2,1};
static GLfloat theta[]={0,0,0};
static GLint axis=2;
static GLfloat zeta[]={0,0,0};
static GLint coord=1;





void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
//heading
output(0,7,0.7,0.7,0.3,GLUT_BITMAP_HELVETICA_18,"**Right Click for Menu**");


//moving box

glPushMatrix();
glTranslatef(-4,-3,-movz-12);
glScalef(1,4,3);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(-4,-3,-movz);
glScalef(1,4,3);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(-4,-3,-movz+22);
glScalef(1,4,3);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(4,-3,-movz+15);
glScalef(1,7,3);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(4,-3,-movz+40);
glScalef(1,7,3);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(4,-3,-movz+5);
glScalef(1,7,2);
glutSolidCube(1);
glPopMatrix();

//base
glPushMatrix();
glTranslatef(0,-6.3,0);
glScalef(4,0.2,25);
colorcube();
glPopMatrix();

glRotatef(theta[axis],0,1,0);
//torso

glPushMatrix();

//text
glPushMatrix();
//char scrtext[]="E-Bot";
char scrtext[]="Eurobot";
glColor3f(0.7,0.7,0.3);
//glTranslatef(-1,0.5,1.05);
glTranslatef(-0.86,0.5,1.05);
//glScalef(0.004,0.005,2);
glScalef(0.0026,0.005,2);
for( p=0;scrtext[p]!=0;++p)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,scrtext[p]);
glPopMatrix();


SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
glScalef(1,2,1);
colorcube();
glPopMatrix();
glScalef(1,2,1);
//head
glPushMatrix();
glPushMatrix();
glColor3f(1,0.5,0);
glTranslatef(0,2,0);
glutSolidSphere(0.9,20,15);
glPopMatrix();
glColor3f(0.2,0.2,0.2);
glTranslatef(0,2,0);
glutWireSphere(1,20,15);
glPopMatrix();
//right Hand
glPushMatrix();	
SetMaterial(mat_specular5, mat_ambient5, mat_diffuse5, mat_shininess5);
glRotatef(zeta[coord],-1,0,0);
glPushMatrix();
glPushMatrix();

glColor3f(0,0.5,0.7);
glTranslatef(-1,0.8,0);
glutSolidSphere(0.6,15,10);
glPopMatrix();

glColor3f(0,0.5,1);
glTranslatef(-2.8,-0.8,0);
glutSolidSphere(0.4,15,10);
glPopMatrix();
glColor3f(0,1,1);

glTranslatef(-2.68,-0.7,0);
glRotatef(-45,0,0,1);
glRotatef(-90,1,0,0);
GLUquadricObj *quadratic;
quadratic = gluNewQuadric();
gluCylinder(quadratic,0.3,0.3,2.5f,32,32);
glPopMatrix();
//left hand

glPushMatrix();
glRotatef(zeta[coord],1,0,0);
glPushMatrix();
glPushMatrix();

glColor3f(0,0.5,0.7);
glTranslatef(1,0.8,0);
glutSolidSphere(0.6,15,10);
glPopMatrix();

glColor3f(0,0.5,1);
glTranslatef(2.8,-0.8,0);
glutSolidSphere(0.4,15,10);
glPopMatrix();
glColor3f(0,1,1);

glTranslatef(2.68,-0.7,0);
glRotatef(45,0,0,1);
glRotatef(-90,1,0,0);
GLUquadricObj *quadratic1;
quadratic1 = gluNewQuadric();
gluCylinder(quadratic1,0.3,0.3,2.5f,32,32);
glPopMatrix();
//right leg
glPushMatrix();

glPushMatrix();

glRotatef(zeta[coord],1,0,0);
glTranslatef(-1,-2,0);	
glScalef(0.5,1,0.5);
colorcube();
glPopMatrix();
glPopMatrix();

//left leg
glPushMatrix();


glPushMatrix();
glRotatef(zeta[coord],-1,0,0);
glTranslatef(1,-2,0);
glColor3f(0,0,1);
glScalef(0.5,1,0.5);
colorcube();
glPopMatrix();
glPopMatrix();
glFlush();
glutSwapBuffers();
}

void spincube()
{
theta[axis]+=1;
if(theta[axis]>360)
theta[axis]-=360;
glutPostRedisplay();
}

//movement of hands and legs
void move()
{
if(flag!=2)
{
if((flag==0)&&(zeta[coord]<25))
{
zeta[coord]+=1;
flag=0;
}
else 
flag=1;
if((flag==1)&&(zeta[coord]>-25))
{
zeta[coord]+=-1;
flag=1;
}
else
flag=0;
}
if(l==0)
{
movz+=0.05;
if(movz>60)
movz-=95;
}
glutPostRedisplay();
}



void mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{axis=0; coord=0;}
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
{axis=1; coord=0;}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=2;
spincube();
move();
}
void myReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glOrtho(-8,8,-8*(GLfloat) h/(GLfloat) w, 8*(GLfloat) h/(GLfloat)w, -30,30);
else
glOrtho(-8*(GLfloat) w/(GLfloat) h, 8*(GLfloat) w/(GLfloat) h, -8,8,-30,30);
glMatrixMode(GL_MODELVIEW);
}

void
menu(int value)
{
  switch (value)
  {
  
  case 1:
     theta[axis]=0;
     flag=0;
     l=0;
     glutIdleFunc(move);
     break;
  case 2:
      flag=2;
      l=2;	
      break;
  case 3:
    l=2;
    glutIdleFunc(spincube);
    break;

  case 4: 
       if((flag==0||1)&&(theta[axis]==0))
        glutIdleFunc(move);
      else
        glutIdleFunc(NULL);
    break;

  case 666:
    exit(0);

  }
}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("**EuroBot**"); 
glClearColor(0,0.5,1,1);
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glutIdleFunc(spincube);
glutIdleFunc(move);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST);
  glutCreateMenu(menu);
  glutAddMenuEntry("Start walk", 1);
  glutAddMenuEntry("Stop walk", 2);
  glutAddMenuEntry("Start rotation", 3);
  glutAddMenuEntry("Stop rotation", 4);
  glutAddMenuEntry("Quit", 666);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
glEnable(GL_LIGHTING); 
glEnable(GL_LIGHT0);  
glutMainLoop();
}
