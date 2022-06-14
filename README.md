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

4.6 git pull是把雲端拉下來到你的硬碟倉庫(先PULL再)
4.6.1 start . 可以開啟現在的目錄 就可以複製貼上你的程式
4.6.2 再重複git status 那段

再重新git pus
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
<加在display裡>
```
## Step03 主題: 上週貼圖+貼到圓球=會轉的地球
```C
3-1 File-New-Project-GLUT專案,week10_texture_earth
3-2 Q:圓球怎麼畫?A:圓球的3D座標和2D的貼圖座標要用cos(),sin()算出來
3-3 GLUquadric * sphere = NULL;//指標,指到2次曲面
3-4 在main()sphere=gluNewQuadric();//準備好2次曲面
3-5 在display() gluQuadricTexture(sphere,1);///設好貼圖
3-6 在display() gluSphere(sphere,1,30,30);///畫圓球
gluSphere(一個指標,R半徑,slices,stacks);
gluSphere(sphere     ,    1     ,  30   ,   30   );
-OpenGL(GL)的函式 ex.glVertex2f();
-OpenGL Utillies(GLU)的函式 ex.gluSphere();
-OpenGL User Toolkit(GLUT)的函式 ex.glutSolidTeapot();
```
## 目前的程式碼
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
GLUquadric * sphere = NULL;///指標,指到2次曲面
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
    gluQuadricTexture(sphere,1);
    gluSphere(sphere,1,30,30);
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])///main()主函式 進階版
 {
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week10texturebackground");///開GLUT視窗

    glutDisplayFunc(display);///顯示用的函式
    myTexture("earth.jpg");
    sphere=gluNewQuadric();///準備好2次曲面
    glutMainLoop();
 }

```
## Step04 轉把轉吧七彩霓虹燈
```C
在display函式裡加入些許程式碼
void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere,1);
        gluSphere(sphere,1,30,30);
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01;///每執行一次DISPLAY加一度
 }
 ```
## 實作時間 (ᗒᗣᗕ)՞
```C
再加入修改一些程式碼讓他正轉&&看起來式3D的!
        glRotatef(90,1,0,0);///正轉，對X軸旋轉
        glEnable(GL_DEPTH_TEST);///3D跑圖
```
## Step05 主題: 上週貼圖+貼到模型=鋼彈模型
```
5-1 至https://jsyeh.org/3dcg10 下載3個檔案
windows.zip =解壓
data.zip =解壓
source.zip
5-2 下載老師買的鋼彈模型
5-3 File-New-Project-GLUT專案 week10_texture_model
5-4 在C:\Users\YUXUAN\Desktop\freeglut\bin 放入鋼彈的模型DATA
5-5 把source裡的glm.h 和glm.cpp放在專案目錄裡,main.cpp的旁邊
```
鋼彈程式
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel=NULL;
///GLUquadric * sphere = NULL;///指標,指到2次曲面
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
float angle=0;///旋轉角度
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,1,0);
        if(pmodel==NULL)
        {
            pmodel=glmReadOBJ("data/Gundam.obj");
            glmUnitize(pmodel);
            glmFacetNormals(pmodel);
            glmVertexNormals(pmodel,90);
        }
        glmDraw(pmodel,GLM_TEXTURE);
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01;
 }
 int main(int argc, char *argv[])///main()主函式 進階版
 {
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week10texturebackground");///開GLUT視窗

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);///顯示用的函式
    glutIdleFunc(display);
    myTexture("data/Diffuse.jpg");
    ///myTexture("earth.jpg");
    ///sphere=gluNewQuadric();///準備好2次曲面
    glutMainLoop();
 }
```
```
一定要記的在旁邊新增glm.cpp
不然找不到東西😢😢😢
```
# WEEK11
##  電腦圖學 Week11 2022-05-02
```
1. 主題: 持續實作 glm 模型相關練習
2. 主題: 利用 Maya 切割模型
3. 主題: 對(特定)旋轉軸轉動(下週作業&下下週考試)
   組合技: T移動、R旋轉、T移動
