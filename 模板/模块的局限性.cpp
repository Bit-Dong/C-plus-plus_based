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
		string Name;
		int Age;
};

//普通函数模板
template<class T>
bool myCompare(T &a,T &b)
{
	if(a==b)  return true;
	else      return false;
} 

//具体化，显示具体化的原型和定义是以template<>开头，并通过名称来指出类型
//具体化优先常规模板
template<> bool myCompare(Person &p1,Person &p2)
{
	if(p1.Name==p2.Name&&p1.Age==p2.Age)  return true;
	else  return false;
} 

void test01()
{
	int a=10;
	int b=20;
	//内置数据类型可以直接使用通用的函数模板
	bool ret=myCompare(a,b);
	if(ret)  cout<<"a == b"<<endl;
	else     cout<<"a != b"<<endl; 
}

void test02()
{
	Person p1("tom",10);
	Person p2("tom",10);
	//自定义数据类型，不会调用普通的函数模板 
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret=myCompare(p1,p2);
	if(ret)  cout<<"p1 == p2"<<endl;
	else     cout<<"p1 != p2"<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
