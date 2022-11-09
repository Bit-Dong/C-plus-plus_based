#include<iostream>
#include<string>
#include<deque>
using namespace std;

void PrintDeque(const deque<int> &d)       // 加const变为只读 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  只读迭代器 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	deque<int> d1;

//插入操作 
	//尾插
	d1.push_back(10); 
	d1.push_back(20); 
	//头插
	d1.push_front(100); 
	d1.push_front(200);      
	
	// 200 100 10 20
	PrintDeque(d1);
	
//删除操作
	//尾删
	d1.pop_back();
	// 200 100 10
	PrintDeque(d1);
	//头删
	d1.pop_front();
	//100 10
	PrintDeque(d1);	
	
//insert插入
	d1.insert(d1.begin(),1000);    //在头部插入1000 
	// 1000 100 10
	PrintDeque(d1);
	
	d1.insert(d1.begin(),2,10000);    //在头部插入俩个10000 
	// 10000 10000 1000 100 10
	PrintDeque(d1); 
	
//按照区间进行插入
	deque<int> d2;
	d2.push_back(1); 
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(),d2.begin(),d2.end());    //在d1的头部插入 区间[d2.begin(),d2.end()] 
	// 1 2 3 10000 10000 1000 100 10
	PrintDeque(d1); 
}

//删除操作 
void test02()
{
	deque<int> d1;
	
	d1.push_back(10); 
	d1.push_back(20); 
	d1.push_front(100); 
	d1.push_front(200);  
	
//删除
	deque<int> ::iterator it=d1.begin();
	it++;   //即it指向第二个数
	d1.erase(it);   //删除it指向的这个数
	//  200 10 20
	PrintDeque(d1);
//按区间方式删除
	d1.erase(d1.begin(),d1.end());    //删除d1的全部数据
	
//清空
	d1.clear();
	PrintDeque(d1); 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
