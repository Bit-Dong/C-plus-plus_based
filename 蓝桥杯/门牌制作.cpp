/*
题目描述:
小蓝要为一条街的住户制作门牌号。这条街一共有2020位住户，门牌号从1到2020编号。
小蓝制作门牌的方法是先制作0到9这几个数字字符，最后根据需要将字符粘贴到门牌上，
例如门牌1017需要依次粘贴字符1、0、1、7，即需要1个字符0，2个字符1，1个字符7。
请问要制作所有的1到2020号门牌，总共需要多少个字符2？
*/

#include<iostream>
using namespace std;

int panduan(int num){
	int sum=0;
	while(num){
		if(num%10==2){
			sum++;
		}
		num=num/10;
	}
	return sum;
}

int main(){
	int n;
	for(int i=0;i<=2020;i++){
		n+=panduan(i);
	}
	cout<<n;
} 
