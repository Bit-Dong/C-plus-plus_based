#include <iostream>
using namespace std;
#define MAXN 20

//问题表示
int n=4;			//4种物品
int W=6;			//限制重量为6
int w[]={0,5,3,2,1};		//存放4个物品重量,不用下标0元素
int v[]={0,4,4,3,1};		//存放4个物品价值,不用下标0元素
//求解结果表示
int x[MAXN];			//存放最终解
int maxv; 			//存放最优解的总价值

void dfs(int i,int tw,int tv,int rw,int op[])
{  if (i>n)				//找到一个叶子结点
   {  if (tw==W && tv>maxv)		//找到一个满足条件的更优解,保存
      {  maxv=tv;
         for (int j=1;j<=n;j++)
            x[j]=op[j];
      }
   }
   else					//尚未找完所有物品
   {
       if ( tw+w[i]<=W )		//左孩子结点剪枝
      {  op[i]=1;			//选取第i个物品
         dfs(i+1,tw+w[i],tv+v[i],rw-w[i],op);
      }

      if (  tw+rw-w[i]>=W )  //右孩子结点剪枝
      {  op[i]=0;			 //不选取第i个物品,回溯
          dfs(i+1,tw,tv,rw-w[i],op);
      }

   }
}

int main()
{
    int op[MAXN];
    dfs(1,0,0,11,op);
    cout<<"最优值是："<<maxv<<endl;
    for(int j=1;j<=n;j++)
        cout<<x[j]<<" ";

}
