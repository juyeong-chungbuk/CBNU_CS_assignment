//#include <Windows.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <stdbool.h>
//
//static POINT ptLastMousePosit;
//static POINT ptCurrentMousePosit;
//static bool bMousing;
//
//float g_fDistance = -20.0f;
//float g_fSpinX = 0.0f;
//float g_fSpinY = 0.0f;
//
//GLUnurbsObj* pNurb = NULL; // NURBS 객체의 포인터 변수
//
//GLint nNumPoints = 4; // 4 X 4 곡선을 위한 제어점
//
//// x축과 y축을 따라 -6~6까지 4개의 단위로 Mesh 확장. 평면은 z축에 존재
//// Mesh는 4x4 크기의 u,v 좌표를 가지며 각 좌표는 vertex로 구성 (x,y,z)
////GLfloat ctrlPoints[4][4][3] = {
////{{ -6.0f, -6.0f, 0.0f}, // u = 0, v = 0
////{ -6.0f, -2.0f, 0.0f}, // v = 1
////{ -6.0f, 2.0f, 0.0f}, // v = 2
////{ -6.0f, 6.0f, 0.0f}}, // v = 3
////
////{{ -2.0f, -6.0f, 0.0f}, // u = 1 v = 0
////{ -2.0f, -2.0f, 8.0f}, // v = 1
////{ -2.0f, 2.0f, 8.0f}, // v = 2
////// { -2.0f, -2.0f, 0.0f}, // v = 1
////// { -2.0f, 2.0f, 0.0f}, // v = 2
////{ -2.0f, 6.0f, 0.0f}}, // v = 3
////
////{{ 2.0f, -6.0f, 0.0f}, // u = 2 v = 0
////{ 2.0f, -2.0f, 8.0f}, // v = 1
////{ 2.0f, 2.0f, 8.0f}, // v = 2
////// { 2.0f, -2.0f, 0.0f}, // v = 1
////// { 2.0f, 2.0f, 0.0f}, // v = 2
////{ 2.0f, 6.0f, 0.0f}}, // v = 3
////
////{{ 6.0f, -6.0f, 0.0f}, // u = 3 v = 0
////{ 6.0f, -2.0f, 0.0f}, // v = 1
////{ 6.0f, 2.0f, 0.0f}, // v = 2
////{ 6.0f, 6.0f, 0.0f}} }; // v = 3
//
//GLUquadricObj* qobj;
//
//GLfloat Knots[8] = { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f }; // NURBS를 위한 매듭의 순서 지정
//
//// NURBS 위에 적색의 제어점을 그리기 위해 호출되는 함수
////void DrawPoints(void) {
////	// 초기의 큰 빨간 점
////	glPointSize(5.0f);
////	glColor3ub(255, 0, 0);
////
////	// 배열의 모든 점 그리기
////	glBegin(GL_POINTS);
////	for (int i = 0; i < 4; i++)
////		for (int j = 0; j < 4; j++)
////			glVertex3fv(ctrlPoints[i][j]);
////	glEnd();
////}
//
//// 그린 장면 불러오기
//void RenderScene(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glTranslatef(0.0f, 0.0f, g_fDistance);
//	//glRotatef(-g_fSpinY, 1.0f, 0.0f, 0.0f);
//	//glRotatef(-g_fSpinX, 0.0f, 1.0f, 0.0f);
//
//	glColor3ub(0, 0, 220);
//	glPushMatrix();
//	qobj = gluNewQuadric();
//	//glRotatef(330.0f, 1.0f, 0.0f, 0.0f);
//	gluSphere(qobj, 1.0, 40, 40); // Sphere 생성
//
//	// NURBS의 표면 정의 구분하는 기능 시작
//	gluBeginSurface(pNurb);
//	//// NURBS 표면의 모양 정의
//	//gluNurbsSurface(pNurb, // NURBS renderer에 대한 포인터
//	//	8, Knots, // knots 수와 knot 배열의 u direction
//	//	8, Knots, // knots 수와 knot 배열의 v direction
//	//	4 * 3, // u dir에서 제어점 사이의 거리
//	//	3, // v dir에서 제어점 사이의 거리
//	//	//&ctrlPoints[0][0][0], // 제어점
//	//	4, 4, // 표면의 u와 v 순서
//	//	GL_MAP2_VERTEX_3); // 표면의 종류
//		// NURBS의 표면 정의 구분하는 기능 끝
//	gluEndSurface(pNurb);
//	// 제어점 표시
//	//DrawPoints();
//	// modelview 행렬 복원
//	glPopMatrix();
//	// 이미지 표시
//	glutSwapBuffers();
//}
//
//// 이 함수는 렌더링 문맥에서 필요한 초기화를 수행합니다.
//// 여기서는 장면의 조명을 설정하고 초기화합니다
//void SetupRC() {
//	// 빛 값과 좌표
//	GLfloat whiteLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat specular[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat shine[] = { 100.0f };
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);
//
//	// glColor 값을 따르도록 재질 속성 설정
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//	// 평가된 표면을 위한 법선 벡터 자동 생산
//	glEnable(GL_AUTO_NORMAL);
//	// NURBS의 객체 설정
//	pNurb = gluNewNurbsRenderer();
//	// NURBS의 속성 설정
//	gluNurbsProperty(pNurb, GLU_SAMPLING_TOLERANCE, 25.0f);
//	// gluNurbsProperty(pNurb, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON);
//	gluNurbsProperty(pNurb, GLU_DISPLAY_MODE, (GLfloat)GLU_FILL);
//}
//
//void MyReshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MySpecial(int key, int x, int y) {
//	if (key == GLUT_KEY_PAGE_UP) {
//		g_fDistance -= 1.0f;
//	}
//	else if (key == GLUT_KEY_PAGE_DOWN) {
//		g_fDistance += 1.0f;
//	}
//	glutPostRedisplay(); // glutDisplayFunc에 등록된 함수 호출 (창을 다시 그려준다
//}
//
//void MyMouse(int button, int state, int x, int y) {
//	switch (button) {
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			ptLastMousePosit.x = ptCurrentMousePosit.x = x;
//			ptLastMousePosit.y = ptCurrentMousePosit.y = y;
//			bMousing = true;
//		}
//		else
//			bMousing = false;
//		break;
//	case GLUT_MIDDLE_BUTTON:
//	case GLUT_RIGHT_BUTTON:
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void MyMotion(int x, int y) {
//	ptCurrentMousePosit.x = x;
//	ptCurrentMousePosit.y = y;
//	if (bMousing)
//	{
//		g_fSpinX -= (ptCurrentMousePosit.x - ptLastMousePosit.x);
//		g_fSpinY -= (ptCurrentMousePosit.y - ptLastMousePosit.y);
//	}
//	ptLastMousePosit.x = ptCurrentMousePosit.x;
//	ptLastMousePosit.y = ptCurrentMousePosit.y;
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("NURBS Surface");
//	glutReshapeFunc(MyReshape);
//	glutDisplayFunc(RenderScene);
//	glutMouseFunc(MyMouse);
//	glutMotionFunc(MyMotion); // 마우스 버튼을 누른 채로 윈도우 내부에서 움직일 때 호출
//	glutSpecialFunc(MySpecial); // 특수키
//	SetupRC();
//	glutMainLoop();
//	return 0;
//}