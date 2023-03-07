#include<stdio.h>
#include<stdlib.h>
#define PN 12//页面访问列长度
#define FN 3//分配给进程的内存块数

int *pageSeq;//页面访问序列
int *frames;//内存块数组
int fault,exchange;//缺页次数和置换次数
float ratio;//缺页率

void init();//初始化页面访问向量
void clear();//初始化内存块
void print();//输出最后结果
void print1(int);//输出每一步结果
void OPT(int*,int,int*,int);//OPT算法
void FIFO(int*,int,int*,int);//FIFO算法
void LRU(int*,int,int*,int);//LRU算法
int search(int,int*,int,int);//搜索页面在序列某段中的位置，找到返回下标，否则返回-1

int main()
{
int num;
printf("【页面置换算法】\n");
printf("序列长度：%d\n",PN);
printf("内存块数：%d\n",FN);
printf("======================\n\n");
    init();//初始化页面访问向量
    printf("操作说明：\n");
    printf("    num=0  程序结束\n");
    printf("    num=1  OPT算法\n");
    printf("    num=2  FIFO算法\n");
    printf("    num=3  LRU算法\n");
    printf("==============================\n");
    printf("\n");
    printf("输入操作序号num：");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
            case 0:printf("\n=====程序结束！=====\n");return 0;
            case 1:printf("\n【OPT算法】\n");OPT(pageSeq,PN,frames,FN);break;
            case 2:printf("\n【FIFO算法】\n");FIFO(pageSeq,PN,frames,FN);break;
            case 3:printf("\n【LRU算法】\n");LRU(pageSeq,PN,frames,FN);break;
            default:printf("\n=====重新输入=====\n");goto L1;
        }
        print();
L1:     printf("\n");
        printf("输入操作序号num：");
        scanf("%d",&num);
    }
}

void init()//输入访问序列
{
    int i;
    pageSeq=(int*)(malloc(PN*sizeof(int)));
    frames=(int*)(malloc(FN*sizeof(int)));
    printf("向pageSeq输入页面访问序列：");
    for(i=0;i<PN;i++)
        scanf("%d",&pageSeq[i]);
    printf("\n");
    printf("页面访问序列：\n\n");//输出页面访问序列
    for(i=0;i<PN;i++)
        printf("%3d",pageSeq[i]);
    printf("\n\n");
    printf("===============================================================\n");
}

void clear()//重新初始化内存块frames，因为有0号页面，所以置-1
{
    int i;
    fault=0;//缺页次数
    exchange=0;//置换次数
    for(i=0;i<FN;i++)//内存块置-1
        frames[i]=-1;
}

void print1(int flag)//flag为缺页标志，输出每一步结果
{
    int t;
    for(t=0;t<FN;t++)//每访问一个页面，都输出一次内存块（页面）
        printf("%3d",frames[t]);
    if(flag) printf("  fault");//在缺页位置标记“fault”
    printf("\n");
}

void print()//输出最后结果
{
    exchange=fault-FN;
    ratio=(float)fault/PN*100;
    printf("------------------------------\n");
    printf("缺页次数：%d\n",fault);
    printf("置换次数：%d\n",exchange);
    printf("缺 页 率：%4.1f%%\n",ratio);
    printf("==============================\n");
}

int search(int p,int* ar,int start,int end)//参数说明：(页号，页面访问序列或者内存块数组，起点，终点)
{//检测页面p是否存在数组ar中(起点start，终点end)，存在则返回其在ar中的位置(下标)，否则返回-1
    int i,f;
    if(start>end)f=-1;//f作为方向标志，f=1时，循环变量递增；f=-1时，循环变量递减
    else f=1;
    i=start;//从strat位置开始搜索
    while(i!=end+f)//i超过end时结束循环
    {//在OPT算法中，start<end，循环变量递增，f=1；而在LRU算法中则相反，f=-1
        if(p==ar[i])return i;//首次搜索到p即返回下标
        i=i+f;
    }
    return -1;//未搜索到页面p，即p在未来不再被访问
}

