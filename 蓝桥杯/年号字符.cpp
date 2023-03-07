/*
题目描述:
小明用字母 A对应数字 1，B对应 2，以此类推，用 Z对应 26。对于 27以上的数字，小明用两位或更长位的字符串来对应，例如 AA对应27，AB对
应28，AZ对应52，LQ对应329。
请问2019对应的字符串是什么？

题目分析:
这题就是类似于一个进制转换，你可以回想一下十进制转二进制如何转换，然后再想想将十进制转化成26进制，口诀就是除p取余
*/

#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n=2019;
	stack<int> s;
	int temp;
	while(n){
		temp=n%26;
		s.push(temp);
		n/=26;
	}
	while(!s.empty()){
		char c=s.top()+64;
		cout<<c;
		s.pop();
	}
}
