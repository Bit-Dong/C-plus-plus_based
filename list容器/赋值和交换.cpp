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


//list 容器赋值
void test01()
{
	list<int> l1;  //默认构造
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //后插入数值 
	} 
	printList(l1);
	
//赋值 operator=
	list<int> l2;
	l2=l1; 
	printList(l2);
	
//assign
	list<int> l3;
	l3.assign(l1.begin(),l1.end());    //利用assign区间方式(左闭右开)  将l1赋值给l3    
	printList(l3);
	
//n个elem方式赋值
	list<int> l4;
	l4.assign(10,100);        //10个100赋值给l4 
	printList(l4); 
} 

//交换 
void test02()
{
	list<int> l1;  //默认构造
	for(int i=0;i<10;i++)
	{
		l1.push_back(i);           //后插入数值 
	} 
	
	list<int> l2;
	l2.assign(10,100);        //10个100赋值给l4 
	cout<<"交换前："<<endl;
	printList(l1); 
	printList(l2); 
	
	l1.swap(l2);
	cout<<"交换后："<<endl;
	printList(l1); 
	printList(l2); 
		
}

int main()
{
//	test01();
	test02();
	 
	system("pause");
	return 0;
} 
