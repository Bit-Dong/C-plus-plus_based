/*
题目描述:
给定数列1,1,1,3,5,9,17,…，从第4项开始，每项都是前3项的和。求
第20190324项的最后4位数字。

题目分析:
应为保留最后四位数字，所以每次计算过后需要用10000取余，不然会溢出
*/

#include<iostream>
using namespace std;

int main(){
	int n0=0,n1=1,n2=1,n3=1,n=3;
	long long int s=0;
	while(n){
		s=n1+n2+n3;
		s%=10000;
		n1=n2;
		n2=n3;
		n3=s;
		
		n++;
		if(n==20190324) break;
	}	
	cout<<s;
}
