#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
/*
merge(iterator beg1，iterator end1， iterator beg2，iterator end2，iterator dest);
容器元素合并，并存储到另一容器中
注意:两个容器必须是有序的,合并后也是有序的 
 beg1容器1开始迭代器    end1容器1结束迭代器   beg2容器2开始迭代器    end2容器2结束迭代器    dest目标容器开始迭代器
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
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int>v3;
	v3.resize(v1.size()+v2.size());   //开辟目标容器空间 
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());    //合并俩个有序序列 
	for_each(v3.begin(),v3.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
