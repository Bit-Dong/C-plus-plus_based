/*
题目描述:
小蓝给学生们组织了一场考试，卷面总分为100分，每个学生的得分都是一个0到100的整数。如果得分至少是60分，则称为及格。如果得分至少为85分，则称为优秀。请计算及格率和优秀率，用百分数表示，百分号前的部分四舍五入保留整数。
【输入格式】 输入的第一行包含一个整数n，表示考试人数。接下来n行，每行包含一个0至100的整数，表示一个学生的得分。
【输出格式】 输出两行，每行一个百分数，分别表示及格率和优秀率。百分号前的部分四舍五入保留整数。
【样例输入】
7
80
92
56
74
88
100
0
【样例输出】
71%
43%
*/

#include<iostream>
using namespace std;

int main(){
	int n,bad=0,good=0,b,f;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=85){
			good++;	
		}
		if(a[i]>=60){
			bad++;
		}
		
	}
	b=bad*100.0/n*1.0+0.5;
	f=good*100.0/n*1.0+0.5;
	cout<<b<<"%"<<endl;
	cout<<f<<"%"<<endl;
}
