#include<iostream>
#include<string>
#include<deque>
using namespace std;

//  总结: deque容器和vector容器的构造方式几乎一致,灵活使用即可

void PrintDeque(const deque<int> &d)       // 加const变为只读 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  只读迭代器 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	deque<int> d;
	for(int i=9;i>=0;i--)
	{
		d.push_front(i);
	}
	PrintDeque(d);
	
	deque<int>d2(d.begin(),d.end());    //区间赋值 
	PrintDeque(d2);
	
	deque<int>d3(10,100);       //赋值 10个100 
	PrintDeque(d3);       
	
	deque<int>d4(d3);       //拷贝构造 
	PrintDeque(d4);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
