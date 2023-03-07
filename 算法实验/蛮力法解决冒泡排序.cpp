#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
//对a[0..n-1]按递增有序进行冒泡排序
{  int i,j; int tmp;
   bool exchange;
   for (i=0;i<n-1;i++)	   //进行n-1趟排序
   {	exchange=false;	   //本趟排序前置exchange为false
	for (j=n-1;j>i;j--)	   //无序区元素比较,找出最小元素
          if (a[j]<a[j-1])	   //当相邻元素反序时
          {  swap(a[j],a[j-1]); //a[j]与a[j-1]进行交换
             exchange=true;	   //发生交换置exchange为true
          }
       if (exchange==false)  	   //本趟未发生交换时结束算法
         return;
   }
}
int main()
{
	int a[]={5,9,4,2,1};
	BubbleSort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
}
