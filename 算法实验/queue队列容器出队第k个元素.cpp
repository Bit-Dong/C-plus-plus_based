/*
【问题描述】编写一个实验程序，对于一个含n(n>1)个元素的queue<int>队列容器qu，
 			出队从队头到队尾的第k(1<=k<=n)个元素，其他队列元素不变。
*/

#include<iostream>
#include<queue>
using namespace std;
char solve(queue<char> &qu,int k)
{
    queue<char> temp;
    char e;
    for(int i=0;i<k-1;i++)
    {
        temp.push(qu.front());
        qu.pop();
    }
    e=qu.front();
    qu.pop();
    while(!qu.empty())
    {
        temp.push(qu.front());
        qu.pop();
    }
    qu=temp;
    return e;
}
int main()
{
    queue<char> qu;
    qu.push('a');
    qu.push('b');
    qu.push('c');
    qu.push('d');
    int k=3;
    char e=solve(qu,k);
    cout<<"出队元素是"<<e<<endl;
    cout<<"出队顺序是:";
    while(!qu.empty())
    {
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
    return 0;
}
