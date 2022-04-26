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
## step03-1.將偷來的程式碼帶入之前教的黃色茶壺
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
## step03-2.在float後面宣告一個angle,使得因為有角度兒可以旋轉
```C
加入程式碼
float x=150,y=150,z=0,scale=1.0,angle=0.0;
glRotatedf(angle,0,1,0);
angle+=(mouseX-oldX)
```
## step04 .透過keyboard來控制要旋轉,移動還縮放
加入的程式碼為
```C
int oldX=0,oldY=0,now=0;///1移動2轉動3縮放
```
```C
 void motion(int mouseX,int mouseY)
 {
     if (now==1)
     {
        x+=(mouseX-oldX); y+=(mouseY-oldY);
     }
     else if(now==2)
     {
         angle+=(mouseX-oldX);
     }
    else if(now==3)
    {
    if(mouseX-oldX>0) scale*=1.01;
    if(mouseX-oldX<0) scale*=0.99;
    }
    oldX=mouseX; oldY=mouseY;
    display();
 }
 ```
 ```C
 void mouse(int button,int state,int mouseX,int mouseY)
 {
    oldX=mouseX; oldY=mouseY;
 }
 void keyboard( unsigned char key,int mouseX,int mouseY)
 {
    if(key=='1'||key=='w'||key=='W') now=1;
    if(key=='2'||key=='e'||key=='E') now=2;
    if(key=='3'||key=='r'||key=='R') now=3;
 }
```
```C
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=0;///1移動2轉動3縮放
 void display()
 {
     glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glRotatef(angle,0,1,0);
        glScalef(scale,scale,scale);
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 void motion(int mouseX,int mouseY)
 {
     if (now==1)
     {
        x+=(mouseX-oldX); y+=(mouseY-oldY);
     }
     else if(now==2)
     {
         angle+=(mouseX-oldX);
     }
    else if(now==3)
    {
    if(mouseX-oldX>0) scale*=1.01;
    if(mouseX-oldX<0) scale*=0.99;
    }
    oldX=mouseX; oldY=mouseY;
    display();
 }
 void mouse(int button,int state,int mouseX,int mouseY)
 {
    oldX=mouseX; oldY=mouseY;
 }
 void keyboard( unsigned char key,int mouseX,int mouseY)
 {
    if(key=='1'||key=='w'||key=='W') now=1;
    if(key=='2'||key=='e'||key=='E') now=2;
    if(key=='3'||key=='r'||key=='R') now=3;
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week06");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
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

```
# Week08 
 ## Step0. 重複上上週的步驟

 ## 0-1 至https://jsyeh.org/3dcg10 下載3個檔案

 ## 0-2 
 ```
     windows.zip =解壓=> 下載\windows\Light Material.exe

     data.zip =解壓=>下載\windows\data\模型.org

     source.zip

    開啟LightMaterial.exe(今日的主角)
 ```

 ## Step1. 複習上週的打光程式，確定大家在家可以執行

##  Step2.實作時間٩(๑❛ᴗ❛๑)۶
```
      2-1-1.Moodle 下載 freeglut....zip

      2-1-2.將桌面freeglut 中的 lib裡面有 libfreeglut.a複製貼在同一資料夾中，

      後將其檔案名稱改成 libglut32.a(是為了能在CodeBlocks中成功開啟檔案!

      2-1-3.從GLUT，source.zip偷程式碼，放入Notepad++

```
  

  ## Step3.了解GLUT範例 sample.cpp 177行做甚麼事
  ```C

  /*

 * GLUT Shapes Demo
 * Written by Nigel Stewart November 2003
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes ar
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
static int slices = 16;
static int stacks = 16;
/* GLUT callback Handlers */
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();
    glutSwapBuffers();
}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case '+':
            slices++;
            stacks++;
            break;
        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }
    glutPostRedisplay();
}
static void idle(void)
{
    glutPostRedisplay();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
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
    return EXIT_SUCCESS;
}
```
```
    GLUT callback?會被GLUT呼叫的函示

    (我們寫的那些display() keyboard() mouse() motion()函示)
```
 ## 期中考題
