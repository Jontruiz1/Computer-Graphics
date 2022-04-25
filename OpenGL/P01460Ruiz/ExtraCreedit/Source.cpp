// Extra Credit - Jonathan Ruiz

#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;


// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -5.0f;
// XZ position of the camera
float y = 0.0f;


/// <summary>
/// Very inefficient, I'm so sorry
/// Procrastinated very hard but I could probably do something similar with
/// the flyby cube model that I took the namespace idea from.
/// I was going to set an array of the vertices since many of the vertices are shared
/// and then use loops to draw the vertices.
/// 
/// Issue with the triangles drawing infront of the faces. Ran out of time to figure out why
/// </summary>
namespace SnakeCube {
	const int V = 32;


	GLfloat vertices[4][4]{


		{1.0f, 2.0f, -1.0f}, {-1.0f, 2.0f, -1.0f}, {-1.0f, 2.0f, 1.0f}, {1.0f, 2.0f, 1.0f}


	};

	GLfloat colors[6][3]{

		{0.0f, 1.0f, 0.0f}, 

	};

	void drawFaces() {
		glBegin(GL_QUADS);
		
		/**/
		// Top face (y = 1.0f)
	 // Define vertices in counter-clockwise (CCW) order with normal pointing out
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
		glVertex3f(1.0f, 2.0f, -1.0f);
		glVertex3f(-1.0f, 2.0f, -1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);

		
		// Bottom face (y = -1.0f)
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f(1.0f, -2.0f, 1.0f);
		glVertex3f(-1.0f, -2.0f, 1.0f);
		glVertex3f(-1.0f, -2.0f, -1.0f);
		glVertex3f(1.0f, -2.0f, -1.0f);
		
		
		// Back face  (z = 1.0f)
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(1.0f, 1.0f, 2.0f);
		glVertex3f(-1.0f, 1.0f, 2.0f);
		glVertex3f(-1.0f, -1.0f, 2.0f);
		glVertex3f(1.0f, -1.0f, 2.0f);
		
		// Front face (z = -1.0f)
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f(1.0f, -1.0f, -2.0f);
		glVertex3f(-1.0f, -1.0f, -2.0f);
		glVertex3f(-1.0f, 1.0f, -2.0f);
		glVertex3f(1.0f, 1.0f, -2.0f);
		
		// Right face (x = -1.0f)
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
		glVertex3f(-2.0f, 1.0f, 1.0f);
		glVertex3f(-2.0f, 1.0f, -1.0f);
		glVertex3f(-2.0f, -1.0f, -1.0f);
		glVertex3f(-2.0f, -1.0f, 1.0f);
		
		// Left face (x = 1.0f)
		glColor3f(0.5f, 0.0f, 0.5f);     // Dark Purple
		glVertex3f(2.0f, 1.0f, -1.0f);
		glVertex3f(2.0f, 1.0f, 1.0f);
		glVertex3f(2.0f, -1.0f, 1.0f);
		glVertex3f(2.0f, -1.0f, -1.0f);
		
		glEnd();
	}

	void drawRectangles() {
		glBegin(GL_QUADS);
		
		// Front to Right
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -2.0f);
		glVertex3f(-1.0f, -1.0f, -2.0f);
		glVertex3f(-2.0f, -1.0f, -1.0f);
		glVertex3f(-2.0f, 1.0f, -1.0f);

