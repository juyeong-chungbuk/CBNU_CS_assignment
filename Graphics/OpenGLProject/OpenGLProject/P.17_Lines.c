//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0); //흰색
//
//	glBegin(GL_LINES); //점을 두개씩 묶어 선을 만듦
//	glVertex3f(0.0, -0.5, 0.0); glVertex3f(-0.5, 0.0, 0.0); //1번 선
//	glVertex3f(0.0, 0.25, 0.0); glVertex3f(0.5, 0.5, 0.0); //2번 선
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