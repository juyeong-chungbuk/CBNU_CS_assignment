///*******************************************************************************************/
///*                    HW#5 : 계층적 모델링, 시점변환  - 전신 Can Robot 제작                */
///*                  작성자 : 신주영               날짜 : 2020년 11월 10일                  */
///*                                                                                         */
///* 문제 정의 : 머리, 왼팔, 오른팔, 다리, 몸통 함수를 따로 구현하여 DrawAndriod함수 안에서  */
///*             호출하여 초기 차렷 자세를 만들고, 마우스 오른쪽 버튼 클릭시 오른팔이        */
///*             움직이는 모양을 그렸다.                                                     */
///*******************************************************************************************/
//
//#include <windows.h>
//#include <stdlib.h>
//#include <MMSystem.h>
//#include <GL/glut.h>
//#include <math.h>
//
//static double time = 0;  // Run_time 변수
//int move = 0;
//
//GLfloat R_Arm_x = 0; // 오른쪽 어깨
//GLfloat R_Arm_y = 0; // 오른쪽 팔
//GLfloat L_Arm_x = 0; // 왼쪽 어깨
//GLfloat L_Arm_y = 0; // 왼쪽 팔
//GLfloat R_Leg_x = 0; // 오른 허벅지
//GLfloat R_Leg_y = 0; // 오른 종아리
//GLfloat L_Leg_x = 0; // 왼 허벅지
//GLfloat L_Leg_y = 0; // 왼 종아리
//GLfloat R = 0; // 왼쪽 로켓 펀치 움직임 변수
//GLfloat R2 = 0;// 오른쪽 로켓 펀치 움직임 변수
//
//GLUquadricObj* cyl;// 실린더 객체 선언
//
//static int flag = 0; // wireframe 모드와 solid rendering 모드 구분 변수
//static int key = 0;  // 동작 모드와 색상 변경 변수
//
//#define RUN		1						
//#define YUNA	4	
//#define EXIT	6	
//
//void glInit(void) { // 지엘 초기화 함수 
//	glEnable(GL_DEPTH_TEST); // 깊이 테스팅 사용
//	glEnable(GL_NORMALIZE);  // 정규화
//	glEnable(GL_SMOOTH);     // 각 정점의 색상을 부드럽게 연결하여 칠해지도록  하므로, 각정점에 적용된 색상이 혼합되어 적용된다. 
//	glEnable(GL_LIGHTING);   // 지엘 조명. 빛을 받는 각도에 따라 로봇 색상이 변화
//
//	/* 빛을 받는 각도에 따라 로봇 색깔의 변화를 위한 설정 */
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
//	glClearColor(0.0, 1.0, 1.0, 1.0); // 배경 검은색
//	glMatrixMode(GL_PROJECTION);   // 모드 설정
//	glLoadIdentity();              // CTM 값 초기화 
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시 범위 설정
//}
//
//void Draw_Color(int i) { // 색상을 그리는 함수
//		glColor3f(1.0, 1.0, 0.0);
//}
//
//void Change_Wire_Or_Solid(int i) {          // 솔리드, 와이어 선택
//	if (flag == 1)
//		gluQuadricDrawStyle(cyl, GLU_LINE); // 스타일을 와이어로 변경
//}
///*
//로봇 왼팔을 그리는 함수
//*/
//
//void DrawL_Arm(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);     // 색 설정
//	cyl = gluNewQuadric();   // 실린더 객체 생성
//	glRotatef(x, a, b, c);  // 파라미터 값만큼 회전
//	glRotatef(90.0, 1.0, 0.0, 0.0); // 실린더를 x축 기준으로 90도 회전(실린더 생성 시 각도 변경을 위해)
//	glTranslatef(0.25, 0.0, 0.0);    // 왼쪽 어깨 시작점으로 이동
//	glRotatef(15.0, 0.0, 1.0, 0.0); // 왼쪽 어깨를 y축을 기준으로 15도 회전
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1); // 실린더를 그림
//}
//
///*
//로봇 왼쪽 손을 그리는 함수
//*/
//void DrawL_Hand(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);       // 색 설정
//	cyl = gluNewQuadric();   // 실린더 객체 생성
//	glTranslatef(0.0, 0.0, 0.22); // 왼손 시작점
//	glRotatef(y, a, b, c);        // 파라미터 값만큼 회전
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.02, 0.2, 15, 1); // 깔때기 모양 실린더를 그림
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);           // 실린더를 그림
//	glPopMatrix();
//}
///*
//로봇 왼쪽 주먹
//*/
//void DrawL_HandRocket() {
//	glPushMatrix();
//	Draw_Color(key);     // 색 설정
//	cyl = gluNewQuadric(); // 실린더 객체 생성
//	glTranslatef(0, 0, R); // 왼쪽 주먹 위치를 파라미터만큼 이동
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1); // 실린더를 그림
//	glPopMatrix();
//}
///*
//로봇 오른팔을 그리는 함수
//*/
//void DrawR_Arm(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);     // 색 설정
//	cyl = gluNewQuadric(); // 실린더 객체 생성
//	glRotatef(x, a, b, c);  // 파라미터 값만큼 회전
//	glRotatef(90.0, 1.0, 0.0, 0.0); // 실린더를 x축을 기준으로 90도 회전(실린더 생성 시 각도 변경을 위해)
//	glTranslatef(-0.25, 0.0, 0.0); //우측 어깨 시작점으로 이동
//	glRotatef(-15.0, 0.0, 1.0, 0.0); //우측 어깨 -15도 y축기준 회전
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// 실린더 그림
//
//}
///*
//로봇 오른쪽 손을 그리는 함수
//*/
//void DrawR_Hand(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key); // 색 설정
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glTranslatef(0.0, 0.0, 0.22);//오른쪽 손 시작점
//	glRotatef(y, a, b, c);// 파라미터값 만큼 회전
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.02, 0.2, 50, 1);// 깔때기 모양 실린더 그림
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// 실린더 그림
//	glPopMatrix();
//}
//
///*
//로봇 오른쪽 로켓트 함수
//*/
//
//void DrawR_HandRocket() {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric(); //실린더 객체 생성
//	glTranslatef(0, 0, R2);//오른주먹 위치 파라미터만큼 이동
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// 실린더 그림
//	glPopMatrix();
//}
///*
//로봇 몸체를 그리는 함수
//*/
//void DrawBody(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glRotatef(x, a, b, c);//파라미터값 만큼 회전
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.2, 0.2, 0.45, 50, 1);// 실린더 그림
//	glPopMatrix();
//}
///*
//로봇 왼쪽 허벅지를 그리는 함수
//*/
//void DrawL_Legs(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glTranslatef(0.1, 0.0, 0.42);//왼쪽 허벅지 시작점
//	glRotatef(x, a, b, c);//파라미터만큼 회전
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);// 실린더 그림
//
//}
///*
//로봇 왼쪽 종아리를 그리는 함수
//*/
//void DrawL_foot(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glTranslatef(0.0, 0.0, 0.18);//왼쪽 종아리 시작점
//	glRotatef(y, a, b, c);//파라미터만큼 회전
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.03, 0.2, 50, 1);// 깔때기 모양 실린더 그림
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);// 실린더 그림
//	glPopMatrix();
//}
///*
//로봇 오른쪽 허벅지를 그리는 함수
//*/
//void DrawR_Legs(int x, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glTranslatef(-0.1, 0.0, 0.42);//오른쪽 허벅지 시작점
//	glRotatef(x, a, b, c);//파라미터만큼 회전
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);// 실린더 그림
//
//}
///*
//로봇 오른쪽 종아리를 그리는 함수
//*/
//void DrawR_foot(int y, int a, int b, int c) {
//	glPushMatrix();
//	Draw_Color(key);
//	cyl = gluNewQuadric();//실린더 객체 생성
//
//	glTranslatef(0.0, 0.0, 0.18);//오른쪽 종아리 시작점
//	glRotatef(y, a, b, c);//파라미터만큼 회전
//
//	Change_Wire_Or_Solid(flag);
//	if (key == YUNA) gluCylinder(cyl, 0.05, 0.03, 0.2, 15, 1);// 깔때기 모양 실린더 그림
//	else gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);// 실린더 그림
//	glPopMatrix();
//}
///*
//로봇 목을 그리는 함수
//*/
//void Drawneck() {
//	glPushMatrix();
//	glColor3f(1.0, 1.0, 1.0);//색 지정(흰색)
//	cyl = gluNewQuadric();//실린더 객체 생성
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glTranslatef(0.0, 0.0, -0.045); // 목 시작점
//	Change_Wire_Or_Solid(flag);
//	gluCylinder(cyl, 0.2, 0.2, 0.025, 100, 1);// 실린더 그림
//	glPopMatrix();
//}
//
///*
//로봇 머리를 그리는 함수
//로봇의 머리에 달려있는 뿔과
//로봇의 눈을 설정하였다.
//*/
//void DrawHead() {
//	glTranslatef(0.0, 0.02, 0.0);//머리 시작점
//	glPushMatrix();// 처음 저장 좌표 다시 저장
//	cyl = gluNewQuadric();
//	Change_Wire_Or_Solid(flag);
//	Draw_Color(key);//색깔 설정
//	gluSphere(cyl, 0.20, 30, 10);//머리 그리기
//	/*왼쪽 뿔 그리기*/
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glTranslatef(-0.16, 0.0, -0.22);//왼쪽 뿔 시작점
//	glRotatef(35.0, 0.0, 1.0, 0.0);//35도 y축 기준 회전
//	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);//실린더 그림
//	glPopMatrix(); // 처음 저장 좌표로 돌아 간다.
//	glPushMatrix();// 처음 저장 좌표 다시 저장
//
//	/*오른쪽 뿔 그리기*/
//	glRotatef(90.0, 1.0, 0.0, 0.0);//실린더 90도 x축기준 회전 (실린더 생성시 각도 변경을 위하여)
//	glTranslatef(0.16, 0.0, -0.22);//오른쪽 뿔 시작점
//	glRotatef(-35.0, 0.0, 1.0, 0.0);//-35도 y축 기준 회전
//	gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);//실린더 그림
//	glPopMatrix(); // 처음 저장 좌표로 돌아 간다.	
//	glPushMatrix();// 처음 저장 좌표 다시 저장
//
//	/*왼쪽 눈 그리기*/
//	glTranslatef(-0.1, 0.1, 0.13);//왼쪽 눈 시작점
//	glColor3f(0.0, 0.0, 0.0);// 눈 컬러 설정(흑색)
//	gluSphere(cyl, 0.03, 10, 10);
//
//	glPopMatrix(); // 처음 저장 좌표로 돌아 간다.
//	glPushMatrix();// 처음 저장 좌표 다시 저장
//
//	/*오른쪽 눈 그리기*/
//	glTranslatef(0.1, 0.1, 0.13);//오른쪽 눈 시작점
//	gluSphere(cyl, 0.03, 10, 10);
//	glPopMatrix();// 처음 저장 좌표 다시 저장
//}
//
///*
//안드로이드 전체 모습을 그리는 함수
//*/
//void DrawAndroid() {
//
//
//	cyl = gluNewQuadric(); //실린더 객체 생성
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //초기화
//	glMatrixMode(GL_MODELVIEW); //모드 설정
//
//	glLoadIdentity();//CTM 초기화
//
//
//	DrawBody(0, 0, 0, 0); // 몸통 함수 호출
//	Drawneck(); // 목함수 호출
//	DrawHead(); // 머리 호출
//	DrawR_Arm(R_Arm_x, 1, 0, 0);//우측팔뚝
//	DrawR_Hand(R_Arm_y, 1, 0, 0);  //우측팔호출
//	DrawL_Arm(L_Arm_x, 1, 0, 0);   //좌측팔뚝
//	DrawL_Hand(L_Arm_y, 1, 0, 0);//좌측손호출
//	DrawL_Legs(L_Leg_x, 1, 0, 0);  //좌측다리
//	DrawL_foot(L_Leg_y, 1, 0, 0);  //좌측발		 
//	DrawR_Legs(R_Leg_x, 1, 0, 0);  //우측다리
//	DrawR_foot(R_Leg_y, 1, 0, 0);  //우측발	
//}
//
///*
//타이머 함수
//각 장면마다 상태 표현을 다르게 두기 위해 대양한 시간 변수들이 쓰였다.
//*/
//void MyTimer(int Value) {
//	if (move == 1)
//		time = time + 0.1;//달릴때 쓰인 타이머 변수
//
//	else
//		time = time + 0.0;
//	glutPostRedisplay();
//	glutTimerFunc(40, MyTimer, 1);
//}
//
//
///*
//로봇이 달리는 것을 표현한 함수.
//로봇의 관절이 움직이는 것을 표현했고,
//로봇이 달리면서 상,하,좌,우로 움직이는 모습을 표현했다.
//*/
//void Run() {
//	sndPlaySound(TEXT("C:\\sample1.wav"), SND_ASYNC | SND_NOSTOP);
//	glLoadIdentity();//CTM 초기화
//					 
//					 
//	////////////////display////////////////
//
//	cyl = gluNewQuadric(); //실린더 객체 생성
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //초기화
//	glMatrixMode(GL_MODELVIEW); //모드 설정
//	glLoadIdentity();//CTM 초기화
//	DrawAndroid();
//
//	if (move == 1) {
//		L_Arm_x = sin(time) * 80;
//	}
//	move = 2;
//	glutTimerFunc(40, MyTimer, 1); //타이머 함수
//
//	glTranslatef(0.0, 0.5, 0.0);//최초 로봇의 위치 
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
//키보드 콜백 설정 함수
//w를 누르면 wire 모드로, s를 누르면 solid 모드로, q를 누르면 종료를 표현
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
//	glutInit(&argc, argv);//초기화
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//디스플레이 모드 설정
//	glutInitWindowSize(800, 800);//윈도우 크기 설정
//	glutInitWindowPosition(0, 0);//윈도우 초기 위치 설정
//	glutCreateWindow("전신 Can Robot 제작");//윈도우 생성
//	glInit(); // 조명 초기화
//
//	glutMouseFunc(MyMouse);
//	glutKeyboardFunc(MyKeyboard); //키보드 콜백
//	glutDisplayFunc(MyDisplay); //디스플레이
//
//	glutMainLoop();
//	return 0;
//}