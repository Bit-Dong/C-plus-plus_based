#include<stdio.h>
#include<stdlib.h>
#define N 5     //进程数目
#define START 0 //调度起始时间

typedef struct{
    char pro_name;//进程名
    int arr_time;//到达时间
    int ser_time;//服务时间
    int com_time;//完成时间
    float tur_time;//周转时间
    float wei_time;//带权周转时间
    int flag;//运行标记，0表示未运行，1表示已运行
    }pcb;//定义进程pcb类型

    float mean_time;//平均周转时间
    float meanw_time;//平均带权周转时间
    int last_time;//前一个进程结束时间

    pcb* init();//初始化，输入初始数据
    void clear(pcb*);//清除前一个实验的数据
    void output(pcb*);//输出结果
    void FCFS(pcb*);
    void SPF(pcb*);
    void RR(pcb*);

int main()
{
    pcb* proc;
    int num;
    proc=init();
    printf("\n");
    printf("===============================================================\n");
    printf("num值对应操作序号：\n\n");
    printf("   num=0  结束操作\n");
    printf("   num=1  FCFS算法\n");
    printf("   num=2  SPF算法\n");
    printf("   num=3  RR算法\n");
    printf("===============================================================\n");
    printf("\n");
    printf("选择操作序号(num)：");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
            case 0:printf("\n===操作结束！===\n");return 0;
            case 1:printf("\n【FCFS算法】\n");FCFS(proc);break;
            case 2:printf("\n【SPF算法】\n");SPF(proc);break;
            case 3:printf("\n【RR算法】\n");RR(proc);
        }
        printf("\n");
        printf("===============================================================\n");
        printf("\n");
        printf("选择操作序号(num)：");
        scanf("%d",&num);
    }
}

pcb* init()
{
    pcb* p;
    int i;
    p=(pcb*)malloc(N*sizeof(pcb));
    printf("进程初始数据（名称,到达时间,服务时间）：\n");
    for(i=0;i<N;i++)
    {
        scanf("%c%d%d",&p[i].pro_name,&p[i].arr_time,&p[i].ser_time);
        getchar();
        p[i].flag=0;
        mean_time=0.0;
        meanw_time=0.0;
    }
    return p;
}

void output(pcb* p)
{
    int i;
    printf("进程名  到达时间  服务时间  完成时间  周转时间  带权周转时间\n");
    for(i=0;i<N;i++)
        printf("  %-8c%-10d%-10d%-10d%-10.0f%-10.1f\n",p[i].pro_name,p[i].arr_time,p[i].ser_time,p[i].com_time,p[i].tur_time,p[i].wei_time);
    printf("\n");
    printf("平均周转时间：%10.1f\n",mean_time);
    printf("平均带权周转时间：%6.1f",meanw_time);
}
void clear(pcb* p)
{
    int i;
    for(i=0;i<N;i++)
    {
        p[i].com_time=0;
        p[i].tur_time=0.0;
        p[i].wei_time=0.0;
        p[i].flag=0;
        mean_time=0.0;
        meanw_time=0.0;
    }
}

