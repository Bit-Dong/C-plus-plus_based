#include<iostream>
#include<string>
using namespace std;

//string 字符串比较
/*
功能描述： 字符串之间的比较
比较方式： 字符串比较是按字符夫人ASCII码进行比较 
           = 返回 0
		   > 返回 1
		   < 返回-1 
函数原型：
        int compare(const string &s) const;   //与字符串s比较 
        int compare(const char *s) const;     //与字符串s比较
*/ 

void test01()
{
	string s1="a";         // a --- 97   b=98....
	string s2="A";         // A --- 65   B=66....
	
	int ret=s1.compare(s2);
	if(ret==0)       cout<<"s1 = s2"<<endl;
	else if(ret>0)   cout<<"s1 > s2"<<endl;
	else             cout<<"s1 < s2"<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
