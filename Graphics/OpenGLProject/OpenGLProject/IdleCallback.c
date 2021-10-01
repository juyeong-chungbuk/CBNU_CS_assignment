///*************************************************************/
///*       HW#4 : Callback ���α׷���  - Idle Callback(1)      */
///*      �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��     */
///*                                                           */
///* ���� ���� : UPŰ ���� ��, ��ǥ�� �������� 0.1�� �̵�      */
///*             DOWNŰ ���� ��, ��ǥ�� �Ʒ������� 0.1�� �̵�  */
///*             LEFTŰ ���� ��, ��ǥ�� �������� 0.1�� �̵�    */
///*             RIGHTŰ ���� ��, ��ǥ�� ���������� 0.1�� �̵� */
///*    -> Idel Callback�Լ��� �̿��Ͽ� �� Ű�� �������� ȣ��  */
///*************************************************************/
//
//#include<GL/glut.h>
//
//GLfloat vertex[4][3] = { {-0.5,-0.5,0.0},{0.5,-0.5,0.0},{0.5,0.5,0.0},{-0.5,0.5,0.0} }; //������ ���ü
//GLfloat Delta = 0.0; //������Ų ����
//int n = 0; //���� Ű ������ ����
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.5, 0.8);
//
//	if (n == 1) { //����
//
//		if (vertex[3][1]+Delta <= 1.0) { //������ ȭ�� �ȿ�����
//			glVertex3f(vertex[0][0], vertex[0][1] + Delta, vertex[0][2]);
//			glVertex3f(vertex[1][0], vertex[1][1] + Delta, vertex[1][2]);
//			glVertex3f(vertex[2][0], vertex[2][1] + Delta, vertex[2][2]);
//			glVertex3f(vertex[3][0], vertex[3][1] + Delta, vertex[3][2]); //y��ǥ ����
//		}
//
//		else { //������ ������ �ʵ��� ����
//		glVertex3f(vertex[0][0], 0.0 , vertex[0][2]);
//		glVertex3f(vertex[1][0], 0.0 , vertex[1][2]);
//		glVertex3f(vertex[2][0], 1.0 , vertex[2][2]);
//		glVertex3f(vertex[3][0], 1.0 , vertex[3][2]);
//		}
//
//	}
//
//	else if (n == 2){ //�Ʒ���
//
//		if (vertex[0][1]-Delta >= -1.0) {//������ ȭ�� �ȿ�����
//			glVertex3f(vertex[0][0], vertex[0][1] - Delta, vertex[0][2]);
//			glVertex3f(vertex[1][0], vertex[1][1] - Delta, vertex[1][2]);
//			glVertex3f(vertex[2][0], vertex[2][1] - Delta, vertex[2][2]);
//			glVertex3f(vertex[3][0], vertex[3][1] - Delta, vertex[3][2]); //y��ǥ ����
//		}
//		else {//������ ������ �ʵ��� ����
//			glVertex3f(vertex[0][0], -1.0, vertex[0][2]);
//			glVertex3f(vertex[1][0], -1.0, vertex[1][2]);
//			glVertex3f(vertex[2][0], 0.0, vertex[2][2]);
//			glVertex3f(vertex[3][0], 0.0, vertex[3][2]);
//		}
//
//	}
//
//	else if (n == 3) { //����
//
//		if (vertex[0][0] - Delta >= -1.0) {//������ ȭ�� �ȿ�����
//			glVertex3f(vertex[0][0] - Delta, vertex[0][1], vertex[0][2]);
//			glVertex3f(vertex[1][0] - Delta, vertex[1][1], vertex[1][2]);
//			glVertex3f(vertex[2][0] - Delta, vertex[2][1], vertex[2][2]);
//			glVertex3f(vertex[3][0] - Delta, vertex[3][1], vertex[3][2]); //x��ǥ ����
//		}
//
//		else {//������ ������ �ʵ��� ����
//			glVertex3f(-1.0, vertex[0][1], vertex[0][2]);
//			glVertex3f(0.0, vertex[1][1], vertex[1][2]);
//			glVertex3f(0.0, vertex[2][1], vertex[2][2]);
//			glVertex3f(-1.0, vertex[3][1], vertex[3][2]);
//		}
//
//	}
//
//	else { //������
//
//		if (vertex[1][0] + Delta <= 1.0) {//������ ȭ�� �ȿ�����
//			glVertex3f(vertex[0][0] + Delta, vertex[0][1], vertex[0][2]);
//			glVertex3f(vertex[1][0] + Delta, vertex[1][1], vertex[1][2]);
//			glVertex3f(vertex[2][0] + Delta, vertex[2][1], vertex[2][2]);
//			glVertex3f(vertex[3][0] + Delta, vertex[3][1], vertex[3][2]); //x��ǥ ����
//		}
//
//		else {//������ ������ �ʵ��� ����
//			glVertex3f(0.0, vertex[0][1], vertex[0][2]);
//			glVertex3f(1.0, vertex[1][1], vertex[1][2]);
//			glVertex3f(1.0, vertex[2][1], vertex[2][2]);
//			glVertex3f(0.0, vertex[3][1], vertex[3][2]);
//		}
//
//	}
//
//	glEnd();
//	glutSwapBuffers();
//}
//
//void MyIdle() {
//
//	if (n == 1 || n == 2 || n == 3 || n == 4) //�� Ű�� ��������
//		Delta = Delta + 0.001; //0.001�� ����
//
//	glutPostRedisplay(); //���÷��� �Լ� ȣ��
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0); //��� ���
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //���ú��� ����
//}
//
//void MySpecial(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_UP:
//		glutIdleFunc(MyIdle);  Delta = 0.0; break; //�� Ű�� �� ���� �� ��, Delta�ʱ�ȭ
//	case GLUT_KEY_DOWN:
//		n = 2; glutIdleFunc(MyIdle);  Delta = 0.0; break;
//	case GLUT_KEY_LEFT:
//		n = 3; glutIdleFunc(MyIdle); Delta = 0.0; break;
//	case GLUT_KEY_RIGHT:
//		n = 4; glutIdleFunc(MyIdle); Delta = 0.0; break;
//	}
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //�������
//	glutInitWindowSize(300, 300); //������ âũ��
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Idle Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
//	glutSpecialFunc(MySpecial); //�����Ű �Լ� ���
//	glutIdleFunc(MyIdle); //Idel�Լ� ���
//	glutMainLoop();
//	return 0;
//}