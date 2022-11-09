#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
replace(iterator beg,iterator end，oldvalue，newvalue) ;
将区间内 旧元素替换成新元素
 beg 开始迭代器   end结束迭代器    oldvalue 旧元素     newalue新元素
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
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	cout<<"替换前："<<endl;
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
	
	cout<<"替换后："<<endl;
	replace(v1.begin(),v1.end(),5,500);
	for_each(v1.begin(),v1.end(),myprint()); 
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
