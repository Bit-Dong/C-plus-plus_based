#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->Name=name;
		this->Age=age;
	}
	void showPerson()
	{
		cout<<"name:"<<this->Name<<"   age:"<<this->Age<<endl;
	}
	
public:
	NameType Name;
	AgeType Age;			
};

void test01()
{
	//指定NameType 为string类型，AgeType为int类型
	Person<string,int> P1("孙悟空",999);
	P1.showPerson(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