```
## Step0持續實作glm模型相關練習
```
0-1 安裝freeglut (libglut32.a要有)
0-2 安裝opencv2.1(Add path)
0-3 Setting-compiler 設定 Include (目錄C:\opencv2.1\include)
0-4 Setting-compiler 設定 Lib (目錄C:\opencv2.1\lib)
0-5 Setting-compiler 設定 Linker 加入
          cv210, cxcore210, highgui210
0-6 Seach diretories目錄在哪呢(◔ д◔)?
        我的位置:C:\Users\YUXUAN\Desktop\freeglut\bin(圖片也要放在這裡喔!
        成功設置完後就可以跑程式囉~
```	
## Step01上週貼圖+貼到模型=鋼彈模型
```
1-1 File-New-Project-GLUT專案,week11_gundam(gundam.zip裡的DATA放在freeglut裡面)
1-2  把source裡的glm.h 和glm.c(改成.cpp)放在專案目錄裡
1-3  把glm.cpp用Add file的方式加入進main.cpp旁邊
1-4  讀進模型進茶壺
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
    glutCreateWindow("week11Texture");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    myTexture("data/Diffuse.jpg");
    glutMainLoop();
 }
```

## Step02 持續實作 glm 模型相關練習
```C
2-1 在https://jsyeh.org/3dcg10/裡下載source.zip 
2-2  取得glm.h 和glm.c改成.cpp 和 transformation.c
2-3 把glm.cpp用Add file的方式加入進main.cpp旁邊                 
                            (一定要記得加很有可能就是少這步鋼彈才出不來( ͒˃⌂˂ ͒))
2-4 從transformation.c參考並加入程式碼
2-5 main.cpp加入兩行程式碼
#include "glm.h"
GLMmodel * pmodel=NULL;
2-6 display()加入好幾行
```
## 2-7 最終程式碼
```C
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel=NULL;
///GLUquadric * sphere = NULL;///指標,指到2次曲面
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
float angle=0;///旋轉角度
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,1,0);
        if(pmodel==NULL)///如果是空指標 表示模型還沒準備好
        {
            pmodel=glmReadOBJ("data/Gundam.obj");///讀模型
            glmUnitize(pmodel);///換算成unit單位大小
            glmFacetNormals(pmodel);///重新計算模型的面的法向量
            glmVertexNormals(pmodel,90);///重新計算模型頂點的法向量
        }
        glmDraw(pmodel,GLM_TEXTURE);///有模型後畫面要記得畫貼圖
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01;
 }
 int main(int argc, char *argv[])///main()主函式 進階版
 {
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week11_gundam");///開GLUT視窗

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);///顯示用的函式
    glutIdleFunc(display);
    myTexture("data/Diffuse.jpg");
    ///myTexture("earth.jpg");
    ///sphere=gluNewQuadric();///準備好2次曲面
    glutMainLoop();
 }
DoReMeSo~~ ʕ •̀ o •́ ʔ
```
## 今天做到一半的實作
```C
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
```
 

# Week12
```
電腦圖學 Week12 2022-05-10
1. 主題: T-R-T (移動、旋輚、移動)對特定軸轉動
2. 作業: T-R-T 
3. 下週考試: T-R-T 對特定軸轉動
```
## step01-1 課本範例 看Transfromation.exe的變化
```
1.至https://jsyeh.org/3dcg10下載 data.zip windows.zip
2.windows.zip =解壓=> 下載\windows\Transfromation.exe
3.data.zip =解壓=>下載\windows\data\模型
4.重點在: 有T移動、有R轉動，按右鍵Swap交換T R
5.glTranslatef( 0.9 , 0.0 , 0.0 );移動
6.glrotatef(角度,0,1,0);旋轉
```
## 在右邊轉動的藍色車子
```C
glTranslatef( 0.9 , 0.0 , 0.0 );移動在右邊
glrotatef(角度,0,1,0);旋轉
畫一台藍色的車子
```

## 繞著中間轉彎的車子
```C
glrotatef(角度,0,1,0);旋轉
glTranslatef( 0.9 , 0.0 , 0.0 );移動在右邊
```


## step01-2 用另一程式來理解: OpenGL T-R-T函式: 對特定軸轉動練習
```
1.120.125.80.50/GL (小心! 不安全,繼續)期中考、小考題
2.(右下角)點ToDraw, 右邊黑色可以畫圖
3.Ctrl-R Reload可以清空
4.可以畫個身體 叫 MyDrawObject(0)
5.可以畫個手臂 叫 MyDrawObject(1)
6.可以改程式碼的順序
7.可以按 angle= 再按空白鍵 會自動改變成動畫
```
```C
glPushMatrix();
    glRotatef(angle,0,0,1)
    myDrawObject(1);///畫手臂
