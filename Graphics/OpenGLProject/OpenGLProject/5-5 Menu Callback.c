///******************************************************************************/
///*                 HW#4 : Callback 프로그래밍  - 메뉴콜백(1)                  */
///*              작성자 : 신주영          날짜 : 2020년 10월 16일              */
///*                                                                            */
///* 문제 정의 : 5가지 메뉴와 각 하위메뉴에 small, large를 생성하여             */
///*             각 도형의 크기를 조절하고 새삭메뉴를 통해 도형의 색을 변경한다.*/
///******************************************************************************/ 
//
//
//#include <GL/glut.h>
//#include <stdlib.h>
//GLboolean IsSphere = TRUE; //sphere메뉴
//GLboolean IsSmallsphere; //shpere의 하위메뉴
//
//GLboolean IsTorus; //torus메뉴
//GLboolean IsSmallTorus; //torus의 하위메뉴
//
//GLboolean IsTeapot; //teapot메뉴
//GLboolean IsSmallTeapot; //teapot의 하위메뉴
//
//GLboolean IsChangeColor; //color메뉴
//GLint color; //color의 하위메뉴
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.5, 0.5);
//
//	if (IsSphere && IsSmallsphere) { //shpere->small선택
//		
//		if(IsChangeColor &&color==1) //red선택
//		glColor3f(1.0, 0.0, 0.0);
//		else if(IsChangeColor &&color==2) //green선택
//			glColor3f(0.0, 1.0, 0.0);
//		else if(IsChangeColor &&color==3) //blue선택
//			glColor3f(0.0, 0.0, 1.0);
//		glutWireSphere(0.3, 30, 30);	//smallshpere생성
//	}
//	else if (IsSphere && !IsSmallsphere) { //shpere->large선택
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireSphere(0.5, 40, 20); //largeshpere생성
//	}
//
//	if (IsSmallTorus && IsTorus) { //torus->small선택
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireTorus(0.1, 0.3, 30, 30); //smalltorus생성
//	}
//	else if (!IsSmallTorus && IsTorus) { //torus->large선택
//
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//
//		glutWireTorus(0.2, 0.5, 40, 20); //largetorus생성
//	}
//
//	if (IsTeapot && IsSmallTeapot) { //teapot->small선택
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//		
//		glutWireTeapot(0.1); //smallteapot생성
//	}
//
//	else if (IsTeapot && !IsSmallTeapot) { //teapot->large선택
//		if (IsChangeColor &&color == 1)
//			glColor3f(1.0, 0.0, 0.0);
//		else if (IsChangeColor &&color == 2)
//			glColor3f(0.0, 1.0, 0.0);
//		else if (IsChangeColor &&color == 3)
//			glColor3f(0.0, 0.0, 1.0);
//		
//		glutWireTeapot(0.5); //largeteapot생성
//	}
//
//	glFlush();
//}
//
//void MyMainMenu(int entryID) {
//	if (entryID == 5)exit(0); //종료메뉴
//	glutPostRedisplay();
//}
//
//
//void MySphereMenu(int entryID)
//{
//	IsTorus = FALSE;
//	IsTeapot = FALSE; //shpere외에는 false로
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
//	IsTeapot = FALSE; //torus외에는 false로
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
//	IsTorus = FALSE; //teapot외에는 false로
//
//	IsTeapot = TRUE;
//	if (entryID == 1)IsSmallTeapot = TRUE; //small
//	else if (entryID == 2)IsSmallTeapot = FALSE; //large
//	glutPostRedisplay();
//}
//
//void MychangecoloreMenu(int entryID) //컬러메뉴 선택
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
//	GLint Mysphere = glutCreateMenu(MySphereMenu); //shpere하위메뉴 생성
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint Mytorus = glutCreateMenu(MyTorusMenu); //torus하위 메뉴 생성
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint Myteapot = glutCreateMenu(MyTeapotMenu); //teapot하위메뉴 생성
//	glutAddMenuEntry("Small", 1);
//	glutAddMenuEntry("Large", 2);//
//	GLint MyChangeColor = glutCreateMenu(MychangecoloreMenu); //color하위메뉴 생성
//	glutAddMenuEntry("Red", 1);
//	glutAddMenuEntry("Green", 2);//	glutAddMenuEntry("Blue", 3);//
//
//	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //메뉴 생성
//	glutAddSubMenu("Draw Sphere", Mysphere);
//	glutAddSubMenu("Draw Torus", Mytorus);
//	glutAddSubMenu("Draw Teapot", Myteapot);
//	glutAddSubMenu("Change Color", MyChangeColor);
//	glutAddMenuEntry("Exit", 5);
//	glutAttachMenu(GLUT_RIGHT_BUTTON); //오른쪽 마우스버튼 클릭 시
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Menu Callback");
//	MyInit(); //메뉴 넣어줌
//	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
//	glutMainLoop();
//	return 0;
//}