void OPT(int* arp,int p,int* arf,int f)
{//参数说明：(页面访问序列数组，数组长度，内存块数组，数组长度)
    int i=0,j,flag;
    int kf=0;//kf为进入内存页面数，当kf>=f时，内存块满，此时缺页产生置换，且kf的值不再增加
    int kp;//搜索起点，即页面访问序列中当前页的下一位置
    int posi,pmaxi,pmaxj;//未来最久不使用页面在arp和arf中的位置
    clear();//内存块数据清零
    printf("页面访问过程：\n");
    printf("------------------------------\n");
    for(i=0;i<p;i++)//扫描页面序列
    {
        flag=0;//缺页标志，初值置0，不缺页
        if(search(arp[i],arf,0,f-1)==-1)//页不在内存
        {
            flag=1;//缺页，flag置1
            fault++;//缺页+1
            if(kf<f)//有空闲内存块，无置换
            {
                arf[kf]=arp[i];//页面直接调入内存块arf[kf]中
                kf++;//当内存块放满页面后，kf不再增加
            }
            else//没有空闲内存块，将产生置换
            {
               kp=i+1; //设置页面访问序列arp中向后搜索的起点，选择淘汰页面
               pmaxi=-1;//被淘汰页面在访问序列arp中的位置，初值置-1
               for(j=0;j<f;j++)
               {//对内存arf中的每个页面依次查找其在访问序列arp中（未来）第一次出现的位置，并存放在posi中
                   posi=search(arf[j],arp,kp,p-1);
                   if(posi==-1)//search()返回-1，说明该页面在未来不存在，即不会再被访问到
                   {
                       arf[j]=arp[i];//置换并终止循环
                       break;
                   }
                   if(posi>pmaxi)
                   {//search()返回值不是-1，则记录最久未使用页面在访问序列arp中的位置
                       pmaxi=posi;//记录最大位置
                       pmaxj=j;//记录最久未使用页面在内存arf中的位置
                   }
               }
               if(j>=f)arf[pmaxj]=arp[i];//当内存块数组arf中所有页面在未来都会被访问到时，置换
            }
        }
        print1(flag);//输出一次内存页面情况
    }
}

void FIFO(int* arp,int p,int* arf,int f)
{//参数说明：(页面访问序列数组，数组长度，内存块数组，数组长度)
    int i,j=0,flag;
    clear();//内存块数据清零
    printf("页面访问过程：\n");
    printf("------------------------------\n");
    for(i=0;i<p;i++)
    {
        flag=0;//缺页标志，同OPT
        if(search(arp[i],arf,0,f-1)==-1)//如果当前页面arp[i]不在内存
        {
            fault++;//缺页+1
            flag=1;
            arf[j]=arp[i];//页面调入内存
            j=(j+1)%f;//j+1，循环
        }
        print1(flag);//输出一次内存页面情况
    }
}

void LRU(int* arp,int p,int* arf,int f)
{//参数说明：(页面访问序列数组，数组长度，内存块数组，数组长度)
    int i,j;
    int kf=0;//kf>=f时，内存块满，此时缺页产生置换
    int flag;//缺页标志
    int pmini,pminj;//最久未访问页面在arp[]中过去的位置和在arf[]中的位置
    int posi;
    clear();//清理内存块数据等
    for(i=0;i<p;i++)
    {
        flag=0;
        if(search(arp[i],arf,0,f-1)==-1)//页面不在内存
        {
            flag=1;
            fault++;//缺页
            if(kf<f)//有空闲块，无置换
            {
                arf[kf]=arp[i];
                kf++;
            }
            else//无空闲块，产生置换
            {//在arp[]中向前搜索，寻找最久未被访问的页面位置
                pmini=p;//pmini值初值（最大值或者当前值i）
                for(j=0;j<f;j++)
                {
                    posi=search(arf[j],arp,i-1,0);//这里与OPT不同，不会出现页面不存在的情况
                    if(posi<pmini)
                    {
                        pmini=posi;
                        pminj=j;
                    }
                }
                arf[pminj]=arp[i];//置换
            }
        }
        print1(flag);//输出一次内存页面情况
    }
}




