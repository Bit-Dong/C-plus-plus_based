#include<iostream>
#include<string>

using namespace std;

class Building
{
	friend void goodGay(Building &build);   //告诉编译器goodGay全局函数是Building类的好朋友，可以访问类中的私有内容
	
	public:
		Building()     //构造函数 
		{
			sittingroom="客厅";
			bedroom="卧室";
		}
	public:
		string sittingroom;
	private:
		string bedroom;
}; 
void goodGay(Building &build)
{
	cout<<"好友正在访问："<<build.sittingroom<<endl;
	cout<<"好友正在访问："<<build.bedroom<<endl;
}

void text01()
{
	Building b;
	goodGay(b);
}

int main()
{
	text01();
		
	system("pause");
	return 0;
}
