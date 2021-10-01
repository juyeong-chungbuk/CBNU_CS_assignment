//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_TRIANGLE_STRIP); //»ï°¢Çü³¢¸® ¿¬°á
//	glVertex3f(0.9, 0.2, 0.0); glVertex3f(0.75, 0.5, 0.0); glVertex3f(0.5, 0.1, 0.0); //V0, V1, V2
//	glVertex3f(0.25, 0.25, 0.0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(-0.25, -0.25, 0.0); //V3, V4, V5
//	glVertex3f(-0.5, -0.5, 0.0); //V6
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("TrianglesStrip");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}