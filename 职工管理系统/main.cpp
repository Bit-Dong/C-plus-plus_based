#include<iostream>
#include<string>
#include"WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{

	WorkerManager wm;
	int chice=0;
	while(true)
	{
		wm.Show_Menu();	   //显示菜单
		cout<<"请输入您的选择："<<endl;
		cin>>chice;
		
		switch(chice)
		{
			case 0:   //退出系统
				wm.ExitSystem();
				break; 
			case 1:   //添加职工 
				wm.Add_Emp();
				break; 
			case 2:   //显示职工 
				wm.Show_Emp(); 
				break; 
			case 3:   //删除职工
				wm.Del_Emp();
				break; 
			case 4:   //修改职工 
				wm.Mod_Emp();
				break; 
			case 5:   //查找职工 
			wm.Find_Emp();
				break; 
			case 6:   //排序职工 
				wm.Sort_Emp();
				break; 
			case 7:   //清空文件 
				wm.Clean_File();
				break; 
			default:
				system("cls");    //清屏 
				break; 
		} 
	}
	
	
	system("pause");
	return 0;
}

