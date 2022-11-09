#include<iostream>
#include<string>
using namespace std;

//普通函数与函数模板的区别
//  1、普通函数调用可以发生隐式类型转换 
//  2、函数模板 用自动类型推导，不可以发生隐式类型转换 
//  3、函数模板 用显示指定类型，可以发生隐式类型转换 

//普通函数
int myAdd01(int a,int b)
{
	return a+b;
} 

//函数模板 
template<class T>
T myAdd02(T a,T b)
{
	return a+b;
}

void test01()
{
	int a=10;
	int b=20;
	char c='c';   //a - 97 ,  c - 99
	cout<<myAdd01(a,c)<<endl;    //会自动给字符‘c’ 转换为ASCII码 99 进行相加 
	
	//自动类型推导 不会发生隐式类型转换
//	cout<<myAdd02(a,c)<<endl;    	 //报错，因为字符'c'  函数模块不知道转换为int 还是 char

	//显示指定类型  会发生隐式类型转换
	cout<<myAdd02<int>(a,c)<<endl;   //会将字符'c' 转换成int型 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
