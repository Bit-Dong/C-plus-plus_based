#include<iostream>
using namespace std;

//函数重载的注意事项： 
//            1、 引用作为重载的条件
//            2、 函数重载碰到函数默认参数

//引用作为重载条件 
void func(int &a)
{
	cout<<"func(int &a)的调用！"<<endl; 
}

void func(const int &a)
{
	cout<<"func(const int &a)的调用！"<<endl; 
}

//函数重载碰到函数默认参数
void func2(int a,int b=10)   //int b=10函数默认参数 
{
	cout<<"func2(int a,int b=10)的调用！"<<endl; 
}

void func2(int a)
{
	cout<<"func2(int a)的调用！"<<endl; 
}

int main()
{
	int a=10;
	func(a);     //调用无const的 
	func(10);    //调用有const的 
	
//	fun2(10);    //报错  当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况 
	func2(10,20); 
}
