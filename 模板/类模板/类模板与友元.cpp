#include<iostream>
#include<string>
using namespace std;

//全局函数类内实现----直接在类内声明友元即可
//全局函数类外实现---需要提前让编译器知道全局函数的存在

template<class T1,class T2>
class Person;

//全局函数类外实现 
template<class T1,class T2>
void PrintPerson2(Person<T1,T2> p)
{
	cout<<"类外实现-----姓名："<<p.Name<<"年龄："<<p.Age<<endl;
}

template<class T1,class T2>
class Person
{
	//全局函数类内实现 
	friend void PrintPerson(Person<T1,T2> p)
	{
		cout<<"姓名："<<p.Name<<"年龄："<<p.Age<<endl;
	}

	//全局函数类外实现 
	//加空模块<>参数列表
	//如果全局函数 是类外实现，需要让编译器提前知道这个函数的存在 
	friend void PrintPerson2<>(Person<T1,T2> p);
	
	public:
		Person(T1 name,T2 age)
		{
			this->Name=name;
			this->Age=age;
		}
		
	private:
		T1 Name;
		T2 Age; 
};


//全局函数在类内实现 
void test01()
{
	Person<string,int>p("Nie",20);
	PrintPerson(p);
}


void test02()
{
	Person<string,int>p("Dong",20);
	PrintPerson2(p);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
