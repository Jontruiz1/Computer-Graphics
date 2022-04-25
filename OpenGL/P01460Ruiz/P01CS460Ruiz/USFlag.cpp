#include <GL/glut.h>
#include <cmath>
#include <iostream>

void DrawStar(float fX, float fY) {
	const float PI = 3.14159265359;
	//Draw a bunch of triangles to form the star...
	const float RADIUS = 0.0308;
	const float INNER_RADIUS = RADIUS * (1.0 / (sin((2.0 * PI) / 5.0) * 2.0 * cos(PI / 10) + sin((3.0 * PI) / 10.0)));

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(fX, fY, 0.0);
	for (int i = 0; i < 10; i++) {
		float angleStart = PI / 2.0 + (i * 2.0 * PI) / 10.0;
		float angleEnd = angleStart + PI / 5.0;
		if (i % 2 == 0) {
			glVertex3f(fX + RADIUS * cos(angleStart) / 1.9, fY + RADIUS * sin(angleStart), 0.0);
			glVertex3f(fX + INNER_RADIUS * cos(angleEnd) / 1.9, fY + INNER_RADIUS * sin(angleEnd), 0.0);
		}
		else {
			glVertex3f(fX + INNER_RADIUS * cos(angleStart) / 1.9, fY + INNER_RADIUS * sin(angleStart), 0.0);
			glVertex3f(fX + RADIUS * cos(angleEnd) / 1.9, fY + RADIUS * sin(angleEnd), 0.0);
		}
	}
	glEnd();
}

void DrawStars() {
	float offset = 0.76 / 1.9;		//.4
	float shortHalf = 6.0 / 13.0;	//0.46153846153
	float longHalf = 7.0 / 13.0;	//0.53846153846
	

	for (int i = 0; i < 9; i++) {
		float fY = shortHalf + (i + 1) * (longHalf / 10);
		float fX = .0633/2;					// The G on specifications is .0633
		//Alternate between rows of 5 or 6 stars
		if (i % 2 == 0) {
			for (int j = 0; j < 6; j++) {
				DrawStar(fX, fY);
				fX += offset / 5.5;				// move over offset/5.5, half the number of stars as the odd rows 
			}
		}
		else {
			for (int k= 0; k < 5; k++) {
				fX += offset/11;				// move over offset/11 because 11 stars
				DrawStar(fX, fY);
				fX += offset / 11;				// move over offset/11
			}
		}
	}

}

void DrawStripes() {
	
	//initially red
	float offset = 0.76 / 1.9 + .03;			// .0769 is width of a stripe from specification and 1.9 is width of width of flag
	float fX = 0;
	float fY = 0;
	float gb = 0;

	//Remember the last seven stripes are shorter..
	// x for the 2nd and 3rd point is always at the screen width, so x always 1
	for (int i = 0; i < 13; i++) {
		gb = (i % 2 == 0) ? 0 : 255;				// I just didn't want if-else statements, made a variable for the green and blue value to change to white or red
		fX = i > 5 ? offset : 0;			// goes to the width of the canton

		glColor3f(255, gb, gb);
		glBegin(GL_POLYGON);
		//Points 1 and 2
		glVertex3f(fX, fY, 0);
		glVertex3f(1, fY, 0);

		//Points 3 and 4
		fY += .0769;						// Flag specifications say width of stripe = .0769
		glVertex3f(1, fY, 0);
		glVertex3f(fX, fY, 0);

		glEnd();
	}
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
	DrawStars();
	DrawStripes();
	glFlush();
}

void Init() {
	glClearColor(0.0, 0.0, 0.4, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100, 600);
	glutInitWindowPosition(800, 300);
	glutCreateWindow("US Flag");
	Init();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}