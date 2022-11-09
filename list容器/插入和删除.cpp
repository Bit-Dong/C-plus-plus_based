#include<iostream>
#include<string>
#include<list>
using namespace std;

void PrintList(const list<int> &d)       // 加const变为只读 
{
	for(list<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  只读迭代器 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	list<int> l1;

//插入操作 
	//尾插
	l1.push_back(10); 
	l1.push_back(20); 
	//头插
	l1.push_front(100); 
	l1.push_front(200);      
	
	// 200 100 10 20
	PrintList(l1);
	
//删除操作
	//尾删
	l1.pop_back();
	// 200 100 10
	PrintList(l1);
	//头删
	l1.pop_front();
	//100 10
	PrintList(l1);	
	
//insert插入
	l1.insert(l1.begin(),1000);    //在头部插入1000 
	// 1000 100 10
	PrintList(l1);
	
	l1.insert(l1.begin(),2,10000);    //在头部插入俩个10000 
	// 10000 10000 1000 100 10
	PrintList(l1); 
	
//按照区间进行插入
	list<int> l2;
	l2.push_back(1); 
	l2.push_back(2);
	l2.push_back(3);
	l1.insert(l1.begin(),l2.begin(),l2.end());    //在l1的头部插入 区间[l2.begin(),l2.end()] 
	// 1 2 3 10000 10000 1000 100 10
	PrintList(l1); 
}

//删除操作 
void test02()
{
	list<int> l1;
	
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_front(100); 
	l1.push_front(200);  
	
//删除
	list<int> ::iterator it=l1.begin();
	it++;   //即it指向第二个数
	l1.erase(it);   //删除it指向的这个数
	//  200 10 20
	PrintList(l1);
	l1.remove(200);    //删除与200相同的数 
//按区间方式删除
//	l1.erase(l1.begin(),l1.end());    //删除l1的全部数据
	
//清空
//	l1.clear();
	PrintList(l1); 
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
}
