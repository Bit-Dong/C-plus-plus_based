#ifndef __BOSS_H_
#define __BOSS_H_

#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//老板类 
class Boss :public Worker
{
	public:
		
		//构造函数
		Boss(int id,string name,int did);
		
		//显示个人信息
		virtual void showInfo();
		
		//获取职工岗位名称
		virtual string getDeptName();
		
};

#endif
 
