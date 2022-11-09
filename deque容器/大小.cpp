#include<iostream>
#include<string>
#include<deque>
using namespace std;

//对deque容器的大小操作 (deque容器没有容量概念)

// empty();    判断容器是否为空 
// capacity();  容器的容量 
// size();    返回容器中元素的个数 
// resize(int num);  重新指定容器的长度为num，若容器变长，则以默认值填充新位置
//                                            若容器变短，则末尾超出容器长度的元素被删除 
// resize(int num,elem);   重新指定容器的长度为num，若容器变长，则以elem值填充新位置
//                                                  若容器变短，则末尾超出容器长度的元素被删除 

void printDeque(const deque<int> &d)       // 加const变为只读 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  只读迭代器 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//deque容器的容量和大小操作
void test01()
{
	deque<int> d1;  //默认构造
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);           //后插入数值 
	} 
	printDeque(d1);
	
	if(d1.empty())    //为真 代表容器为空
	{
		cout<<"d1为空"<<endl;
	}
	else
	{
		cout<<"d1不为空"<<endl;
		cout<<"d1的大小为："<<d1.size()<<endl;
	}
	
//重新指定大小
	d1.resize(15,1);     //利用重载版本，可以指定默认填充值  这里设定的大小长度为15，长出的部分用1填充（不设定的话，默认用0填充） 
	printDeque(d1);
	
	d1.resize(5);       //设定的大小长度为5 
	printDeque(d1);   //如果重新指定的长度比原来短了，超出部分会删除掉 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
