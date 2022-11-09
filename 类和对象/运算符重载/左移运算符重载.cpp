#include<iostream>
#include<string>
using namespace std;

class Person
{
	friend ostream & operator<<(ostream &out,Person &p);   //全局函数做友元，可以访问私有权限 
	public:
		Person(int a,int b)   //有参构造 
		{
			A=a;
			B=b;	
		}
		
//    利用成员函数重载左移运算符p.operator<<(cout) 简化版本p<<cout
//    不会利用成员函数重载<<运算符，因为无法实现cout在左侧
//    void operator<<( cout )
//   {
//   }	
		
	private:
		int A;
		int B;
};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &out,Person &p)   //本质：operator<<(out,p)   简化：out<<p  
{
	out<<"A="<<p.A<<"  B="<<p.B;
	return out;
}

void test01()
{
	Person p(10,10);
	cout<<p<<"  Hello World!"<<endl;
}

int main()
{ 
	
	test01();
	system("pause");
	return 0; 
}
