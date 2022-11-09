#include<iostream>
#include<string>
using namespace std;

/*
函数对象使用特点：
1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
2、函数对象超出普通函数概念，函数对象可以有自己的状态
3、函数对象可以作为参数传递 
*/

//1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
	public:
		int operator()(int v1,int v2)
		{
			return v1+v2;
		}
};
void test01()
{
	MyAdd myadd;
	cout<<myadd(10,10)<<endl<<endl;
}

//2、函数对象超出普通函数概念，函数对象可以有自己的状态
class MyPrint
{
	public:
		MyPrint()
		{
			count=0;
		}
		void operator()(string test)
		{
			cout<<test<<endl;
			count++;    //统计使用次数 
		}
		int count;    //内部自己的状态 
};
void test02()
{
	MyPrint myprint;
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");
	myprint("Hello Bit Dongge!");	
	cout<<"myprint使用次数为："<<myprint.count<<endl<<endl;
} 

//3、函数对象可以作为参数传递 
void doprint(MyPrint &p,string test)
{
	p(test);
}
void test03()
{
	MyPrint myprint;
	doprint(myprint,"Bit Dongge!");
}

int main()
{
	test01();
	test02();
	test03();
	
	system("pause");
	return 0;
}
