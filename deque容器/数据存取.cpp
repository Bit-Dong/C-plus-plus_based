#include<iostream>
#include<string>
#include<deque>
using namespace std;


// at(int idx);    返回索引idx所指的数据   
// operator[];     返回索引idx所指的数据 
// front();        返回容器中第一个数据元素 
// back();         返回容器中最后一个数据元素 


//对deque器中的数据进行存取操作
void test01()
{
	deque<int> d1;
	
	d1.push_back(10); 
	d1.push_back(20); 
	d1.push_front(100); 
	d1.push_front(200); 
	
	//利用[]方式访问数组元素
	for(int i=0;i<d1.size();i++)
	{
		cout<<d1[i]<<" ";
	}
	cout<<endl;
	
	//利用at方式访问元素
	for(int i=0;i<d1.size();i++)
	{
		cout<<d1.at(i)<<" ";
	} 
	cout<<endl;
	
	//获取第一个元素
	cout<<"第一个元素为："<<d1.front()<<endl;
	
	//获取最后一给元素
	cout<<"最后一个元素为："<<d1.back()<<endl; 

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
