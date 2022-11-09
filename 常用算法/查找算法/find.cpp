#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
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
		
		// 重载==
		bool operator==(const Person &p)
		{
			if(this->Name==p.Name&&this->Age==p.Age)
				return true;
			else
				return false;
		} 
	public:
		string Name;
		int Age;
};

//内置数据类型查找 
void test01()
{
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	
	//查找容器中是否有 5 这个元素
	vector<int>::iterator it=find(v.begin(),v.end(),50);
	if(it==v.end())
		cout<<"没有找到！"<<endl;
	else
		cout<<"找到元素："<<*it<<endl;  
}

//自定义数据类型查找 
void test02()
{
	vector<Person> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person p10("bbb",20);
	vector<Person>::iterator it=find(v.begin(),v.end(),p10);
	if(it==v.end())
		cout<<"没有找到！"<<endl;
	else
		cout<<"找到元素 "<<"  姓名："<<it->Name<<"    年龄："<<it->Age<<endl;  
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
