#include<iostream>
#include<string>
using namespace std;


class Base1
{
	public:
		Base1()
		{
			A=100;
		}
	public:
		int A;
};

class Base2
{
	public:
		Base2()
		{
			A=200;
		}
	public:
		int A;
};

//语法：  class 子类： 继承方式 父类1，继承方式 父类2
class son : public Base2,public Base1
{
	public:
		son()
		{
			C=300;
			D=400;
		}
	public:
		int C;
		int D;
};

//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
	son s;
	cout<<"sizeof son = "<<sizeof(s)<<endl;
	cout<<s.Base1::A<<endl;
	cout<<s.Base2::A<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
