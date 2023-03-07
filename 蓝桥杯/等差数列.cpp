/*
数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一部分的数列，只记得其中N个整数。
现在给出这N个整数，小明想知道包含这N个整数的最短的等差数列有几项？
输入描述
输入的第一行包含一个整数 N。第二行包含N个整数A1,A2...An 。(注意并不一定是按等差数列中的顺序给出)
输出一个整数表示答案。
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,min=10000;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int j=0;j<n-1;j++){
    if(a[j+1]-a[j]<min){
        min=a[j+1]-a[j];
    }
  }
  int m=(a[n-1]-a[0])/min;
  if(min==0) cout<<n;
  else cout<<m+1;
  return 0;
}
