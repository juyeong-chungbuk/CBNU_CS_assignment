///**************************************************************************************************/
///*                HW#5 : 계층적 모델링, 시점변환  - gluLookAt() 실시간 제어                       */
///*                  작성자 : 신주영               날짜 : 2020년 11월 5일                          */
///*                                                                                                */
///* 문제 정의 : Timer콜백함수를 활용하여 전역변수 cameradhk focus를 LookAt함수에 인자로            */
///*  넣어주어 각각 UP, DOWN, LEFT, RIGHT키를 눌렀을 때, 카메라의 Y축좌표가                         */
///*  0.1씩 증가, 감소하고, X축 좌표가 증가, 감소한다.                                              */
///*  a, f, r, v, z, t를 눌렀을 때는 각각 카메라가 바라보고 있는 초점의 X축 좌표가 증가, 감소하고   */
///*  Y축 좌표가 증가, 감소하고 Z축 좌표가 증가, 감소하는 프로그램이다.                             */
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
//		if (n == 1) { //a or A 버튼 누를 시
//			if (focusX < 3.0) //윈도우를 벗어나지 않을 조건
//				focusX = focusX + 0.1; //초점을 0.1씩 증가
//			else
//				focusX = focusX + 0.0;
//		}
//		else if (n == 2) { //f or F 버튼 누를 시
//			if (focusX > -3.0)
//				focusX = focusX - 0.1;  //초점을 0.1씩 감소
//			else
//				focusX = focusX + 0.0;
//		}
//		else if (n == 3) { //r or R 버튼 누를 시
//			if (focusY < 3.0)
//				focusY = focusY + 0.1;
//			else
//				focusY = focusY + 0.0;
//		}
//		else if (n == 4) { //v or V 버튼 누를 시
//			if (focusY > -3.0)
//				focusY = focusY - 0.1;
//			else
//				focusY = focusY + 0.0;
//		}
//		else if (n == 5) { //z or Z 버튼 누를 시
//			if (focusZ < 3.0)
//				focusZ = focusZ + 0.1;
//			else
//				focusZ = focusZ + 0.0;
//		}
//		else if (n == 6) { //t or T 버튼 누를 시
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
//	glutPostRedisplay(); //디스플레이 함수 호출
//	glutTimerFunc(10, MyTimer, 1); //인위적으로 넣어줘야함
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