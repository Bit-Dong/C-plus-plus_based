#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
		Person(int age)
		{
			Age=new int(age);   //将年龄数据开辟到堆区 
		}
		
	//重载赋值运算符
	Person &operator=(Person &p)
	{
		if(Age!=NULL)
		{
			delete Age;
			Age=NULL;
		}
		//编译器提供的代码是浅拷贝 
		//Age=p.Age; 
		
		//提供深拷贝 解决浅拷贝的问题
		Age=new int(*p.Age);
		
		//返回自身
		return *this; 
	} 
	
	~Person()
	{
		if(Age!=NULL)
		{
			delete Age;
			Age=NULL;
		}
	}
		
	int *Age;
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3=p2=p1;
	cout<<"p1的年龄为："<<*p1.Age<<endl;
	cout<<"p2的年龄为："<<*p2.Age<<endl;
	cout<<"p3的年龄为："<<*p3.Age<<endl;
}


int main()
{
	test01();
	
	system("pause");
	return 0;
}
