///**************************************************************************/
///*               HW#4 : Callback 프로그래밍  - 키보드콜백(2)              */
///*          작성자 : 신주영          날짜 : 2020년 10월 16일              */
///*                                                                        */
///* 문제 정의 : 응용1과는 다르게 스페셜 키보드 콜백을 이용하여             */
///*             방향키로 도형을 조정하고, PAGE_UP, DOWN키로 확대,축소한다. */
///**************************************************************************/
//
//
//#include <GL/glut.h>
//
//GLfloat vertex[4][3] = { {-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0} };
//GLfloat color[3] = { 0.5,0.5,0.5 };
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//}
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3fv(color);
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertex[0]);
//	glVertex3fv(vertex[1]);
//	glVertex3fv(vertex[2]);
//	glVertex3fv(vertex[3]);
//	glEnd();
//	glFlush();
//}
//
//void MySpecial(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_UP: if (vertex[1][0] <= 1.0) {
//		vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//	}break;
//	case GLUT_KEY_DOWN: if (vertex[1][1] >= -1.0) {
//		vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1;
//	}break;
//	case GLUT_KEY_LEFT: if (vertex[0][0] >= -1.0) {
//		vertex[0][0] += -0.1; vertex[1][0] += -0.1; vertex[2][0] += -0.1; vertex[3][0] += -0.1;
//	}break;
//	case GLUT_KEY_RIGHT: if (vertex[1][0] <= 1.0) {
//		vertex[0][0] += 0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += 0.1;
//	}break;
//
//	case GLUT_KEY_PAGE_UP:if (vertex[1][0] <= 1.0 && vertex[1][1] >= -1.0 && vertex[0][0] >= -1.0 && vertex[1][0] <= 1.0) {
//		vertex[0][0] += -0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += -0.1; //x좌표
//		vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//	}break; //y좌표
//	case GLUT_KEY_PAGE_DOWN:
//		vertex[0][0] += 0.1; vertex[1][0] += -0.1; vertex[2][0] += -0.1; vertex[3][0] += 0.1; //x좌표
//		vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; break; //y좌표
//
//	default:
//		break;
//	}
//
//	//윈도우 벗어나면 더 이상 증가 x
//
//	glutPostRedisplay();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Keyboard Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutSpecialFunc(MySpecial);
//	glutMainLoop();
//	return 0;
//}