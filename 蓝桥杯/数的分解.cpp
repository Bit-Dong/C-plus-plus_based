/*
题目描述
把 2019分解成 3个各不相同的正整数之和，并且要求每个正整数都不包
含数字2和4，一共有多少种不同的分解方法？
注意交换 3个整数的顺序被视为同一种方法，例如 1000+1001+18和
1001+1000+18被视为同一种。
*/
#include <iostream>
using namespace std;

bool check(int n){
  for(int i=0;n!=0;i++){
    if(n%10==2||n%10==4) return false;
    else n/=10;
  }
  return true;
}

int main()
{
  int num=0;
  for(int num1=1;num1<=2019/3;num1++){
    if(check(num1)){
      for(int num2=num1+1;num2<=(2019-num1)/2;num2++){
        if(check(num2)){
          int num3=2019-num1-num2;
          if(check(num3)&&num3>num2) num++;
        }
      }
    }
  }
  cout<<num;
  return 0;
}
