#include<iostream>
#include<string>
using namespace std;

//公共继承 
class  Base1
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son1 : public Base1
{
	public:
		void func()
		{
			A=10;  //父类中的公共权限成员  到子类中依然是公共权限 
			B=10;  //父类中的保护权限成员  到子类中依然是保护权限 
//			C=10;   //父类中的私有权限成员  子类中访问不到 
		}
};
test01()
{
	son1 s1;
	s1.A=100;
//	s1.B=100;   //到son1中 B是保护权限 类外访问不到 
}


//保护继承 
class  Base2
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son2 : public Base2
{
	public:
		void func()
		{
			A=10;  //父类中的公共权限成员  到子类中是保护权限 
			B=10;  //父类中的保护权限成员  到子类中依然是保护权限 
//			C=10;   //父类中的私有权限成员  子类中访问不到 
		}
};
test02()
{
	son2 s2;
//	s2.A=100;   //到son2中 A是保护权限 类外访问不到
//	s2.B=100;   //到son2中 B是保护权限 类外访问不到 
}


//私有继承 
class  Base3
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;
};
class son3 : public Base3
{
	public:
		void func()
		{
			A=10;  //父类中的公共权限成员  到子类中是私有权限 
			B=10;  //父类中的保护权限成员  到子类中是私有权限 
//			C=10;   //父类中的私有权限成员  子类中访问不到 
		}
};
class Grandson3 : public son3
{
	public:
		void func()
		{
//			A=10;  //到了son3中 A变为了私有权限  Grandson3访问不到 
//			B=10;  //到了son3中 B变为了私有权限  Grandson3访问不到 
//			C=10;   
		}	
};
test03()
{
	son3 s3;
//	s3.A=100;   //到son3中 A是私有权限 类外访问不到
//	s3.B=100;   //到son3中 B是私有权限 类外访问不到 
}

int main()
{
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
}
