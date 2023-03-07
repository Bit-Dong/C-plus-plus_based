/*
题目描述:
数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一
部分的数列，只记得其中 N 个整数。
现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有
几项？
【输入格式】
输入的第一行包含一个整数 N。
第二行包含 N 个整数 A 1 ,A 2 ,··· ,A N 。(注意 A 1 ～ A N 并不一定是按等差数
列中的顺序给出)
【输出格式】
输出一个整数表示答案。
【样例输入】
5
2 6 4 10 20
【样例输出】
10
【样例说明】
包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、
18、20。
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int depthes[1000]={0},N,depth,sd[100]={0},max=0,f,h;
	cin>>N;
	depth=ceil(log2(N+1));
	for(int i=1;i<=N;i++){
		cin>>depthes[i];
	}
	for(int j=1;j<=N;j++){
		h=ceil(log2(j+1));
		sd[h]+=depthes[j];
	}
	for(int k=1;k<=depth;k++){
		if(sd[k]>max){
			max=sd[k];
			f=k;
		}
	}
	cout<<f<<endl;
}
