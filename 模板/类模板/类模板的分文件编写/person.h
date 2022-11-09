#ifndef __PRESON_H_
#define __PRESON_H_

#include<iostream>
#include<string>
using namespace std;

//类模板中成员函数类外实现
template<class T1,class T2>
class Person
{
	public:
		//成员函数类内声明
		Person(T1 name,T2 age);
		void showPerson();
	public:
		T1 Name;
		T2 Age; 
};

#endif
