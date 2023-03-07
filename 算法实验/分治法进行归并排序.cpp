/*
分治法进行归并排序
*/

#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
void Merge(int a[],int low,int mid,int high)
{
    int *tmpa;
    int i=low,j=mid+1,k=0;
    tmpa=(int *)malloc((high-low+1)*sizeof(int));
    while(i<=mid&&j<=high)
        if(a[i]<=a[j])  //将第1子表中的元素放入tmpa中
        {
            tmpa[k]=a[i];  i++; k++;
        }
        else   //将第2子表中的元素放入tmpa中
        {
            tmpa[k]=a[j];j++;k++;
        }
    while (i<=mid)		//将第1子表余下部分复制到tmpa
    {  tmpa[k]=a[i]; i++; k++; }
    while (j<=high)		//将第2子表余下部分复制到tmpa
    {  tmpa[k]=a[j]; j++; k++; }
    for(k=0,i=low;i<=high;k++,i++) //将tmpa复制回a中
        a[i]=tmpa[k];
    free(tmpa);			//释放tmpa所占内存空间
}
//一趟二路归并排序
void MergePass(int a[],int length,int n)
{
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)  //归并length长的两相邻子表
        Merge(a,i,i+length-1,i+2*length-1);
    if(i+length-1<n)   //余下两个子表，后者长度小于length
        Merge(a,i,i+length-1,n-1);  //归并这两个子表
}
void MergeSort(int a[],int n)	//二路归并算法
{  int length;
   for (length=1;length<n;length=2*length)
    MergePass(a,length,n);
}
int main()
{
    int a[]={2,5,1,7,10,6,9,4,3,8};
    MergeSort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
