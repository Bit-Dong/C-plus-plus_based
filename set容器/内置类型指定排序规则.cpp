#include<iostream>
#include<string>
#include<set>
using namespace std;

class MyCompare
{
	public:
		bool operator()(int v1,int v2)
		{
			return v1>v2;
		}
};

void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(7);
	//默认从小到大
	for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
	{
		cout<<*it<<"  ";
	} 
	cout<<endl;
	
	//指定排序规则
	set<int,MyCompare>s2;
	
	s2.insert(8); 
	s2.insert(5); 
	s2.insert(9); 
	s2.insert(4); 
	s2.insert(7);	 
	for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++)
	{
		cout<<*it<<"  ";
	} 
	cout<<endl;	
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
