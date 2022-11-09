#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//vector容器中存放自定义数据类型
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

//存放对象 
void test01()
{
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
	vector<Person> v;
	
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	
	//向容器中放数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	//遍历容器中的数据 
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
//		cout<<"姓名："<<(*it).Name<<"  年龄："<<(*it).Age<<endl;     //与下面等同 
		cout<<"姓名："<<it->Name<<"  年龄："<<it->Age<<endl;
	} 
}

void test02()
{
	vector<Person*> v;
	
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	
	//向容器中放数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);	
	
	//遍历容器中的数据 
	for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
	{
//		cout<<"姓名："<<(*it)->Name<<"  年龄："<<(*it)->Age<<endl;        //与下面等同 
//		cout<<"姓名："<<(*(*it)).Name<<"  年龄："<<(*(*it)).Age<<endl;
		cout<<"姓名："<<(**it).Name<<"  年龄："<<(**it).Age<<endl;
	} 
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
}
	 
