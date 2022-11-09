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

//大小 
void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	printSet(s1);
	
  	if(s1.empty())
	{
	 	cout<<"s1为空！"<<endl;	
	}
	else
	{
		cout<<"s1不为空！"<<endl;
		cout<<"s1的大小为："<<s1.size()<<endl;
	}
}

//交换
void test02() 
{
	set<int>s1;
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5);
	
	set<int>s2;
	s2.insert(10); 
	s2.insert(20); 
	s2.insert(30); 
	s2.insert(40); 
	s2.insert(50);
	
	cout<<"交换前："<<endl;
	printSet(s1);
	printSet(s2);
	
	s1.swap(s2);
	cout<<"交换后："<<endl;
	printSet(s1);
	printSet(s2);
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
