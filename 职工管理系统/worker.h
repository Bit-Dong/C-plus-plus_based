#ifndef __WORKER_H_
#define __WORKER_H_

#include<iostream>
#include<string>

using namespace std;
class Worker
{
	public:
		virtual void showInfo()=0;        //显示个人信息 
		virtual string getDeptName()=0;   //获取岗位名称 
		
		int Id;        //职工编号 
		string Name;   //职工姓名 
		int DeptId;    //职工所在部门名称编号 
};

#endif
 
