#include<iostream>
#include<string>
using namespace std;

class MyInteger
{
	friend ostream & operator<<(ostream &out,MyInteger myint);   //全局函数做友元，可以访问私有权限 
	public:
		MyInteger()
		{
			Num=0;
		}

	//前置++
	MyInteger &operator++()     //返回引用为了一直对一个数据进行递增操作
	{
		Num++;  
		return *this;
	} 
	//后置++
	MyInteger operator++(int)   // operator++(int)  int代表占位参数，可以用于区分前置和后置递增
	{
		MyInteger temp=*this;   //记录当前本身的值， 然后让本身的值加一1， 但是返回的是以前的值， 达到先返回后++ 
		Num++;
		return temp; 
	} 
	private:
		int Num;

};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &out,MyInteger myint)   
{
	out<<myint.Num;
	return out;
}

//前置++  先++ 再返回 
void test01()
{
	MyInteger myInt;
	cout<<++myInt<<endl;
	cout<<myInt<<endl;
}

//后置++  先返回 再++ 
void test02()
{
	MyInteger myInt;
	cout<<myInt++<<endl;
	cout<<myInt<<endl;
}

int main()
{ 
	
	test01();
	test02();
	system("pause");
	return 0; 
}
