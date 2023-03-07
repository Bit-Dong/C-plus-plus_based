//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#define MAX 10000
//
//typedef struct
//{
//    int track;//磁道号
//    int flag;//标志位，0表示未响应，1表示已响应过
//}diskreq;//一个访问请求
//
//diskreq *reqSeq;//访问序列指针
//int RN,START;//磁盘请求序列长度和磁头起点位置
//float meanD;//平均寻道长度
//
//void init();//初始化，输入访问序列
//void clear();//每趟分析前flag清零
//int search();//查找距离当前位置最近的请求点，返回磁道号
//void FCFS(diskreq*,int);//FCFS算法
//void SSTF(diskreq*,int);//SSTF算法
//void SCAN(diskreq*,int);//SCAN算法
//void CSCAN(diskreq*,int);//CSCAN算法
//void sort(diskreq*);//排序，在扫描算法中需要
//
//int main()
//{
//    int i,j,k,num;
//    init();//初始化
//    printf("操作说明：\n");
//    printf("    num=0  程序结束！\n");
//    printf("    num=1  FCFS算法\n");
//    printf("    num=2  SSTF算法\n");
//    printf("    num=3  SCAN算法\n");
//    printf("    num=4  CSCAN算法\n");
//    printf("==============================\n");
//    printf("\n");
//    printf("输入操作序号num：");
//    scanf("%d",&num);
//    while(1)
//    {
//        switch(num)
//        {
//            case 0:printf("\n=====程序结束！=====\n");return 0;
//            case 1:printf("\n【FCFS算法】\n");FCFS(reqSeq,START);break;
//            case 2:printf("\n【SSTF算法】\n");SSTF(reqSeq,START);break;
//            case 3:printf("\n【SCAN算法】\n");SCAN(reqSeq,START);break;
//            case 4:printf("\n【CSCAN算法】\n");CSCAN(reqSeq,START);break;
//            default:printf("\n=====重新输入=====\n");
//        }
//        printf("\n");
//        printf("输入操作序号num：");
//        scanf("%d",&num);
//    }
//}
//
//void init()
//{
//    int i;
//    printf("输入请求序列长度RN和磁头起点START：");
//    scanf("%d%d",&RN,&START);
//    printf("\n");
//    reqSeq=(diskreq*)malloc(RN*sizeof(diskreq));//建立请求序列数组
//    printf("输入请求序列reqSeq：");
//    for(i=0;i<RN;i++)
//        scanf("%d",&reqSeq[i].track);
//    printf("===================================================\n");
//}
//
//void clear()//标志位清零
//{
//    int i;
//    for(i=0;i<RN;i++)
//        reqSeq[i].flag=0;
//    meanD=0;
//}
//
//int search(diskreq* rq,int pos)
//{//查找距离当前位置最近的请求点
//    int i,d,mi,md=MAX;
//    for(i=0;i<RN;i++)
//        if(rq[i].flag==0)
//        {//只考虑标志位为0的请求点
//            d=abs(rq[i].track-pos);//每个请求点到当前位置的距离d
//            if(d<md)
//            {
//                mi=i;//最小距离请求点的下标mi
//                md=d;
//            }
//        }
//    rq[mi].flag=1;//标志位置1，表示已响应过
//    meanD=meanD+md;//寻到长度累加
//    return rq[mi].track;//返回最近磁道号
//}
//
//void sort(diskreq* rq)
//{
//    int i,j,t,temp;
//    for(i=0;i<RN-1;i++)//升序排序
//    {
//        t=i;
//        for(j=i+1;j<RN;j++)
//            if(rq[j].track<rq[t].track)t=j;
//        if(t!=i)
//        {
//           temp=rq[i].track;
//           rq[i].track=rq[t].track;
//           rq[t].track=temp;
//        }
//    }
//}
//
//void FCFS(diskreq* rq,int s)
//{//参数说明：（磁盘访问序列，磁头起点）
//    int i;
//    clear();//flag清零
//    meanD=abs(s-rq[0].track);//磁头移动到序列起点
//    printf("响应次序：%4d",rq[0].track);//输出第一个请求点
//    for(i=1;i<RN;i++)
//    {//依次求出每次磁头移动距离，并输出磁道号
//        meanD=meanD+abs(reqSeq[i].track-reqSeq[i-1].track);
//        printf("%4d",reqSeq[i].track);
//    }
//    printf("\n\n");
//    meanD=meanD/RN;//求出平均寻到长度
//    printf("平均寻道长度：%6.1f\n",meanD);
//    printf("==============================\n");
//}
//
//void SSTF(diskreq* rq,int s)
//{//参数说明：（磁盘访问序列，磁头起点）
//    int i=0;
//    clear();//flag清零
//    printf("响应次序：");
//    while(i<RN)
//    {//搜索最近请求点，直到结束
//        s=search(rq,s);
//        printf("%4d",s);
//        i++;
//    }
//    printf("\n\n");
//    meanD=meanD/RN;
//    printf("平均寻道长度：%6.1f\n",meanD);
//    printf("==============================\n");
//}
//
//void SCAN(diskreq* rq0,int s)
//{
//    int i,j,d,pos;
//    diskreq* rq;
//    rq=(diskreq*)malloc(RN*sizeof(diskreq));
//    //因为要对访问序列排序，所以需再建立一个数组
//    for(i=0;i<RN;i++)//复制访问序列
//        rq[i]=rq0[i];
//    sort(rq);//升序排序
//    i=0;
//    while(s>rq[i].track)i++;//找到s的位置
//    pos=i;
//    printf(" 1 表示磁头向磁道号增加方向移动\n");
//    printf(" 2 表示磁头向磁道号减少方向移动\n\n");
//    printf("请输入磁头移动方向d: ");
//    while(1)
//    {
//       scanf("%d",&d);
//       if(!(d==1||d==2))
//       {
//          printf("输入错误，请重新输入：");
//          continue;
//       }
//       break;
//    }
//    if(d==1)
//    {
//        if(s==rq[0].track||s==rq[RN-1].track)//当起点刚好在两个端点位置时；
//            meanD=rq[RN-1].track-rq[0].track;
//        else
//            meanD=2*rq[RN-1].track-s-rq[0].track;
//        printf("\n");
//        printf("响应次序：");//输出响应序列
//        for(j=pos;j<RN;j++)
//            printf("%4d",rq[j].track);
//        for(j=pos-1;j>=0;j--)
//            printf("%4d",rq[j].track);
//    }
//    else
//    {
//        if(s==rq[0].track||s==rq[RN-1].track)//当起点刚好在两个端点位置时；
//            meanD=rq[RN-1].track-rq[0].track;
//        else
//            meanD=rq[RN-1].track+s-2*rq[0].track;
//        printf("\n");
//        printf("响应次序：");//输出响应序列
//        for(j=pos-1;j>=0;j--)
//            printf("%4d",rq[j].track);
//        for(j=pos;j<RN;j++)
//            printf("%4d",rq[j].track);
//    }
//    printf("\n\n");
//    meanD=meanD/RN;
//    printf("平均寻道长度：%6.1f\n",meanD);
//    printf("==============================\n");
//}
//
//void CSCAN(diskreq* rq0,int s)
//{
//    int i,j,d,pos;
//    diskreq* rq;
//    rq=(diskreq*)malloc(RN*sizeof(diskreq));
//    //因为要对访问序列排序，所以需再建立一个数组
//    for(i=0;i<RN;i++)//复制访问序列
//        rq[i]=rq0[i];
//    sort(rq);//升序排序
//    i=0;
//    while(s>rq[i].track)i++;//找到s的位置
//    pos=i;
//    printf(" 1 表示磁头向磁道号增加方向移动\n");
//    printf(" 2 表示磁头向磁道号减少方向移动\n\n");
//    printf("请输入磁头移动方向d: ");
//    while(1)
//    {
//       scanf("%d",&d);
//       if(!(d==1||d==2))
//       {
//          printf("输入错误，请重新输入：");
//          continue;
//       }
//       break;
//    }
//    if(d==1)
//    {
//        if(s==rq[0].track||s==rq[RN-1].track)//当起点刚好在两个端点位置时；
//            meanD=rq[RN-1].track-rq[0].track;
//        else
//            meanD=2*(rq[RN-1].track-rq[0].track)-(s-rq[pos-1].track);
//        printf("\n");
//        printf("响应次序：");//输出响应序列
//        for(j=pos;j<RN;j++)
//            printf("%4d",rq[j].track);
//        for(j=0;j<pos;j++)
//            printf("%4d",rq[j].track);
//    }
//    else
//    {
//        if(s==rq[0].track||s==rq[RN-1].track)//当起点刚好在两个端点位置时；
//            meanD=rq[RN-1].track-rq[0].track;
//        else
//            meanD=2*(rq[RN-1].track-rq[0].track)-(rq[pos].track-s);
//        printf("\n");
//        printf("响应次序：");//输出响应序列
//        for(j=pos-1;j>=0;j--)
//            printf("%4d",rq[j].track);
//        for(j=RN-1;j>=pos;j--)
//            printf("%4d",rq[j].track);
//    }
//    printf("\n\n");
//    meanD=meanD/RN;
//    printf("平均寻道长度：%6.1f\n",meanD);
//    printf("==============================\n");
//}