void FCFS(pcb* p)
{
    int i;
    clear(p);
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)
    {
        if(last_time>p[i].arr_time)p[i].com_time=last_time+p[i].ser_time;
        else p[i].com_time=p[i].arr_time+p[i].ser_time;
        p[i].tur_time=p[i].com_time-p[i].arr_time;
        p[i].wei_time=p[i].tur_time/p[i].ser_time;
        p[i].flag=1;
        mean_time=mean_time+p[i].tur_time;
        meanw_time=meanw_time+p[i].wei_time;
        last_time=p[i].com_time;
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}
void SPF(pcb* p)
{
    int i,j,k,shortp;//k表示短进程所在下标，shortp表示短进程服务时间 
    clear(p);
    k=0;//选中的进程编号
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)
    {
        shortp=p[k].ser_time;
        for(j=0;j<N;j++)//在尚未运行的已到达进程中搜索最短进程，标记为k
            if(p[j].flag==0&&p[j].arr_time<=last_time&&p[j].ser_time<shortp)
            {
                k=j;
                shortp=p[k].ser_time;
            }
        if(p[k].arr_time<last_time)p[k].com_time=last_time+p[k].ser_time;
        else p[k].com_time=p[i].arr_time+p[k].ser_time;
        p[k].tur_time=p[k].com_time-p[k].arr_time;
        p[k].wei_time=p[k].tur_time/p[k].ser_time;
        p[k].flag=1;
        mean_time=mean_time+p[k].tur_time;
        meanw_time=meanw_time+p[k].wei_time;
        last_time=p[k].com_time;
        for(j=0;j<N;j++)//在剩余的尚未运行的进程中查找第一个，标记为k
            if(p[j].flag==0)break;
        k=j;
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}
void RR(pcb* p)
{
    int i,j,k=0;//k表示已完成进程数，j记录新起点编号
    int quantum;//时间片大小
    int rrtime[N];//记录进程剩余时间，rrtime[i]=0时进程p[i]结束
    int flagrr;
    clear(p);
    printf("时间片大小quantum：");
    scanf("%d",&quantum);
    last_time=START;
    mean_time=0.0;
    for(i=0;i<N;i++)//进程服务时间作为rrtime初值
        rrtime[i]=p[i].ser_time;
    flagrr=1;
    j=0;
    while(k<N)
    {
        i=0;
        if(flagrr==0)
        {
            i=j;
            last_time=p[i].arr_time;
        }
        flagrr=0;
        while(i<N&&p[i].arr_time<=last_time)
        {//对已到达且为运行完毕的进程在rrtime相应元素减去一个时间片
            if(p[i].flag==0)
            {
                flagrr=1;
                rrtime[i]=rrtime[i]-quantum;
                last_time=last_time+quantum;
                if(rrtime[i]<=0)
                {
                    last_time=last_time+rrtime[i];
                    p[i].com_time=last_time;
                    p[i].tur_time=p[i].com_time-p[i].arr_time;
                    p[i].wei_time=p[i].tur_time/p[i].ser_time;
                    p[i].flag=1;
                    mean_time=mean_time+p[i].tur_time;
                    meanw_time=meanw_time+p[i].wei_time;
                    k++;
                    if(k>=N)break;
                }
            }
            i++;
            if(i>j)j=i;
        }
    }
    mean_time=mean_time/N;
    meanw_time=meanw_time/N;
    output(p);
}



//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 5     //进程数目
//#define START 0 //调度起始时间
//
//typedef struct{
//    char pro_name;//进程名
//    int arr_time;//到达时间
//    int ser_time;//服务时间
//    int com_time;//完成时间
//    float tur_time;//周转时间
//    float wei_time;//带权周转时间
//    int flag;//运行标记，0表示未运行，1表示已运行
//    }pcb;//定义进程pcb类型
//
//    float mean_time;//平均周转时间
//    float meanw_time;//平均带权周转时间
//    int last_time;//前一个进程结束时间
//
//    pcb* init();//初始化，输入初始数据
//    void output(pcb*);//输出结果
//    void FCFS(pcb*);
//
//int main()
//{
//    pcb* proc;
//proc=init();
//FCFS(proc);
// }
//
//pcb* init()
//{
//    pcb* p;
//    int i;
//    p=(pcb*)malloc(N*sizeof(pcb));
//    printf("进程初始数据（名称 到达时间 服务时间）：\n");
//    for(i=0;i<N;i++)
//    {
//        scanf("%c%d%d",&p[i].pro_name,&p[i].arr_time,&p[i].ser_time);
//        getchar();
//        p[i].flag=0;
//        mean_time=0.0;
//        meanw_time=0.0;
//    }
//    return p;
//}
//
//void output(pcb* p)
//{
//    int i;
//    printf("进程名  到达时间  服务时间  完成时间  周转时间  带权周转时间\n");
//    for(i=0;i<N;i++)
//        printf("  %-8c%-10d%-10d%-10d%-10.0f%-10.1f\n",p[i].pro_name,p[i].arr_time,p[i].ser_time,p[i].com_time,p[i].tur_time,p[i].wei_time);
//    printf("\n");
//    printf("平均周转时间：%10.1f\n",mean_time);
//    printf("平均带权周转时间：%6.1f",meanw_time);
//}
//
//void FCFS(pcb* p)
//{
//    int i;
//    last_time=START;
//    mean_time=0.0;
//    for(i=0;i<N;i++)
//    {
//        if(last_time>p[i].arr_time)p[i].com_time=last_time+p[i].ser_time;
//        else p[i].com_time=p[i].arr_time+p[i].ser_time;
//        p[i].tur_time=p[i].com_time-p[i].arr_time;
//        p[i].wei_time=p[i].tur_time/p[i].ser_time;
//        p[i].flag=1;
//        mean_time=mean_time+p[i].tur_time;
//        meanw_time=meanw_time+p[i].wei_time;
//        last_time=p[i].com_time;
//    }
//    mean_time=mean_time/N;
//    meanw_time=meanw_time/N;
//    output(p);
//}
