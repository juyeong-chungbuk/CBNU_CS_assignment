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
//	// 이벤트를 통해 뷰포트를 새롭게 받은 가로와 세로길이로 설정합니다.
//	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)300;
//	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)300;
//	// 이벤트를 통해 새롭게 받은 가로와 세로를 통하여 비율을 새로 정합니다.
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0 * Widthfactor, 20.0 * Widthfactor, 0.0 * Heightfactor, 20.0 * Heightfactor, 10.0, 50.0);
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	// 투영행렬 선택
//	//glMatrixMode(GL_PROJECTION);
//	// 현재 투영행렬을 항등행렬로 초기화
//	glLoadIdentity();
//	// 투영 변환
//	glOrtho(0.0, 20.0, 0.0, 20.0, 10.0, 50.0);
//	// 모델뷰행렬 선택
//	glMatrixMode(GL_MODELVIEW);
//	// 현재 모델뷰 행렬을 항등행렬로 초기화
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
//	// reshape callback 이벤트 수행
//	glutMainLoop();
//	return 0;
//}