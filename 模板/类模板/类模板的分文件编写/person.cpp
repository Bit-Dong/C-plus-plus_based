#include"person.h"

//构造函数 类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
	this->Name=name;
	this->Age;
} 

//成员函数 类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
	cout<<"姓名："<<this->Name<<"年龄："<<this->Age<<endl;
}
