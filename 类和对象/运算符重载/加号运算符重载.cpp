#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
		Person(){};  //默认构造 
		Person(int a,int b)   //有参构造 前面就必须显性声明一个默认构造 
		{
			A=a;
			B=b;
		}
		
		//成员函数实现+号运算符重载 
		Person operator+(const Person &p)     //本质 ：Person p3=p1.operator+(p2)    可以简化为 p3=p1+p2; 
		{
			Person temp;
			temp.A=this->A+p.A;
			temp.B=this->B+p.B;
			return temp;
		}
		
		int A;
		int B;
}; 

//全局函数实现+号运算符重载     //本质： Person p3=operator+(p1,p2)    可以简化为 p3=p1+p2;
Person operator+( Person &p1,Person &p2)
{
	Person temp(0,0);
	temp.A=p1.A+p2.A;
	temp.B=p1.B+p2.B;
	return temp;
}

//运算符重载 也可以发生函数重载
Person operator+( Person &p3,int val)
{
	Person tep;
	tep.A=p3.A+val;
	tep.B=p3.B+val;
	return tep;
} 

void test01()
{
	Person p1(10,10);
	Person p2(20,20);
	
	//成员函数方式 
	Person p3=p1+p2;
	cout<<"A:"<<p3.A<<" B:"<<p3.B<<endl;
	
	//运算符重载发生函数重载 
	Person p4=p3+10;
	cout<<"A:"<<p4.A<<" B:"<<p4.B<<endl;
}

int main()
{
	
	test01();
	system("pause");
	return 0;
} 
