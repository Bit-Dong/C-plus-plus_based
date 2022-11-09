#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
#include<numeric>
using namespace std;

/*
accumulate(iterator beg, iterator end, value) ;
计算容器元素累计总和
beg 开始迭代器    end结束迭代器    value 起始值
*/

void test01()
{
	vector<int>v;
	for(int i=0;i<=100;i++)
	{
		v.push_back(i);
	}
	
	int S=accumulate(v.begin(),v.end(),0);
	cout<<"S = "<<S<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
