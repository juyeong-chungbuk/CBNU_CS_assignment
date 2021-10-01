///**************************************************************************/
///*              HW#4 : Callback 프로그래밍  - 마우스콜백(1)               */
///*           작성자 : 신주영          날짜 : 2020년 10월 16일             */
///*                                                                        */
///* 문제 정의 : 마우스콜백함수를 이용하여 왼클릭 시, 오른쪽으로 연속이동,  */
///*             우클릭 시, 도형 정지하고, 윈도우 화면 벗어나기 전에 멈춤   */
///**************************************************************************/ 
//
//
//#include <GL/glut.h>
//
//GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY; //위왼쪽에서 밑오른쪽으로 가니까
//GLfloat vertex[4][3] = { {0.0,0.0,0.0},{0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0} }; //초기화
//int count = 0; //처음 누를 때와 두번째 누를 때 구분
//GLfloat Delta = 0.0; //증가변수
//
//void MyDisplay() {
//	glViewport(0, 0, 500, 500);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.5, 0.5);
//	glBegin(GL_POLYGON);
//
//	vertex[0][0] = TopLeftX / 500.0; //왼위
//	vertex[0][1] = (500 - TopLeftY) / 500.0;
//	vertex[0][2] = 0.0;
//
//	vertex[1][0] = TopLeftX / 500.0; //왼아래
//	vertex[1][1] = (500 - BottomRightY) / 500.0;
//	vertex[1][2] = 0.0;
//
//	vertex[2][0] = BottomRightX / 500.0; //오아래
//	vertex[2][1] = (500 - BottomRightY) / 500.0;
//	vertex[2][2] = 0.0;
//
//	vertex[3][0] = BottomRightX / 500.0; //오위
//	vertex[3][1] = (500 - TopLeftY) / 500.0;
//	vertex[3][2] = 0.0;
//
//
//	glVertex3f(vertex[0][0] + Delta, vertex[0][1], vertex[0][2]);
//	glVertex3f(vertex[1][0] + Delta, vertex[1][1], vertex[1][2]);
//	glVertex3f(vertex[2][0] + Delta, vertex[2][1], vertex[2][2]);
//	glVertex3f(vertex[3][0] + Delta, vertex[3][1], vertex[3][2]); //x증가시키면서 출력
//
//	glEnd();
//	glFlush();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//
//	switch (Button) {
//	case GLUT_LEFT_BUTTON:
//		if (State == GLUT_DOWN&&count==0) { //처음 도형 만들 때
//			TopLeftX = X;
//			TopLeftY = Y;
//			count = 1;
//		}
//		else if(State == GLUT_DOWN && count == 1){ //두번째 왼클릭
//			while (1) {
//				
//				if (vertex[3][0] + Delta <= 1.0) { //윈도우 안에서만
//					Delta += 0.1; //0.1씩 증가
//					TopLeftX += Delta;
//					BottomRightX += Delta; //x좌표 증가
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
//	case GLUT_RIGHT_BUTTON: //우클릭
//		if (State == GLUT_DOWN) {
//			Delta += 0.0; //그만 증가.
//			TopLeftX += Delta;
//			glutPostRedisplay();
//		}
//		break;
//	}
//
//}
//
//void MyMouseMove(GLint X, GLint Y) { //마우스 뗐을때 위치
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
//	glutMouseFunc(MyMouseClick); //마우스클릭 함수 등록
//	glutMotionFunc(MyMouseMove); //마우스이동 함수 등록
//
//	glutMainLoop();
//	return 0;
//}