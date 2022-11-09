#include<iostream>
#include<string>
#include<stack>
using namespace std;

//栈容器常用接口
void test01()
{
	//创建栈容器 栈容器必须符合先进后出
	stack<int> s;
	
	//入栈
	s.push(10); 
	s.push(20); 
	s.push(30); 
	
	while(!s.empty())
	{
		cout<<"栈顶元素为："<<s.top()<<endl;
		s.pop();   //弹出栈顶元素 
	}
	cout<<"栈的大小为："<<s.size()<<endl; 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
