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


//list 容器构造
void test01()
{
	list<int> l1;  //默认构造
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //后插入数值 
	} 
	printList(l1);
	
//通过区间方式进行构造
	list<int> l2(l1.begin(),l1.end());     //将l1的值赋给l2 
	printList(l2);
	
//n个elem方式构造
	list<int> l3(10,100);        //将10个为100的数值 赋给l3
	printList(l3);
	
//拷贝构造
	list<int> l4(l3);          //将l3的值拷贝给l4 
	printList(l4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
