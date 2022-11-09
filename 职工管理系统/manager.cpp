#include "manager.h"

Manager::Manager(int id,string name,int did)
{
	this->Id=id;
	this->Name=name;
	this->DeptId=did;
	
}

void Manager::showInfo()
{
	cout<<"职工编号："<<this->Id<<"\t职工姓名："<<this->Name<<"\t岗位："<<this->getDeptName()<<"\t岗位职责：完成老板交给的任务，并下发任务给员工"<<endl;
}

string Manager::getDeptName()
{
	return string("经理"); 
}
