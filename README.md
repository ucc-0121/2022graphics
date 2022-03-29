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
```
## git hub貼上程式碼的網頁
>>gist.github.com
要記得登入自己的帳號密碼!
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
```C
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
```C
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
```C
1.至https://jsyeh.org/3dcg10

   下載data.zip windows.zip 

1-2.windows.zip =解壓=> 下載\windows\Transformation.exe

  data.zip =解壓=>下載\windows\data\模型.org



  1-3.執行Transformation.exe
    (右下角)點擊右鍵:可以更換其他模型



    (下方)拖曳綠色的數值:可以上下、左右、前後移動
     
我們要透過上週的茶壺程式進行變更
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
```      

  (透過glutMouseFunc()就可以使用滑鼠點擊感變物件位置~)
程式碼的部分~
```C
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
```C
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
 # WEEK04今日主題:Rotate旋轉
 ## 1-1
```
1.至https://jsyeh.org/3dcg10下載
    data.zip windows.zip
2.windows.zip =解壓=> 下載\windows\Transformation.exe
    data.zip =解壓=>下載\windows\data\一堆模型
```
## 1-2
```
旋轉動作1:
Ps.當y軸都為1時，以y軸為中心向右旋轉

旋轉動作2:
ps.當x,y軸都為1時，以xy的中間值為中心向右下角旋轉

旋轉動作3:
ps.當x軸為1時，以ｘ軸為中心向前方旋轉
```
## 1-3用CodeBlocks開啟新專案 :week04_Rotate
```C
可以做出一個可以政著旋轉的茶壺~

///此刻的程式碼
#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,0,0,1);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("第04週的程式喔!!");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
```
## 1-4使用MOUSE_MOTION功能
```C
其實就是加上這些程式碼
void motion(int x,int y)
 {
    angle = x;
    display();
 }
 glutMotionFunc(motion);
```
## 1-5這次是將每次點及得舊的x定為中心後旋轉
```C
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
```
# week05
```
>今日介紹 電腦圖學之父Ivan Sutherland --Sketchpad<
  step0-1 windows.zip =解壓=> 下載\windows\Transformation.exe
               data.zip =解壓=>下載\windows\data\模型.org
```
 ## step1-1 在CODEBLOCKS上開啟新專案在過去的程式碼(茶壺)貼上進行修改
         在MAIN裡建立一個glutKeyboardFunc(keyboard)函式

                 做完後可以看到每按一次鍵盤會跳出滑鼠所在的座標      
## step2-1  多加一些函示，使得茶壺可以透過滑鼠拖曳
```
<<char範圍:-128~128>>
   <<unsigned:不要加上負號，使得數字範圍從0~255>> 
<<callback函式:
 glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
>>
```

 ## step3-1 結合前面教的mouse和motion函示
         將floatX,y數值進行改變，將程式更優化(圖案不卡頓)
(目前程式碼)
```C
#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0;
int oldX=0,oldY=0;
 void display()
 {
     glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 void motion(int mouseX,int mouseY)
 {
    x+=(mouseX-oldX); y+=(mouseY-oldY);
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
```
## step4-1透過SCALE的X值來拉大拉小茶壺大小
```C
            加入程式碼<<scale=1.0;
            if(mouseX-oldX>0) scale*=1.01;
            if(mouseX-oldX<0) scale*=0.99;
```
```C
>最終程式碼<
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
```
# week06 主題: 打光
## step01.與重複上週步驟:
```C
1-1至https://jsyeh.org/3dcg10(下載data.zip windows.zip )

1-2.windows.zip =解壓=> 下載\windows\Light Material.exe

    data.zip =解壓=>下載\windows\data\模型.org

(左上)左鍵drg可以旋轉  (左上)右鍵可以換模型 (左下)右鍵可以換Material
```
## step02. 解釋光的性質 glLightfv(GL_LIGHT,GL_POSITION,陣列)
```C
LIGHT=>第幾個燈

POSITION=>設定燈的位置

gl=>使用opengl  ,   fv=> float vector(陣列)

GLflaot light_pos[]={-2.0,2.0,2.0,1.0};陣列
```
```
實作時間٩(๑❛ᴗ❛๑)۶

2-1-1.Moodle 下載 freeglut....zip

2-1-2.將桌面freeglut 中的 lib裡面有 libfreeglut.a複製貼在同一資料夾中，後將其檔案名稱改成libglut32.a

(是為了能在CodeBlocks中成功開啟檔案!

2-1-3.從GLUT偷程式碼(透過CRTL+F查找LIGHT函式)<=有陣列宣告和函示呼叫
```
### 函式呼叫
```C

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
```
### 函式宣告
```C
 glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

```
## step03.將偷來的程式碼帶入之前教的黃色茶壺
```C
目前進度程式碼:
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
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
    glutCreateWindow("week06 light");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
 }



 (秀出了帶有光澤的茶壺醬 ♫.(◕∠◕).♫)

```


