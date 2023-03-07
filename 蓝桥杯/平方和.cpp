/*
小明对数位中含有2、0、1、9的数字很感兴趣，在1到40中这样的数包括1、2、9、10至32、39和40，共28个，他们的和是574，平方和是14362。
注意，平方和是指将每个数分别平方后求和。
请问，在1到2019中，所有这样的数的平方和是多少?
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  // 请在此输入您的代码
  long long sum=0;
  for(int i=1;i<=2019;i++){
    string str=to_string(i);
    if(str.find("2")==-1&&str.find("0")==-1&&str.find("1")==-1&&str.find("9")==-1) continue;
    else sum+=i*i;
  }
  cout<<sum;
  return 0;
}
