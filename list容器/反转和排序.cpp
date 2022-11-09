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

bool myCompare(int val1,int val2)
{
	return val1>val2;
}

//反转和排序
void test01()
{
	list<int> l;
	l.push_back(5); 
	l.push_back(8); 
	l.push_back(3); 
	l.push_back(6); 
	cout<<"操作前：";
	printList(l);
	
	//反转
	l.reverse();
	cout<<endl<<"反转后：";
	printList(l);
	
	//排序
	l.sort();     //默认规则排序 从小到大
	cout<<endl<<"从小到大排序：";
	printList(l);
	
	l.sort(myCompare);   //指定规则 从大到小
	cout<<endl<<"从大到小排序：";
	printList(l); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
