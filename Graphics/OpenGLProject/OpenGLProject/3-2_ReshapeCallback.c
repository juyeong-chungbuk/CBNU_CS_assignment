//#include <GL/glut.h>
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.5, 0.5);
//	glBegin(GL_POLYGON);
//	glVertex3f(0.0, 0.0, -30.0);
//	glVertex3f(10.0, 0.0, -30.0);
//	glVertex3f(10.0, 10.0, -30.0);
//	glVertex3f(0.0, 10.0, -30.0);
//	glEnd();
//	glFlush();
//}
//void MyReshape(int NewWidth, int NewHeight) {
//	glViewport(0, 0, NewWidth, NewHeight);
//	// �̺�Ʈ�� ���� ����Ʈ�� ���Ӱ� ���� ���ο� ���α��̷� �����մϴ�.
//	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)300;
//	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)300;
//	// �̺�Ʈ�� ���� ���Ӱ� ���� ���ο� ���θ� ���Ͽ� ������ ���� ���մϴ�.
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0 * Widthfactor, 20.0 * Widthfactor, 0.0 * Heightfactor, 20.0 * Heightfactor, 10.0, 50.0);
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	// ������� ����
//	//glMatrixMode(GL_PROJECTION);
//	// ���� ��������� �׵���ķ� �ʱ�ȭ
//	glLoadIdentity();
//	// ���� ��ȯ
//	glOrtho(0.0, 20.0, 0.0, 20.0, 10.0, 50.0);
//	// �𵨺���� ����
//	glMatrixMode(GL_MODELVIEW);
//	// ���� �𵨺� ����� �׵���ķ� �ʱ�ȭ
//	glLoadIdentity();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Reshape");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(MyReshape);
//	// reshape callback �̺�Ʈ ����
//	glutMainLoop();
//	return 0;
//}