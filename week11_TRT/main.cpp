#include <GL/glut.h>

void hand()
{
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body()
{
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
     glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
        glPopMatrix();
        glutSwapBuffers();
angle+=0.01;
 }
 int main(int argc, char *argv[])///main()主函式 進階版
{
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week11TRT");///開GLUT視窗

    glutDisplayFunc(display);///顯示用的函式
    glutIdleFunc(display);

    glutMainLoop();
 }
