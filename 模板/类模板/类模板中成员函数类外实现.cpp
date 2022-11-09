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

void test01()
{
	Person<string,int>p("Tom",20);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
