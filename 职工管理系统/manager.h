#ifndef __MANAGER_H_
#define __MANAGER_H_

#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//经理类 
class Manager :public Worker
{
	public:
		
		//构造函数
		Manager(int id,string name,int did);
		
		//显示个人信息
		virtual void showInfo();
		
		//获取职工岗位名称
		virtual string getDeptName();
		
};

#endif
 
