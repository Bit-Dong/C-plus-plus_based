/*
题目描述:
附件 prog.txt 中是一个用某种语言写的程序。
其中 REPEAT k 表示一个次数为 k 的循环。循环控制的范围由缩进表达，从次行开始连续的缩进比该行多的（前面的空白更长的）为循环包含的内容。
例如如下片段：
	REPEAT 2;
		A=A+4;
			REPEAT 5;
			REPEAT 6;
				A=A+5;
			A=A+7;
		A=A+8;
	A=A+9;
	
该片段中从 A = A + 4 所在的行到 A = A + 8 所在的行都在第一行的循环两次中。
REPEAT 6: 所在的行到 A = A + 7 所在的行都在 REPEAT 5: 循环中。
A = A + 5 实际总共的循环次数是 2 × 5 × 6 = 60 次。
请问该程序执行完毕之后，A 的值是多少？

题目分析:
从题目中看出REPEAT就是一个for循环,后面的数字就是循环次数，循环控制的范围由缩进表达。然后模拟出题就可以
*/

#include<iostream>
using namespace std;

int main(){
	int A=0;
	
	for(int i=0;i<2;i++){
		A+=4;
		for(int j=0;j<5;j++){
			for(int k=0;k<6;k++){
				A+=5;
			}
			A+=7;
		}
		A+=8;		
	}
	A+=9;
	
	cout<<"A = "<<A<<endl;
}
