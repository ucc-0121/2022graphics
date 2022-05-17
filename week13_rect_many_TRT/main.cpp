///week13_rect_many_TRT
#include <GL/glut.h>
float angle[20],oldX=0;
int angleID=0;
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請GLUT重劃畫面
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體

    glPushMatrix();///右半部
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle[0],0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛在身上
            glRotatef(angle[1],0,0,1);///對z軸旋轉
            glTranslatef(-0.7,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
        glPopMatrix();
    glPopMatrix();

        glPushMatrix();///左半部
            glTranslatef(-0.3,0.4,0);///把手臂掛在身上
            glRotatef(angle[2],0,0,1);///對z軸旋轉
            glTranslatef(0.3,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(1,0,0);
            glRectf(-0.3,0.5,-0.7,0.3);///左上手臂

            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///把手臂掛在身上
                glRotatef(angle[3],0,0,1);///對z軸旋轉
                glTranslatef(0.7,-0.4,0);///挑整手臂的旋轉中心
                glColor3f(0,1,0);
                glRectf(-0.7,0.5,-1.0,0.3);///左下手肘
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
