#include<iostream>
#include<string>
using namespace std;

//纯虚函数和抽象类                         		//  纯虚函数    只要有一个纯虚函数，这个类称为抽象类 
class Base                                     //  抽象类特点： 
{                                             // 1、无法实例化对象    例如：Base a、new Base都会报错 
	public:                                   // 2、抽象类的子类  必须要重写父类中的纯虚函数，否则也属于抽象类 
		virtual void func()=0;
};

class son :public Base
{
	public:
		virtual void func()
		{
			cout<<"func函数调用"<<endl;
		}
};

void test01()
{
	//Base b;     //抽象类无法实例化对象
	//new Base;  //抽象类无法实例化对象
	//son a;   //子类必须重写父类中的纯虚函数，否则无法实例化对象 
	Base *base=new son;
	base->func(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
