#include<iostream>
#include<string>
#include<list>
using namespace std;

void printList(const list<int> &l)
{
	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//list容器的容量和大小操作
void test01()
{
	list<int> l1;  //默认构造
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //后插入数值 
	} 
	printList(l1);
	
	if(l1.empty())    //为真 代表容器为空
	{
		cout<<"l1为空"<<endl;
	}
	else
	{
		cout<<"l1不为空"<<endl;
		cout<<"l1的大小为："<<l1.size()<<endl;
	}
	
//重新指定大小
	l1.resize(15,1);     //利用重载版本，可以指定默认填充值  这里设定的大小长度为15，长出的部分用1填充（不设定的话，默认用0填充） 
	printList(l1);
	
	l1.resize(5);       //设定的大小长度为5 
	printList(l1);   //如果重新指定的长度比原来短了，超出部分会删除掉 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
