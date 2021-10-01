///******************************************************************************/
///*                 HW#4 : Callback ���α׷���  - �޴��ݹ�(1)                  */
///*              �ۼ��� : ���ֿ�          ��¥ : 2020�� 10�� 16��              */
///*                                                                            */
///* ���� ���� : 5���� �޴��� �� �����޴��� small, large�� �����Ͽ�             */
///*             �� ������ ũ�⸦ �����ϰ� ����޴��� ���� ������ ���� �����Ѵ�.*/
///******************************************************************************/ 
//
//
//#include <GL/glut.h>
//#include <stdlib.h>
//GLboolean IsSphere = TRUE; //sphere�޴�
//GLboolean IsSmallsphere; //shpere�� �����޴�
//
//GLboolean IsTorus; //torus�޴�
//GLboolean IsSmallTorus; //torus�� �����޴�
//
//GLboolean IsTeapot; //teapot�޴�
//GLboolean IsSmallTeapot; //teapot�� �����޴�
//
//GLboolean IsChangeColor; //color�޴�
//GLint color; //color�� �����޴�
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.5, 0.5);
//
//	if (IsSphere && IsSmallsphere) { //shpere->small����
//		
//		if(IsChangeColor &&color==1) //red����
//		glColor3f(1.0, 0.0, 0.0);
//		else if(IsChangeColor &&color==2) //green����
//			glColor3f(0.0, 1.0, 0.0);
//		else if(IsChangeColor &&color==3) //blue����
//			glColor3f(0.0, 0.0, 1.0);
//		glutWireSphere(0.3, 30, 30);	//smallshpere����
//	}
//	else if (IsSphere && !IsSmallsphere) { //shpere->large����
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireSphere(0.5, 40, 20); //largeshpere����
//	}
//
//	if (IsSmallTorus && IsTorus) { //torus->small����
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireTorus(0.1, 0.3, 30, 30); //smalltorus����
//	}
//	else if (!IsSmallTorus && IsTorus) { //torus->large����
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireTorus(0.2, 0.5, 40, 20); //largetorus����
//	}
//
//	if (IsTeapot && IsSmallTeapot) { //teapot->small����
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//		
//		glutWireTeapot(0.1); //smallteapot����
//	}
//
//	else if (IsTeapot && !IsSmallTeapot) { //teapot->large����
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//		
//		glutWireTeapot(0.5); //largeteapot����
//	}
//
//	glFlush();
//}
//
//void MyMainMenu(int entryID) {
//	if (entryID == 5)exit(0); //����޴�
//	glutPostRedisplay();
//}
//
//
//void MySphereMenu(int entryID)
//{
//	IsTorus = FALSE;
//	IsTeapot = FALSE; //shpere�ܿ��� false��
//
//	IsSphere = TRUE;
//	if (entryID == 1)IsSmallsphere = TRUE; //small
//	else if (entryID == 2)IsSmallsphere = FALSE; //large
//	glutPostRedisplay();
//}
//
//
//void MyTorusMenu(int entryID)
//{
//	IsSphere = FALSE;
//	IsTeapot = FALSE; //torus�ܿ��� false��
//
//	IsTorus = TRUE;
//	if (entryID == 1)IsSmallTorus = TRUE; //small
//	else if (entryID == 2)IsSmallTorus = FALSE; //large
//	glutPostRedisplay();
//}
//
//void MyTeapotMenu(int entryID)
//{
//	IsSphere = FALSE;
//	IsTorus = FALSE; //teapot�ܿ��� false��
//
//	IsTeapot = TRUE;
//	if (entryID == 1)IsSmallTeapot = TRUE; //small
//	else if (entryID == 2)IsSmallTeapot = FALSE; //large
//	glutPostRedisplay();
//}
//
//void MychangecoloreMenu(int entryID) //�÷��޴� ����
//{
//	IsChangeColor = TRUE; 
//	if (entryID == 1)color = 1; //red
//	else if (entryID == 2)color = 2; //green
//	else if (entryID == 3)color = 3; //blue
//	glutPostRedisplay();
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//
//	GLint Mysphere = glutCreateMenu(MySphereMenu); //shpere�����޴� ����
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint Mytorus = glutCreateMenu(MyTorusMenu); //torus���� �޴� ����
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint Myteapot = glutCreateMenu(MyTeapotMenu); //teapot�����޴� ����
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint MyChangeColor = glutCreateMenu(MychangecoloreMenu); //color�����޴� ����
//	glutAddMenuEntry("Red", 1);
//	glutAddMenuEntry("Green", 2);//	glutAddMenuEntry("Blue", 3);//
//
//	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //�޴� ����
//	glutAddSubMenu("Draw Sphere", Mysphere);
//	glutAddSubMenu("Draw Torus", Mytorus);
//	glutAddSubMenu("Draw Teapot", Myteapot);
//	glutAddSubMenu("Change Color", MyChangeColor);
//	glutAddMenuEntry("Exit", 5);
//	glutAttachMenu(GLUT_RIGHT_BUTTON); //������ ���콺��ư Ŭ�� ��
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Menu Callback");
//	MyInit(); //�޴� �־���
//	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
//	glutMainLoop();
//	return 0;
//}