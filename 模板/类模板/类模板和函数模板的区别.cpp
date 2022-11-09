#include<iostream>
#include<string>
using namespace std;

//  类模板和函数模板的区别：
//   1、类模板没有自动类型推导使用方式
//   2、类模板在模板参数列表中可以有默认参数

template<class NameType=string,class AgeType=int>   //类模板在模板参数列表中可以有默认参数
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->Name=name;
		this->Age=age;
	}
	void showPerson()
	{
		cout<<"name:"<<this->Name<<"   age:"<<this->Age<<endl;
	}
	
public:
	NameType Name;
	AgeType Age;			
};

//  1、类模板没有自动类型推导使用方式
void test01()
{
//	Person P1("孙悟空",999);    报错， 无法用自动类型推导 
	
	Person<string,int> P1("孙悟空",999);  //正确，只能用显示指定类型    指定NameType 为string类型，AgeType为int类型
	
	P1.showPerson(); 
}

//类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<> p("猪八戒",998);
	p.showPerson(); 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
