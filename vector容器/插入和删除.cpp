#include<iostream>
#include<string>
#include<vector>
using namespace std;

//对vector 容器进行插入、删除操作  
//  push_back(ele);   尾部插入元素ele 
//  pop_back();       删除最后一个元素 
//  insert(const_iterator pos,ele);       迭代器指向位置pos插入元素ele 
//	insert(const_iterator pos,int count,ele);     迭代器指向位置pos插入count个元素ele 
//	erase(const_iterator pos);     删除迭代器指向的元素 
//  erase(const_iterator start,coust_iterator end);    删除迭代器从start到end之间的元素 
// 	clear();       删除容器中所有元素 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector 容器进行插入、删除操作 
void test01()
{
	vector<int> v1;  //默认构造

//尾插
	v1.push_back(10); 
	v1.push_back(20); 
	v1.push_back(30); 
	v1.push_back(40); 
	v1.push_back(50); 
//遍历
	printVector(v1);
	
//尾删
	v1.pop_back();
	printVector(v1);
	
//插入    第一个参数是迭代器
	v1.insert(v1.begin(),100);      //在开头位置插入100
	printVector(v1);
	
	v1.insert(v1.begin(),2,1000);      //在开头位置插入两个1000
	printVector(v1);
	
//删除   参数是迭代器
	v1.erase(v1.begin());     //删除开头第一个元素
	printVector(v1);
	
//清空
//	v1.erase(v1.begin(),v1.end());     //删除从开头到最后一个元素
	v1.clear(); 
	printVector(v1);

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
