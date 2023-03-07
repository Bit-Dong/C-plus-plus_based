/*
分治法进行快排
*/

#include<iostream>
using namespace std;
int Partition(int a[],int s,int t)	//划分算法
{   int i=s,j=t;
    int temp=a[s];	//用序列的第1个记录作为基准
    while(i!=j)
    {
        while(j>i&&a[j]>=temp)
            j--;   //从右向左扫描，找第1个关键字小于tmp的a[j]
        a[i]=a[j];	//将a[j]前移到a[i]的位置
        while(i<j&&a[i]<temp)
            i++;//从左向右扫描，找第1个关键字大于tmp的a[i]
        a[j]=a[i];	//将a[i]后移到a[j]的位置
    }
    a[i]=temp;
    return i;
}
void QuickSort(int a[],int s,int t)
//对a[s..t]元素序列进行递增排序
{  if (s<t) 			//序列内至少存在2个元素的情况
   {   int i=Partition(a,s,t);
       QuickSort(a,s,i-1);	//对左子序列递归排序
       QuickSort(a,i+1,t);	//对右子序列递归排序
   }
}
int main()
{
    int a[10]={5,4,6,2,10,0,3,8,7,9};
    QuickSort(a,0,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
