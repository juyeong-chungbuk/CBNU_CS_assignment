#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#pragma comment(lib,"winmm")
#include<mmsystem.h>
#define SOUND_FILE_NAME "C:/Users/happy/Downloads/CarBBANG.wav" //경적소리

GLint window;
float i, theta;

GLfloat xt = 0.0, yt = 0.0, zt = 0.0, xw = 0.0;
GLfloat xangle = 0.0, yangle = 0.0, zangle = 0.0, angle = 0.0;

GLfloat r = 0, g = 0, b = 1;
GLint light = 1;
int count = 1;
int view = 0;
int aflag = 1; 
int wheelflag = 0;   
GLUquadricObj *t;

GLvoid Transform(GLfloat Width, GLfloat Height)
{
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, Width, Height);
	glLoadIdentity();
	gluPerspective(45.0, Width / Height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

GLvoid InitGL(GLfloat Width, GLfloat Height)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(2.0); 
	Transform(Width, Height);
	t = gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

}
void init()
{
	glClearColor(0, 0, 0, 0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 900.0, 0.0, 600.0, 50.0, -50.0);
	glutPostRedisplay();
}


GLvoid DrawGLScene() //디스플레이 함수
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (count == 1)
		InitGL(800, 800);

	glPushMatrix();
	glLoadIdentity();		
	glTranslatef(-1.0, 0.0, -3.5);

	glRotatef(xangle+10.0, xangle+1000.0, 0.0, 0.0);
	glRotatef(yangle, 0.0, 1.0, 0.0);
	glRotatef(zangle, 0.0, 0.0, 1.0);  //카메라 시점이동

	glTranslatef(xt, yt, zt);
	glEnable(GL_COLOR_MATERIAL);

	glBegin(GL_QUADS);

	//차 앞 부분
	glColor3f(r, g, b);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	
	/* 아래*/
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.2, 0.2, 0.2);

	/* 위*/
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.2, 0.4, 0.6);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.2, 0.2, 0.2);

	/* 뒤*/
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	
	/* 왼*/
	glVertex3f(0.2, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.2, 0.4, 0.6);
	
	/* 오*/
	glVertex3f(0.2, 0.2, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.2, 0.4, 0.2);

	//차 뒷부분
	glVertex3f(0.7, 0.65, 0.6);
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(1.7, 0.65, 0.2);       
	glVertex3f(1.7, 0.65, 0.6);
		
	glColor3f(r, g, b);
	glVertex3f(1.8, 0.5, 0.6);
	glVertex3f(1.8, 0.5, 0.2);
	glVertex3f(2.1, 0.4, 0.2);
	glVertex3f(2.1, 0.4, 0.6);
	
	/*아래*/
	glVertex3f(2.1, 0.2, 0.6);
	glVertex3f(2.1, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.6);		
	glVertex3f(1.8, 0.2, 0.6);
	
	/* 뒤*/
	glVertex3f(2.1, 0.4, 0.6);
	glVertex3f(2.1, 0.4, 0.2);
	glVertex3f(2.1, 0.2, 0.2);
	glVertex3f(2.1, 0.2, 0.6);

	/* 왼쪽*/
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.5, 0.2);
	glVertex3f(2.1, 0.4, 0.2);
	glVertex3f(2.1, 0.2, 0.2);

	/* 오른쪽*/
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8, 0.5, 0.6);
	glVertex3f(2.1, 0.4, 0.6);
	glVertex3f(2.1, 0.2, 0.6);
		
	glVertex3f(0.6, 0.5, 0.6);
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8, 0.5, 0.6);

	/*바닥 사각형*/
	glVertex3f(0.6, 0.2, 0.6);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.6);

	/*뒤에 사각형*/
	glVertex3f(0.6, 0.5, 0.2);
	glVertex3f(0.6, 0.2, 0.2);
	glVertex3f(1.8, 0.2, 0.2);
	glVertex3f(1.8, 0.5, 0.2);

	//창문
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.77, 0.63, 0.2);
	glVertex3f(0.75, 0.5, 0.2);        //앞창문
	glVertex3f(1.2, 0.5, 0.2);
	glVertex3f(1.22, 0.63, 0.2);

	glVertex3f(1.27, 0.63, .2);
	glVertex3f(1.25, 0.5, 0.2);        //뒷창문
	glVertex3f(1.65, 0.5, 0.2);
	glVertex3f(1.67, 0.63, 0.2);
		
	glColor3f(r, g, b);
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f(0.7, 0.5, .2);       //차 첫부분
	glVertex3f(0.75, 0.5, 0.2);
	glVertex3f(0.77, 0.65, 0.2);

	glVertex3f(1.2, 0.65, 0.2);
	glVertex3f(1.2, 0.5, .2);       //차 두번째 부분
	glVertex3f(1.25, 0.5, 0.2);
	glVertex3f(1.27, 0.65, 0.2);

	glVertex3f(1.65, 0.65, 0.2);
	glVertex3f(1.65, 0.5, .2);     //3d separation
	glVertex3f(1.7, 0.5, 0.2);
	glVertex3f(1.7, 0.65, 0.2);

	glVertex3f(0.75, 0.65, 0.2);
	glVertex3f(0.75, 0.63, 0.2);        //line strip
	glVertex3f(1.7, 0.63, 0.2);
	glVertex3f(1.7, 0.65, 0.2);

	glVertex3f(0.75, 0.65, 0.6);
	glVertex3f(0.75, 0.63, 0.6);        //line strip
	glVertex3f(1.7, 0.63, 0.6);
	glVertex3f(1.7, 0.65, 0.6);

	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.77, 0.63, 0.6);
	glVertex3f(0.75, 0.5, 0.6);        //quad front window
	glVertex3f(1.2, 0.5, 0.6);
	glVertex3f(1.22, 0.63, 0.6);

	glVertex3f(1.27, 0.63, .6);
	glVertex3f(1.25, 0.5, 0.6);        //quad back window
	glVertex3f(1.65, 0.5, 0.6);
	glVertex3f(1.67, 0.63, 0.6);

	glBegin(GL_QUADS);

	glPushMatrix();
		glTranslatef(xw, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f(-100, 0.1, -100);
		glVertex3f(-100, 0.1, 0);         //풀밭
		glVertex3f(100, 0.1, 0);
		glVertex3f(100, 0.1, -100);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(-100, 0.1, 0);
		glVertex3f(-100, 0.1, 0.45);         //도로
		glVertex3f(100, 0.1, 0.45);
		glVertex3f(100, 0.1, 0);

		glColor3f(1.0, 0.75, 0.0);
		glVertex3f(-100, 0.1, 0.45);       //중앙선
		glVertex3f(-100, 0.1, 0.55);
		glVertex3f(100, 0.1, 0.55);
		glVertex3f(100, 0.1, 0.45);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(-100, 0.1, 0.55);
		glVertex3f(-100, 0.1, 1);         //도로
		glVertex3f(100, 0.1, 1);
		glVertex3f(100, 0.1, 0.55);

		glColor3f(0, 1, 0);
		glVertex3f(-100, 0.1, 1);
		glVertex3f(-100, 0.1, 100);         //풀밭
		glVertex3f(100, 0.1, 100);
		glVertex3f(100, 0.1, 1);
		glPopMatrix();
		glEnd();

		glBegin(GL_TRIANGLES); 

		  //위에 사각형
		glColor3f(0.3, 0.3, 0.3);
		glVertex3f(0.6, 0.5, 0.6);
		glVertex3f(0.7, 0.65, 0.6);      
		glVertex3f(0.7, 0.5, 0.6);

		glVertex3f(0.6, 0.5, 0.2);
		glVertex3f(0.7, 0.65, 0.2);       
		glVertex3f(0.7, 0.5, 0.2);        //앞창문

		glVertex3f(1.7, 0.65, 0.2);
		glVertex3f(1.8, 0.5, 0.2);      
		glVertex3f(1.7, 0.5, 0.2);

		glVertex3f(1.7, 0.65, 0.6);
		glVertex3f(1.8, 0.5, 0.6);       
		glVertex3f(1.7, 0.5, 0.6);       //뒷창문

		glEnd();

		//바퀴

		glColor3f(0.7, 0.7, 0.7);
		glPushMatrix();
		glBegin(GL_LINE_STRIP);
		for (theta = 0; theta < 360; theta = theta + 40){
			glVertex3f(0.6, 0.2, 0.62);
			glVertex3f(0.6 + (0.08*(cos((theta*3.14) / 180))), 0.2 + (0.05*(sin(theta *3.14) / 180)), 0.62);
		}
		glEnd();

		glBegin(GL_LINE_STRIP);
		for (theta = 0; theta < 360; theta = theta + 40){
			glVertex3f(0.6, 0.2, 0.18);
			glVertex3f(0.6 + (0.08*(cos((theta*3.14) / 180))), 0.2 + (0.05*(sin(theta*3.14) / 180)), 0.18);
		}
		glEnd();

		glBegin(GL_LINE_STRIP);
		for (theta = 0; theta < 360; theta = theta + 40){
			glVertex3f(1.7, 0.2, 0.18);
			glVertex3f(1.7 + (0.08*(cos((theta*3.14) / 180))), 0.2 + (0.05*(sin(theta*3.14) / 180)), 0.18);
		}
		glEnd();

		glBegin(GL_LINE_STRIP);
		for (theta = 0; theta < 360; theta = theta + 40){
			glVertex3f(1.7, 0.2, 0.62);
			glVertex3f(1.7 + (0.08*(cos((theta*3.14) / 180))), 0.2 + (0.05*(sin(theta*3.14) / 180)), 0.62);
		}
		glEnd();

		glTranslatef(0.6, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glutSolidTorus(0.025, 0.07, 10, 25);

		glTranslatef(0, 0, -0.4);
		glutSolidTorus(0.025, 0.07, 10, 25);

		glTranslatef(1.1, 0, 0);
		glutSolidTorus(0.025, 0.07, 10, 25);

		glTranslatef(0, 0, 0.4);
		glutSolidTorus(0.025, 0.07, 10, 25);
		glPopMatrix();

		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glutPostRedisplay();
		glutSwapBuffers();
}

void MyKeyboard(GLubyte key, GLint x, GLint y)
{
	view = 1;
	DrawGLScene();

	switch (key) {

	case 'x': 
		xangle += 5.0;
		glutPostRedisplay();
		break;

	case 'X':
		xangle -= 5.0;
		glutPostRedisplay();
		break;

	case 'y':
		yangle += 5.0;
		glutPostRedisplay();
		break;

	case 'Y':
		yangle -= 5.0;
		glutPostRedisplay();
		break;

	case 'z':
		zangle += 5.0;
		glutPostRedisplay();
		break;

	case 'Z':
		zangle -= 5.0;
		glutPostRedisplay();
		break;

	default:
		break;
	}

}

void SpecialKeyboard(int Key, int x, int y)
{
	switch (Key) {
	case GLUT_KEY_RIGHT:
		if (!wheelflag)
			xt += 0.2;
		if (wheelflag){
			angle += 5;
			xw += 0.2;
		}
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		if (!wheelflag)
			xt -= 0.2;
		if (wheelflag){
			angle += 5;
			xw -= 0.2;
		}
		PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_ASYNC | SND_ALIAS);
		glutPostRedisplay();
		break;
	}
}

void colorMenu(int id)
{
	if (id == 1){
		r = g = 0;
		b = 1;
		glutPostRedisplay();
	}
	else if (id == 2){
		r = 0.8;
		b = g = 0;
		glutPostRedisplay();
	}
	else{
		g = 0.5;
		r = b = 0;
		glutPostRedisplay();
	}
}

void myMenu(int id)
{
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Car Race");
	InitGL(800, 800);
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(SpecialKeyboard);
	int submenu = glutCreateMenu(colorMenu);
	glutAddMenuEntry("blue", 1);
	glutAddMenuEntry("red", 2);
	glutAddMenuEntry("green", 3);
	glutCreateMenu(myMenu);
	glutAddSubMenu("Car Color Change", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 1;
}