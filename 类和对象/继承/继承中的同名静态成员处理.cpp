#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		static int A;    //静态成员 类内声明 ，类外初始化 
		
		static void func()
		{
			cout<<"Base - static void func()"<<endl;
		}
		
		static void func(int a)
		{
			cout<<"Base - static void func(int a)"<<endl;
		}
};
int Base::A=100;   //初始化 

class son :public Base
{
	public:
		static int A;    //静态成员 类内声明 ，类外初始化 
		
		static void func()
		{
			cout<<" son - static void func()"<<endl;
		}
		
};
int son::A=200;   //初始化 

//同名静态成员属性 
void test01()
{
	//1、通过对象访问
	cout<<"通过对象访问："<<endl;
	son s;
	cout<<"son 下 A = "<<s.A<<endl; 
	cout<<"Base下 A = "<<s.Base::A<<endl;
	
	//2、通过类名访问
	cout<<"通过类名访问："<<endl;
	cout<<"son 下 A = "<<son::A<<endl; 
	cout<<"Base下 A = "<<son::Base::A<<endl;    //第一个：：代表通过类名方式访问   第二个：：代表访问父类作用域下 
}

//同名静态成员函数
void test02()
{
	//1、通过对象访问 
	cout<<"通过对象访问:"<<endl;
	son s;
	s.func();
	s.Base::func();
	
	//2、通过类名访问
	cout<<"通过类名访问:"<<endl;
	son::func();
	son::Base::func();
	
//    子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
//    如果想访问父类中被隐藏的同名成员函数，需要加作用域 
	son::Base::func(100);
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
