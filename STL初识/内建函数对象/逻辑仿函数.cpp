#include<iostream>
#include<functional>
#include<vector>
#include<functional> 
#include<algorithm>
using namespace std;

/*
实现关系对比 

template<class T> bool logical_and<T>           //逻辑与 
template<class T> bool logical_or<T>            //逻辑或
template<class T> bool logical_not<T>           //逻辑非 
*/ 

void test01()
{
	vector<bool> v;
	
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	
	for(vector<bool>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	
	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());   //开辟与v一样大小的空间 
	transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());  //搬运操作  把[v.begin(),v.end()]搬运到 以v2.begin()开始的地方    logical_not:搬运完后对其取反 
	for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++)
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
