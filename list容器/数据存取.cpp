#include<iostream>
#include<string>
#include<list>
using namespace std;

void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	//l[0] 不可以用[]访问list容器中的元素
	//l.at(0) 不可以用at方式访问list容器中的元素
	//原因是list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
	cout<<"第一个元素为："<<l.front()<<endl;
	cout<<"最后一个元素为："<<l.back()<<endl;
	
	//验证迭代器是不支持随机访问的
	list<int>::iterator it=l.begin();
	it++;    //支持双向
	it--;
	//it=it+1     //不支持随机访问 	
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
