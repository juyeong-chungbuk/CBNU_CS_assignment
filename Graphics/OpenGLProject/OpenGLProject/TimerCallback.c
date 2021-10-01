///*************************************************************/
///*       HW#4 : Callback 프로그래밍  - 타이머콜백(1)         */
///*      작성자 : 신주영          날짜 : 2020년 10월 16일     */
///*                                                           */
///* 문제 정의 : 타이버 콜백 함수를 이용하여 정사각형을 오른쪽 */
///*        으로 이동 시킴과 동시에 15가지 색상으로 변화시킨다.*/
///*                                                           */
///*************************************************************/
//
//#include <GL/glut.h>
//GLfloat Delta = 0.0; //증가변수
//int n; //색 15가지 변경
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
//	} //내 15가지 마음대로 색깔 설정 .....
//
//	glVertex3f(-1.0 + Delta, -0.5, 0.0);
//	glVertex3f(0.0 + Delta, -0.5, 0.0);
//	glVertex3f(0.0 + Delta, 0.5, 0.0);
//	glVertex3f(-1.0 + Delta, 0.5, 0.0); //오른쪽으로 이동
//
//	glEnd();
//	glutSwapBuffers();
//}
//
//void MyTimer(int Value) {
//	Delta = Delta + 0.005; //0.005씩 증가
//
//	if (n < 16) //15가지 색
//		n++;
//	else
//		n = 0;
//
//	glutPostRedisplay(); //디스플레이 함수 호출
//	glutTimerFunc(10, MyTimer, 1); //인위적으로 넣어줘야함
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0); //배경 흰색
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //가시부피 설정
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Idle Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
//	glutTimerFunc(10, MyTimer, 1); //타이머 콜백 등록
//	glutMainLoop();
//	return 0;
//}