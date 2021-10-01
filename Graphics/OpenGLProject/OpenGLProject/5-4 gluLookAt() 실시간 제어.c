///**************************************************************************************************/
///*                HW#5 : ������ �𵨸�, ������ȯ  - gluLookAt() �ǽð� ����                       */
///*                  �ۼ��� : ���ֿ�               ��¥ : 2020�� 11�� 5��                          */
///*                                                                                                */
///* ���� ���� : Timer�ݹ��Լ��� Ȱ���Ͽ� �������� cameradhk focus�� LookAt�Լ��� ���ڷ�            */
///*  �־��־� ���� UP, DOWN, LEFT, RIGHTŰ�� ������ ��, ī�޶��� Y����ǥ��                         */
///*  0.1�� ����, �����ϰ�, X�� ��ǥ�� ����, �����Ѵ�.                                              */
///*  a, f, r, v, z, t�� ������ ���� ���� ī�޶� �ٶ󺸰� �ִ� ������ X�� ��ǥ�� ����, �����ϰ�   */
///*  Y�� ��ǥ�� ����, �����ϰ� Z�� ��ǥ�� ����, �����ϴ� ���α׷��̴�.                             */
///**************************************************************************************************/
//
//#include <GL/glut.h>
//GLfloat cameraX = 0.0, cameraY=3.5, focusX = 0.0, focusY = 0.0, focusZ = 0.0;
//int n;
//
//void DrawGround() {
//	glColor3f(0.5, 0.5, 0.5);
//	glBegin(GL_POLYGON);
//	glVertex3f(-2.0, -0.71, 2.0);
//	glVertex3f(2.0, -0.71, 2.0);
//	glVertex3f(2.0, -0.71, -2.0);
//	glVertex3f(-2.0, -0.71, -2.0);
//	glEnd();
//	glColor3f(0.3, 0.3, 0.3);
//	glBegin(GL_LINES);
//	for (float x = -2.0; x <= 2.2; x += 0.2) {
//		glVertex3f(x, -0.7, -2.0);
//		glVertex3f(x, -0.7, 2.0);
//	}
//	for (float z = -2.0; z <= 2.2; z += 0.2) {
//		glVertex3f(-2.0, -0.7, z);
//		glVertex3f(2.0, -0.7, z);
//	}
//	glEnd();
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(cameraX, cameraY, 3.5, focusX, focusY, focusZ, 0.0, 1.0, 0.0);
//	DrawGround();
//	glColor3f(1.0, 1.0, 0.0);
//	glutWireTeapot(1.0);
//	glFlush();
//}
//
//void MyTimer(int value)
//{
//		if (n == 1) { //a or A ��ư ���� ��
//			if (focusX < 3.0) //�����츦 ����� ���� ����
//				focusX = focusX + 0.1; //������ 0.1�� ����
//			else
//				focusX = focusX + 0.0;
//		}
//		else if (n == 2) { //f or F ��ư ���� ��
//			if (focusX > -3.0)
//				focusX = focusX - 0.1;  //������ 0.1�� ����
//			else
//				focusX = focusX + 0.0;
//		}
//		else if (n == 3) { //r or R ��ư ���� ��
//			if (focusY < 3.0)
//				focusY = focusY + 0.1;
//			else
//				focusY = focusY + 0.0;
//		}
//		else if (n == 4) { //v or V ��ư ���� ��
//			if (focusY > -3.0)
//				focusY = focusY - 0.1;
//			else
//				focusY = focusY + 0.0;
//		}
//		else if (n == 5) { //z or Z ��ư ���� ��
//			if (focusZ < 3.0)
//				focusZ = focusZ + 0.1;
//			else
//				focusZ = focusZ + 0.0;
//		}
//		else if (n == 6) { //t or T ��ư ���� ��
//			if (focusZ > -3.0)
//				focusZ = focusZ - 0.1;
//			else
//				focusZ = focusZ + 0.0;
//		}
//		else if (n == 7) { //UP
//			if (cameraY < 10.0)
//				cameraY = cameraY + 0.1;
//			else
//				cameraY = cameraY + 0.0;
//		}
//		else if (n == 8) { //DOWN
//			if (cameraY > -10.0)
//				cameraY = cameraY - 0.1;
//			else
//				cameraY = cameraY + 0.0;
//		}
//		else if (n == 9) { //LEFT
//			if (cameraX > -10.0)
//				cameraX = cameraX - 0.1;
//			else
//				cameraX = cameraX + 0.0;
//		}
//		else if (n == 10) { //RIGHT
//			if (cameraX < 10.0)
//				cameraX = cameraX + 0.1;
//			else
//				cameraX = cameraX + 0.0;
//		}
//		else {
//			return;
//		}
//
//	glutPostRedisplay(); //���÷��� �Լ� ȣ��
//	glutTimerFunc(10, MyTimer, 1); //���������� �־������
//}
//
//void MyKeyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 'a':
//		n = 1;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'A':
//		n = 1;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'f':
//		n = 2;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'F':
//		n = 2;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'r':
//		n = 3;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'R':
//		n = 3;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'v':
//		n = 4;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'V':
//		n = 4;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'z':
//		n = 5;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'Z':
//		n = 5;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 't':
//		n = 6;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 'T':
//		n = 6;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case 27:
//		exit(0);
//		break;
//
//	default:
//		break;
//	}
//}
//
//void MyspecialKeyboard(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_UP:
//		n = 7;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case GLUT_KEY_DOWN:
//		n = 8;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case GLUT_KEY_LEFT:
//		n = 9;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case GLUT_KEY_RIGHT:
//		n = 10;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	default:
//		break;
//	}
//}
//
//void MyReshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("VCS (View Coordinate System)");
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(MyReshape);
//	glutKeyboardFunc(MyKeyboard);
//	glutSpecialFunc(MyspecialKeyboard);
//	glutMainLoop();
//	return 0;
//}