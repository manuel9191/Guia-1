#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(12);	
	glColor3f (1.0, 1.0, 1.0);

	GLfloat ang;
	int i;
	
	glBegin(GL_POINTS);	

		for(i=1; i<360; i+=7)
		{
			
			ang = (GLfloat)i*3.14159/180.0f;
			glVertex3f(-1.0f, 0.0f, 0.0f);
			
	glVertex3f (cos(ang), sin(ang), 0.0f);
}
	glEnd();
	glFlush ();
}		
void init (void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Práctica 1 - GL Points");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
