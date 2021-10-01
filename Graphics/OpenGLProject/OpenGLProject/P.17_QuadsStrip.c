//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_QUAD_STRIP); //사각형끼리 연결
//	glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.1, 0.2, 0.0); //V0, V1
//	glVertex3f(0.2, 0.25, 0.0); glVertex3f(0.15, -0.1, 0.0); //V2, V3
//	glVertex3f(0.3, 0.0, 0.0); glVertex3f(0.25, -0.2, 0.0); //V4, V5
//	glVertex3f(0.35, -0.15, 0.0); glVertex3f(0.32, -0.18, 0.0); //V6, V7
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("QuadsStrip");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}