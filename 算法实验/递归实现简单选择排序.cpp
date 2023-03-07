/*
递归实现简单选择排序
*/

#include<iostream>
using namespace std;
void SelectSort(int a[], int n, int i)
{   int j, k;
    if (i==n-1) return;	//满足递归出口条件
    else
    {
    	k=i;			//k记录a[i..n-1]中最小元素的下标
    	for (j=i+1;j<n;j++)  	//在a[i..n-1]中找最小元素
		    if (a[j]<a[k])
		        k=j;
	    if (k!=i)		//若最小元素不是a[i]
	        swap(a[i],a[k]);	//a[i]和a[k]交换
     	SelectSort(a,n,i+1);
    	
    	
	}
}
int main()
{
	int a[10]={5,4,6,2,1,0,3,8,7,9};
	SelectSort(a,10,0);
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<' ';
 } 
