#include<iostream>
#include<string>
using namespace std;

//值传递    
int txt1(int a,int b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

//地址传递
int txt2(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
} 

//引用传递
int txt3(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
 } 
 
int main()
{
	int a=10,b=20;
	//txt1(a,b);        //值传递，形参不能修饰实参 
	//txt2(&a,&b);      //地址传递，形参能修饰实参 
	txt3(a,b);          //引用传递，形参能修饰实参 
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	
	system("pause");
}
