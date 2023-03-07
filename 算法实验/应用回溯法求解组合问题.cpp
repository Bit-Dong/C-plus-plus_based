/*
【问题描述】编写一个实验程序，采用回溯法输出自然数1~n中任取r个数的所有组合。
*/
#include <iostream>
#include <vector>
using namespace std;
int n,r;
void disp(vector<int> path)
{
    for(int j=0;j<path.size();j++)
        cout<<path[j]<<" ";
    cout<<endl;
}
void dfs(vector<int> path,int i,int num)
{
    if(num==r)
        disp(path);
    for(int j=i;j<=n;j++)
    {
        path.push_back(j);
        dfs(path,j+1,num+1);
        path.pop_back();
    }
}
int main()
{
   cin>>n>>r;
   vector<int> path;
   dfs(path,1,0);
   return 0;
}
