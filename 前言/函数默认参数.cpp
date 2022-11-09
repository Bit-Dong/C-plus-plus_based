#include<iostream>
#include<string>

using namespace std;

//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值 
//语法： 返回值类型 函数名 （形参 = 默认值）
int func(int a,int b=10,int c=20)
{
	return a+b+c;
}
 
//注意事项
//1、 如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值 

//2、 如果函数声明有默认参数，函数实现就不能有默认参数
//    声明和实现只能有一个有默认参数 
int func2(int a,int b);   //声明 

int func2(int a=11,int b=22)   //实现 
{
	return a+b;
}

int main()
{
	//cout<<func(10)<<endl; 
    //cout<<func(10,10,100);
	cout<<func2()<<endl;
	 
	system("pause");
}
