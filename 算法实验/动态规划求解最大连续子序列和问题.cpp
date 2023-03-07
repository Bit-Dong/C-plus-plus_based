#include<iostream>
using namespace std;
int a[]={0,-2,11,-4,13,-5,-2};
int n=6;
int dp[20];
void maxsubsum()
{
    dp[0]=0;
    for(int j=1;j<=n;j++)
        dp[j]=max(dp[j-1]+a[j],a[j]);
}
void dispmaxsum()
{
    int  maxj=1;
    for(int j=1;j<=n;j++)
        if(dp[j]>dp[maxj]) maxj=j;
    int k;
    for(k=maxj;k>=1;k--)
        if(dp[k]<=0) break;
    cout<<dp[maxj]<<endl;
    for(int i=k+1;i<=maxj;i++)
        cout<<a[i]<<" ";
}
int main()
{
    maxsubsum();
    dispmaxsum();
    return 0;
}
