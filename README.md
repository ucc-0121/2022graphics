# 2022graphics
# week01滴上課筆記爹斯 
## 第一個OPENGL程式
```
0.將CodeBlocks mingw 17.12安裝好

1.File - New - Project，選OPENGL專案




2.在[...]的目錄，選「桌面」，Projectsje 名稱 week01_OPENGL


3.下一步 下一步，完成後，Build&Run
                            
4.可以看到彩色旋轉的三角形!
```



## 第一個GLUT專案
```
1.Moodle 下載 freeglut....zip

2.解壓縮至桌面 freeglut目錄

3.將桌面freeglut 中的 lib裡面有 libfreeglut.a複製貼在同一資料夾中，
   後將其檔案名稱改成libglut32.a
   (是為了能在CodeBlocks中成功開啟檔案!



4.CodeBlock: file - New - Project，選擇GLUT專案

5.取名為week01_GLUT



6.設定GLUT目錄 C:\Users\XXX\Desktop\freeglut


7.Build & Run ,會看到六個圖形在轉動!

```

## GitHub備份程式
```
0.登入Github.com
1.New repo 新增專案倉庫
1.1 取名為2022graphics
1.2.Public，Add READNE，
                    Add .gitignore用C++



1.3按綠色確認，看到你的新的專案倉庫
2.利用Git 指令
2.1.安裝Git for windows

3. 利用 Git指令下載
3.0. 安裝 Git for Windows
3.1. 開啟 Git Bash
3.2. cd desktop 進入桌面
3.2. git clone https://你的倉庫網址
3.3. 查看 桌面,多了 2022graphics 目錄
3.4. 把今天的程式 複製到 剛剛目錄

4. 把修改的資料, 推送到雲端
4.1. cd 2022graphics 進入你的倉庫
4.2. git status 看你的狀況(紅的,多了目錄)
4.3. git add . 把檔案加進帳冊
4.4. git status 再看一次(綠的)
                
這裡要加入
git config --global user.email "yuxuan910121@gmail.com"
git config --global user.name "yuxuan"
git commit -m "add week01"

4.5要 git push上雲端!
PS. Chrome記得再登入哦~

成功上傳><
```




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
# Week03

## 先做跟上禮拜一樣的步驟
```
1.至https://jsyeh.org/3dcg10

   下載data.zip windows.zip 

1-2.windows.zip =解壓=> 下載\windows\Transformation.exe

  data.zip =解壓=>下載\windows\data\模型.org



  1-3.執行Transformation.exe
    (右下角)點擊右鍵:可以更換其他模型



    (下方)拖曳綠色的數值:可以上下、左右、前後移動
     



```
## 我們要透過上週的茶壺程式進行變更
```
(如果沒有程式碼的可以複製這裡~)
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
 ```
 ```
2-1.這次要做的是移動，所以再加上幾段程式碼
    


   PS.畫上螢光筆的部分分別是
         glPushMatrix();//備份矩陣
         glTranslatef(0.5,0.5,0);//右上角升
         glPopMatrix();//還原矩陣

2-2.為了更有效的做出程式 所以我們宣告了一個函式(紅色框框)


2-3.將剛剛的程式碼複製後貼上在新開的GLUT專案
      

  (透過glutMouseFunc()就可以使用滑鼠點擊感變物件位置~)
程式碼的部分~

#include <GL/glut.h>
float mouseX=0,mouseY=0;
void myTeapot(float x,float y)
{
    glPushMatrix();//備份矩陣
        glTranslatef(x,y,0);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();//還原矩陣
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0,-(mouseY-150)/150.0);
    glutSwapBuffers();
 }
 void mouse(int button,int state,int x,int y)
 {
    mouseX=x;mouseY=y;
 }
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
 }
```
2-4.每點擊一次可以得到座標位置



程式碼兒~
#include <GL/glut.h>
#include <stdio.h>
float mouseX=0,mouseY=0;
void myTeapot(float x,float y)
{
    glPushMatrix();//備份矩陣
        glTranslatef(x,y,0);
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();//還原矩陣
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0,-(mouseY-150)/150.0);
    glutSwapBuffers();
 }
 void mouse(int button,int state,int x,int y)
 {
     printf("%d %d %d %d\n",button,state,x,y);
    mouseX=x;mouseY=y;
 }
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
 }

```



