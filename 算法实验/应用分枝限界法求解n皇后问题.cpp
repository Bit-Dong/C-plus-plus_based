/*
【问题描述】在n×n的方格棋盘上，放置n个皇后，要求每个皇后不同行、不同列、不同左右对角线。
			如图1所示是6皇后问题的一个解。要求采用队列式分枝限界法求解4皇后问题的一个解，
			并分析对应程序运行中创建的队列结点的个数。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath> 
using namespace std;
int n=4;
int Count=1;
struct  NodeType
{
    int no;
    int row;
    vector<int> cols;
};
void dispnode(NodeType e)
{
    if(e.row!=-1)
        cout<<"编号"<<e.no<<"对应位置是："<<e.row<<","<<e.cols[e.row]<<endl;
    else
        cout<<"编号"<<e.no<<"对应位置是："<<e.row<<","<<"*"<<endl;
}
bool Valid(vector <int> cols,int i,int j)
{
    int k=0;
    while(k<i)
    {
        if((cols[k]==j)||(abs(cols[k]-j)==abs(k-i)))  return false;
        k++;
    }
    return true;
}
void solve()
{
    int i,j;
    NodeType e,el;
    queue<NodeType> qu;
    e.no=Count++;
    e.row=-1;
    qu.push(e);
    cout<<"进队:";
    dispnode(e);
    while(!qu.empty())
    {
        e=qu.front();qu.pop();
        cout<<"出队";
        dispnode(e);
        if(e.row==n-1)
        {
            cout<<"产生一个解:";
            for(int i=0;i<n;      i++)
            {
                cout<<i+1<<","<<e.cols[i]+1<<" ";
            }
            cout<<endl;
            return ;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                i=e.row+1;
                if(Valid(e.cols,i,j))
                {
                    el.no=Count++;
                    el.row=i;
                    el.cols=e.cols;
                    el.cols.push_back(j);
                    qu.push(el);
                    cout<<"进队子结点:";
                    dispnode(el);
                }
            }
        }
    }
}
int main()
{
   solve();
   return 0;
}
