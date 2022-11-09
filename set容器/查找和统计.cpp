#include<iostream>
#include<string>
#include<set>
using namespace std;

void printSet(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
}

//查找 
void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	 
	set<int>::iterator pos=s1.find(4);        //存在返回该元素的迭代器，不存在返回set.end() 
	if(pos!=s1.end())
	{
		cout<<"找到元素："<<*pos<<endl;
	}
	else
	{
		cout<<"未找到该元素！"<<endl;
	}
}

//统计
void test02()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	int num=s1.count(5);      //有重复的数 set不会累加，set只会返回0或1 
	cout<<"num = "<<num<<endl;
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
