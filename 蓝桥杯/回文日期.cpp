/*
题目描述
2020年春节期间，有一个特殊的日期引起了大家的注意：2020年2月2日。因为如果将这个日期按“yyyymmdd”的格式写成一个8位数是20200202，恰好是一个回文数。我们称这样的日期是回文日期。有人表示20200202是“千年一遇”的特殊日子。对此小明很不认同，因为不到2年之后就是下一个回文日期：20211202即2021年12月2日。也有人表示20200202并不仅仅是一个回文日期，还是一个ABABBABA型的回文日期。对此小明也不认同，因为大约100年后就能遇到下一个ABABBABA型的回文日期：21211212即2121年12月12日。算不上“千年一遇”，顶多算“千年两遇”。给定一个8位数的日期，请你计算该日期之后下一个回文日期和下一个ABABBABA型的回文日期各是哪一天。

【输入格式】
输入包含一个八位整数N，表示日期。

【输出格式】
输出两行，每行1个八位数。第一行表示下一个回文日期，第二行表示下一个ABABBABA型的回文日期。

【样例输入】
20200202

【样例输出】
20211202
21211212

【评测用例规模与约定】
对于所有评测用例，10000101 <= N <= 89991231，保证N是一个合法日期的8位数表示。
*/

#include<iostream>
using namespace std;

int leap(int year){
	if((year%4==0&&year%100!=0)||year%400==0) return 1;
}

int palindromic(int num){
	int m,m1,m2,m3,m4,m5,m6,m7,m8;
	m1=(num%10)*10000000;
	m2=(num/10%10)*1000000;
	m3=(num/100%10)*100000;
	m4=(num/1000%10)*10000;
	m5=(num/10000%10)*1000;
	m6=(num/100000%10)*100;
	m7=(num/1000000%10)*10;
	m8=num/10000000;
	m=m1+m2+m3+m4+m5+m6+m7+m8;
	if(num==m) return 1;
	else return 0;
}

int main(){
	
	int monthes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day,n,year0,month0,day0,n1,n2,n3,n4,n5,n6,n7,n8,m,m1,m2,m3,m4,m5,m6,m7,m8,k1,k2,k3,k4,k5,k6,k7,k8;
	int num;
	cin>>num; 
	if(!palindromic(num)) return 0;
	n1=(num/10000000)*1000;
	n2=(num/1000000%10)*100;
	n3=(num/100000%10)*10;
	n4=(num/10000%10);
	n5=(num/1000%10)*10;
	n6=(num/100%10);
	n7=(num/10%10)*10;
	n8=(num%10);
	year0=n1+n2+n3+n4;
	month0=n5+n6;
	day0=n7+n8;
		
	for(year=year0;year<10000;year++){
		if(leap(year)==1) monthes[2]=29;
		else monthes[2]=28;
		for(month=month0;month<13;month++){
			for(day=day0+1;day<monthes[month];day++){
				n=year*10000+month*100+day;
				m1=(day%10)*10000000;
				m2=(day/10)*1000000;
				m3=(month%10)*100000;
				m4=(month/10)*10000;
				m5=(year%10)*1000;
				m6=(year/10%10)*100;
				m7=(year/100%10)*10;
				m8=year/1000;
				k1=(day%10);
				k2=(day/10);
				k3=(month%10);
				k4=(month/10);
				k5=(year%10);
				k6=(year/10%10);
				k7=(year/100%10);
				k8=year/1000;
				m=m1+m2+m3+m4+m5+m6+m7+m8;
				if((n==m)&&(k8==k1)&&(k6==k1)&&(k3==k1)&&(k7==k2)&&(k5==k2)&&(k4==k2)) {
					cout<<n<<endl;	
					return 0;
				}
				
			}
		}
	}
}