glPopMatrix();
```
## Step02-1 再剛剛的網頁加新功能，讓手臂揮手身體不動
```
1.點glTranslatef()變紅色後，就可以移動左邊黑色框框裡手臂位置
2.把另一個glTranslatef()放在glrotatef()的下面、手臂的上面
3.把另一個glTranslatef()放在glrotatef()的上面
```
## 透過下面程式碼可以發現，手臂很神奇的長在肚臍的地方且旋轉
```C
glPushMatrix();
    myDrawObject(0);///畫身體
    glRotatef(angle,0,0,1);//這個旋轉會轉下面整個東西
    glTranslatef(-0.25,-0.18,0);//往左下方移動(讓軸心放世界的中心)
    myDrawObject(1);///畫手臂(右上方)
glPopMatrix();
```

## 把上面的T擺好，掛到身體的右上角
```C
myDrawObject(0);///畫身體
glPushMatrix();
    glTranslatef(0.24,0.28,0);//往右上方移動(掛在身體右上方)
    glRotatef(angle,0,0,1);//這個旋轉會轉下面整個東西
    glTranslatef(-0.3,-0.19,0);//往左下方移動(讓軸心放世界的中心)
    myDrawObject(1);///畫手臂(右上方)
glPopMatrix();
```

## Step02-2 老師在講解下禮拜考試題目(類似這種)
```
glPushMatrix();
    glTranslatef(0.29,0.31,0);//往右上方移動(掛在身體右上方)
    glRotatef(angle,0,0,1);//這個旋轉會轉下面整個東西
    glTranslatef(-0.3,-0.19,0);//往左下方移動(讓軸心放世界的中心)
    myDrawObject(1);///畫手臂(右上方)
glPopMatrix();
```

## Step02-3實作時間ಥ⌣ಥ(從今天和之前的筆記剪貼)
```
1.File-New-Project-GLUT專案,week12_TRT
2.把10行程式碼放上去//之前的筆記
3.把TRT的六行程式碼放上去//今天的筆記
4.在讓她自己旋轉 float angle=0;配上
5.再配上glRotatef(angle, 0,0,1);
6.再angle++;//因為電腦跑比較快所以我用+=0.01
7.glutIdleFunc(display);//上週筆記
```
## Step03-1 做出茶壺超人(?有白色的身體,有紅色的手臂,利用TRT讓手臂再任意軸轉動
```C
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);
     glPushMatrix();
        glTranslatef(0.2,0,0);///(3)掛到右邊(整個往動)
        glRotatef(angle, 0,0,1);///(2)旋轉
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺，當作小手臂
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.01; ///每次執行 display() 加1度
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## Step03-2 用來寫回家作業(手臂手軸絕對不能斷!)
```
1.要有3D模型(要有身體，上手臂，下手軸)
2.要用TRT做出來
3.做出來左右兩邊的手臂手肘
4.左手臂手肘可以透過複製右邊的手臂手肘後加上負號
```
```C
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///茶壺當身體

     glPushMatrix();///右邊的手臂手肘
        glTranslatef(0.2,0,0);///(3)掛到右邊(整個往動)
        glRotatef(angle, 0,0,1);///(2)旋轉
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺，當作小手臂
        glPushMatrix();
            glTranslatef(0.2,0,0);///(3)掛到右邊(整個往動)
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///小茶壺，當作小手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左邊的手臂手肘
        glTranslatef(-0.2,0,0);///(3)掛到左邊(整個往動)
        glRotatef(-angle, 0,0,1);///(2)旋轉
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺，當作小手臂
        glPushMatrix();
            glTranslatef(-0.2,0,0);///(3)掛到左邊(整個往動)
            glRotatef(-angle, 0,0,1);///(2)旋轉
            glTranslatef(-0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///小茶壺，當作小手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.01; ///每次執行 display() 加1度
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
 ## 電腦圖學 Week13 2022-05-17
```
1. 示範複習作業/考試的 TRT(實際例子)
2. TRT 的R角度
3. 利用 keyboard/mouse 來改變
4. 如何轉正模型、如何調整模型大小
```
## step01-1 glRectf(x1,y1,x2,y2)方塊
```
1.File-new-Project專案-week13_rect_TRT
2.貼上GLUT的10行程式碼,不用茶壺
```
## 正方形的程式碼
```C
#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRectf(0.3,0.5,-0.3,-0.5);

    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

