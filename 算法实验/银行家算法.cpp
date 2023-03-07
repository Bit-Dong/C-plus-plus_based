#include<stdio.h>
#include<string.h>
#define PN 5//进程数
#define RN 4//资源种类数

typedef struct//定义结构体类型pcb
{
    char name[3];//进程名，如p0
    int max[RN];//最大资源值
    int allocation[RN];//已分配资源数
    int need[RN];//任需求资源数
}pcb;

struct//定义为结构体类型，方便赋值
{
    int flag[PN];//进程检测标志，1时表示已通过
    int safes[PN];//存放进程编号，作为安全序列输出
}fs0,fs;//fs0保存初始值，fs用于工作

struct//定义为结构体类型，方便赋值
{
    int available[RN];//系统可用资源向量
}av0,av,avx;//av0保存初始值，av和avx用于工作

pcb proc0[PN],proc[PN];//proc0保存初始值，proc用于工作
int request[RN];//进程请求资源向量

void init();//初始化，输入数据
void output(pcb*);//输出数据
void cur_state();//判断系统当前状态
void req_state();//分析进程提出的请求是否可以响应
void back0();//退回至初始值
void back1(int);//退回至分配前
int check(int*);//进程need向量与available向量比较
int banker();//银行家算法

int main()
{
int num;
printf("【银行家算法】\n");
printf("进程数：%d\n",PN);
printf("资源数：%d\n",RN);
printf("=================\n");
    init();
    output(proc0);//输出初始资源分配情况
    printf("【系统当前状态分析】\n");
    cur_state();
    printf("======================================================\n\n");
    printf("选择操作序号(0:结束程序；1:资源请求分析)\n");
    printf("输入序号：");
    scanf("%d",&num);getchar();
    while(1)
    {
        switch(num)
        {
            case 1:printf("\n【进程资源请求分析】\n");req_state();break;
            default:printf("\n======分析结束！======\n");return 0;
        }
        printf("\n");
        printf("======================================================\n");
        printf("\n");
        printf("选择操作序号(0:结束程序；1:资源请求分析)\n");
        printf("输入序号：");
        scanf("%d",&num);getchar();
    }
}

void init()
{//初始化
int i,j;
    for(i=0;i<PN;i++)
    {
        printf("\n输入进程名：");
        gets(proc0[i].name);
        printf("输入max：");
        for(j=0;j<RN;j++)
            scanf("%d",&proc0[i].max[j]);
        printf("输入allocation：");
        for(j=0;j<RN;j++)
            scanf("%d",&proc0[i].allocation[j]);
        for(j=0;j<RN;j++)//计算need
            proc0[i].need[j]=proc0[i].max[j]-proc0[i].allocation[j];
        fs0.flag[i]=0;//进程标志位置0
        fs0.safes[i]=-1;//安全序列置-1
        proc[i]=proc0[i];//给工作矩阵proc赋值
        getchar();//吸收scanf()产生的回车符
    }
    printf("\n输入available：");
    for(j=0;j<RN;j++)
        scanf("%d",&av0.available[j]);
    fs=fs0;//给工作单元fs和av赋值
    av=av0;
    getchar();//吸收scanf()产生的回车符
}

