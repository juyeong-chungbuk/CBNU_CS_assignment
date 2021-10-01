///**********************************************************************************************/
///*                              HW#7 : 뷰폿변환  - 뷰폿 분할 응용                             */
///*                    작성자 : 신주영               날짜 : 2020년 11월 16일                    */
///*                                                                                            */
///* 문제 정의 : Keyborad콜백함수를 활용하여 카메라의 X,Y 좌표를 움직인다. a,A : 우측상단       */
///*            a,A : 우측상단X, b,B : 우측상단 Y,  e,E : 좌측상단X, f,F : 좌측상단 Y           */
///*            c,C : 우측하단X, d,D : 우측하단 Y   g,G : 좌측하단X, h,H : 좌측하단 Y           */
///*  마우스콜백함수를 활용하여 4개의 윈도우를 왼쪽 버튼과 오른쪽버튼 둘 다 이용하여 움직인다.  */
///*  + 각 4개의 화면에 sphere를 추가로 넣었다.                                                 */
///**********************************************************************************************/
//
//#include<GL/glut.h>
//int Width, Height;
//GLfloat cameraX_RU = 5.0, cameraY_RU = 5.0; //우상단
//GLfloat cameraX_RB = 1.0, cameraY_RB = 0.0; //우하단
//GLfloat cameraX_LU = 0.0, cameraY_LU = 1.0; //좌상단
//GLfloat cameraX_LB = 0.0, cameraY_LB = 0.0; //좌하단
//
//GLfloat LeftX=0.0, LeftY=0.0, RightX, RightY;
//GLfloat LeftX_final, LeftY_final;
//GLfloat h=3.5, w = 2.5;
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//void DrawScene() {
//	glColor3f(0.7, 0.7, 0.7);
//	glPushMatrix();
//	glTranslatef(0.0, -1.0, 0.0);
//	glBegin(GL_QUADS);
//	glVertex3f(2.0, 0.0, 2.0);
//	glVertex3f(2.0, 0.0, -2.0);
//	glVertex3f(-2.0, 0.0, -2.0);
//	glVertex3f(-2.0, 0.0, 2.0);
//	glEnd();
//	glPopMatrix();
//	glColor3f(0.3, 0.3, 0.7);
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -0.5);
//	glutWireTeapot(1.0);
//	glTranslatef(1.0, 0.1, -0.5);
//	glutWireSphere(0.5, 20, 16);
//	glPopMatrix();
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	// 좌하단 뷰폿
//	glViewport(0, 0, Width / 2, Height / 2);
//	glPushMatrix();
//	glOrtho(-2.0, 1.5, -1.0 * Height / Width, 1.0 * Height / Width, 0.0, 10.0);
//	gluLookAt(cameraX_LB, cameraY_LB, 1.0, LeftX_final / 500, LeftY_final / 500, 0.0, 0.0, 1.0, 0.0);
//	DrawScene();
//	glPopMatrix();
//
//	// 우하단 뷰폿
//	glViewport(Width / 2, 0, Width / 2, Height / 2);
//	glPushMatrix();
//	glOrtho(-1.0, 1.0, -1.0 * Height / Width, 1.0 * Height / Width, 0.0, 20.0);
//	gluLookAt(cameraX_RB, cameraY_RB, 0.0, LeftX_final / 500, LeftY_final / 500, 0.0, 0.0, 1.0, 0.0);
//	DrawScene();
//	glPopMatrix();
//
//	// 좌상단 뷰폿
//	glViewport(0, Height / 2, Width / 2, Height / 2);
//	glPushMatrix();
//	gluLookAt(cameraX_LU, cameraY_LU, 0.0, LeftX_final / 500 , LeftY_final / 500, 0.0, 0.0, 0.0, -1.0);
//	DrawScene();
//	glPopMatrix();
//
//	// 우상단 뷰폿
//	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluPerspective(30, 1.0, 3.0, 50.0);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	gluLookAt(cameraX_RU, cameraY_RU, 5.0, LeftX_final/500 + (500-RightX)/500, LeftY_final/500+(500-RightY)/500, 0.0, 0.0, 1.0, 0.0);
//	DrawScene();
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glFlush();
//}
//
//void MyReshape(int w, int h) {
//	Width = w;
//	Height = h;
//}
//
//void MyKeyborad(unsigned key)
//{
//	switch (key) {
//	case 'a':
//		cameraX_RU += 0.5;
//		break;
//	case 'A':
//		cameraX_RU -= 0.5;
//		break;
//	case 'b':
//		cameraY_RU += 0.5;
//		break;
//	case 'B':
//		cameraY_RU -= 0.5;
//		break;
//
//	case 'c':
//		cameraX_RB += 0.5;
//		break;
//	case 'C':
//		cameraX_RB -= 0.5;
//		break;
//	case 'd':
//		cameraY_RB += 0.5;
//		break;
//	case 'D':
//		cameraY_RB -= 0.5;
//		break;
//
//	case 'e':
//		cameraX_LU += 0.5;
//		break;
//	case 'E':
//		cameraX_LU -= 0.5;
//		break;
//	case 'f':
//		cameraY_LU += 0.5;
//		break;
//	case 'F':
//		cameraY_LU -= 0.5;
//		break;
//
//	case 'g':
//		cameraX_LB += 0.5;
//		break;
//	case 'G':
//		cameraX_LB -= 0.5;
//		break;
//	case 'h':
//		cameraY_LB += 0.5;
//		break;
//	case 'H':
//		cameraY_LB -= 0.5;
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void MyMouseMove(GLint X, GLint Y) {
//	LeftX_final = X;
//	LeftY_final = Y;
//
//	glutPostRedisplay();
//}
//
//void MyMouse(GLint Button, GLint State, GLint X, GLint Y)
//{
//	switch (Button) {
//	case GLUT_LEFT_BUTTON:
//		if (State == GLUT_DOWN) {
//			LeftX = X;
//			LeftY = Y;
//			glutPostRedisplay();
//		}
//		break;
//
//	case GLUT_RIGHT_BUTTON:
//		if (State == GLUT_DOWN) {
//			RightX = X;
//			RightY = Y;
//			glutPostRedisplay();
//		}
//		break;
//
//	default:
//		break;
//	}
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	Width = 500;
//	Height = 500;
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutInitWindowSize(Width, Height);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Viewpory Partition");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(MyReshape);
//	glutKeyboardFunc(MyKeyborad);
//	glutMouseFunc(MyMouse);
//	glutMotionFunc(MyMouseMove);
//	glutMainLoop();
//	return 0;
//}