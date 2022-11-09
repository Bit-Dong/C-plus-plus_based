#include<iostream>
#include<map>
#include<string>
using namespace std;

/*
简介： 
map中所有元素都是pair
pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
所有元素都会根据元素的键值自动排序

本质：
map/multimap属于关联式容器，底层结构是用二叉树实现

优点：
可以根据key值快速找到value值
 
map和multimap区别：
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素

总结: map中所有元素都是成对出现。插入数据时候要使用对组

*/

void PrintMap(map<int,int> &m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"    key = "<<(*it).first<<"   value = "<<it->second;
	}
	cout<<endl;
}

void test01()
{
	//创建map容器 
	map<int,int> m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));
	m1.insert(pair<int,int>(4,40));
	PrintMap(m1);
	
	map<int,int>m2(m1);    //拷贝构造 
	PrintMap(m2);
	
	map<int,int>m3;        //赋值 
	m3=m2;
	PrintMap(m3); 
	 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
 
