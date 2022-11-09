#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
adjacent_find(iterator beg, iterator end) ;
查找相邻重复元素,返回相邻元素的第一个位置的迭代器
beg开始迭代器   end结束迭代器
*/
 
void test01()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(0);
	v.push_back(6);
	v.push_back(6);

	vector<int>::iterator it=adjacent_find(v.begin(),v.end());
	if(it==v.end())
		cout<<"没有找到！"<<endl;
	else
		cout<<"找到相邻重复元素为： "<<*it<<endl;  
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
