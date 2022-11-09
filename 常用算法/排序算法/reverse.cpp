#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
reverse(iterator beg, iterator end );
反转指定范围的元素
 beg 开始迭代器  end结束迭代器 
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
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	cout<<"反转前："<<endl;
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
	
	cout<<"反转后："<<endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	
	system("pause");
	return 0;
}
