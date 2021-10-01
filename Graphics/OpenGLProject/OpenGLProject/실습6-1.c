//#include <GL/glut.h>
//
//void MyDisplay() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glTranslatef(-0.5, 1.0, 0.0);
//
//	glutSolidTeapot(1.0);
//
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("My display");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}