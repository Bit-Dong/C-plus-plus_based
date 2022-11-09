#include<iostream>
#include<string>

using namespace std;

/*int *fuc()
{
	int *p=new int(1102);   //堆区开辟整形数据 
	return p;              //返回数据对应类型的指针 
} 
int main()
{
	int *p=fuc();
	cout<<*p<<endl;
	delete p;           //释放 
	cout<<*p<<endl;	    //输出乱码 
	system("pause");
} */

int *arr=new int[10];     //堆区开辟数组 
int txt()
{
	for(int i=0;i<10;i++)
	{
		arr[i]=i;
		cout<<arr[i]<<"   ";    //输出数组 
	}
}

int main()
{
	txt();
	system("pause");
}
