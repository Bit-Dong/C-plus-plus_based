#pragma once


#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>
#include<time.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define WIDE 60  //宽度
#define HIGH 20  //高度

//一个身体的对象
struct BODY {
	int X;
	int Y;
};

//定义蛇对象
struct SNAKE {
	struct BODY body[WIDE * HIGH];
	int size;
}snake;

//定义食物对象
struct FOOD {
	int X;
	int Y;
}food;

int score = 0;   //分数

int kx = 0;   //用户按下asdw任意一个按键所得到的坐标值
int ky = 0;

int lastX = 0;  //蛇尾的坐标
int lastY = 0;
int sleepSecond = 300;

void initSnake(void);
void initFood(void);
void initUI(void);
void initWall(void);
void playGame(void);
void showScore(void);