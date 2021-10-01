//#include<GL/glut.h>
//
//void MyDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glBegin(GL_TRIANGLE_FAN); //부채꼴모양으로 삼각형 연결
//	glVertex3f(0.0, 0.0, 0.0); //V0
//	glVertex3f(0.1, 0.5, 0.0); glVertex3f(0.2, 0.53, 0.0); glVertex3f(0.3, 0.45, 0.0); //V1, V2, V3
//	glVertex3f(0.4, 0.4, 0.0); glVertex3f(0.5, 0.2, 0.0); //V4, V5
//
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("TriangleFan");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}