```

## step01-2 把手加上去而且可以旋轉!
```
1.另一個小方塊，且加上色彩
2.準備好TRT程式碼
```
## 加上小手臂
```C
#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        ///glTranslatef(x,y,z);///把手臂掛在身上
        ///glRotatef(angle,0,0,1);///對z軸旋轉
        ///glTranslatef(x2,y2,z2);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
```

## step01-3 把旋轉中心放在正中心
## 移動小手臂
```C
1.把(0.3,0.4)移到(0,0)=>glTranslatef(-0.3,-0.4,0);
```

## 轉動45度角
```C
加上
float angle=45;
glRotatef(angle,0,0,1);
可以旋轉45度~
```

## 把手移回原處
```C
glTranslatef(0.3,0.4,0);
```


## 調整步驟(目前結果)
```
1. 先調整最下面的Translate改變中心點
2.改變Rotate數值改變旋轉角度
3.最後調整最上面的Translate將手臂位置移回原處
```
```C
#include <GL/glut.h>
float angle=45;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

```
## step02-1 裡用Mouse motion來改變手臂的旋轉角度
```C
1.為了能使用滑鼠控制加上Mouse和Motion
2.用glutPostRedisplay();來重新畫出視窗
3.最後加上 glutMouseFunc(mouse);
                    glutMotionFunc(motion);來函式呼叫
```
## 目前程式碼
```C
#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請GLUT重劃畫面
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
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
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
```

##  step02-2 要開新專案 week13_rect_TRT_TRT做出更多關節
```
1.File-New-Project-GLUT專案-week13_rect_TRT_TRT
2.把前面程式拿來用
3.要新增的地方是第二個手臂的關節
```
## 第二個手臂關節的部分~
```C
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請GLUT重劃畫面
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            ///glTranslatef(0.3,0.4,0);///把手臂掛在身上
            ///glRotatef(angle,0,0,1);///對z軸旋轉
            ////glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
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
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

```

## 把手肘掛在肚臍
```C
1.把第21行註解
2.執行程式可以發現只有綠色手臂在旋轉
glPushMatrix();
            ///glTranslatef(0.3,0.4,0);///把手臂掛在身上
            glRotatef(angle,0,0,1);///對z軸旋轉
            glTranslatef(-0.7,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
glPopMatrix();
```
## 掛回原處
```
1.將數值改成glTranslatef(0.7,0.4,0);///把手臂掛在身上
2.把剛剛註解的部分取消
3.可以看到手臂和手肘成功連接一起旋轉
```
```C
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請GLUT重劃畫面
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛在身上
            glRotatef(angle,0,0,1);///對z軸旋轉
            glTranslatef(-0.7,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
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
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

```
## step03-1 複製出左半部分手臂手肘
```
1.File-New-Project-GLUT專案-week13_rect_many_TRT
2.複製剛剛的程式碼
3.在把剛剛右半部手臂手肘複製貼上
4.透過鏡射原理改變x值(正負值顛倒)=>(變到左邊去)
```
## 雙手臂
```C
///week13_rect_many_TRT
#include <GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
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
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛在身上
            glRotatef(angle,0,0,1);///對z軸旋轉
            glTranslatef(-0.7,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
        glPopMatrix();
    glPopMatrix();

        glPushMatrix();///左半部
            glTranslatef(-0.3,0.4,0);///把手臂掛在身上
            glRotatef(angle,0,0,1);///對z軸旋轉
            glTranslatef(0.3,-0.4,0);///挑整手臂的旋轉中心
            glColor3f(1,0,0);
            glRectf(-0.3,0.5,-0.7,0.3);///左上手臂

            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///把手臂掛在身上
                glRotatef(angle,0,0,1);///對z軸旋轉
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
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }

```
## step03-2 如果只有一個角度，就不會有其他變化
```C
1.要有多少角度呢?? =>每個關節要分別有兩個軸向=>總共20個
   =>float angle=0改成float angle[20](全部的角度都要改)
2.多關節用keyboard 切換
```
## 加入哪些程式碼
### 透過鍵盤的輸入控制要用滑鼠改變的關節
```C
float angle[20],oldX=0;
int angleID=0;
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}

```
## 調整角度的地方
```C
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
```
## 宣告的地方(在main裡加上)
```C
glutKeyboardFunc(keyboard);
```
#  Week14
```
電腦圖學 Week14 2022-05-24
1. 寫檔、讀檔
2. 關節、做動畫
3. 計時器 glutTimerFunc(時間, timer, 參數t)
4. 播放聲音
```
## step01-1寫檔 File Output (紀錄)
```C
0.File-New-Empty File-存檔到week14-1_fprintf目錄裡的week14-1.cpp
1.fopen() 開啟檔案
2.printf()   =>  fprintf()
3.fclose(fout) 關閉檔案
```

## step01-2 讀檔 File Input
## 貼心小提醒d(`･∀･)b
```
在做scanf()時,讀檔的位置要記得加個&才能讀到檔呦
```
```C
0.File-New-Empty File-存檔到week14-2_fprintf_fscanf 目錄裡的 week14-2.cpp
1.把剛剛的week14-1拿來用
2.另外一組 FILE * fin = fopen("檔名","r");
3.scanf ()   =>    fscanf()
4.fclose(fin)
```


