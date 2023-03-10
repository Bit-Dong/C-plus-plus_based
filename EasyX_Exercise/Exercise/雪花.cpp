/*	*************************
 *	程序名称：	LoveSnow - 表白程序
 *	********* 说明 **********
 *	需要自己提供一张大小为 640×480 的图片(img.jpg)在项目根目录下
 *	大小可以在程序内更改，图片名字也可以。
 *	*************************/
#include <graphics.h>

#define MAX_STAR 500			// 雪花数量上限
#define SCREEN_WIDTH 640		// 屏幕宽度
#define SCREEN_HEIGHT 480		// 屏幕高度
#define MAX_STEP 3				// 雪花每次移动最高步长
#define MAX_RADIUS 3			// 雪花最大半径
#define IMGNAME _T("表白.jpg")	// 图片名字

using namespace std;

// 图片转数组（这个有很大优化空间的，需要识别彩色照片可以看这）
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// 雪花状态
enum STATUS
{
	STOP = 0,	// 不动
	UP,			// 向上
	DOWN,		// 向下
	LEFT,		// 向左
	RIGHT,		// 向右
	RANDOM,		// 随机
	ALL_STATUS	// 记录状态总数
};
struct STAR
{
	int x;				// 雪花的 x 坐标
	int y;				// 雪花的 y 坐标
	enum STATUS stat;	// 雪花状态
	unsigned radius;	// 雪花的半径
	int step;			// 雪花每次移动的步长
	int color;			// 雪花的颜色
};
struct SqList
{
	struct STAR* elems; // 顺序表的基地址
	int length;			// 顺序表的长度
	int size;			// 顺序表的空间
};

// 顺序表的接口
bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);

bool initList(SqList& L)
{
	L.elems = new struct STAR[MAX_STAR];
	if (!L.elems) return false;
	L.length = 0;
	L.size = MAX_STAR;
	return true;
}
bool listAppend(SqList& L, struct STAR e)
{
	if (L.length == L.size) return false;	// 存储空间已满
	L.elems[L.length] = e;
	L.length++;								// 表长加 1
	return true;
}
bool listDelete(SqList& L, int i)
{
	if (i < 0 || i >= L.length) return false;
	if (i == L.length - 1)
	{										// 删除最后一个元素
		L.length--;
		return true;
	}
	for (int j = i; j < L.length - 1; j++)
	{
		L.elems[j] = L.elems[j + 1];		// 删除位置的后续元素一次往前移
	}
	L.length--;
	return true;
}
void destroyList(SqList& L)
{
	if (L.elems) delete[]L.elems;			// 释放存储空间
	L.length = 0;
	L.size = 0;
}

/************************************
* 功能：移动雪花，并在指定区域留下雪痕
* 输入参数：
* L - 雪花对象
* i - 雪花在全局数组中的下标
* 返回值：无
************************************/
void MoveStar(SqList& L, int i)
{
	// 留下雪痕
	if (L.elems[i].stat == DOWN)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y += L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == UP)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y -= L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == LEFT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x -= L.elems[i].step;
	}
	if (L.elems[i].stat == RIGHT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x += L.elems[i].step;
	}

	if (L.elems[i].stat == STOP) return;
	// 擦除原来的雪花
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
	if (L.elems[i].stat == DOWN)
	{
		L.elems[i].y += L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0;
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// 这段代码可以让飘出屏幕外的雪花消亡
	}
	else if (L.elems[i].stat == UP)
	{
		L.elems[i].y -= L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y < 0) L.elems[i].y = SCREEN_HEIGHT;
		//if(L.elems[i].y<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT)
	{
		L.elems[i].x -= L.elems[i].step;
		if (L.elems[i].x > 0) L.elems[i].x = SCREEN_WIDTH;
		//if(L.elems[i].x<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT)
	{
		L.elems[i].x += L.elems[i].step;
		if (L.elems[i].x > SCREEN_HEIGHT) L.elems[i].x = 0;
		//if(L.elems[i].x>SCREEN_WIDTH) listDelete(L, i);
	}
	setfillcolor(L.elems[i].color);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
}


/************************************
* 功能：初始化雪花
* 输入参数：
* i - 雪花在全局数组中的下标
* 返回值：无
************************************/
void initStar(struct STAR& _star)
{
	int rgb = 0;
	//rand() 得到随机数范围 0 - 32767 RAND_MAX
	_star.x = rand() % SCREEN_WIDTH;		// x 范围 0 - SCREEN_WIDTH
	_star.y = rand() % SCREEN_HEIGHT;		// y 范围 0 - SCREEN_HEIGHT
	//_star.stat = STATUS(rand() % 6);		// 雪花状态：随机
	_star.stat = DOWN;						// 雪花状态：向下
	_star.radius = 1 + rand() % MAX_RADIUS; // 半径控制 1 - MAX_RADIUS
	_star.step = rand() % MAX_STEP + 1;		// 步长 1 - MAX_STEP
	rgb = 255 * _star.step / MAX_STEP;		// RGB：0 - 255
	_star.color = RGB(rgb, rgb, rgb);
}


int main02()
{
	bool quit = false;
	struct STAR star;
	SqList starList;

	// 初始化屏幕
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	// 初始化图片
	IMAGE img(SCREEN_WIDTH, SCREEN_HEIGHT);
	//loadimage(&img, IMGNAME);
	SetWorkingImage(&img);	// 设置 img为绘制设备
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);
	settextstyle(120, 55, _T("黑体"));
	outtextxy(100, 150, _T("比特冬哥"));
	//outtextxy(100, 250, _T("有一个家"));
	COLORREF color;			// 记录像素颜色
	BYTE r, b, g;			// 记录像素RGB

	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			color = getpixel(x, y);		// 获取像素颜色
			r = GetRValue(color);
			b = GetBValue(color);
			g = GetGValue(color);
			if (r < 200 && b < 200 && g < 200)
			{							// 判断需留下“雪痕”的数组位置
				imgList[y][x] = 1;
			}
		}
	}

	SetWorkingImage();	// 设置回默认绘制设备
	cleardevice();

	// 初始化保存雪花状态的顺序表
	initList(starList);

	for (int i = 0; i < MAX_STAR; i++)
	{
		initStar(star);
		listAppend(starList, star);
	}

	for (int i = 0; i < starList.length; i++)
	{
		setfillcolor(starList.elems[i].color);
		solidcircle(starList.elems[i].x, starList.elems[i].y,
			starList.elems[i].radius);
	}

	while (quit == false)
	{
		for (int i = 0; i < starList.length; i++)
		{
			MoveStar(starList, i);
		}

		if (starList.length == 0)
		{	// 若设置雪花离开屏幕后消亡，则会触发此退出
			quit = true;
		}
		Sleep(50);
	}
	system("pause");
	closegraph();
	return 0;
}