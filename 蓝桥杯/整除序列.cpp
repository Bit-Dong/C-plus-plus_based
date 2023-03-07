/*
题目描述:
有一个序列，序列的第一个数是 n，后面的每个数是前一个数整除 2，请输出这个序列中值为正数的项。
【输入格式】
输入一行包含一个整数 n。
【输出格式】
输出一行，包含多个整数，相邻的整数之间用一个空格分隔，表示答案。
【评测用例规模与约定】
对于 80% 的评测用例，1≤n≤109。
对于所有评测用例，1≤n≤1018。
*/

#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int a[100],j=0,i,s;
	cin>>i;
	while(i){
		a[j]=i/2;
		i=i/2;
		j++;
		s++;
	}
	
	for(int m=0;m<s-2;m++){
		cout<<a[m];
		if(a[m+1]!=0)  cout<<",";
	}
}