## step01-3 把上週的week13_rect_many_TRT 拿來改
```C
0. File-New-Project-GLUT專案->week14_angles_fprintf
1.貼上上週的最後程式
2.新增些許程式碼 printf("%.1f",angle[i]);///小黑印出來
3.                             fprintf(fout,"%.1f",angle[i]);///檔案印出來
4.以上是存檔和讀檔                                
```
目前加上的程式碼
```
///week14_angles_fprintf
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE * fout=NULL;
void myWrite()
{
    if(fout == NULL)fout=fopen("file.txt","w+");

    for(int i = 0;i<20;i++)
    {
        printf("%.1f",angle[i]);///小黑印出來
        fprintf(fout,"%.1f",angle[i]);///檔案印出來
    }///這裡老師沒有fclose
}
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
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
```
## step 02-1 做動畫囉~
```
0.File-New-Project-GLUT專案->week14_angles_fprintf_fscanf
1.copy前一個版本的程式進行修改
2.要寫void myRead()
3.在keyboard()裡 按下'r' 可以呼叫 myRead()
>>這裡R要一直按著!!!只是因為鍵盤的關西，重播會跑很慢
>>fout 那的printf和fprintf裡的跳行要記得空格，不然會發生錯誤!!
```
```C
///week14_angles_fprintf
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE * fout=NULL, * fin = NULL;
void myWrite()
{///每呼叫一次myWrite
    if(fout == NULL)fout=fopen("file.txt","w+");

    for(int i = 0;i<20;i++)
    {
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout,"%.1f ",angle[i]);///檔案印出來
    }///這裡老師沒有fclose
    printf("\n");///小黑印出跳行
    fprintf(fout,"\n");///檔案跳行
}
void myRead()
{
    if(fout!=NULL){fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重劃畫面
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
```
## step02-2 為啥我們產生的檔案file.txt放在很神奇的地方ㄋ?
>> C:\Users\YUXUAN\Desktop\freeglut\bin 目標放在程式專案的目錄
```
0.為甚麼呢?
1.原來是電腦餘讀 GLUT專案需要freeglut.dll 所以工作目錄才會跑到freeglut/bin裡
2.在 .cbp codeblocks project檔裡,有工作目錄的設定 工作執行的目錄
3.使用notepad++ 開啟.cbp檔 將 裡面的working dir裡改成<Option working_dir="." />
4.notepad++檔案存檔後,codeblock檔案reload 後就完成
5.小心歷史餘毒!!=>將原freeglut/bin裡的freeglut.dll複製貼上到程式專案的資料夾中
```
## step03-1 glutTimerFunc() 計時器
```
0.為甚麼要這個? 因為每個人鍵盤輸入速度步一樣
0-1.File-New-Project-GLUT專案->week14_timer
1.void timer(int t)寫入timer函式
2.glutTimerFunc(等多久,timer,t參數);
3.其他就是GLUT的10行程式碼
```
```C
///week14_timer
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("起床,現在時間: %d\n",t);
}
void display()
{
}
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(1000,timer,1);
    glutTimerFunc(2000,timer,2);
    glutTimerFunc(3000,timer,3);
    glutTimerFunc(4000,timer,4);
    glutTimerFunc(5000,timer,5);
    glutDisplayFunc(display);
    glutMainLoop();
 }

```
## step03-2 期末作業30秒要30格,900個timer有點麻煩,程式應該自動一點
```
1.透過函式呼叫函式
2.glutTimerFunc(1000,timer,t+1); 隨著時間每秒+1
3. glutTimerFunc(5000,timer,0);///設定:5秒後,才叫第0個timer
```
```C
///week14_timer
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("起床,現在時間: %d\n",t);
    glutTimerFunc(1000,timer,t+1);
}
void display()
{
}
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(5000,timer,0);///設定:5秒後,才叫第0個timer

    glutDisplayFunc(display);
    glutMainLoop();
 }
```
## step03-3 播放聲音PlaySound() 下載do.wav
```
1.繼續改 剛剛那隻程式(week14_timer_auto)
2.#include <mmsytem.h>
3.PlaySound("do.wav",NULL,SND_ASYNC);
```
## 有聲音的程式碼(*´∀`)~♥
```C
///week14_timer
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
    printf("我起床囉!  %d\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    glutTimerFunc(2000,timer,t+1);
}
void display()
{
}
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(5000,timer,0);///設定:5秒後,才叫第0個timer

    glutDisplayFunc(display);
    glutMainLoop();
 }

```
# Week15
## 電腦圖學 Week15 2022-05-31
```
1. 播聲音、播MP3
2. 播放動畫、內插
3. 機器人擺動作、跳舞
```
## Step01-1 PlaySound()解釋
```C
0.File-New-Empty File-week15_playsound.cpp
1.上週#include<mmsystem.h>
2.這週使用#include<windows.h>
3.上週playsound("檔名.wav",NULL,SND_ASYNC);//不等待,不同步
4.這週PlaySound("檔名.wav",NULL,SND_SYNC);//等待,同步
5.setting-compiler setting-linker加入winmm(可以撥聲音)

6.注意工作目錄的位置!
7.將下載下來的聲音檔放在你檔案存放的位置(記得音樂檔是wav檔)
```
## Step01-2 PlaySound()更多參數
```C
0.File-New-Empty File-week15-2_SND_SYNC_SND_ASYNC
1.PlaySound("檔名.wav",NULL,SND_SYNC);=>加上變ASYNC就會不播音樂直接結束
```

