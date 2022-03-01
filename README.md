# 2022graphics
# week02滴上課筆記爹斯 
## step01 跑別人的範例
```
1.至https://jsyeh.org/3dcg10下載

    data.zip  windows.zip glut32.dll

2.windows.zip =解壓=> 下載\windows\Shapes.exe

    data.zip =解壓=>下載\windows\data\模型

    glut32.dll =複製=>下載\windows\glut32.dll

3.開啟Shapes.exe看看範例，試試看

    在左邊圖案按右鍵選單:放大縮小頂點、選各種顏色

    在右邊圖案按右鍵選單:ponit.....polygon
```


## step02-1 跑自己上週的程式
```
1.安裝 上週安裝過的Git for Windows
2.開啟安裝完的的git bash: cd desktop>git clone (自己GITHUB的網址)>cd 2022graphics
3.安裝上周的freeglut到桌面，將freeglut\lib中的libfreeglut.a檔案複製貼上後重新命名為libglut32.a

4.開啟CodeBlocks File->Open week01_GLUT專案後，跑動它!

成功Again ʚ(•”̮•)ɞ
```
## step02-2 做一個自己的GLUT專案
```
1.File->New->Project->選擇GLUT檔案
   檔名:week02_COLOR
是這個圖式喔!!不要選錯了 (ᗒᗣᗕ)՞
2.程式撰寫

 #include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);

    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("第02週的程式喔!!");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

3.打完後案Build就會得出一個黃色的實心茶壺呦(●’ω`●）
```

## step3模仿windows.zip 中的Shapes
```
1.將上面step2-2中的程式做點修改
   (把原先打Teapot的那行註解後打上程式
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);//紅色
        glVertex2f(-1,-1);

        glColor3f(0,1,0);//綠色
        glVertex2f(+1,-1);

        glColor3f(0,0,1);//藍色
        glVertex2f(0,+1);

    glEnd();
2.就可以完成一個類似的三角形拉(灑花✧*｡٩(ˊᗜˋ*)و
```
