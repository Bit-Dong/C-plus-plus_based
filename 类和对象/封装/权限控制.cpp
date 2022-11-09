#include<iostream>
#include<string>
using namespace std;

//访问权限(三种)：
//        1、公共权限  public       成员 类内可访问，类外不可访问
//        2、保护权限  protected    成员 类内可访问，类外不可访问     儿子可以访问父亲的保护内容 
//        3、私有权限  private      成员 类内可访问，类外不可访问     儿子不可以访问父亲的私有内容 

class people
{
	public:
		string name;
		
	protected:
		string car;
		
	private:
		string password;
		
	public:
		void func()
		{
			name="聂冬";
			car="保时捷";
			password="123456789"; 
		}
		void display()
		{
			cout<<"姓名："<<name<<"  车型："<<car<<"  密码："<<password<<endl; 
		}
};

int main()
{
	//实例化具体对象
	people c1;
	
	//  c1.car="拖拉机";         //会报错，修改不了   因为car为保护权限内容，在类外访问不到 
	//  c1.password="546124";    //会报错，修改不了   因为password为私有权限内容，在类外访问不到 
	
	c1.func();
	c1.display();
	
	system("pause");
	return 0;
}
