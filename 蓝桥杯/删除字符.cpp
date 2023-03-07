/*
给定一个单词，请问在单词中删除t个字母后，能得到的字典序最小的单词是什么？

输入描述
输入的第一行包含一个单词，由大写英文字母组成。
第二行包含一个正整数 t。其中，单词长度不超过100，t小于单词长度。
输出描述
输出一个单词，表示答案。
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string str;
  int n;
  cin>>str;
  cin>>n;
  int f=str.length()-1;
  while(n--){
    for(int i=0;i<str.length()-1;i++){
      if(str[i]>str[i+1]){
        f=i;
        break;
      }
    }
    str[f]='0';
  }

  for(int j=0;j<str.length();j++){
    if(str[j]!='0') cout<<str[j];
  }
  return 0;
}
