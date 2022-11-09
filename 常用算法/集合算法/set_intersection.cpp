#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
set_intersection(iterator beg1，iterator end1，iterator beg2，iterator end2，iterator dest);
 求两个集合的交集
 注意:两个集合必须是有序序列  
 beg1容器1开始迭代器    end1容器1结束迭代器   beg2容器2开始迭代器   end2容器2结束迭代器    dest目标容器开始迭代器
*/

class myprint
{
	public:
		int operator()(int val)
		{
			cout<<val<<" ";
		}
};


void test01()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget; 
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	for(int i=0;i<10;i++)
	{
		v2.push_back(i+5);
	}
	
	cout<<"v1:"<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	cout<<"v2:"<<endl;
	for_each(v2.begin(),v2.end(),myprint());
	cout<<endl;
	
	cout<<"------------------------"<<endl;
	
	cout<<"取交集："<<endl;
	vTarget.resize(min(v1.size(),v2.size()));
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());    //返回取交集的最后一个元素的迭代器 
	
	for_each(vTarget.begin(),itEnd,myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
