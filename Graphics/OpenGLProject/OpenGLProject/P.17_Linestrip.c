//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_LINE_STRIP); //선끼리 연결
//	glVertex3f(-0.75, 0.5, 0.0); glVertex3f(-0.5, 0.25, 0.0); //1번 선
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, 0.25, 0.0); //2번 선
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("LineStrip");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}