## 做一些變更
```C
#include <windows.h>
#include <stdio.h>
int main()
{///不等待會快速執行下一行，互動性佳
    PlaySound("07013033.wav",NULL,SND_ASYNC);///背景會先撥放此段音樂
    while(1){
        printf("請輸入數字: ");///邊秀出文字
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("do.wav",NULL,SND_ASYNC);///ASYNC不等待
        if(n==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}

```
## Step02-1 MP3(小/有壓縮) vs WAV(大/原始檔)
>>PlaySound()只能撥最原始的檔案,只要一行
>>,MP3比較麻煩,需要打比較多行
```C
1.在Moodle下載CMP3_MCI.h
2.程式碼#include<CMP3_MCI.h>
3.宣告 CMP3_MCI mp3
4.mp3.Load("檔名.mp3");
5.mp3.play();
```
## Step02-2 接續上周的week14_angles_TRT_write_and_read
```C
0.File-New-Project-GLUT專案,week15_angles_TRT_again
1.複製上週程式碼,並試跑看看能否正確執行
2.發現問題: 不像動畫,只會動一個關節，而且很慢
3.myWrite()會寫一行,myRead()會讀一行
4.不能把myWrite()放在motion()
5.把動作對應的關節全部做好再存起來成一個動作
6.擺好動作按下's'存檔
7.執行時可以存入幾個動作'r'可讀入
8.事後在工作目錄裡(C:\Users\YUXUAN\Desktop\freeglut\bin)有file.txt可以大量copy動作，重新跑完程式動作就變多了
```
## Step03-1 讓他搖擺(*´ω`)人(´ω`*)
```C
1.需要 3D Model (glm.h/.cpp) (.obj .mtl .jpg.....)
2.需要把模型切很多塊(因為整塊的話關節不會動)
3.TRT的程式才會轉動
4.keyboard()切換關節,mouse motion()旋轉關節
```
## 慢慢做
```C
1.File-new-project,GLUT專案,week15_hw4
2.改善電腦餘毒=>開啟notepad++將工作目錄改成<Option working_dir="." />
3.將freeglut.dll複製貼上到程式所在的檔案夾
4.把glm.h glm.cpp和gundam的data目錄,全放在現在要用的檔案目錄
```
## 實作小tips
```
1.為了不要打太多行程式碼進行縮減
2.建立一個類似於檔案夾的東西
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
3.這樣每次要從裡面抓檔案時只要打一行程式碼就好
ex.if (body==NULL) body=myReadOne("data/body.obj");
    glmDraw(body,GLM_TEXTURE|GLM_SMOOTH);
4.再去調整關節的TRT
```
# Week16
 ## 電腦圖學 Week16 2022-06-07
