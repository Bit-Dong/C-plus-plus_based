#include<iostream>
#include<string>
using namespace std;

class C1         
{
	string name;        //默认权限为私有权限 
};

struct C2
{
	string name;       //默认权限为公共权限 
};

int main()
{
	                    //         struct 和 class区别：
						//                   struct默认权限是公共权限 public
						//                   class默认权限是私有权限 private 
	
	
//	C1 s1;
//	s1.name="小丑";           //会报错，在class里 默认权限为私有权限  因此类外不可以访问 
//	cout<<s1.name<<endl;    
	
	C2 s2;
	s2.name="聂冬";    //不会报错， 在struct里 默认权限为公共权限  因此类外可以访问 
	cout<<s2.name<<endl;
	
	system("pause");
} 
