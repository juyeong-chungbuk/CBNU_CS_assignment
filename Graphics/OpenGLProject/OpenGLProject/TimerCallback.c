///*************************************************************/
///*       HW#4 : Callback ���α׷���  - Ÿ�̸��ݹ�(1)         */
///*      �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��     */
///*                                                           */
///* ���� ���� : Ÿ�̹� �ݹ� �Լ��� �̿��Ͽ� ���簢���� ������ */
///*        ���� �̵� ��Ŵ�� ���ÿ� 15���� �������� ��ȭ��Ų��.*/
///*                                                           */
///*************************************************************/
//
//#include <GL/glut.h>
//GLfloat Delta = 0.0; //��������
//int n; //�� 15���� ����
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//
//	switch (n) {
//	case 0:
//		glColor3f(0.0, 0.0, 0.0); 
//		break;
//	case 1:
//		glColor3f(0.2, 0.2, 0.0);
//		break;
//	case 2:
//		glColor3f(0.5 , 0.2, 0.0);
//		break;
//	case 3:
//		glColor3f(0.7, 0.5, 0.0);
//		break;
//	case 4:
//		glColor3f(1.0, 0.0, 0.0);
//		break;
//	case 5:
//		glColor3f(0.0, 1.0, 0.0);
//		break;
//	case 6:
//		glColor3f(0.0, 0.0, 1.0);
//		break;
//	case 7:
//		glColor3f(0.0, 0.2, 0.3);
//		break;
//	case 8:
//		glColor3f(0.3, 0.0, 1.0);
//		break;
//	case 9:
//		glColor3f(0.8, 0.2, 0.6);
//		break;
//	case 10:
//		glColor3f(0.0,0.5, 1.0);
//		break;
//	case 11:
//		glColor3f(0.2, 0.8, 0.5);
//		break;
//	case 12:
//		glColor3f(0.5,0.8, 0.5);
//		break;
//	case 13:
//		glColor3f(1.0, 0.0, 1.0);
//		break;
//	case 14:
//		glColor3f(1.0, 1.0, 0.0);
//		break;
//	case 15:
//		glColor3f(1.0, 1.0, 1.0);
//		break;
//	} //�� 15���� ������� ���� ���� .....
//
//	glVertex3f(-1.0 + Delta, -0.5, 0.0);
//	glVertex3f(0.0 + Delta, -0.5, 0.0);
//	glVertex3f(0.0 + Delta, 0.5, 0.0);
//	glVertex3f(-1.0 + Delta, 0.5, 0.0); //���������� �̵�
//
//	glEnd();
//	glutSwapBuffers();
//}
//
//void MyTimer(int Value) {
//	Delta = Delta + 0.005; //0.005�� ����
//
//	if (n < 16) //15���� ��
//		n++;
//	else
//		n = 0;
//
//	glutPostRedisplay(); //���÷��� �Լ� ȣ��
//	glutTimerFunc(10, MyTimer, 1); //���������� �־������
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0); //��� ���
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //���ú��� ����
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Idle Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
//	glutTimerFunc(10, MyTimer, 1); //Ÿ�̸� �ݹ� ���
//	glutMainLoop();
//	return 0;
//}