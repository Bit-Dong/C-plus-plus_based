#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
 
/*
random_shuffle(iterator beg,iterator end);
指定范围内的元素随机调整次序
beg开始迭代器    end结束迭代器
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
	
	for_each(v.begin(),v.end(),myprint()); 
	cout<<endl;
	
	//打乱顺序
	random_shuffle(v.begin(),v.end());
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
