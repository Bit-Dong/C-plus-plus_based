#include<iostream>
#include<map>
#include<string>
using namespace std;
 
void test01()
{
	map<int,int>m;

	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	
	map<int,int>::iterator pos=m.find(3);
	if(pos!=m.end())
	{
		cout<<"查到元素 key = "<< (*pos).first<<"    value = "<< (*pos).second<<endl;
	} 
	else
	{
		cout<<"未找到元素！"<<endl;
	}

	//统计
	//map不允许插入重复key元素，count统计而言 结果要么是0要么是1 
	int num=m.count(3);
	cout<<"num = "<<num<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
