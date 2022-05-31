///week15�ק��week14_angles_fprintf
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include "glm.h"
#include <stdio.h>
GLMmodel * pmodel=NULL;
GLMmodel * body=NULL;
GLMmodel * head=NULL;
GLMmodel * arm1=NULL;
GLMmodel * arm2=NULL;
float angle[20],oldX=0;
int angleID=0;
FILE * fout=NULL, * fin = NULL;
void myWrite()
{///�C�I�s�@��myWrite
    if(fout == NULL)fout=fopen("file.txt","w+");

    for(int i = 0;i<20;i++)
    {
        printf("%.1f ",angle[i]);///�p�¦L�X��
        fprintf(fout,"%.1f ",angle[i]);///�ɮצL�X��
    }///�o�̦Ѯv�S��fclose
    printf("\n");///�p�¦L�X����
    fprintf(fout,"\n");///�ɮ׸���
}
void myRead()
{
    if(fout!=NULL){fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///�����e��
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='s') myWrite();///�զn�ʧ@�~save�s��
    if(key=='r') myRead();
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
    ///myWrite();
    oldX=x;
    glutPostRedisplay();
}
GLMmodel * myReadone(char * filename)
{
    if(one==NULL)
    {
        one=glmReadOBJ("data/body.obj");
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one,90);
    }
    return one;
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glColor3f(1,1,1);
    ///glRectf(0.3,0.5,-0.3,-0.5);
    if (body==NULL) body=myReadOne("data/body.obj");
    glmDraw(body,GLM_TEXTURE|GLM_SMOOTH);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        ///glColor3f(1,0,0);
        ///glRectf(0.3,0.5,0.7,0.3);
        if (arm1==NULL) body=myReadOne("data/arm1.obj");
        glmDraw(arm1,GLM_TEXTURE|GLM_SMOOTH);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            ///glColor3f(0,1,0);
            ///glRectf(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.3,0.4,0);
            glRotatef(angle[2],0,0,1);
            glTranslatef(0.3,-0.4,0);
            ///glColor3f(1,0,0);
            ///glRectf(-0.3,0.5,-0.7,0.3);

            glPushMatrix();
                glTranslatef(-0.7,0.4,0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(0.7,-0.4,0);
                ///glColor3f(0,1,0);
                ///glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15_HW4");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
 }