		// Front to Left
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -2.0f);
		glVertex3f(1.0f, 1.0f, -2.0f);
		glVertex3f(2.0f, 1.0f, -1.0f);
		glVertex3f(2.0f, -1.0f, -1.0f);

		// Right to Back
		glColor3f(0.5f, 0.0f, 0.5f);
		glVertex3f(-2.0f, 1.0f, 1.0f);
		glVertex3f(-2.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 2.0f);
		glVertex3f(-1.0f, 1.0f, 2.0f);
		
		// Back to Left
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 2.0f);
		glVertex3f(1.0f, -1.0f, 2.0f);

		glVertex3f(2.0f, -1.0f, 1.0f);
		glVertex3f(2.0f, 1.0f, 1.0f);

		// Front to Top
		glColor3f(0.6f, 0.8f, 0.19f);
		glVertex3f(1.0f, 1.0f, -2.0f);
		glVertex3f(-1.0f, 1.0f, -2.0f);
		glVertex3f(-1.0f, 2.0f, -1.0f);
		glVertex3f(1.0f, 2.0f, -1.0f);

		// Right to Top
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-2.0f, 1.0f, -1.0f);
		glVertex3f(-2.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, -1.0f);
		
		// Back to Top
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 2.0f);
		glVertex3f(1.0f, 1.0f, 2.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);
		
		// Left to Top
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(2.0f, 1.0f, 1.0f);
		glVertex3f(2.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 2.0f, -1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);

		// Front to Bottom
		glColor3f(1.0f, 0.7f, 0.1f);
		glVertex3f(-1.0f, -1.0f, -2.0f);
		glVertex3f(1.0f, -1.0f, -2.0f);
		glVertex3f(1.0f, -2.0f, -1.0f);
		glVertex3f(-1.0f, -2.0f, -1.0f);
		

		// Right to Bottom
		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(-2.0f, -1.0f, 1.0f);
		glVertex3f(-2.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -2.0f, -1.0f);
		glVertex3f(-1.0f, -2.0f, 1.0f);

		// Left to Bottom
		glColor3f(0.7f, 0.5f, 0.2f);
		glVertex3f(2.0f, -1.0f, -1.0f);
		glVertex3f(2.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -2.0f, 1.0f);
		glVertex3f(1.0f, -2.0f, -1.0f);

		// Back to Bottom
		glColor3f(1.0f, 0.7f, 0.0f);
		glVertex3f(1.0f, -1.0f, 2.0f);
		glVertex3f(-1.0f, -1.0f, 2.0f);
		glVertex3f(-1.0f, -2.0f, 1.0f);
		glVertex3f(1.0f, -2.0f, 1.0f);
		glEnd();
	}

	void drawCornerTriangles(){
		// Left to Top Corner
		
		glBegin(GL_TRIANGLES);
		
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(2.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		
		// Left to Top Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(2.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 2.0f, -1.0f);


		// Front to Top Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(1.0f, 1.0f, -2.0f);
		glVertex3f(1.0f, 2.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);


		// Front to Top Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(-1.0f, 1.0f, -2.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 2.0f, -1.0f);
		
		// Right to Top Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-2.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 2.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);


		// Right to Top Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(-2.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);


		// Back to Top Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-1.0f, 1.0f, 2.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		// Back to Top Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(1.0f, 1.0f, 2.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);

		// Front to Bottom Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(1.0f, -1.0f, -2.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -2.0f, -1.0f);

		// Front to Bottom Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-1.0f, -1.0f, -2.0f);
		glVertex3f(-1.0f, -2.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		// Right to Bottom Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(-2.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -2.0f, -1.0f);

		// Right to Bottom Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-2.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -2.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		// Back to Bottom Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(-1.0f, -1.0f, 2.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -2.0f, 1.0f);

		// Back to Bottom Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, 2.0f);
		glVertex3f(1.0f, -2.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		

		// Left to Bottom Corner
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(2.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -2.0f, 1.0f);

		// Left to Bottom Corner
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(2.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -2.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glEnd();

	}

	void drawRectangleTriangles() {
		
		
		glBegin(GL_TRIANGLES);
		
		// Right Top Front Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -2.0f);
		glVertex3f(-2.0f, 1.0f, -1.0f);

		// Right Bottom Front Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-2.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -2.0f);

		// Left Top Front Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(2.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -2.0f);

		// Left Bottom Front Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(2.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -2.0f);
		
		
		// Right Top Back Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-2.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 2.0f);

		// Right Bottom Back Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 2.0f);
		glVertex3f(-2.0f, -1.0f, 1.0f);


		// Left Top Back Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 1.0f);

		// Left Bottom Back Corner
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(2.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 2.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		
		
		


		glEnd();
	}
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	SnakeCube::drawRectangleTriangles();
	SnakeCube::drawCornerTriangles();
	SnakeCube::drawRectangles();
	SnakeCube::drawFaces();
	glFlush();
	glutSwapBuffers();
}

void Timer(int v) {
	glLoadIdentity();
	gluLookAt(lx, y, lz, .5, .5, .5 , 0, 1.0, 0.0);
	glutPostRedisplay();
	glutTimerFunc(1000 / 60.0, Timer, v);
}

void Init() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void Keyboard(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angle += 0.1f;
		lx = sin(angle) * 5;
		lz = -cos(angle) * 5;
		break;
	case GLUT_KEY_RIGHT:
		angle -= 0.1f;
		lx = sin(angle) * 5;
		lz = -cos(angle) * 5;
		break;
	case GLUT_KEY_UP:
		angle += 0.1f;
		y = sin(angle) * 5;
		lz = -cos(angle) * 5;
		break;
	case GLUT_KEY_DOWN:
		angle -= 0.1f;
		y = sin(angle) * 5;
		lz = -cos(angle) * 5;
		break;

	}
}

void Reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, GLfloat(w) / GLfloat(h), 0.5, 40.0);
	glMatrixMode(GL_MODELVIEW);
}

// Writes the controls to console
void WriteHelpToConsole() {
	cout << "	**** Controls ****" << endl;
	cout << "	Left arrow / Down arrow = Rotate left and right" << endl;
	cout << "	Up arrow / Down arrow = Rotate up and down" << endl;


	cout << "Side note: Controls are very janky also slightly last minute\n" <<
		"Just wanted to get some method of looking around the cuboid" << endl << endl << endl;
}

//Main never changes...well almost never
int main(int argc, char** argv) {
	WriteHelpToConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Snake Cube");
	glutDisplayFunc(Draw);
	glutReshapeFunc(Reshape);
	glutTimerFunc(100, Timer, 0);
	glutSpecialFunc(Keyboard);
	Init();
	glutMainLoop();
}