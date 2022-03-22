#include <GL/glut.h>
#include <stdio.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);

    glutSwapBuffers();
 }
 void keyboard( unsigned char key,int x,int y)
 {
    printf("你按下了%c 在%d %d座標\n",key,x,y);
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week05");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glutKeyboardFunc(keyboard);
    glutMainLoop();
 }
