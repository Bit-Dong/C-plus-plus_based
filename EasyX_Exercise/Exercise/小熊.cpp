#include <stdio.h>
#include <easyx.h>

int main03()
{
    initgraph(800, 600);

    //  背景
    setbkcolor(RGB(169, 92, 10));
    cleardevice();

    //  耳朵阴影
    setfillcolor(RGB(130, 69, 4));
    solidcircle(200, 130, 90);
    solidcircle(600, 130, 90);
    //  留出月牙状阴影
    //setfillcolor(RGB(255, 178, 50));
    //solidcircle(200, 120, 90);
    //solidcircle(600, 120, 90);

    //  耳朵剪切区域
    HRGN leftEarClip = CreateEllipticRgn(110, 30, 290, 210);
    HRGN rightEarClip = CreateEllipticRgn(510, 30, 690, 210);
    HRGN earsClip = CreateRectRgn(0, 0, 0, 0);
    CombineRgn(earsClip, leftEarClip, rightEarClip, RGN_OR);
    setcliprgn(earsClip);

    //  留出耳朵高光
    setfillcolor(RGB(243, 154, 2));
    solidcircle(200, 130, 90);
    solidcircle(600, 130, 90);

    //  耳朵里面
    setfillcolor(RGB(255, 178, 50));
    solidcircle(200, 210, 90);
    solidcircle(600, 210, 90);

    //  释放区域
    DeleteObject(leftEarClip);
    DeleteObject(rightEarClip);
    DeleteObject(earsClip);
    //  禁用剪切区域
    setcliprgn(NULL);

    //  头
    setfillcolor(RGB(255, 178, 50));
    solidcircle(400, 300, 250);

    //  头剪切区域
    HRGN headClip = CreateEllipticRgn(150, 50, 650, 550);
    setcliprgn(headClip);

    //  留出头高光
    setfillcolor(RGB(243, 154, 2));
    solidcircle(400, 320, 250);

    //  释放区域
    DeleteObject(headClip);
    //  禁用剪切区域
    setcliprgn(NULL);

    //  眼睛
    setfillcolor(RGB(51, 34, 8));
    solidcircle(275, 300, 25);
    solidcircle(525, 300, 25);

    //  白色椭圆阴影
    setfillcolor(RGB(130, 69, 4));
    solidellipse(310, 385, 490, 485);

    //  白色椭圆
    setfillcolor(WHITE);
    solidellipse(310, 380, 490, 480);

    //  鼻子
    setfillcolor(RGB(51, 34, 8));
    solidcircle(400, 420, 15);

    //  胡须
    setlinestyle(PS_SOLID, 5);
    setlinecolor(RGB(51, 34, 8));
    line(400, 420, 370, 450);
    line(400, 420, 430, 450);


    getchar();
    closegraph();
    return 0;
}