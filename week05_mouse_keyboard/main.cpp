#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
 void display()
 {
     glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glScalef(scale,scale,scale);
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 void motion(int mouseX,int mouseY)
 {
    if(mouseX-oldX>0) scale*=1.01;
    if(mouseX-oldX<0) scale*=0.99;
    //x+=(mouseX-oldX); y+=(mouseY-oldY);
    oldX=mouseX; oldY=mouseY;
    display();
 }
 void mouse(int button,int state,int mouseX,int mouseY)
 {
    oldX=mouseX; oldY=mouseY;
 }
 void keyboard( unsigned char key,int mouseX,int mouseY)
 {

 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week05");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
 }
