//#include <GL/glut.h>
//#include <stdlib.h> // rand() 함수 사용 용도
//void MyInit()
//{
//	//glClearColor(1.0, 1.0, 1.0, 1.0); // 하얀배경으로 세팅
//	//glColor3f(1.0, 0.0, 0.0); // 빨간점으로 세팅
//
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//
//	//glOrtho(0.0, 500.0, 0.0, 500.0, 1, -1);
//
//	//glMatrixMode(GL_MODELVIEW);
//	//glLoadIdentity();
//
//	glClearColor(1.0, 1.0, 1.0, 1.0); // 하얀배경으로 세팅
//	glColor3f(1.0, 0.0, 0.0); // 빨간점으로 세팅
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 500.0, 0.0, 500.0, 1, -1);
//}
//
//void MyDisplay(void)
//{
//	//GLfloat *a, *b, *c;
//
//	//glVertex3fv(a);
//	//glVertex3fv(b);
//	//glVertex3fv(c);
//	float vertices[3][2] = { { 0.0,0.0 },{ 250.0,500.0 },{ 500.0,0.0 } }; //초기 세모
//	int i, j;
//	float p[3] = { 75.0, 50.0, 0.0 };
//	// 찍힐 포인트
//	glClear(GL_COLOR_BUFFER_BIT);
//	for (j = 0; j < 50000; j++)
//	{
//		i = rand() % 3; // 임의의 점 선택. 0-2의 값
//		p[0] = (p[0] + vertices[i][0]) / 2.0;
//		p[1] = (p[1] + vertices[i][1]) / 2.0;
//		// 새로 선택된 좀과 현재 점을 기준으로 새로운 점 위치 계산( 중점의 위치 계산 )
//		glBegin(GL_POINTS);
//		glVertex3fv(p); // 찍힐 위치에 점 찍기
//		glEnd();
//	}
//	glFlush();//
//
//	//float p[2] = { 0.0,0.0 };
//	//float q[2] = { 250.0,500.0 };
//	//float r[2] = { 500.0,0.0 };
//
//	//glClear(GL_COLOR_BUFFER_BIT);
//	//glBegin(GL_POINTS);
//
//	//glVertex2fv(p); // 찍힐 위치에 점 찍기
//	//glVertex2fv(q);
//	//glVertex2fv(r);
//
//	//glEnd();
//	//glFlush();
//	//// 찍힐 포인트
//	//glClear(GL_COLOR_BUFFER_BIT);
//	//for (j = 0; j < 50000; j++)
//	//{
//	//	i = rand() % 3; // 임의의 점 선택. 0-2의 값
//	//	p[0] = (p[0] + vertices[i][0]) / 2.0;
//	//	p[1] = (p[1] + vertices[i][1]) / 2.0;
//	//	// 새로 선택된 좀과 현재 점을 기준으로 새로운 점 위치 계산( 중점의 위치 계산 )
//	//	glBegin(GL_POINTS);
//	//	glVertex2fv(p); // 찍힐 위치에 점 찍기
//	//	glEnd();
//	//}
//	//glFlush();
//}
//
////void MyReshape(int w, int h)
////{
////	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
////	glMatrixMode(GL_PROJECTION); //투영
////	glLoadIdentity();
////	
////	GLfloat Width = (GLfloat)w / (GLfloat)100;
////	GLfloat Height = (GLfloat)h / (GLfloat)2;////
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////	glOrtho(0.0 * Width, 200.0 * Width, 0.0 * Height, 20.0 * Height, 100.0, 50.0);
////}
//
//void main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("3D Sierpinski Gasket");
//	glutDisplayFunc(MyDisplay);
//
//	MyInit();
//	//glutReshapeFunc(MyReshape);
//	glutMainLoop();
//}