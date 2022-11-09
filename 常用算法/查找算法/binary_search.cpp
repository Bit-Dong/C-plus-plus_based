#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
bool binary_search(iterator beg, iterator end,value);
查找指定的元素，查到返回true 否则false
注意:在无序序列中不可用
beg 开始迭代器    end结束迭代器     value查找的元素
*/

void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	//  v.push_back(2);  如果时无序序列，结构未知！
	//  注意：容器必须是有序的序列 
	//  查找容器中是否有 9 这个元素
	bool ret=binary_search(v.begin(),v.end(),9);
	
	if(ret)
		cout<<"查到了！"<<endl;
	else
		cout<<"没查到！"<<endl; 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
