//#include <GL/glut.h>
//#include <stdlib.h> // rand() �Լ� ��� �뵵
//void MyInit()
//{
//	//glClearColor(1.0, 1.0, 1.0, 1.0); // �Ͼ������� ����
//	//glColor3f(1.0, 0.0, 0.0); // ���������� ����
//
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//
//	//glOrtho(0.0, 500.0, 0.0, 500.0, 1, -1);
//
//	//glMatrixMode(GL_MODELVIEW);
//	//glLoadIdentity();
//
//	glClearColor(1.0, 1.0, 1.0, 1.0); // �Ͼ������� ����
//	glColor3f(1.0, 0.0, 0.0); // ���������� ����
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
//	float vertices[3][2] = { { 0.0,0.0 },{ 250.0,500.0 },{ 500.0,0.0 } }; //�ʱ� ����
//	int i, j;
//	float p[3] = { 75.0, 50.0, 0.0 };
//	// ���� ����Ʈ
//	glClear(GL_COLOR_BUFFER_BIT);
//	for (j = 0; j < 50000; j++)
//	{
//		i = rand() % 3; // ������ �� ����. 0-2�� ��
//		p[0] = (p[0] + vertices[i][0]) / 2.0;
//		p[1] = (p[1] + vertices[i][1]) / 2.0;
//		// ���� ���õ� ���� ���� ���� �������� ���ο� �� ��ġ ���( ������ ��ġ ��� )
//		glBegin(GL_POINTS);
//		glVertex3fv(p); // ���� ��ġ�� �� ���
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
//	//glVertex2fv(p); // ���� ��ġ�� �� ���
//	//glVertex2fv(q);
//	//glVertex2fv(r);
//
//	//glEnd();
//	//glFlush();
//	//// ���� ����Ʈ
//	//glClear(GL_COLOR_BUFFER_BIT);
//	//for (j = 0; j < 50000; j++)
//	//{
//	//	i = rand() % 3; // ������ �� ����. 0-2�� ��
//	//	p[0] = (p[0] + vertices[i][0]) / 2.0;
//	//	p[1] = (p[1] + vertices[i][1]) / 2.0;
//	//	// ���� ���õ� ���� ���� ���� �������� ���ο� �� ��ġ ���( ������ ��ġ ��� )
//	//	glBegin(GL_POINTS);
//	//	glVertex2fv(p); // ���� ��ġ�� �� ���
//	//	glEnd();
//	//}
//	//glFlush();
//}
//
////void MyReshape(int w, int h)
////{
////	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
////	glMatrixMode(GL_PROJECTION); //����
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