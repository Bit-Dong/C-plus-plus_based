#include<iostream>
using namespace std;

//构造函数的分类： 
//      1、按照参数分类分为有参和无参构造  无参又称为默认构造函数
//      2、按照类型分类分为普通构造和拷贝构造

//构造函数的调用方式：
//        括号法、显示法、隐式转换法

class Person
{
	public:
	
	//无参构造 
		Person()
		{
			cout<<"Person的无参构造函数调用！"<<endl;
		}
	//有参构造	
		Person(int a)
		{
			age=a;
			cout<<"Person的有参构造函数调用！"<<endl;
		}
	
	//拷贝构造
	 	Person(const Person &p)
		{
			//将传入的人身上的所有属性,拷贝到我身上
			age=p.age;
			cout<<"Person的拷贝构造函数调用！"<<endl;
		}
			
		~Person()
		{
			cout<<"Person的析构函数调用！"<<endl; 
		}
		
	int age; 
}; 

//调用方式 
void txt()
{
//括号法
//	Person p1;        //默认函数调用
//	Person p2(10);    //有参函数调用
//	Person p3(p2);    //拷贝函数调用 
//注意事项:
//     调用默认函数时不要加 ()
//     因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象 
//     Person p1();   类似于 void func();

//显示法
//    Person p1;
//	Person p2=Person(10);   //有参构造 
//	Person p3=Person(p2);   //拷贝构造
	
	//Person(10);   //匿名对象  特点：当前行执行结束后，系统会立即回收匿名对象 
	//cout<<"aaaaa"<<endl; 
//注意事项：
//     不要利用拷贝构造函数，初始化匿名对象，编码器会认为 Person(p3)等价于Person p3 ;对象声明 
//     Person(p3);

//隐式转换法
    Person p4=10;      //相当于 写了 Person p4 = Person(10); 有参构造
	Person p5=p4;      //拷贝构造 
}

int main()
{
	txt();
	
	system("pause");
} 
