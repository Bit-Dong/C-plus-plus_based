#include "employee.h"

Employee::Employee(int id,string name,int did)
{
	this->Id=id;
	this->Name=name;
	this->DeptId=did;
}

void Employee::showInfo()
{
	cout<<"职工编号："<<this->Id<<"\t职工姓名："<<this->Name<<"\t岗位："<<this->getDeptName()<<"\t岗位职责：完成经理交给的任务"<<endl; 
}

string Employee::getDeptName()
{
	return string("员工");
}
