#include<iostream>
#include<string>
using namespace std;

//string 字符串拼接
/*
string& operator+=(const char *str);             //重载+=操作符 
string& operator+=(const char c);                //重载+=操作符
string& operator+=(const string &str);           //重载+=操作符
string& append(const char *s);                   //把字符串s连接到当前字符串结尾 
string& append(const char *s,int n);             //把字符串s的前n个字符连接到当前字符串结尾 
string& append(const string &s);                 //同operator+=(const string &str) 
string& append(const string &s,int pos,int n);   //字符串s中从pos开始的n个字符连接到字符串结尾 
*/ 

void test01()
{
	string str1="我";
	str1+="爱玩游戏";      //将“爱玩游戏”拼接到“我”的后面 
	cout<<"str1 = "<<str1<<endl; 
	
	str1+=':';           //将“：”拼接到str1后面 
	cout<<"str1 = "<<str1<<endl; 
	
	string str2=" LOL DNF";         //将str2拼接到str1后面 
	str1+=str2;
	cout<<"str1 = "<<str1<<endl; 
	
	string str3="I";
	str3.append(" Love ");        //将字符拼接到str3原有字符后面 
	cout<<"str3 = "<<str3<<endl;
	
	str3.append("game abcde",4);   //取前四个字符拼接到str3后面 
	cout<<"str3 = "<<str3<<endl;
	
	str3.append(str2);     //把str2拼接到str3后面 
	cout<<"str3 = "<<str3<<endl;
	
	str3.append(str2,0,4);        //取str2的 第0-4位置的字符拼接到str3后面 
	cout<<"str3 = "<<str3<<endl;
	
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
