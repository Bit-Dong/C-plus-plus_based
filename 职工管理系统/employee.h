#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//员工类 
class Employee:public Worker
{
	public:
		
		//构造函数
		Employee(int id,string name,int did);
		
		//显示个人信息
		virtual void showInfo();
		
		//获取职工岗位名称
		virtual string getDeptName();
		
};

#endif
 
