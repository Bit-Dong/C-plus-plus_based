#include<iostream>
#include<string>
using namespace std;

//实现通用 对数组进行排序的函数 
//规则 从大到小 
//算法  选择 
//测试  char数组、int数组

//交换函数模板
template<typename T>      //typename可以替换成 class 
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}   

//排序算法
template<class T>  
void mySort(T arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		int max=i;
		for(int j=i+1;j<len;j++)
		{
			if(arr[max]<arr[j])
			{
				max=j;
			}
		}
		if(max!=i)
		{
			mySwap(arr[max],arr[i]);
		}
	}
}

//提供打印数组模板
template<class T>
void printArray(T arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 


// 测试char数组
void test01()     
{
	char charArr[]="badfec";
	int len=sizeof(charArr)/sizeof(char);
	mySort(charArr,len);
	printArray(charArr,len);
}

// 测试int数组
void test02()     
{
	int intArr[]={2,5,1,6,8,4,7,5,0,1,3};
	int len=sizeof(intArr)/sizeof(int);
	mySort(intArr,len);
	printArray(intArr,len);
}


int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
} 
