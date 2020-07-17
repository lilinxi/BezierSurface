#include <GLUT/glut.h>
#include <ctime>
#include <iostream>

using namespace std;

GLfloat ctrlpoints[4][4][3] = {
	{{-3, 0, 4.0}, {-2, 0, 2.0}, {-1, 0, 0.0}, {0, 0, 2.0}}, {{-3, 1, 1.0}, {-2, 1, 3.0}, {-1, 1, 6.0}, {0, 1, -1.0}}, {{-3, 2, 4.0}, {-2, 2, 0.0}, {-1, 2, 3.0}, {0, 2, 4.0}}, {{-3, 3, 0.0}, {-2, 3, 0.0}, {-1, 3, 0.0}, {0, 3, 0.0}} };
void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix ();
	glRotatef(45.0, 1.0, 1.0, 1.0);

	//´ò¿ª¿¹¾â³Ý¹¦ÄÜ
		   //1.¿ªÆô»ìºÏ¹¦ÄÜ
	glEnable(GL_BLEND);

	//2.Ö¸¶¨»ìºÏÒò×Ó
	//×¢Òâ:Èç¹ûÄãÐÞ¸ÄÁË»ìºÏ·½³ÌÊ½,µ±ÄãÊ¹ÓÃ»ìºÏ¿¹¾â³Ý¹¦ÄÜÊ±,ÇëÒ»¶¨Òª¸ÄÎªÄ¬ÈÏ»ìºÏ·½³ÌÊ½
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//3.¿ªÆô¶Ôµã\Ïß\¶à±ßÐÎµÄ¿¹¾â³Ý¹¦ÄÜ
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	double duration;
	clock_t start, finish;

	start = clock();

	for (j = 0; j <= 40; j++) {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 40; i++)
			glEvalCoord2f((GLfloat)i/40.0, (GLfloat)j/40.0); //µ÷ÓÃÇóÖµÆ÷
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 40; i++)
			glEvalCoord2f((GLfloat)j/40.0, (GLfloat)i/40.0); //µ÷ÓÃÇóÖµÆ÷
		glEnd();
	}

	finish = clock();
	duration = (double)(finish - start);
	cout<<"»æÖÆÊ±¼ä µ¥Î»£ºmsec\n"<<duration<<endl;


	//¹Ø±Õ¿¹¾â³Ý¹¦ÄÜ
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_POLYGON_SMOOTH);
	glPopMatrix ();
	glFlush();
}
void init(void) {
	glClearColor (0.92, 0.92, 0.92, 0.0); //ÏÂÐÐµÄ´úÂëÓÃ¿ØÖÆµã¶¨ÒåBezierÇúÃæº¯Êý
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3); //¼¤»î¸ÃÇúÃæº¯Êý
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); //¹¹ÔìÆ½ÐÐÍ¶Ó°¾ØÕó
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 500);
	glutInitWindowPosition (60, 60);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
