#include<iostream>
#include<string>            //注意事项： 
                                   //引用必须初始化 
using namespace std;              //引用在初始化后，不可以改变 

int main()
{
	int a=10;
	int &b=a;    //引用初始化 
	int c=20;
	b=c;        //赋值操作，不是改引用    
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
		
	system("pause");
}
