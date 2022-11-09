#include<iostream>
#include<string>
#include<vector> 
#include<algorithm>
using namespace std;

class MyCompare
{
	public:
		bool operator()(int v1,int v2)
		{
			return v1>v2;
		}
};

void test01()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(4);
	v.push_back(9);
	v.push_back(8);
	v.push_back(7);
	
	sort(v.begin(),v.end());    //默认从小到大 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	
	cout<<"----------------------"<<endl;
	sort(v.begin(),v.end(),MyCompare());
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
