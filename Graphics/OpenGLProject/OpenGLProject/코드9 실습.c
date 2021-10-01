//#include <GL/glut.h>
//int window_width = 640;
//int window_height = 480;
//const GLfloat red[] = { 0.8f, 0.0, 0.0, 1.0 };
//const GLfloat blue[] = { 0.0, 0.2f, 1.0, 1.0 };
//const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
//const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
//const GLfloat polished[] = { 100.0 };
//const GLfloat dull[] = { 0.0 };
//const GLfloat light_pos[] = { 0.0, 0.0, 0.0, 1.0 };
//GLfloat move_y = 0.0;
//GLfloat move_z = 0.0;
//GLfloat const_att = 2.5;
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glShadeModel(GL_SMOOTH);
//	glTranslatef(0.0, 0.0, -20.0);
//	glPushMatrix();
//	glTranslatef(0.0, move_y, move_z);
//	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
//	glDisable(GL_LIGHTING);
//	glColor3d(0.9, 0.9, 0.5);
//	glutSolidSphere(0.1, 10, 10);
//	glEnable(GL_LIGHTING);
//	glPopMatrix();
//	glTranslatef(-5.0, 0.0, 0.0);
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
//	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
//	glutSolidSphere(3.0, 40, 40);
//	glTranslatef(10.0, 0.0, 0.0);
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
//	glMaterialfv(GL_FRONT, GL_SHININESS, polished);
//	glutSolidSphere(3.0, 40, 40);
//	glutSwapBuffers();
//	glFlush();
//}
//
//void Mouse_Movement(int x, int y) {
//	move_z = (10.0 * x) / window_width;
//	move_y = 5.0 - (10.0 * y) / window_height;
//	glutPostRedisplay();
//}
//void MyReshape(int w, int h) {
//	window_width = w;
//	window_height = h;
//	glViewport(0, 0, window_width, window_height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(35.0, (window_width) / t(window_height), 1.0, 50.0);
//	glutPostRedisplay();
//}
//void MySpecial(int key, int x, int y) {
//	if (key == GLUT_KEY_LEFT) {
//		const_att *= 0.9f;
//	}
//	else if (key == GLUT_KEY_RIGHT) {
//		const_att /= 0.9f;
//	}
//	glutPostRedisplay();
//}
//
//void MyInit() {
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
//	glEnable(GL_DEPTH_TEST);
//}
//int main(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowSize(window_width, window_height);
//	glutCreateWindow("One Lighting Two Objects");
//	MyInit();
//	glutDisplayFunc(MyDisplay);
//	glutMotionFunc(Mouse_Movement);
//	glutReshapeFunc(MyReshape);
//	glutSpecialFunc(MySpecial);
//	glutMainLoop();
//	return 0;
//}