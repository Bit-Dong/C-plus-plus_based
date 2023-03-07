/*
请你找到最小的整数X 同时满足：X是2019的整倍数；X的每一位数字都是奇数。
*/
#include <iostream>
using namespace std;

int main()
{
  // 请在此输入您的代码
  int n1,n2,n3,n4,n5,n6;
  for(int i=2019;;i++){
        n1=i%10;
        n2=i/10%10;
        n3=i/100%10;
        n4=i/1000%10;
        n5=i/10000%10;
        n6=i/100000%10;
        if(i%2019==0&&n1%2==1&&n2%2==1&&n3%2==1&&n4%2==1&&n5%2==1&&n6%2==1){
          cout<<i;
          return 0;
        }
    }
  return 0;
}

