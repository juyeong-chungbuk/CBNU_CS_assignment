///**************************************************************************************/
///*                 HW#5 : 계층적 모델링, 시점변환  - 태양계 모델링 확장               */
///*                 작성자 : 신주영               날짜 : 2020년 11월 4일               */
///*                                                                                    */
///* 문제 정의 : 태양과 4개의 행성을 모델링하고, 각각의 크기와 위치를 다르게 지정한다.  */
///*             마우스 콜백, 타이머 콜백기능을 사용하여 왼쪽 버튼 클릭 시,             */
///*             행성들이 공전하고, 오른쪽버튼 클릭 시, 공전을 정지시킨다.              */
///**************************************************************************************/
//
//#include <GL/glut.h>
//static int Day = 0, Time = 0;
//int n = 0;
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	
//	    glColor3f(1.0, 0.3, 0.3);
//		glutWireSphere(0.2, 20, 16); //태양
//		glPushMatrix();
//		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
//		glTranslatef(0.5, 0.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//
//		glColor3f(0.9, 0.5, 0.9);
//		glutWireSphere(0.1, 10, 8); //중간
//		glPushMatrix();
//		glRotatef((GLfloat)Day*2, 0.0, 1.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//		glTranslatef(0.1, 0.0, 0.0);
//
//		glColor3f(1.0, 0.5, 0.0);
//		glutWireSphere(0.04, 10, 8); //젤 작은거
//		glPushMatrix();
//		glRotatef((GLfloat)Day+10, 0.0, 1.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//		glTranslatef(0.15, 0.0, 0.0);
//		
//		glColor3f(0.0, 1.0, 0.0);
//		glutWireSphere(0.08, 10, 8); //중간
//		glPushMatrix();
//		glRotatef((GLfloat)Day+7, 0.0, 1.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//		glTranslatef(0.09, 0.0, 0.0);
//	
//		glColor3f(0.0, 0.0, 0.8);
//		glutWireSphere(0.12, 20, 8); //중간
//		glPushMatrix();
//		glRotatef((GLfloat)Day/2, 0.0, 1.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//		glTranslatef(0.02, 0.0, 0.0);
//
//	glPopMatrix();
//	glutSwapBuffers();
//}////void MyKeyboard(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'd':
//		Day = (Day + 10) % 360;
//		break;
//	case 't':
//		Time = (Time + 5) % 360;
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void MyTimer(int value) {
//	if (n == 1) {
//		Day = (Day + 5) % 360;
//		glutPostRedisplay();
//		glutTimerFunc(80, MyTimer, 0);
//		
//	}
//	else {
//		Day = Day % 360;
//		glutPostRedisplay();
//	}
//}
//
//void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
//
//	switch (Button) {
//	case GLUT_LEFT_BUTTON:
//		glutTimerFunc(50, MyTimer, 0);
//		n = 1;
//		break;
//
//	case GLUT_RIGHT_BUTTON:
//		n = 2;
//		break;
//	}
//}
//
//
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Solar System");
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//	glutDisplayFunc(MyDisplay);
//	glutMouseFunc(MyMouse);
//	//glutTimerFunc(10, MyTimer, 0);
//	glutKeyboardFunc(MyKeyboard);
//	glutMainLoop();
//	return 0;
//}