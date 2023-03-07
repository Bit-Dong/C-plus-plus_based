/*
递归实现冒泡排序
*/
#include<iostream>
using namespace std;
void BubbleSort(int a[], int n,int i)
{   int  j;
    bool exchange;
    if (i==n-1) return;		//满足递归出口条件
    else
    {
    	exchange=false;		//置exchange为false
    	for(j=n-1;j>i;j--)
		    if(a[j]<a[j-1]) //当相邻元素反序时
		    {
		    	swap(a[j],a[j-1]);
		    	exchange=true; //发生交换置exchange为true
			}
		
		if(exchange==false) //未发生交换时直接返回　
	    	return ;
	    else                   //发生交换时继续递归调用
            BubbleSort(a,n,i+1);	        
    	
	}
}
int main()
{
	int a[10]={5,4,6,2,1,0,3,8,7,9};
	BubbleSort(a,10,0);
	
	for(int i=0;i<10;i++)
	cout<<a[i]<<' ';
 } 
