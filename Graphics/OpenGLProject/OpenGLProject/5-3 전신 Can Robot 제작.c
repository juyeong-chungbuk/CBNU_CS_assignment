///*******************************************************************************************/
///*                    HW#5 : ������ �𵨸�, ������ȯ  - ���� Can Robot ����                */
///*                  �ۼ��� : ���ֿ�               ��¥ : 2020�� 11�� 10��                  */
///*                                                                                         */
///* ���� ���� : �Ӹ�, ����, ������, �ٸ�, ���� �Լ��� ���� �����Ͽ� DrawAndriod�Լ� �ȿ���  */
///*             ȣ���Ͽ� �ʱ� ���� �ڼ��� �����, ���콺 ������ ��ư Ŭ���� ��������        */
///*             �����̴� ����� �׷ȴ�.                                                     */
///*******************************************************************************************/
//
//#include <windows.h>
//#include <stdlib.h>
//#include <MMSystem.h>
//#include <GL/glut.h>
//#include <math.h>
//
//static double time = 0;  // Run_time ����
//int move = 0;
//
//GLfloat R_Arm_x = 0; // ������ ���
//GLfloat R_Arm_y = 0; // ������ ��
//GLfloat L_Arm_x = 0; // ���� ���
//GLfloat L_Arm_y = 0; // ���� ��
//GLfloat R_Leg_x = 0; // ���� �����
//GLfloat R_Leg_y = 0; // ���� ���Ƹ�
//GLfloat L_Leg_x = 0; // �� �����
//GLfloat L_Leg_y = 0; // �� ���Ƹ�
//GLfloat R = 0; // ���� ���� ��ġ ������ ����
//GLfloat R2 = 0;// ������ ���� ��ġ ������ ����
//
//GLUquadricObj* cyl;// �Ǹ��� ��ü ����
//
//static int flag = 0; // wireframe ���� solid rendering ��� ���� ����
//static int key = 0;  // ���� ���� ���� ���� ����
//
//#define RUN		1						
//#define YUNA	4	
//#define EXIT	6	
//
//void glInit(void) { // ���� �ʱ�ȭ �Լ� 
//	glEnable(GL_DEPTH_TEST); // ���� �׽��� ���
//	glEnable(GL_NORMALIZE);  // ����ȭ
//	glEnable(GL_SMOOTH);     // �� ������ ������ �ε巴�� �����Ͽ� ĥ��������  �ϹǷ�, �������� ����� ������ ȥ�յǾ� ����ȴ�. 
//	glEnable(GL_LIGHTING);   // ���� ����. ���� �޴� ������ ���� �κ� ������ ��ȭ
//
//	/* ���� �޴� ������ ���� �κ� ������ ��ȭ�� ���� ���� */
//	GLfloat ambientLight[] = { 0.3f,0.3f,0.3f,1.0f };
//	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
//	GLfloat specular[] = { 1.0f,1.0f,1.0f,1.0f };
//	GLfloat specref[] = { 1.0f,1.0f,1.0f,1.0f };
//	GLfloat position[] = { 400.0,300.0,-700.0,1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glMateriali(GL_FRONT, GL_SHININESS, 128);
//
//	glClearColor(0.0, 1.0, 1.0, 1.0); // ��� ������
//	glMatrixMode(GL_PROJECTION);   // ��� ����
//	glLoadIdentity();              // CTM �� �ʱ�ȭ 
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // ���� ���� ����
//}
//
//void Draw_Color(int i) { // ������ �׸��� �Լ�
//		glColor3f(1.0, 1.0, 0.0);
//}
//
//void Change_Wire_Or_Solid(int i) {          // �ָ���, ���̾� ����
//	if (flag == 1)
//		gluQuadricDrawStyle(cyl, GLU_LINE); // ��Ÿ���� ���̾�� ����
//}
///*
//�κ� ������ �׸��� �Լ�
//*/
//
//void DrawL_Arm(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);     // �� ����
//	cyl = gluNewQuadric();   // �Ǹ��� ��ü ����
//	glRotatef(x, a, b, c);  // �Ķ���� ����ŭ ȸ��
//	glRotatef(90.0, 1.0, 0.0, 0.0); // �Ǹ����� x�� �������� 90�� ȸ��(�Ǹ��� ���� �� ���� ������ ����)
//	glTranslatef(0.25, 0.0, 0.0);    // ���� ��� ���������� �̵�
//	glRotatef(15.0, 0.0, 1.0, 0.0); // ���� ����� y���� �������� 15�� ȸ��
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1); // �Ǹ����� �׸�
//}
//
///*
//�κ� ���� ���� �׸��� �Լ�
//*/
//void DrawL_Hand(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);       // �� ����
//	cyl = gluNewQuadric();   // �Ǹ��� ��ü ����
//	glTranslatef(0.0, 0.0, 0.22); // �޼� ������
//	glRotatef(y, a, b, c);        // �Ķ���� ����ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.02, 0.2, 15, 1); // �򶧱� ��� �Ǹ����� �׸�
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);           // �Ǹ����� �׸�
//	glPopMatrix();
//}
///*
//�κ� ���� �ָ�
//*/
//void DrawL_HandRocket() {
//	glPushMatrix();
//	Draw_Color(key);     // �� ����
//	cyl = gluNewQuadric(); // �Ǹ��� ��ü ����
//	glTranslatef(0, 0, R); // ���� �ָ� ��ġ�� �Ķ���͸�ŭ �̵�
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1); // �Ǹ����� �׸�
//	glPopMatrix();
//}
///*
//�κ� �������� �׸��� �Լ�
//*/
//void DrawR_Arm(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);     // �� ����
//	cyl = gluNewQuadric(); // �Ǹ��� ��ü ����
//	glRotatef(x, a, b, c);  // �Ķ���� ����ŭ ȸ��
//	glRotatef(90.0, 1.0, 0.0, 0.0); // �Ǹ����� x���� �������� 90�� ȸ��(�Ǹ��� ���� �� ���� ������ ����)
//	glTranslatef(-0.25, 0.0, 0.0); //���� ��� ���������� �̵�
//	glRotatef(-15.0, 0.0, 1.0, 0.0); //���� ��� -15�� y����� ȸ��
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// �Ǹ��� �׸�
//
//}
///*
//�κ� ������ ���� �׸��� �Լ�
//*/
//void DrawR_Hand(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key); // �� ����
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glTranslatef(0.0, 0.0, 0.22);//������ �� ������
//	glRotatef(y, a, b, c);// �Ķ���Ͱ� ��ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.02, 0.2, 50, 1);// �򶧱� ��� �Ǹ��� �׸�
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
//
///*
//�κ� ������ ����Ʈ �Լ�
//*/
//
//void DrawR_HandRocket() {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric(); //�Ǹ��� ��ü ����
//	glTranslatef(0, 0, R2);//�����ָ� ��ġ �Ķ���͸�ŭ �̵�
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
///*
//�κ� ��ü�� �׸��� �Լ�
//*/
//void DrawBody(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glRotatef(x, a, b, c);//�Ķ���Ͱ� ��ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.2, 0.2, 0.45, 50, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
///*
//�κ� ���� ������� �׸��� �Լ�
//*/
//void DrawL_Legs(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glTranslatef(0.1, 0.0, 0.42);//���� ����� ������
//	glRotatef(x, a, b, c);//�Ķ���͸�ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);// �Ǹ��� �׸�
//
//}
///*
//�κ� ���� ���Ƹ��� �׸��� �Լ�
//*/
//void DrawL_foot(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glTranslatef(0.0, 0.0, 0.18);//���� ���Ƹ� ������
//	glRotatef(y, a, b, c);//�Ķ���͸�ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.03, 0.2, 50, 1);// �򶧱� ��� �Ǹ��� �׸�
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
///*
//�κ� ������ ������� �׸��� �Լ�
//*/
//void DrawR_Legs(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glTranslatef(-0.1, 0.0, 0.42);//������ ����� ������
//	glRotatef(x, a, b, c);//�Ķ���͸�ŭ ȸ��
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);// �Ǹ��� �׸�
//
//}
///*
//�κ� ������ ���Ƹ��� �׸��� �Լ�
//*/
//void DrawR_foot(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//
//	glTranslatef(0.0, 0.0, 0.18);//������ ���Ƹ� ������
//	glRotatef(y, a, b, c);//�Ķ���͸�ŭ ȸ��
//
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.03, 0.2, 15, 1);// �򶧱� ��� �Ǹ��� �׸�
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
///*
//�κ� ���� �׸��� �Լ�
//*/
//void Drawneck() {
//	glPushMatrix();
//	glColor3f(1.0, 1.0, 1.0);//�� ����(���)
//	cyl = gluNewQuadric();//�Ǹ��� ��ü ����
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glTranslatef(0.0, 0.0, -0.045); // �� ������
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.2, 0.2, 0.025, 100, 1);// �Ǹ��� �׸�
//	glPopMatrix();
//}
//
///*
//�κ� �Ӹ��� �׸��� �Լ�
//�κ��� �Ӹ��� �޷��ִ� �԰�
//�κ��� ���� �����Ͽ���.
//*/
//void DrawHead() {
//	glTranslatef(0.0, 0.02, 0.0);//�Ӹ� ������
//	glPushMatrix();// ó�� ���� ��ǥ �ٽ� ����
//	cyl = gluNewQuadric();
//	Change_Wire_Or_Solid(flag);
//	Draw_Color(key);//���� ����
//	gluSphere(cyl, 0.20, 30, 10);//�Ӹ� �׸���
//	/*���� �� �׸���*/
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glTranslatef(-0.16, 0.0, -0.22);//���� �� ������
//	glRotatef(35.0, 0.0, 1.0, 0.0);//35�� y�� ���� ȸ��
//	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);//�Ǹ��� �׸�
//	glPopMatrix(); // ó�� ���� ��ǥ�� ���� ����.
//	glPushMatrix();// ó�� ���� ��ǥ �ٽ� ����
//
//	/*������ �� �׸���*/
//	glRotatef(90.0, 1.0, 0.0, 0.0);//�Ǹ��� 90�� x����� ȸ�� (�Ǹ��� ������ ���� ������ ���Ͽ�)
//	glTranslatef(0.16, 0.0, -0.22);//������ �� ������
//	glRotatef(-35.0, 0.0, 1.0, 0.0);//-35�� y�� ���� ȸ��
//	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);//�Ǹ��� �׸�
//	glPopMatrix(); // ó�� ���� ��ǥ�� ���� ����.	
//	glPushMatrix();// ó�� ���� ��ǥ �ٽ� ����
//
//	/*���� �� �׸���*/
//	glTranslatef(-0.1, 0.1, 0.13);//���� �� ������
//	glColor3f(0.0, 0.0, 0.0);// �� �÷� ����(���)
//	gluSphere(cyl, 0.03, 10, 10);
//
//	glPopMatrix(); // ó�� ���� ��ǥ�� ���� ����.
//	glPushMatrix();// ó�� ���� ��ǥ �ٽ� ����
//
//	/*������ �� �׸���*/
//	glTranslatef(0.1, 0.1, 0.13);//������ �� ������
//	gluSphere(cyl, 0.03, 10, 10);
//	glPopMatrix();// ó�� ���� ��ǥ �ٽ� ����
//}
//
///*
//�ȵ���̵� ��ü ����� �׸��� �Լ�
//*/
//void DrawAndroid() {
//
//
//	cyl = gluNewQuadric(); //�Ǹ��� ��ü ����
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�ʱ�ȭ
//	glMatrixMode(GL_MODELVIEW); //��� ����
//
//	glLoadIdentity();//CTM �ʱ�ȭ
//
//
//	DrawBody(0, 0, 0, 0); // ���� �Լ� ȣ��
//	Drawneck(); // ���Լ� ȣ��
//	DrawHead(); // �Ӹ� ȣ��
//	DrawR_Arm(R_Arm_x, 1, 0, 0);//�����ȶ�
//	DrawR_Hand(R_Arm_y, 1, 0, 0);  //������ȣ��
//	DrawL_Arm(L_Arm_x, 1, 0, 0);   //�����ȶ�
//	DrawL_Hand(L_Arm_y, 1, 0, 0);//������ȣ��
//	DrawL_Legs(L_Leg_x, 1, 0, 0);  //�����ٸ�
//	DrawL_foot(L_Leg_y, 1, 0, 0);  //������		 
//	DrawR_Legs(R_Leg_x, 1, 0, 0);  //�����ٸ�
//	DrawR_foot(R_Leg_y, 1, 0, 0);  //������	
//}
//
///*
//Ÿ�̸� �Լ�
//�� ��鸶�� ���� ǥ���� �ٸ��� �α� ���� ����� �ð� �������� ������.
//*/
//void MyTimer(int Value) {
//	if (move == 1)
//		time = time + 0.1;//�޸��� ���� Ÿ�̸� ����
//
//	else
//		time = time + 0.0;
//	glutPostRedisplay();
//	glutTimerFunc(40, MyTimer, 1);
//}
//
//
///*
//�κ��� �޸��� ���� ǥ���� �Լ�.
//�κ��� ������ �����̴� ���� ǥ���߰�,
//�κ��� �޸��鼭 ��,��,��,��� �����̴� ����� ǥ���ߴ�.
//*/
//void Run() {
//	sndPlaySound(TEXT("C:\\sample1.wav"), SND_ASYNC | SND_NOSTOP);
//	glLoadIdentity();//CTM �ʱ�ȭ
//					 
//					 
//	////////////////display////////////////
//
//	cyl = gluNewQuadric(); //�Ǹ��� ��ü ����
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�ʱ�ȭ
//	glMatrixMode(GL_MODELVIEW); //��� ����
//	glLoadIdentity();//CTM �ʱ�ȭ
//	DrawAndroid();
//
//	if (move == 1) {
//		L_Arm_x = sin(time) * 80;
//	}
//	move = 2;
//	glutTimerFunc(40, MyTimer, 1); //Ÿ�̸� �Լ�
//
//	glTranslatef(0.0, 0.5, 0.0);//���� �κ��� ��ġ 
//	DrawAndroid();
//	glutSwapBuffers();
//}
//
//void MyMouse(GLint Button, GLint State, GLint X, GLint Y)
//{
//	switch (Button) {
//	case GLUT_RIGHT_BUTTON:
//		move = 1;
//		break;
//	default:
//		break;
//	}
//}
//
//
///*
//Ű���� �ݹ� ���� �Լ�
//w�� ������ wire ����, s�� ������ solid ����, q�� ������ ���Ḧ ǥ��
//*/
//void MyKeyboard(unsigned char KeyPressed, int x, int y) {
//	switch (KeyPressed) {
//	case 'q':
//		key = 6;
//		break;
//	}
//}
//
//void MyDisplay() {		
//	Run();
//	glPopMatrix();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);//�ʱ�ȭ
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//���÷��� ��� ����
//	glutInitWindowSize(800, 800);//������ ũ�� ����
//	glutInitWindowPosition(0, 0);//������ �ʱ� ��ġ ����
//	glutCreateWindow("���� Can Robot ����");//������ ����
//	glInit(); // ���� �ʱ�ȭ
//
//	glutMouseFunc(MyMouse);
//	glutKeyboardFunc(MyKeyboard); //Ű���� �ݹ�
//	glutDisplayFunc(MyDisplay); //���÷���
//
//	glutMainLoop();
//	return 0;
//}