void output(pcb* p)
{//输出资源分配情况，觉得麻烦可以不考虑
    int i,j;
    printf("\n");
    printf("===============================================================================\n");
    printf(" 标志位 | 进程名 |  最大值 \t|  已分配 \t|  需求值 \t|  可用数 \n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<PN;i++)
    {
        printf("   %-5d",fs.flag[i]);
        printf("|");
        printf("   %-5s",p[i].name);
        printf("| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].max[j]);
        printf("\t| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].allocation[j]);
        printf("\t| ");
        for(j=0;j<RN;j++)
            printf("%-3d",p[i].need[j]);
        printf("\t| ");
        if(i==0)
            for(j=0;j<RN;j++)
                printf("%-3d",av.available[j]);
        printf("\n");
    }
    printf("===============================================================================\n\n");
}

int banker()
{//银行家算法
    int i,j,t=0,k,f;
    k=0;//计数器，找到符合条件的进程数
    f=1;//标志位，每轮查找标志，f=0时该轮未找到合适进程，查找结束
    while(f==1&&k<PN)
    {
        f=0;//本轮查找标志置0
        for(i=0;i<PN;i++)
            if(!fs.flag[i]&&check(proc[i].need))
            {//找到符合条件的进程
                f=1;//本轮查找标志置1
                fs.flag[i]=1;//进程标志置1
                for(j=0;j<RN;j++)//修改available中的值
                    av.available[j]+=proc[i].allocation[j];
                fs.safes[t]=i;//进程序号i记入safes数组中，作为安全序列输出
                t++;k++;
            }
    }
    if(k<PN)return 0;//当k<PN时说明不存在安全序列，返回0
    else return 1;
}

int check(int* p)//p为当前进程的need向量
{//当前进程need向量与available向量比较
    int i;
    for(i=0;i<RN;i++)
        if(p[i]>av.available[i])return 0;//若检测不通过则返回0
    return 1;//检测通过
}

void cur_state()
{//检测系统当前状态
    int i;
    if(banker())
    {
        printf("分析结果：当前系统处于安全状态，存在安全序列 ");
        for(i=0;i<PN;i++)//输出安全序列
            printf("p%d",fs.safes[i]);
        printf("\n");
    }
    else
        printf("分析结果：当前系统处于不安全状态！请结束程序");
    //output(proc);//输出分析后的状态（查看flag和available状况）
    fs=fs0;av=av0;//退回至初始状态
    printf("\n\n");
}

void req_state()
{//对进程提出的资源请求，判断分配的可行性
    int i,j,n;
    printf("输入提出请求的进程序号n：p");
    scanf("%d",&n);
    printf("输入请求资源向量request：");
    for(i=0;i<RN;i++)
        scanf("%d",&request[i]);
    for(i=0;i<RN;i++)//判断请求的合法性
        if(request[i]>proc[n].need[i]||request[i]>av.available[i])
        {
            printf("分析结果：请求不合法，系统不予响应！");
            for(j=0;j<RN;j++)
                request[j]=0;//清空request
            return;
        }

    for(i=0;i<RN;i++)
    {//尝试分配，修改allocation,need和available的值
        av.available[i]-=request[i];
        proc[n].need[i]-=request[i];
        proc[n].allocation[i]+=request[i];

    }
    avx=av;//avx保存分配后available的值
    //output(proc);//输出分配后的资源分布状况
    if(banker())//调用银行家算法，寻找安全序列
    {
        printf("分析结果：当前系统处于安全状态，存在安全序列 ");
        for(i=0;i<PN;i++)//输出安全序列
            printf("p%d ",fs.safes[i]);
        printf("\n");
        av=avx;//分析结束，确定资源分配
        fs=fs0;//清空标识位flag和安全序列safes
    }
    else
    {
        printf("分析结果：不存在安全序列，系统不予响应，进程阻塞！\n");
        //output(proc);//输出分析结束后的情况（查看flag和available状况）
        back1(n);//取消分配，退回至分配前
        printf("已取消分配，退回至分配前\n");
    }
    printf("\n\n");
    printf("输入“y”可退回到初始状态，请选择(y/n)\n");
    printf("请输入：");
    getchar();//吸收前面的输入所产生的回车符
    if(getchar()=='y')
    {
        back0();
        printf("已退回至初始状态\n");
    }
}

void back0()
{//恢复至初始值
    int i;
    fs=fs0;
    av=av0;
    for(i=0;i<PN;i++)
        proc[i]=proc0[i];
}

void back1(int m)//m为提出资源请求的进程序号
{//撤销分配，退回至分配前
    int i;
    fs=fs0;
    for(i=0;i<RN;i++)
    {
        av.available[i]=avx.available[i]-request[i];
        proc[m].need[i]+=request[i];
        proc[m].allocation[i]-=request[i];
    }
}