#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000

typedef struct
{
    int track;//磁道号
    int flag;//标志位，0表示未响应，1表示已响应过
}diskreq;//一个访问请求

diskreq *reqSeq;//访问序列指针
int RN,START;//磁盘请求序列长度和磁头起点位置
float meanD;//平均寻道长度

void init();//初始化，输入访问序列
void clear();//每趟分析前flag清零
int search();//查找距离当前位置最近的请求点，返回磁道号
void FCFS(diskreq*,int);//FCFS算法
void sort(diskreq*);//排序，在扫描算法中需要

int main()
{
    int i,j,k,num;
    init();//初始化
	FCFS(reqSeq,START); 
}

void init()
{
    int i;
    printf("输入请求序列长度RN和磁头起点START：");
    scanf("%d%d",&RN,&START);
    printf("\n");
    reqSeq=(diskreq*)malloc(RN*sizeof(diskreq));//建立请求序列数组
    printf("输入请求序列reqSeq：");
    for(i=0;i<RN;i++)
        scanf("%d",&reqSeq[i].track);
    printf("===================================================\n");
}

void clear()//标志位清零
{
    int i;
    for(i=0;i<RN;i++)
        reqSeq[i].flag=0;
    meanD=0;
}

int search(diskreq* rq,int pos)
{//查找距离当前位置最近的请求点
    int i,d,mi,md=MAX;
    for(i=0;i<RN;i++)
        if(rq[i].flag==0)
        {//只考虑标志位为0的请求点
            d=abs(rq[i].track-pos);//每个请求点到当前位置的距离d
            if(d<md)
            {
                mi=i;//最小距离请求点的下标mi
                md=d;
            }
        }
    rq[mi].flag=1;//标志位置1，表示已响应过
    meanD=meanD+md;//寻到长度累加
    return rq[mi].track;//返回最近磁道号
}

void sort(diskreq* rq)
{
    int i,j,t,temp;
    for(i=0;i<RN-1;i++)//升序排序
    {
        t=i;
        for(j=i+1;j<RN;j++)
            if(rq[j].track<rq[t].track)t=j;
        if(t!=i)
        {
           temp=rq[i].track;
           rq[i].track=rq[t].track;
           rq[t].track=temp;
        }
    }
}

void FCFS(diskreq* rq,int s)
{//参数说明：（磁盘访问序列，磁头起点）
    int i;
    clear();//flag清零
    meanD=abs(s-rq[0].track);//磁头移动到序列起点
    printf("响应次序：%4d",rq[0].track);//输出第一个请求点
    for(i=1;i<RN;i++)
    {//依次求出每次磁头移动距离，并输出磁道号
        meanD=meanD+abs(reqSeq[i].track-reqSeq[i-1].track);
        printf("%4d",reqSeq[i].track);
    }
    printf("\n\n");
    meanD=meanD/RN;//求出平均寻到长度
    printf("平均寻道长度：%6.1f\n",meanD);
    printf("==============================\n");
}

