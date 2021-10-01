///**************************************************************************/
///*               HW#4 : Callback ���α׷���  - Ű�����ݹ�(2)              */
///*          �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��              */
///*                                                                        */
///* ���� ���� : ����1���� �ٸ��� ����� Ű���� �ݹ��� �̿��Ͽ�             */
///*             ����Ű�� ������ �����ϰ�, PAGE_UP, DOWNŰ�� Ȯ��,����Ѵ�. */
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
//		vertex[0][0] += -0.1; vertex[1][0] += 0.1; vertex[2][0] += 0.1; vertex[3][0] += -0.1; //x��ǥ
//		vertex[0][1] += -0.1; vertex[1][1] += -0.1; vertex[2][1] += 0.1; vertex[3][1] += 0.1;
//	}break; //y��ǥ
//	case GLUT_KEY_PAGE_DOWN:
//		vertex[0][0] += 0.1; vertex[1][0] += -0.1; vertex[2][0] += -0.1; vertex[3][0] += 0.1; //x��ǥ
//		vertex[0][1] += 0.1; vertex[1][1] += 0.1; vertex[2][1] += -0.1; vertex[3][1] += -0.1; break; //y��ǥ
//
//	default:
//		break;
//	}
//
//	//������ ����� �� �̻� ���� x
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