```
1. 主題: 內插、動作內插
2. 主題: 攝影機、運鏡 
3. 實作: gluLookAt()
```
## step01-1 Alpha內插公式    =>   alpha: 0.0~1.0
>>> angle=alpha*新+(1-alpha)*舊
```
ex.
-  alpha:0  =>  舊
-  alpha:0.5  =>半新半就
-  alpha:1  =>新
可以使用Excel or Google Spreadsheet 來做
```

## step01-2 用程式試試看(●´ω｀●)ゞ
>>> 使用上週 week15_angles_TRT_again 改動
```C
1.File-New-Project-GLUT專案-week16_interpolation 內插
2.複製程式=>執行=>mouse motion改動作,按s存檔一行關節動作*4次
3.按r之後發現動作不連續
```
## 改造程式碼
```C
1.void myInterpolate(float alpha)
2.一樣按s儲存每個動作
3.按下p可以逐步計算內插,做新舊角度交換
    if(key=='p'){///play
            if(t%30==0) myRead();///介於0.0~1.0
            myInterpolate((t%30)/30.0);
            glutPostRedisplay();
            t++;
        }
=>>動畫變得更順👍👍
```

## step02-1 讓動畫跑得更順(將myInterpolate在timer裡呼叫)
```
1.透過上一節課的程式碼進行修改
2.將原本的一直按著p改成按一次p可以自動重複撥放
3.timer計時器可以設定幾秒撥一次動畫
4.%50的原因是因為這樣計算下來每1秒會跑一格動畫
```
## 目前程式碼
```C
///week15修改自week14_angles_fprintf
///week16_interpolation
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE * fout=NULL, * fin = NULL;
void myWrite()
{///每呼叫一次myWrite
    if(fout == NULL)fout=fopen("file.txt","w+");

    for(int i = 0;i<20;i++)
    {
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout,"%.1f ",angle[i]);///檔案印出來
    }///這裡老師沒有fclose
    printf("\n");///小黑印出跳行
    fprintf(fout,"\n");///檔案跳行
}
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL){fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        OldAngle[i]=NewAngle[i];///原來新的變舊
        fscanf(fin,"%f",&NewAngle[i]);///得到新角度
        ///fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重劃畫面
}
void myInterpolate(float alpha)
{
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*NewAngle[i]+(1-alpha)*OldAngle[i];
    }
}
void timer (int t)
{  if(t%50==0) myRead();
    myInterpolate((t%50)/50.0);
    glutPostRedisplay();
    glutTimerFunc(20,timer,t+1);
}
///int t=0;
void keyboard(unsigned char key,int x,int y)
{
    if(key=='p'){///play
            myRead();
            glutTimerFunc(0,timer,0);
        ///if(t%30==0) myRead();///介於0.0~1.0
        ///myInterpolate((t%30)/30.0);
        ///glutPostRedisplay();
        ///t++;
    }
    if(key=='s') myWrite();///調好動作才save存檔
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
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.3,0.4,0);
            glRotatef(angle[2],0,0,1);
            glTranslatef(0.3,-0.4,0);
            glColor3f(1,0,0);
            glRectf(-0.3,0.5,-0.7,0.3);

            glPushMatrix();
                glTranslatef(-0.7,0.4,0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(0.7,-0.4,0);
                glColor3f(0,1,0);
                glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16_interpolation");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
 }

```

