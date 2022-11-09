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

void test01()
{
	set<int>s1;
	
	s1.insert(8); 
	s1.insert(5); 
	s1.insert(9); 
	s1.insert(4); 
	s1.insert(5); 
	
	printSet(s1);
	
	//删除
	s1.erase(s1.begin());       //删除开头位置数
	printSet(s1);
	
	s1.erase(5);    //删除与5相同的数
	printSet(s1);
	
	s1.erase(s1.begin(),s1.end());    //全删 
	s1.clear();    //清空 
	printSet(s1); 
	
}

int main()
{
	test01();

	system("pause");
	return 0;
}
