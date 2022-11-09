#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
#include<numeric>
using namespace std;

/*
fill(iterator beg, iterator end, value) ;
 向容器中填充元素
 beg开始迭代器   end结束迭代器   value填充的值
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
	vector<int>v;
	
	for(int i=0;i<=5;i++)
	{
		v.push_back(i);
	} 
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl<<"大小为："<<v.size()<<endl;
	v.resize(8);
	fill(v.begin(),v.end(),66);         // [v.begin(),v.end()]填充区间  会覆盖区间内的所有值 
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl<<"大小为："<<v.size()<<endl;;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
