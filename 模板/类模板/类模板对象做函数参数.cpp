#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

//类模板
template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age)
	{
		this->Name=name;
		this->Age=age;
	}
	void showPerson()
	{
		cout<<"name:"<<this->Name<<"  age:"<<this->Age<<endl;
	}
	
public:
	T1 Name;
	T2 Age;
};

//1、指定传入的类型
void printPerson1(Person<string,int> &p)
{
	p.showPerson();
} 
void test01()
{
	Person<string,int> p("孙悟空",100);
	printPerson1(p);
}

//2、参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p)
{
	p.showPerson();
	cout<<"T1的类型为："<<typeid(T1).name()<<endl;
	cout<<"T2的类型为："<<typeid(T2).name()<<endl;
} 
void test02()
{
	Person<string,int> p("猪八戒",65);
	printPerson2(p);
}

//3、整个类模板化
template<class T>
void printPerson3(T &p)
{
	cout<<"T的类型为："<<typeid(T).name()<<endl;
	p.showPerson();
}
void test03()
{
	Person<string,int> p("唐僧",46);
	printPerson3(p);
}

int main()
{
	test01();
	test02();
	test03();
	
	system("pause");
	return 0;
} 
