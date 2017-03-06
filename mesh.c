#include<stdlib.h>
#include<GL/glut.h>
#define maxx 10
#define maxy 10
#define dx 10
#define dy 10

GLfloat x0=150,y0=100;
GLfloat x[maxx]={0.0};
GLfloat y[maxy]={0.0};
Glint i,j;
void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,400.0,0.0,400.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
for(i=0,i<maxx;i++)
x[i]=x0+i*dx;
for(j=0;j<maxy;j++)
y[j]=y0+j*dy;
for(i=0;i<maxx-1;i++)
for(j=0;j<maxy-1;j++)
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(x[i],y[j]);
glVertex2f(x[i],y[j+1]);
glVertex2f(x[i+1],y[j+1]);
glVertex2f(x[i+1],y[j]);
glEnd();
glFlush();
}
glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("mesh");
glutDisplayFunc(display);
init();
glutMainLoop();
}

 


