#include<iostream>
using namespace std;

//编译器提供的构造和析构函数是空实现 
//对象的初始化和清理

//构造函数：主要作用于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用 
//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作。

class Person
{
	public:
	
		//    构造函数 语法： 类名（）{} 
		// 1、没有返回值  不写void 
		// 2、函数名与类名相同 
		// 3、构造函数可以有参数，可以发生重载 
		// 4、创建对象的时候，构造函数会自动调用，而且只调用一次 
		Person()
		{
			cout<<"Person 构造函数的调用！"<<endl;
		}
			
		//     析构函数 语法： ~类名（）{} 
		//没有返回值 不写void 
		//函数名与类名相同 在名称前加~ 
		//析构函数不可以有参数的，不可以发生重载 
		//对象在销毁前，会自动调用析构函数，而且只会调用一次	
		~Person()
		{
			cout<<"Person 析构函数的调用！"<<endl; 
		}
		
	
}; 

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构 

	void txt()
		{
			Person c1;      //在栈上的数据，txt执行完毕后，会释放这个对象 
		} 
int main()
{
	txt();
	//Person c1;
	system("pause");
} 
