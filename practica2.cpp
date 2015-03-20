#include <GL/gl.h>
#include <GL/glut.h>


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	
//Triangulo superior color amarillo
      glBegin(GL_TRIANGLES);
	  glColor3f (1.0, 1.0, 0.0); 
	  glVertex3f(0.0f, 0.5f, 0.0f);
	  glVertex3f(-0.2f, 0.2f, 0.0f);
	  glVertex3f(0.2f, 0.2f, 0.0f);
	  glEnd();
	  
//triangulo izquierdo color verde
	  glBegin(GL_TRIANGLES);
	  glColor3f (0.0, 1.0, 0.0); 
	  glVertex3f(-0.5f, 0.0f, 0.0f);
	  glVertex3f(-0.2f, -0.2f, 0.0f);
	  glVertex3f(-0.2f, 0.2f, 0.0f);
	  glEnd();
	  
//Cuadro color azul
	  glColor3f (0.0, 0.0, 1.0);
	  glBegin(GL_QUADS);	
	  glVertex2f( -0.2f, 0.2f); 	
      glVertex2f( -0.2f, -0.2f); 
      glVertex2f( 0.2f, -0.2f);
      glVertex2f( 0.2f, 0.2f);
	  glEnd();
	  
//Triangulo derecho color verde
	  glBegin(GL_TRIANGLES);
	  glColor3f (0.0, 1.0, 0.0); 
	  glVertex3f(0.5f, 0.0f, 0.0f);
	  glVertex3f(0.2f, -0.2f, 0.0f);
	  glVertex3f(0.2f, 0.2f, 0.0f);
	  glEnd();
	  
//triangulo inferior color rojo
	  glBegin(GL_TRIANGLES);
	  glColor3f (1.0, 0.0, 0.0); 
	  glVertex3f(0.0f, -0.5f, 0.0f);
	  glVertex3f(0.2f, -0.2f, 0.0f);
	  glVertex3f(-0.2f, -0.2f, 0.0f);
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
	glutCreateWindow ("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
