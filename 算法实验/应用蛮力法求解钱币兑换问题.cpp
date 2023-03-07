/*
【问题描述】某个国家仅有1分、2分和5分硬币，将钱n(n>=5)兑换成硬币有很多种兑法。
			编写一个实验程序计算出10分钱有多少种兑法，并列出每种兑换方式。
*/
#include<iostream>
using namespace std;
int main()  
{
	int n=10;
	int x,y,z;
	int num=0;
	
	for(z=0;z<=2;z++)
	{
		for(y=0;y<=5;y++)
		{
			for(x=0;x<=10;x++)
			{
				if(z*5+y*2+x*1==10)
				{
					cout<<"兑换方式"<<++num; 
					if(z!=0) cout<<" 5分的硬币有："<<z<<"个"; 
					if(y!=0) cout<<" 2分的硬币有："<<y<<"个"; 
					if(x!=0) cout<<" 1分的硬币有："<<x<<"个"; 
					
					cout<<endl;
				}
			}
		}
	
	}
	cout<<"共有"<<num<<"种兑换方式"<<endl; 
	 
	return 0;
}