//
//#include<stdio.h>
//#include<stdlib.h>
//#define PN 20//页面访问列长度
//#define FN 3//分配给进程的内存块数
//
//int *pageSeq;//页面访问序列
//int *frames;//内存块数组
//int fault,exchange;//缺页次数和置换次数
//float ratio;//缺页率
//
//void init();//初始化页面访问向量
//void clear();//初始化内存块
//void print();//输出最后结果
//void print1(int);//输出每一步结果
//void LRU(int*,int,int*,int);//LRU算法
//int search(int,int*,int,int);//搜索页面在序列某段中的位置，找到返回下标，否则返回-1
//
//int main()
//{
//int num;
//printf("【页面置换LRU算法】\n");
//printf("序列长度：%d\n",PN);
//printf("内存块数：%d\n",FN);
//printf("======================\n\n");
//    init();//初始化页面访问向量
//
//     LRU(pageSeq,PN,frames,FN);
//     print(); 
//}
//
//void init()//输入访问序列
//{
//    int i;
//    pageSeq=(int*)(malloc(PN*sizeof(int)));
//    frames=(int*)(malloc(FN*sizeof(int)));
//    printf("向pageSeq输入页面访问序列：");
//    for(i=0;i<PN;i++)
//        scanf("%d",&pageSeq[i]);
//    printf("\n");
//    printf("页面访问序列：\n\n");//输出页面访问序列
//    for(i=0;i<PN;i++)
//        printf("%3d",pageSeq[i]);
//    printf("\n\n");
//    printf("===============================================================\n");
//}
//
//void clear()//重新初始化内存块frames，因为有0号页面，所以置-1
//{
//    int i;
//    fault=0;//缺页次数
//    exchange=0;//置换次数
//    for(i=0;i<FN;i++)//内存块置-1
//        frames[i]=-1;
//}
//
//void print1(int flag)//flag为缺页标志，输出每一步结果
//{
//    int t;
//    for(t=0;t<FN;t++)//每访问一个页面，都输出一次内存块（页面）
//        printf("%3d",frames[t]);
//    if(flag) printf("  fault");//在缺页位置标记“fault”
//    printf("\n");
//}
//
//void print()//输出最后结果
//{
//    exchange=fault-FN;
//    ratio=(float)fault/PN*100;
//    printf("------------------------------\n");
//    printf("缺页次数：%d\n",fault);
//    printf("置换次数：%d\n",exchange);
//    printf("缺 页 率：%4.1f%%\n",ratio);
//    printf("==============================\n");
//}
//
//int search(int p,int* ar,int start,int end)//参数说明：(页号，页面访问序列或者内存块数组，起点，终点)
//{//检测页面p是否存在数组ar中(起点start，终点end)，存在则返回其在ar中的位置(下标)，否则返回-1
//    int i,f;
//    if(start>end)f=-1;//f作为方向标志，f=1时，循环变量递增；f=-1时，循环变量递减
//    else f=1;
//    i=start;//从strat位置开始搜索
//    while(i!=end+f)//i超过end时结束循环
//    {//在OPT算法中，start<end，循环变量递增，f=1；而在LRU算法中则相反，f=-1
//        if(p==ar[i])return i;//首次搜索到p即返回下标
//        i=i+f;
//    }
//    return -1;//未搜索到页面p，即p在未来不再被访问
//}
//
//
//void LRU(int* arp,int p,int* arf,int f)
//{//参数说明：(页面访问序列数组，数组长度，内存块数组，数组长度)
//    int i,j;
//    int kf=0;//kf>=f时，内存块满，此时缺页产生置换
//    int flag;//缺页标志
//    int pmini,pminj;//最久未访问页面在arp[]中过去的位置和在arf[]中的位置
//    int posi;
//    clear();//清理内存块数据等
//    for(i=0;i<p;i++)
//    {
//        flag=0;
//        if(search(arp[i],arf,0,f-1)==-1)//页面不在内存
//        {
//            flag=1;
//            fault++;//缺页
//            if(kf<f)//有空闲块，无置换
//            {
//                arf[kf]=arp[i];
//                kf++;
//            }
//            else//无空闲块，产生置换
//            {//在arp[]中向前搜索，寻找最久未被访问的页面位置
//                pmini=p;//pmini值初值（最大值或者当前值i）
//                for(j=0;j<f;j++)
//                {
//                    posi=search(arf[j],arp,i-1,0);//这里与OPT不同，不会出现页面不存在的情况
//                    if(posi<pmini)
//                    {
//                        pmini=posi;
//                        pminj=j;
//                    }
//                }
//                arf[pminj]=arp[i];//置换
//            }
//        }
//        print1(flag);//输出一次内存页面情况
//    }
//}
