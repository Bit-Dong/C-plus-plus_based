#include<iostream>
#include<string>
using namespace std;                                  //虚析构和纯虚析构共性： 1、可以解决父类指针释放子类对象 
                                                     //                        2、都需要有具体的函数实现 
class Animal                                         // 虚析构和纯虚析构区别： 如果是纯虚析构 该类属于抽象类，无法实例化对象 
{                                                   //  虚析构语法： virtual ~类名(){}                   
	public:                                         // 纯虚析构语法：virtual ~类名()=0;   类名::~类名(){} 
		Animal()
		{
			cout<<"Animal构造函数调用"<<endl;
		}
		
//		//利用虚析构可以解决父类指针释放字类对象时不干净的问题
//		virtual ~Animal()     
//		{
//			cout<<"Animal析构函数调用"<<endl;
//		}
		
		//纯虚析构   需要声明、需要实现
		//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象 
		 virtual ~Animal()=0;
		
		//纯虚函数                                      //总结： 
		virtual void speak()=0;                         //   1、虚析构或纯虚析构就是用来就解决通过父类指针释放子类对象 
	                                                    //   2、如果子类中没有堆区数据，可以不写为虚析构或纯虚析构 
};                                                      //   3、拥有纯虚析构函数的类也属于抽象类 
Animal::~Animal()
{
	cout<<"Animal纯虚析构调用"<<endl;
}


class Cat : public Animal
{
	public:
		Cat(string name)
		{
			cout<<"Cat构造函数调用"<<endl; 
			Name=new string(name);
		}
		
		~Cat()
		{
			if(Name!=NULL)
			{
				cout<<"Cat析构函数调用"<<endl;
				delete Name;
				Name=NULL;
			}
		}
		
		virtual void speak()
		{
			cout<<*Name<<"小猫在说话"<<endl;
		}
		string *Name; 
};

void test01()
{
	Animal *animal=new Cat("Tom");
	animal->speak();
	//父类指针在析构时候不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	delete animal;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
