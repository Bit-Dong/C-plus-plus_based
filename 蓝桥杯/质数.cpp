/*
我们知道第一个质数是2、第二个质数是 3第三个质数是5... 
请你计算第2019个质数是多少？
*/

#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int flag=0;
  int num=2;
  for(int i=5;i<20000;i++){
    flag=0;
    for(int j=2;j<i;j++){
      if(i%j==0){
        flag=1;
        break;
      }
    }
    if(flag==0){
      num++;
      if(num==2019) cout<<i;
    }
  }

  return 0;
}