## Step02-2 運鏡
```
eye=>位置
center=>位置
up=>向量(攝影機指向的地方)
謝謝老師熱情的代入教學
>>>想看可至https://2022graphicsa.blogspot.com/search/label/09160455_%E9%BB%83%E6%A6%86%E8%90%B1
```
##  Step03-1 保持長寬比
>>> 不會變形
```
1.File-New-Project-GLUT專案-week16_camera_projection_GlutLookat
2.備份177行範例,透過那段程式進行修改
3.aspect ratio 長寬比(左寬右高) ex.1920x1080 1280x720 640x480,16:9,4:3....
```


## 在做一些改動
```
1.新增void motion函式
2.原本視角固定在0,0,3的位置=>(x-150)/150.0,(y-150)/150.0,3, ///eye
   (透過滑鼠的滑動做出視窗的轉變)
```
## 現在程式碼
```C
#include <GL/glut.h>
void reshape(int w,int h){///不能 整數除
    float ar = (float) w/(float) h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60,ar,0.1,100);

    glMatrixMode(GL_MODELVIEW);///3D Model+view
    glLoadIdentity();
    gluLookAt(0,0,3, ///eye
              0,0,0, ///center看哪裡
              0,1,0);///up向量
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
void motion(int x,int y)
{
    glMatrixMode(GL_MODELVIEW);///3D Model+view
    glLoadIdentity();
    gluLookAt((x-150)/150.0,(y-150)/150.0,3, ///eye
              0,0,0, ///center看哪裡
              0,1,0);///up向量
    glutPostRedisplay();///重劃畫面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16 camera");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);///範例是resize
    glutMainLoop();

}

```
# Week17
## 電腦圖學 Week17 2022-06-14
```
1. 期末作品繳交方式
2. 期末作品評分方式
3. 網友問 push matrix 和 pop matrix 事件
4. 整學期大複習-示範期末作品怎麼做
```
## 怎把期末作業做出來
>>>環境的部分
```
1.開啟codeblocks
2.File->New->project->GLUT專案->打上專案名稱
3.Q:如何改變工作目錄?
   A1:點擊專案的main按右鍵->Notepad++
   A2:找到working_dir將路徑改成小數點
   A3:複製freeglut裡的dll檔案貼上到專案檔案裡
4.opencv的設定()



5.貼上10行程式碼
```
## 程式碼的部分
>>>基本十行
```C
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
## 打光
>>>函示呼叫
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
>>>函示宣告
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
## 貼圖
>>>#include <GL/glut.h>,main裡加上myTexture();
```C
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
```
## 帶入3D模型
>>>#include "glm.h"
```C
GLMmodel *(obj檔案的名稱)=NULL;
```
<<< 在void display裡加入(一個關節一段)
## 如果模型太大
```
glmScale(模型名稱,大小.0)
```
```C
     if(關節名稱==NULL)
        {
            pmodel=glmReadOBJ("data/關節名稱.obj");
            glmUnitize(關節名稱);
            glmFacetNormals(關節名稱);
            glmVertexNormals(關節名稱,90);
        }
        glmDraw(關節名稱,GLM_TEXTURE);///劃出模型
    glPopMatrix();
```
>>>main裡加上
```C
    glutDisplayFunc(display);///顯示用的函式
    glutIdleFunc(display);
```
## 怎麼辦怎麼立體感沒出來!!!
>>> 在main裡加上
```
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
```
## 攝影機
```C
void reshape(int w,int h){///不能 整數除
    float ar = (float) w/(float) h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60,ar,0.1,100);

    glMatrixMode(GL_MODELVIEW);///3D Model+view
    glLoadIdentity();
    gluLookAt(0,0,3, ///eye
              0,0,0, ///center看哪裡
              0,1,0);///up向量
}
```
## main裡加上
```C
 glutReshapeFunc(reshape)
```