```C
glPushMatrix();//備份矩陣

  glTranslatef(x,y,z);//移動

  glRotatef(角度,x,y,z);//轉動

  glScalef(x,y,z);//縮放

glPopMatrix();//還原矩陣
```
## 函示呼叫
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
## 函示宣告
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
 ## Step4.拿去上週的程式碼(week06_light)
 ```C
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
 int main(int argc, char *argv[])//main()
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);//
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
 ```
  ## Step 4-1 git 下載你上週的程式
  ```
          git clone 下來 或在你的專案資料夾裡 git pull
          把上週的light檔案在NOTEPAD++裡開啟，複製貼上在WEEK08的main.cpp
          執行時會跑出有光澤的黃色茶壺
```
  ## Step 4-2
  ```
       把 sourse.zip看裡面的3個程式 glm.h glm.c lightmaterial.cpp
       拿裡面的程式來用，便能讀入3D模型
```
## Step4-2-1
```C
   #include <GL/glut.h>//是系統裡的include 裡的檔案
```
```C
   #include "glm.h" //雙引號，同目錄裡的檔案
```
```C
   GLMmodel* pmodel = NULL;//指到GLMmodel模型的指標，NULL表示還沒完成
```
```C
    void
    drawmodel(void)
       {
        if (!pmodel) {
	    pmodel = glmReadOBJ("data/soccerball.obj");
	    if (!pmodel) exit(0);
	    glmUnitize(pmodel);
	    glmFacetNormals(pmodel);
	    glmVertexNormals(pmodel, 90.0);
        }
     glmDraw(pmodel, GLM_SMOOTH);
        }//用來畫3D模型的程式碼，學習他   
``` 
## Step4-2-2
```
   1.用哪一行程式? drawmodel()
   2.檔案在哪裡?要放在working dir工作目錄
   3.在CodeBlocks下方藍色的Build Log說我們的目錄在...
   4.C:\Users\YUXUAN\Desktop\freeglut\bin
   5.把剛剛下載的DATA.zip裡的data資料夾整個放在工作目錄中
   6.把glm.h 和 glm.c(改名成glm.cpp) 放在week08_model目錄中
   7.附檔名要看到才行
   8.在week08_model專案中ADD 剛剛同目錄的glm.cpp
(以上步驟做完會出現一顆黃色足球😭😭😭)
講解各種模型，可以自己改，在把專案saveproject存檔放到GitHub裡
```
# WEEK09貼圖座標
## Step0. 重複上上週的步驟
## 0-1 
```
     至https://jsyeh.org/3dcg10 下載3個檔案
     windows.zip =解壓=> 下載\windows\Texture.exe
     data.zip =解壓=>下載\windows\data\圖檔.org
     source.zip
     開啟Texture.exe(今日的主角)

>>左邊的鉤和叉是頂點 右邊的是貼圖座標<<
```
## Step1.下載OpenCV
```
1-1 open cv 2.1.0 win32 vs2008(最小，安裝最快，可以跨平台，簡單)
1-2 下載後, 安裝有一個特別重要的事:
      不要改目錄 C:\OpenCV2.1等一下設定才會方便
```
## Step2.寫Opencv 可以讀圖和秀圖
```C
2-1 安裝完後要重開CODEBLOCKS因為PATH會改變
2-2 file-NewFile-存成week09_opencv.cpp
#include <opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("檔名.jpg");
    cvShowImage("weel09",img);
    cvWaitKey(0);
}
```
```
2-3 開始設定 (ఠ్ఠ ˓̭ ఠ్ఠ)
2-3-1 設定很困難: Setting-compiler 設定 Include 目錄
2-3-2 設定很困難: Setting-compiler 設定 Lib 目錄
2-3-3 設定很困難: Setting-compiler 設定 Linker 加入
          cv210,  cxcore210, highgui210
2-4 Seach diretories目錄在哪呢(◔ д◔)?
      compiler 的 Include 目錄 C:\opencv2.1\include
                               C:\opencv2.1\lib
成功設置完後就可以跑程式囉~
DOREMESO~٩(●ᴗ●)۶
```
## Step3 結合opencv和opengl
```
3-1 程式碼用剪貼的
3-2 非常複雜        非常簡單
3-3 最簡單的整合:把10行GLUT範例(黃色茶壺那個)+3~5行的opencv讀圖秀圖
3-4 file-new-project,Glut專案 week09_texture
3-5 寫出10行
3-6 加入我們的程式
```
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage*img=cvLoadImage("earth.jpg");
    cvShowImage("opencv",img);
    //cvWaitKey(0);
}
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
    glutCreateWindow("week09Texture");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    myTexture();
    glutMainLoop();
 }  
```
## 實作演練(,,Ծ‸Ծ,, )
```C
從老師那偷取程式碼
https://gist.github.com/jsyeh/5ed01210559721ec71b659b3ffed2dd7
複製前段的程式碼後貼在剛剛的專案裡
BUILD後就好啦~~~
```
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void myTexture()
{
    IplImage*img=cvLoadImage("earth.jpg");
    cvShowImage("opencv",img);
    //cvWaitKey(0);
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);

    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week09Texture");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    myTexture("earth.jpg");
    glutMainLoop();
 }

```
# week10
```
1. 討論: 期中考成績、快篩(缺貨、APP、價錢、Seven)、覺得好累
2. 主題: 上週貼圖+貼到四邊形=背景圖
3. 主題: 上週貼圖+貼到圓球=會轉的地球
4. 主題: 上週貼圖+貼到模型=鋼彈模型
```
## Step0貼圖
```
0-1 安裝freeglut (libglut32.a要有),opencv2.1(Add path)
0-2 File-New-project-GLUT專案week10_texture_background
0-3 把上週Blog裡的Mytexture複製過來
0-4 把上上周的10行GLUT程式碼貼過來
```
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week10Texture");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    myTexture("earth.jpg");
    glutMainLoop();
 }  
 }  
```
## Step1 OPENCV設定
```
1-1 開始設定 (ఠ్ఠ ˓̭ ఠ్ఠ)
1-2 設定很困難: Setting-compiler 設定 Include (目錄C:\opencv2.1\include)
1-3 設定很困難: Setting-compiler 設定 Lib (目錄C:\opencv2.1\lib)
1-4 設定很困難: Setting-compiler 設定 Linker 加入
          cv210,  cxcore210, highgui210
1-5 Seach diretories目錄在哪呢(◔ д◔)?
我的位置:C:\Users\YUXUAN\Desktop\freeglut\bin(圖片也要放在這裡喔!)
成功設置完後就可以跑程式囉~
DOREMESO~٩(●ᴗ●)۶
```
## Step02 
```C
接下來我們利用期中考考的glBegin(GL_POLYGON)開始畫及glEnd()結束畫，
中間夾4行glTexCoord2f(tx,ty)及glVertex2f(x,y)來把背景貼圖做出來
glBegin(GL_POLYGON);
    glTexCoord2f(tx,ty); glVertex2f(x,y);//要有四次，前面是貼圖座標,後面是4個頂點
glEnd();
```
