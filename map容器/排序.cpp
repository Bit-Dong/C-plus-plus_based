#include<iostream>
#include<map>
#include<string>
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
	map<int,int,MyCompare>m;

	m.insert(make_pair(1,10));
	m.insert(make_pair(6,60));
	m.insert(make_pair(7,70));
	m.insert(make_pair(4,40));
	m.insert(make_pair(9,90));

	for(map<int,int,MyCompare>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"    key = "<<(*it).first<<"   value = "<<it->second<<endl;
	}
	cout<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
