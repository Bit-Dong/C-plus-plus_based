#include<iostream>
#include<string>
using namespace std;

//注意事项：
//   1、自动类型推导，必须推导出一致的数据类型T，才可以使用 
//   2、模板必须要确定出T的数据类型，才可以使用 

//利用模板函数提供通用的交换函数
template<typename T>      //typename可以替换成 class 
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}  

//自动类型推导，必须推导出一致的数据类型T，才可以使用 
void test01()
{
	int a=10;
	int b=20;
	char c='c';
	mySwap(a,b);   //正确，可以推导出一致的T
//  mySwap(a,c);   //错误，推导不出一致的T类型 
}

// 模板必须要确定出T的数据类型，才可以使用 
template<class T>
void func()
{
	cout<<"func调用"<<endl;
}

void test02()
{
//	func();   //错误，模板不能独立使用，必须确定出T的类型
	func<int>();  //利用显示指定类型的方式，给T一个类型，才可以使用改模板 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
