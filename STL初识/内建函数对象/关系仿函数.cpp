#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

/*
实现关系对比 

template<class T> bool equal_to<T>            //等于 
template<class T> bool not_equal_to<T>        //不等于 
template<class T> bool greater<T>             //大于  
template<class T> bool greater_equal<T>       //大于等于  
template<class T> bool less<T>                //小于  
template<class T> bool less_equal<T>          //小于等于  
*/ 

void test01()
{
	vector<int> v;
	
	v.push_back(5);
	v.push_back(9);
	v.push_back(4);
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	
	cout<<"原始排序："<<endl;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;

	cout<<"sort默认排序(升序)："<<endl; 
	sort(v.begin(),v.end());
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;

	cout<<"降序："<<endl; 
	sort(v.begin(),v.end(),greater<int>());         //STL内建仿函数  大于仿函数 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
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
