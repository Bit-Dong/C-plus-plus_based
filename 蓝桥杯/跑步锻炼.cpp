/*
题目描述:
小蓝每天都锻炼身体。正常情况下，小蓝每天跑1千米。如果某天是周一或者月初（1日），为了激励自己，小蓝要跑2千米。
如果同时是周一或月初，小蓝也是跑2千米。小蓝跑步已经坚持了很长时间，从2000年1月1日周六（含）到2020年10月1日周四（含）。
请问这段时间小蓝总共跑步多少千米？

题目分析:
首先算出总的天数，和月份数，然后求出一共有多少个周一，和周一中为月份的天数
最后总天数+周一天数+月初天数 - 周一和月初重合天数
*/

#include<iostream>
using namespace std;

int panduan(int a){
	if((a%4==0&&a%100!=0)||a%400==0)  return 1;
	else return 0;
}

int main(){
	int sum=0;
	int monthes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int mon=6;  //星期几 
	for(int year=2000;year<=2020;year++){
		if(panduan(year)) monthes[2]=29;
		else monthes[2]=28;
		for(int month=1;month<=12;month++){
			for(int day=1;day<=monthes[month];day++){
				if(mon==8) mon=1;
				
				if(mon==1&&day==1){
					sum+=2;
				}
				else if(mon==1||day==1){
					sum+=2;
				}
				else sum+=1;
				
				if(year==2020&&month==10&&day==1) {
					cout<<sum;
					return 0;
				}
				mon++;				
			}
			
		}
		
	}
}
