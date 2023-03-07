/*
【问题描述】给定一个m行n列的矩阵,从左上角开始每次只能向右或者向下移动,
			最后到达右下角的位置,路径上的所有数字累加起来作为这条路径的路径和。
			编写一个实验程序求所有路径和中的最小路径和。例如,以下矩阵中的路径
			1→3→1→0→6→1→0是所有路径中路径和最小的，返回结果是12：
	1 3 5 9
	8 1 3 4
	5 0 6 1
	8 8 4 0
*/
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
#define MAXM 100
#define MAXN 100
//问题表示
int a[MAXM][MAXN]={{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
int m=4,n=4;
//求解结果表示
int ans;						//最小路径长度
int dp[MAXM][MAXN];
int pre[MAXM][MAXN];
void Minpath()					//求最小和路径ans 
{	int i,j;
	dp[0][0]=a[0][0];
	for(i=1;i<m;i++)				//计算第一列的值
	{	dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;			//垂直路径
	}
	for(j=1;j<n;j++)				//计算第一行的值
	{	dp[0][j]=dp[0][j-1]+a[0][j];
		pre[0][j]=1;			//水平路径
	}
	for(i=1;i<m;i++)				//计算其他dp值
		for(j=1;j<n;j++)
		{	if (dp[i][j-1]<dp[i-1][j])
			{	dp[i][j]=dp[i][j-1]+a[i][j];
				pre[i][j]=1;
			}
			else
			{	dp[i][j]=dp[i-1][j]+a[i][j];
				pre[i][j]=0;
			}
		}
	ans=dp[m-1][n-1];
}
void Disppath()					//输出最小和路径
{	int i=m-1,j=n-1;
	vector<int> path;				//存放反向最小路径
	vector<int>::reverse_iterator it;
	while (true)
	{	path.push_back(a[i][j]);
		if (i==0 && j==0) break;
		if (pre[i][j]==1)	j--;		//同行
		else i--;				//同列
	}
	printf("    最短路径: ");
	for (it=path.rbegin();it!=path.rend();++it)
		printf("%d ",*it);		//反向输出构成正向路径
	printf("\n    最短路径和:%d\n",ans);
}
int main()
{
	Minpath();					//求最小路径和
	printf("求解结果\n");
	Disppath();					//输出求最小路径与最小路径和
	return 0;
}

