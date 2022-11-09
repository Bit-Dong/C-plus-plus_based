#ifndef __WORKMANAGER_H_
#define __WORKMANAGER_H_

#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;
class WorkerManager
{
	public:
		WorkerManager();
		~WorkerManager();
		
		void Show_Menu();     //展示菜单 
		void ExitSystem();    //退出系统 
		void Add_Emp();       //添加职工 
		void save();         //保存文件 
		void init_Emp();     //初始化员工 
		void Show_Emp();     //显示职工
		void Del_Emp();      //删除职工
		int IsExist(int id);  //按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1 
		void Mod_Emp();      //修改职工 
		void Find_Emp();     //查找职工 
		void Sort_Emp();     //排序职工 
		void Clean_File();   //清空文件 
		
		int EmpNum;          //记录职工人数 
		Worker **EmpArray;   //职工数组指针 
		bool FileIsEmpty;    //判断文件是否为空 标志
		int get_EmpNum();    //统计文件中人数 
		
};

#endif
 

