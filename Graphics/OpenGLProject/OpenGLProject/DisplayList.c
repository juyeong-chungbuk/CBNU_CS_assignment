//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//int MyListID; //DisplayList�� ���� ID�� ���� �ĺ�
//// Display List ����
//
//void MyCreateList() {
//	MyListID = glGenLists(1); // DisplayList ����
//	// ���̵� ���� ����Ʈ 1���� ���� �����,
//	// �������� �ʰ� ������ �Ϸ�� ������ �����.
//	glNewList(MyListID, GL_COMPILE);
//	glBegin(GL_POLYGON); // ����Ʈ�� �����ϴ� �Լ� ����
//	glColor3f(0.5, 0.5, 0.5);
//	glVertex3f(-0.5, -0.5, 0.0);
//	glVertex3f(0.5, -0.5, 0.0);
//	glVertex3f(0.5, 0.5, 0.0);
//	glVertex3f(-0.5, 0.5, 0.0);
//	glEnd();
//	glEndList();
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glViewport(0, 0, 300, 300);
//	glCallList(MyListID); // �������� �Ϸ�� ����Ʈ�� ������ ����
//	glFlush();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("OpenGL Example Drawing");
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, - 1.0);
//
//	glutDisplayFunc(MyDisplay);
//	MyCreateList(); // Display List ����
//	glutMainLoop();
//	return 0;
//}