#include <GL/glut.h>
float angle=0,oldX=0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
 }

 void motion(int x,int y)
 {
    angle += (x-oldX);
    oldX=x;
    display();
 }
  void mouse(int button,int state,int x,int y)
 {

    oldX=x;
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("第04週的程式喔!!");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();
 }
