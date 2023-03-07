/*
【问题描述】给定含有n个元素的多重集合S，每个元素在S中出现的次数称为该元素的重数。
			多重集S中重数最大的元素称为众数。?例如，S={1，2，2，2，3，5}。??多重集S的众数是2，
			其重数为3。??对于给定的由n 个自然数组成的多重集S，编程计算S 的众数及其重数。
*/
#include <iostream>
#include<algorithm>
using namespace std;
#define M 100
int a[M];
int num,val,n; //重数, 众数,个数、
 
void find(int &l,int &r,int mid)//找中位数的最左，最右边界位置
{
	l = r= mid;
 	while(a[l]==a[mid] && l>= 0) --l;
 	l++; //还原
 	while(a[r]==a[mid] && r<= n-1) ++r;
 	r--;
}

void Fun(int low,int high)
{
	if(low > high) return; //左右边界交叉，结束
	int mid = (low + high)/2; //中位数
	int i,j;
	find(i,j,mid);
	if(j-i+1 > num)
	{ //更新
		num = j-i+1;
		val = a[mid];
 	}
 	if(i-low > num)
	{//分治递归
  		Fun(low,i-1);
 	}
 	if(high -j > num)
	 {
  		Fun(j+1,high);
 	}
}
int main()
{
    int  i;
    cout<<"输入元素个数：\n";
    cin>>n;
    cout<<"输入元素：\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
        cout<<a[i]<<",";
    Fun(0,n-1);
    cout<<endl<<"众数："<<val<<" 重数："<<num;
    return 0;
}
