#include<iostream>
#include<string>
using namespace std;

//   从字符串中获取想要的子串 
//   string substr(int pos=0,int n=npos) const    //返回由pos开始的n个字符组成的字符串 

//获取字串 
void test01()
{
	string str="abcdefg";
	string subStr=str.substr(1,3);       //获取到str的第1-3个字符 
	cout<<"subStr = "<<subStr<<endl;
} 

//实用操作：从邮件地址中 获取 用户名信息 
void test02()
{
	string email="Niedong@qq.com";
	int pos=email.find("@");     //获取到字符'@' 的位置   8
	cout<<"pos = "<<pos<<endl;     //输出位置信息
	
	string userName=email.substr(0,pos);
	cout<<userName<<endl; 
} 

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
