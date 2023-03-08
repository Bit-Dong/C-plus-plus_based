#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"



int main(void) {
	//去除光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;  //设置为false则光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	srand(time(NULL));  //播种随机数种子
	initWall();      //画墙
	initSnake();   //初始化蛇
	initFood();    //初始化食物
	initUI();      //画蛇和食物
	playGame();   //启动游戏

	showScore();  //打印分数
	system("pause");
	return 0;
}

//启动游戏
void playGame(void) {

	char key = 'd';

	//判断蛇撞墙
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH) {
		initUI();  //更新蛇

		//接收用户按键输入
		if (_kbhit()) {     //为真时，说明用户按下按键   _kbhit()不阻塞判断用户输入
			key = _getch();   //                         _getch()不回显读取一个字符
		}
		switch (key) {
		case 'w':	kx = 0;  ky = -1; break;
		case 's':	kx = 0;  ky = +1; break;
		case 'a':	kx = -1; ky = 0;  break;
		case 'd':	kx = +1; ky = 0;  break;
		default:	break;
		}

		//蛇头撞身体 蛇头==任一一节身体
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
				return;    //游戏结束
		}
		//蛇头撞食物
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y) {
			initFood();     //食物消失		
			snake.size++;   //身体增长
			score += 10;    //加分
			sleepSecond -= 25;//加速
		}

		//存储蛇尾坐标
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		//蛇移动，前一节身体给后一节身体赋值
		for (size_t k = snake.size - 1; k > 0; k--)
		{
			snake.body[k].X = snake.body[k - 1].X;
			snake.body[k].Y = snake.body[k - 1].Y;
		}

		snake.body[0].X += kx;   //蛇头坐标根据用户按键 修改
		snake.body[0].Y += ky;

		Sleep(sleepSecond);
	}
	return;
}

//画墙
void initWall(void) {
	for (size_t i = 0; i <= HIGH; i++)
	{
		for (size_t j = 0; j <= WIDE; j++)
		{
			if (j == WIDE)
				cout << "|";
			else if (i == HIGH)
				cout << "_";
			else
				cout << " ";
		}
		cout << endl;
	}
}

//定义初始化蛇函数
void initSnake(void) {
	snake.size = 2;

	snake.body[0].X = WIDE / 2;		 //蛇头初始化
	snake.body[0].Y = HIGH / 2;

	snake.body[1].X = WIDE / 2 - 1;  //蛇的一节身体初始化
	snake.body[1].Y = HIGH / 2;

	return;
}

//食物的初始化函数
void initFood(void) {
	food.X = rand() % WIDE;  // 0-59
	food.Y = rand() % HIGH;  // 0-19

	return;
}

//初始化界面控件
void initUI(void) {
	COORD coord = {0};         //光标移动的位置

	//画蛇
	for (size_t i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		if(i==0)
			putchar('@');
		else 
			putchar('*');
	}

	//去除蛇尾
	coord.X = lastX;
	coord.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//画食物
	coord.X = food.X;
	coord.Y = food.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}

//打印分数
void showScore(void) {
	//将光标默认位置移动至 不干扰游戏的位置
	COORD coord;
	coord.X = 0;
	coord.Y = HIGH + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	cout << "Game Over!!!" << endl;
	cout << "成绩为：" << score << endl<<endl<<endl;
}