//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_TRIANGLES); //삼각형만들기
//	glVertex3f(0.0, 0.5, 0.0); glVertex3f(0.5, -0.5, 0.0);  //V0, V1
//  glVertex3f(-0.5, -0.5, 0.0);  //V2
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Trangles");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}