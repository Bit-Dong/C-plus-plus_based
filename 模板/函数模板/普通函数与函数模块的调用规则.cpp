#include<iostream>
#include<string>
using namespace std;

//普通函数和函数模板的调用规则
//  1、如果函数模板和普通函数都可以实现，优先调用普通函数 
//  2、可以通过空模板参数列表来 强制调用函数模板 
//  3、函数模板也可以发生重载 
//  4、如果函数模板可以产生更好的匹配 优先调用函数模块 

                                           //总结:既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

//普通函数
void myPrint(int a,int b)
{
	cout<<"调用的普通函数"<<endl;
} 

template<typename T>
void myPrint(T a,T b)
{
	cout<<"调用的函数模板"<<endl;
}

template<typename T>
void myPrint(T a,T b,T c)
{
	cout<<"调用的重载函数模板"<<endl;
}


void test01()
{
	int a=10;
	int b=20;
	int c=30;
	char c1='a';
	char c2='b';
	myPrint(a,b);      //  1、如果函数模板和普通函数都可以实现，优先调用普通函数
	myPrint<>(a,b);    //  2、可以通过空模板参数列表来 强制调用函数模板 
	myPrint(a,b,c);    //  3、函数模板也可以发生重载
	myPrint(c1,c2);    //  4、如果函数模板可以产生更好的匹配 优先调用函数模块 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
