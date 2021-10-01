///**************************************************************************/
///*              HW#4 : Callback ���α׷���  - ���콺�ݹ�(1)               */
///*           �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��             */
///*                                                                        */
///* ���� ���� : ���콺�ݹ��Լ��� �̿��Ͽ� ��Ŭ�� ��, ���������� �����̵�,  */
///*             ��Ŭ�� ��, ���� �����ϰ�, ������ ȭ�� ����� ���� ����   */
///**************************************************************************/ 
//
//
//#include <GL/glut.h>
//
//GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY; //�����ʿ��� �ؿ��������� ���ϱ�
//GLfloat vertex[4][3] = { {0.0,0.0,0.0},{0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0} }; //�ʱ�ȭ
//int count = 0; //ó�� ���� ���� �ι�° ���� �� ����
//GLfloat Delta = 0.0; //��������
//
//void MyDisplay() {
//	glViewport(0, 0, 500, 500);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.5, 0.5);
//	glBegin(GL_POLYGON);
//
//	vertex[0][0] = TopLeftX / 500.0; //����
//	vertex[0][1] = (500 - TopLeftY) / 500.0;
//	vertex[0][2] = 0.0;
//
//	vertex[1][0] = TopLeftX / 500.0; //�޾Ʒ�
//	vertex[1][1] = (500 - BottomRightY) / 500.0;
//	vertex[1][2] = 0.0;
//
//	vertex[2][0] = BottomRightX / 500.0; //���Ʒ�
//	vertex[2][1] = (500 - BottomRightY) / 500.0;
//	vertex[2][2] = 0.0;
//
//	vertex[3][0] = BottomRightX / 500.0; //����
//	vertex[3][1] = (500 - TopLeftY) / 500.0;
//	vertex[3][2] = 0.0;
//
//
//	glVertex3f(vertex[0][0] + Delta, vertex[0][1], vertex[0][2]);
//	glVertex3f(vertex[1][0] + Delta, vertex[1][1], vertex[1][2]);
//	glVertex3f(vertex[2][0] + Delta, vertex[2][1], vertex[2][2]);
//	glVertex3f(vertex[3][0] + Delta, vertex[3][1], vertex[3][2]); //x������Ű�鼭 ���
//
//	glEnd();
//	glFlush();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//
//	switch (Button) {
//	case GLUT_LEFT_BUTTON:
//		if (State == GLUT_DOWN&&count==0) { //ó�� ���� ���� ��
//			TopLeftX = X;
//			TopLeftY = Y;
//			count = 1;
//		}
//		else if(State == GLUT_DOWN && count == 1){ //�ι�° ��Ŭ��
//			while (1) {
//				
//				if (vertex[3][0] + Delta <= 1.0) { //������ �ȿ�����
//					Delta += 0.1; //0.1�� ����
//					TopLeftX += Delta;
//					BottomRightX += Delta; //x��ǥ ����
//					glutPostRedisplay();
//				}
//				else
//					break;
//
//			}
//			
//		}
//		break;
//
//	case GLUT_RIGHT_BUTTON: //��Ŭ��
//		if (State == GLUT_DOWN) {
//			Delta += 0.0; //�׸� ����.
//			TopLeftX += Delta;
//			glutPostRedisplay();
//		}
//		break;
//	}
//
//}
//
//void MyMouseMove(GLint X, GLint Y) { //���콺 ������ ��ġ
//
//	BottomRightX = X;
//	BottomRightY = Y;
//
//	glutPostRedisplay();
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Mouse Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutMouseFunc(MyMouseClick); //���콺Ŭ�� �Լ� ���
//	glutMotionFunc(MyMouseMove); //���콺�̵� �Լ� ���
//
//	glutMainLoop();
//	return 0;
//}