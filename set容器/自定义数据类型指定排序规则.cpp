#include<iostream>
#include<string>
#include<set>
using namespace std;

class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		string Name;
		int Age;
};

class ComparePerson
{
	public:
		bool operator()(const Person &p1,const Person &p2)
		{
			//按照年龄进行排序  降序
			return p1.Age>p2.Age; 
		}
};

void test01()
{
	//自定义数据类型 都会指定排序规则
	set<Person,ComparePerson> s;
	
	//创建Person对象
	Person p1("刘备",54);
	Person p2("曹超",58);
	Person p3("赵飞",50);
	Person p4("公瑾",46);
	
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	
	for(set<Person,ComparePerson>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<"姓名："<<it->Name<<"   年龄："<<it->Age<<endl;
	}
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
