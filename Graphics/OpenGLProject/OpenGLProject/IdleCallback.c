///*************************************************************/
///*       HW#4 : Callback 프로그래밍  - Idle Callback(1)      */
///*      작성자 : 신주영          날짜 : 2020년 10월 16일     */
///*                                                           */
///* 문제 정의 : UP키 누를 시, 좌표가 위쪽으로 0.1씩 이동      */
///*             DOWN키 누를 시, 좌표가 아래쪽으로 0.1씩 이동  */
///*             LEFT키 누를 시, 좌표가 왼쪽으로 0.1씩 이동    */
///*             RIGHT키 누를 시, 좌표가 오른쪽으로 0.1씩 이동 */
///*    -> Idel Callback함수를 이용하여 각 키를 눌렀을때 호출  */
///*************************************************************/
//
//#include<GL/glut.h>
//
//GLfloat vertex[4][3] = { {-0.5,-0.5,0.0},{0.5,-0.5,0.0},{0.5,0.5,0.0},{-0.5,0.5,0.0} }; //최초의 사면체
//GLfloat Delta = 0.0; //증가시킨 변수
//int n = 0; //누른 키 구분할 변수
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.5, 0.8);
//
//	if (n == 1) { //위쪽
//
//		if (vertex[3][1]+Delta <= 1.0) { //윈도우 화면 안에서만
//			glVertex3f(vertex[0][0], vertex[0][1] + Delta, vertex[0][2]);
//			glVertex3f(vertex[1][0], vertex[1][1] + Delta, vertex[1][2]);
//			glVertex3f(vertex[2][0], vertex[2][1] + Delta, vertex[2][2]);
//			glVertex3f(vertex[3][0], vertex[3][1] + Delta, vertex[3][2]); //y좌표 증가
//		}
//
//		else { //윈도우 나가지 않도록 설정
//		glVertex3f(vertex[0][0], 0.0 , vertex[0][2]);
//		glVertex3f(vertex[1][0], 0.0 , vertex[1][2]);
//		glVertex3f(vertex[2][0], 1.0 , vertex[2][2]);
//		glVertex3f(vertex[3][0], 1.0 , vertex[3][2]);
//		}
//
//	}
//
//	else if (n == 2){ //아래쪽
//
//		if (vertex[0][1]-Delta >= -1.0) {//윈도우 화면 안에서만
//			glVertex3f(vertex[0][0], vertex[0][1] - Delta, vertex[0][2]);
//			glVertex3f(vertex[1][0], vertex[1][1] - Delta, vertex[1][2]);
//			glVertex3f(vertex[2][0], vertex[2][1] - Delta, vertex[2][2]);
//			glVertex3f(vertex[3][0], vertex[3][1] - Delta, vertex[3][2]); //y좌표 감소
//		}
//		else {//윈도우 나가지 않도록 설정
//			glVertex3f(vertex[0][0], -1.0, vertex[0][2]);
//			glVertex3f(vertex[1][0], -1.0, vertex[1][2]);
//			glVertex3f(vertex[2][0], 0.0, vertex[2][2]);
//			glVertex3f(vertex[3][0], 0.0, vertex[3][2]);
//		}
//
//	}
//
//	else if (n == 3) { //왼쪽
//
//		if (vertex[0][0] - Delta >= -1.0) {//윈도우 화면 안에서만
//			glVertex3f(vertex[0][0] - Delta, vertex[0][1], vertex[0][2]);
//			glVertex3f(vertex[1][0] - Delta, vertex[1][1], vertex[1][2]);
//			glVertex3f(vertex[2][0] - Delta, vertex[2][1], vertex[2][2]);
//			glVertex3f(vertex[3][0] - Delta, vertex[3][1], vertex[3][2]); //x좌표 감소
//		}
//
//		else {//윈도우 나가지 않도록 설정
//			glVertex3f(-1.0, vertex[0][1], vertex[0][2]);
//			glVertex3f(0.0, vertex[1][1], vertex[1][2]);
//			glVertex3f(0.0, vertex[2][1], vertex[2][2]);
//			glVertex3f(-1.0, vertex[3][1], vertex[3][2]);
//		}
//
//	}
//
//	else { //오른쪽
//
//		if (vertex[1][0] + Delta <= 1.0) {//윈도우 화면 안에서만
//			glVertex3f(vertex[0][0] + Delta, vertex[0][1], vertex[0][2]);
//			glVertex3f(vertex[1][0] + Delta, vertex[1][1], vertex[1][2]);
//			glVertex3f(vertex[2][0] + Delta, vertex[2][1], vertex[2][2]);
//			glVertex3f(vertex[3][0] + Delta, vertex[3][1], vertex[3][2]); //x좌표 증가
//		}
//
//		else {//윈도우 나가지 않도록 설정
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
//	if (n == 1 || n == 2 || n == 3 || n == 4) //각 키를 눌렀을때
//		Delta = Delta + 0.001; //0.001씩 증가
//
//	glutPostRedisplay(); //디스플레이 함수 호출
//}
//
//void MyInit() {
//	glClearColor(1.0, 1.0, 1.0, 1.0); //배경 흰색
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //가시부피 설정
//}
//
//void MySpecial(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_UP:
//		glutIdleFunc(MyIdle);  Delta = 0.0; break; //각 키를 다 돌고 난 뒤, Delta초기화
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
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //더블버퍼
//	glutInitWindowSize(300, 300); //윈도우 창크기
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Idle Callback");
//	MyInit();
//	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
//	glutSpecialFunc(MySpecial); //스페셜키 함수 등록
//	glutIdleFunc(MyIdle); //Idel함수 등록
//	glutMainLoop();
//	return 0;
//}