#include<iostream>
#include<string>
#include<list>
using namespace std;

class Person
{
	public:
		Person(string name,int age,int height)
		{
			this->Name=name;
			this->Age=age;
			this->Height=height;
		}
		
		string Name;
		int Age;
		int Height;
};

bool myCompare(Person &p1,Person &p2)
{
	if(p1.Age==p2.Age)
	{
		return p1.Height>p2.Height;
	}
	else
	  	return p1.Age<p2.Age;
}

void test01()
{
	list<Person> l;
	Person p1("张飞",31,162);
	Person p2("刘备",41,168);
	Person p3("赵云",22,181);
	Person p4("孔明",22,179);
	Person p5("关羽",31,169);
	
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	
	cout<<"排序前："<<endl;
	for(list<Person>::iterator it=l.begin();it!=l.end();it++)
	{
		cout<<"姓名："<<(*it).Name<<"     年龄："<<it->Age<<"    身高："<<it->Height<<endl;
	}
	
	l.sort(myCompare);
	cout<<"排序后："<<endl;
	for(list<Person>::iterator it=l.begin();it!=l.end();it++)
	{
		cout<<"姓名："<<(*it).Name<<"     年龄："<<it->Age<<"    身高："<<it->Height<<endl;
	}
}

int main()
{
	test01();
		
	system("pause");
	return 0;
}
