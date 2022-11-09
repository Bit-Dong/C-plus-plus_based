#include<iostream>
#include<string>
using namespace std;

//  成员属性私有化
//   1、自己可以控制读写权限
//   2、对于写可以检查数据的有效性

//设计人类
class people                          //        姓名设置为    可读可写 
{                                     //        年龄设置为    只读 
	public:                           //        女朋友设置为  只写 
		//设置姓名  
		void setname(string name1)
		{
			name=name1;
		}
		
		//获取姓名
		string getname()
		{
			return name;
		}
		
		//获取年龄
		int getage()
		{
			age=20;
			return age;
		} 
		 
		//设置女朋友
		void setgirlfriend(string girlfriend1)
		{
			girlfriend=girlfriend1;
		}
		
				
	
	private:
		string name;            //设置为可读可写 
	    int age;                //设置为只读 
		string girlfriend;      //设置为只写 
}; 

int main()
{ 
// 设置c为具体对象 
	people c;
	
//姓名的设置与获取
    c.setname("聂冬");
	cout<<"姓名："<<c.getname()<<endl;
	
//年龄的读取
    cout<<"年龄："<<c.getage()<<endl;
	
//女朋友的设置
    c.setgirlfriend("苍井"); 
	
} 
