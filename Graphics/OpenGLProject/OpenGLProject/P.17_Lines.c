//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0); //���
//
//	glBegin(GL_LINES); //���� �ΰ��� ���� ���� ����
//	glVertex3f(0.0, -0.5, 0.0); glVertex3f(-0.5, 0.0, 0.0); //1�� ��
//	glVertex3f(0.0, 0.25, 0.0); glVertex3f(0.5, 0.5, 0.0); //2�� ��
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Lines");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}