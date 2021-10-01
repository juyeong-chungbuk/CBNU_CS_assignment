///**************************************************************************************/
///*                  HW#5 : 계층적 모델링, 시점변환  - 로봇팔 응용                     */
///*                작성자 : 신주영               날짜 : 2020년 11월 10일               */
///*                                                                                    */
///* 문제 정의 : 1,2,3 번 키를 누르면 각각 1,2,3번 손가락을 접었다 펼쳤다를 반복한다.   */
///*             마우스 콜백을 이용하여 왼쪽버튼 클릭 시, 어깨, 팔꿈치, 손가락이 180도  */
///*             이내로 회전하고, 오른쪽 클릭 시, 제자리로 돌아옴.                      */
///**************************************************************************************/
//
//#include <GL/glut.h>
//#include<stdlib.h>
//static int shoulder = 0, elbow = 0, finger1 = 0, finger2 = 0, finger3 = 0;
//int n;
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(1.0, 1.0, 1.0);
//	glPushMatrix();
//
//	glTranslatef(-1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
//	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(1.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	glTranslatef(1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
//	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(1.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	glTranslatef(1.5, 0.25, 0.0); // Pivot 지정 및 객체 이동    //손가락1-1
//	glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 이동    //손가락1-2
//	glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.0, -0.25, 0.0); // Pivot 지정 및 객체 이동    //손가락2-1
//	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(-0.5, -0.0, 0.0); // Pivot 지정 및 객체 이동    //손가락2-2
//	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//
//	glTranslatef(0.0, -0.25, 0.0); // Pivot 지정 및 객체 이동     //손가락3-1
//	glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.5, -0.0, 0.0); // Pivot 지정 및 객체 이동     //손가락3-2
//	glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
//	glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
//	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glPopMatrix();
//	glPopMatrix();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//void MyInit(void) {
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glShadeModel(GL_FLAT);
//}
//
//void MyReshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, -5.0);
//}
//
//void MyTimer()
//{
//	if (n == 1) {
//		finger1 = (finger1 - 1) % 360;
//
//		if (finger1 < -90) {
//			finger1 = (finger1 + 1) % 360;
//		}
//	}
//	else if (n == 2) {
//		finger2 = (finger2 - 1) % 180;
//
//		if (finger1 < -90) {
//			finger2 = (finger2 + 1) % 180;
//		}
//	}
//	else if (n == 3) {
//		finger3 = (finger3 - 1) % 180;
//
//		if (finger1 < -90) {
//			finger3 = (finger3 + 1) % 180;
//		}
//	}
//	else if (n == 4) {
//		if (shoulder <= 170 || elbow <= 170 ) {
//			shoulder = (shoulder + 1) % 180;
//			elbow = (elbow + 1) % 180;
//			finger1 = (finger1 + 1) % 180;
//			finger2 = (finger2 + 1) % 180;
//			finger3 = (finger3 + 1) % 180;
//		}
//		else {
//			shoulder = shoulder + 0;
//			elbow = elbow + 0;
//			finger1 = finger1 + 0;
//			finger2 = finger2 + 0;
//			finger3 = finger3 + 0;
//		}
//	}
//	else if (n == 5) {
//			shoulder = (shoulder - 1) % 180;
//			elbow = (elbow - 1) % 180;
//			finger1 = (finger1 - 1) % 180;
//			finger2 = (finger2 - 1) % 180;
//			finger3 = (finger3 - 1) % 180;
//
//			if (shoulder <= 1) {
//				shoulder = 0;
//				elbow = 0;
//				finger1 = 0;
//				finger2 = 0;
//				finger3 = 0;
//			}
//	}
//
//	glutPostRedisplay(); //디스플레이 함수 호출
//	glutTimerFunc(10, MyTimer, 1); //인위적으로 넣어줘야함
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) 
//{
//	switch (Button) {
//		case GLUT_LEFT_BUTTON :
//			if (State == GLUT_DOWN) {
//				n = 4;
//				glutTimerFunc(10, MyTimer, 1);
//			}
//			break;
//		case GLUT_RIGHT_BUTTON:
//			if (State == GLUT_DOWN) {
//				n = 5;
//				glutTimerFunc(10, MyTimer, 1);
//			}
//			break;
//		default:
//			break;
//	}
//}
//
//void MyKeyboard(unsigned char key, int x, int y) {
//	switch (key) {
//	case 's':
//		shoulder = (shoulder + 5) % 360;
//		break;
//	case 'S':
//		shoulder = (shoulder - 5) % 360;
//		break;
//	case 'e':
//		elbow = (elbow + 5) % 360;
//		break;
//	case 'E':
//		elbow = (elbow - 5) % 360;
//		break;
//
//	case '1':
//		n = 1;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case '2':
//		n = 2;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//	case '3':
//		n = 3;
//		glutTimerFunc(10, MyTimer, 1);
//		break;
//
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Robot Arm");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(MyReshape);
//	glutKeyboardFunc(MyKeyboard);
//	glutMouseFunc(MyMouseClick);
//	glutMainLoop();
//	return 0;
//}