#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout<<"Base的构造函数!"<<endl;
		}
		~Base()
		{
			cout<<"Base的析构函数!"<<endl;
		}
};

class son :public Base
{
	public:
		son()
		{
			cout<<"son的构造函数!"<<endl;
		}
		~son()
		{
			cout<<"son的析构函数!"<<endl;
		}	
};

void test01()
{
	son s1;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
