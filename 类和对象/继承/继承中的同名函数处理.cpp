#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		Base()
		{
			A=100;
		}
		
		void func()
		{
			cout<<"Base - func()调用"<<endl;
		}
		
		void func(int a)
		{
			cout<<"Base - func(int a)调用"<<endl;
		}
		
	public:
		int A;
};

class son : public Base
{
	public:
		son()
		{
			A=200;
		}
		
//      当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数 
//      如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
		
		void func()
		{
			cout<<" son - func()调用"<<endl;
		} 
	public:
		int A;
};

void test01()
{
	son s;
	
	cout<<" son下的 A = "<<s.A<<endl;
	cout<<"Base下的 A = "<<s.Base::A<<endl;
	
	s.func();
	s.Base::func();
	s.Base::func(10);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
