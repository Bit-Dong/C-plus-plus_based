#include<iostream>
#include<map>
#include<string>
using namespace std;

void printMap(map<int,int>&m) 
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"    key = "<<(*it).first<<"   value = "<<it->second<<endl;
	}
	cout<<endl;
}

//大小 
void test01()
{
	map<int,int>m1;
	
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));
	m1.insert(pair<int,int>(4,40));
	
  	if(m1.empty())
	{
	 	cout<<"m1为空！"<<endl;	
	}
	else
	{
		cout<<"m1不为空！"<<endl;
		cout<<"m1的大小为："<<m1.size()<<endl;
	}
}

//交换
void test02() 
{
	map<int,int>m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));
	m1.insert(pair<int,int>(4,40));
	
	map<int,int>m2;
	m2.insert(pair<int,int>(5,100));
	m2.insert(pair<int,int>(6,200));
	m2.insert(pair<int,int>(8,300));
	m2.insert(pair<int,int>(7,400));
	
	cout<<"交换前："<<endl;
	printMap(m1);
	printMap(m2);
	
	m1.swap(m2);
	cout<<"交换后："<<endl;
	printMap(m1);
	printMap(m2);
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
}
