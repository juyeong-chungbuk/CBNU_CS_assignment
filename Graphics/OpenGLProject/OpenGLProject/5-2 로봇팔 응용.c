///**************************************************************************************/
///*                  HW#5 : ������ �𵨸�, ������ȯ  - �κ��� ����                     */
///*                �ۼ��� : ���ֿ�               ��¥ : 2020�� 11�� 10��               */
///*                                                                                    */
///* ���� ���� : 1,2,3 �� Ű�� ������ ���� 1,2,3�� �հ����� ������ ���ƴٸ� �ݺ��Ѵ�.   */
///*             ���콺 �ݹ��� �̿��Ͽ� ���ʹ�ư Ŭ�� ��, ���, �Ȳ�ġ, �հ����� 180��  */
///*             �̳��� ȸ���ϰ�, ������ Ŭ�� ��, ���ڸ��� ���ƿ�.                      */
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
//	glTranslatef(-1.0, 0.0, 0.0); // Pivot ���� �� ��ü �̵�
//	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(1.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	glTranslatef(1.0, 0.0, 0.0); // Pivot ���� �� ��ü �̵�
//	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(1.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	glTranslatef(1.5, 0.25, 0.0); // Pivot ���� �� ��ü �̵�    //�հ���1-1
//	glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.5, 0.0, 0.0); // Pivot ���� �� ��ü �̵�    //�հ���1-2
//	glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.0, -0.25, 0.0); // Pivot ���� �� ��ü �̵�    //�հ���2-1
//	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(-0.5, -0.0, 0.0); // Pivot ���� �� ��ü �̵�    //�հ���2-2
//	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//
//	glTranslatef(0.0, -0.25, 0.0); // Pivot ���� �� ��ü �̵�     //�հ���3-1
//	glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(0.2);
//	glPopMatrix();
//
//	glTranslatef(0.5, -0.0, 0.0); // Pivot ���� �� ��ü �̵�     //�հ���3-2
//	glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
//	glTranslatef(0.0, 0.0, 0.0); // Pivot���� ������ ��ġ�� �������� �̵�
//	glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
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
//	glutPostRedisplay(); //���÷��� �Լ� ȣ��
//	glutTimerFunc(10, MyTimer, 1); //���������� �־������
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