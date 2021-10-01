//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	GLfloat Size[2];
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_LINE_LOOP); //첫번째 점과 마지막 점을 연결
//	glVertex3f(-0.75, 0.5, 0.0); glVertex3f(-0.5, 0.25, 0.0); //V0 , V1
//	glVertex3f(-0.5, 0.25, 0.0); glVertex3f(0.0, 0.5, 0.0); //V2, V3
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, 0.25, 0.0); //V4, V5
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("My First OpenGL Code");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}