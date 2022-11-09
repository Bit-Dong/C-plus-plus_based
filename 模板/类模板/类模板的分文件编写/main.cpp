#include<iostream>
#include<string>
using namespace std;

#include"person.cpp "    //第一种解决方法：直接包含.cpp文件
//#include<person.hpp>   //第二种解决方法：将.cpp和.h文件写到同一个文件中，并更改后缀名为.hpp   .hpp是约定的名称，并不是强制 

void test01()
{
	Person<string,int>p("Niedong",20);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
