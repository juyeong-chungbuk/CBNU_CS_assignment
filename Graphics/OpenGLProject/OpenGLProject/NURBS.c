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
//GLUnurbsObj* pNurb = NULL; // NURBS ��ü�� ������ ����
//
//GLint nNumPoints = 4; // 4 X 4 ��� ���� ������
//
//// x��� y���� ���� -6~6���� 4���� ������ Mesh Ȯ��. ����� z�࿡ ����
//// Mesh�� 4x4 ũ���� u,v ��ǥ�� ������ �� ��ǥ�� vertex�� ���� (x,y,z)
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
//GLfloat Knots[8] = { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f }; // NURBS�� ���� �ŵ��� ���� ����
//
//// NURBS ���� ������ �������� �׸��� ���� ȣ��Ǵ� �Լ�
////void DrawPoints(void) {
////	// �ʱ��� ū ���� ��
////	glPointSize(5.0f);
////	glColor3ub(255, 0, 0);
////
////	// �迭�� ��� �� �׸���
////	glBegin(GL_POINTS);
////	for (int i = 0; i < 4; i++)
////		for (int j = 0; j < 4; j++)
////			glVertex3fv(ctrlPoints[i][j]);
////	glEnd();
////}
//
//// �׸� ��� �ҷ�����
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
//	gluSphere(qobj, 1.0, 40, 40); // Sphere ����
//
//	// NURBS�� ǥ�� ���� �����ϴ� ��� ����
//	gluBeginSurface(pNurb);
//	//// NURBS ǥ���� ��� ����
//	//gluNurbsSurface(pNurb, // NURBS renderer�� ���� ������
//	//	8, Knots, // knots ���� knot �迭�� u direction
//	//	8, Knots, // knots ���� knot �迭�� v direction
//	//	4 * 3, // u dir���� ������ ������ �Ÿ�
//	//	3, // v dir���� ������ ������ �Ÿ�
//	//	//&ctrlPoints[0][0][0], // ������
//	//	4, 4, // ǥ���� u�� v ����
//	//	GL_MAP2_VERTEX_3); // ǥ���� ����
//		// NURBS�� ǥ�� ���� �����ϴ� ��� ��
//	gluEndSurface(pNurb);
//	// ������ ǥ��
//	//DrawPoints();
//	// modelview ��� ����
//	glPopMatrix();
//	// �̹��� ǥ��
//	glutSwapBuffers();
//}
//
//// �� �Լ��� ������ ���ƿ��� �ʿ��� �ʱ�ȭ�� �����մϴ�.
//// ���⼭�� ����� ������ �����ϰ� �ʱ�ȭ�մϴ�
//void SetupRC() {
//	// �� ���� ��ǥ
//	GLfloat whiteLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat specular[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat shine[] = { 100.0f };
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);
//
//	// glColor ���� �������� ���� �Ӽ� ����
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//	// �򰡵� ǥ���� ���� ���� ���� �ڵ� ����
//	glEnable(GL_AUTO_NORMAL);
//	// NURBS�� ��ü ����
//	pNurb = gluNewNurbsRenderer();
//	// NURBS�� �Ӽ� ����
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
//	glutPostRedisplay(); // glutDisplayFunc�� ��ϵ� �Լ� ȣ�� (â�� �ٽ� �׷��ش�
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
//	glutMotionFunc(MyMotion); // ���콺 ��ư�� ���� ä�� ������ ���ο��� ������ �� ȣ��
//	glutSpecialFunc(MySpecial); // Ư��Ű
//	SetupRC();
//	glutMainLoop();
//	return 0;
//}