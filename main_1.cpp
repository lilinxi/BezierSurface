#define GLUT_DISABLE_ATEXIT_HACK //防¤¨¤止1GLUT版ã?本À?问¨º题¬a出?错ä¨ª
#include <GLUT/glut.h>
//#include <stdlib.h>
float ctrlpoints[9][3] = {
        { 0,10,0 },
        { 15,10,0 },
        {15,-10,0 },
        { 5,-10,0 },
        { -10,-10,0 },
        { -10,10,0 },
        { 0,10,0 },
        { -5,10,0 },
        { -5,-5,0 }
};
int spin = 0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    //在¨²这a里¤?定¡§义°?Bezier曲¨²线?
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3,4, &ctrlpoints[0][0]);
    //在¨²这a里¤?启?用®?Bezier曲¨²线?
    glEnable(GL_MAP1_VERTEX_3);
}
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //在¨²这a里¤?曲¨²线?插?值¦Ì拟a合?
    glBegin(GL_LINE_STRIP);//(GL_POINTS);
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat) i/30.0);
    glEnd();
    /* The following code displays the control points as dots. */
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3,4, &ctrlpoints[3][0]);
    glBegin(GL_LINE_STRIP);//(GL_POINTS);
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat) i/30.0);
    glEnd();


    glPointSize(5.0);
    glColor3f(1.0, 1.0, 0.0);
    //在¨²这a里¤?绘?出?控?制?点Ì?
    glBegin(GL_POINTS);
    for (i = 0; i < 9; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-20.0, 20.0, -20.0*(GLfloat)h/(GLfloat)w,
                20.0*(GLfloat)h/(GLfloat)w, -20.0, 20.0);
    else
        glOrtho(-20.0*(GLfloat)w/(GLfloat)h,
                20.0*(GLfloat)w/(GLfloat)h, -20.0, 20.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case'd':
            spin = spin + 1;
            glRotatef(spin,1.0,1.0,0.0);
            glutPostRedisplay();
            break;
        case 27:
            break;
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc (keyboard);
    glutMainLoop();
    return 0;
}
//-------------------------代ä¨²码?末?

