#include<iostream>
#include<functional>
using namespace std;

/*
实现四则运算
其中negate是一元运算，其他都是二元运算

template<class T> T plus<T>          //加法仿函数 
template<class T> T minus<T>         //剑法仿函数 
template<class T> T multiplies<T>    //乘法仿函数 
template<class T> T divides<T>       //除法仿函数 
template<class T> T modulus<T>       //取模仿函数 
template<class T> T negate<T>        //取反仿函数 
*/ 

//negate
void test01()
{
	negate<int> n;
	cout<<n(50)<<endl;
} 

void test02()
{
	plus<int>p1;
	cout<<p1(20,10)<<endl; 
	
	minus<int>p2;
	cout<<p2(20,10)<<endl; 
	
	multiplies<int>p3;
	cout<<p3(20,10)<<endl; 
	
	divides<int>p4;
	cout<<p4(20,10)<<endl; 
	
	modulus<int>p5;
	cout<<p5(20,10)<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
