#include "boss.h"

Boss::Boss(int id,string name,int did)
{
	this->Id=id;
	this->Name=name;
	this->DeptId=did;
	
}

void Boss::showInfo()
{
	cout<<"职工编号："<<this->Id<<"\t职工姓名："<<this->Name<<"\t岗位："<<this->getDeptName()<<"\t岗位职责：管理公司所有事务"<<endl;
}

string Boss::getDeptName()
{
	return string("总裁"); 
}
