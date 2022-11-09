#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		
	bool operator==(Person &p)
	{
		if(this->Name==p.Name&&this->Age==p.Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
			
	bool operator!=(Person &p)
	{
		if(this->Name==p.Name&&this->Age==p.Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	string Name;
	int Age;
	
}; 

void test01()
{
	Person a("猪八戒",20);
	Person b("猪悟能",20);
	
	if(a==b)  cout<<"a和b相等"<<endl;
	else      cout<<"a和b不相等"<<endl;
	
	if(a!=b)  cout<<"a和b不相等"<<endl;
	else      cout<<"a和b相等"<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
