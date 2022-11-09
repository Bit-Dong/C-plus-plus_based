#include<iostream>

using namespace std;

//引用做函数的返回值 
//1.不要返回局部变量的引用
int & txt1()
{
	int a=10;   //局部变量存放在栈区
	return a; 
 } 

//2.函数的调用可以作为左值
int & txt2()
{
	static int b=20;   //静态变量，存放在全局区，全局区上的数据在程序结束后由系统释放
	return b; 
 } 
int main()
{
	int &re1=txt1();           //re1为a的别名 
	cout<<"re1="<<re1<<endl;   //第一次结果正确，是因为编译器做了保留 
	cout<<"re1="<<re1<<endl;   //第二次结果错误，是因为a的内存已经释放 
	
	int &re2=txt2();           //re2为b的别名 
	cout<<"re2="<<re2<<endl;   
	cout<<"re2="<<re2<<endl;
	txt2()=1000;
	cout<<"re2="<<re2<<endl;   
	cout<<"re2="<<re2<<endl;
	
	system("pause");
}
