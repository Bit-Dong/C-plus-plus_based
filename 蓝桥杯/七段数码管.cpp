/*
题目描述:
小蓝要用七段码数码管来表示一种特殊的文字。
七段码上图给出了七段码数码管的一个图示，数码管中一共有 7 段可以发光的二极管，分别标记为 a, b,
c, d, e, f, g。小蓝要选择一部分二极管（至少要有一个）发光来表达字符。在设计字符的表达时，要求
所有发光的二极管是连成一片的。
例如：b 发光，其他二极管不发光可以用来表达一种字符。
例如：c 发光，其他二极管不发光可以用来表达一种字符。这种方案与上一行的方案可以用来表示不同
的字符，尽管看上去比较相似。
例如：a, b, c, d, e 发光，f, g 不发光可以用来表达一种字符。

思路：
暴力，最后减去三种特殊情况（暴力判断不了的情况） 1101100  1011010  0110110
*/

#include<iostream>
using namespace std;

int main()
{
    int sum=0;
    for(int a=0; a<=1; a++)
    {
        for(int b=0; b<=1; b++)
        {
            for(int c=0; c<=1; c++)
            {
                for(int d=0; d<=1; d++)
                {
                    for(int e=0; e<=1; e++)
                    {
                        for(int f=0; f<=1; f++)
                        {
                            for(int g=0; g<=1; g++)
                            {
                                int s=a+b+c+d+e+f+g;
                                if(s==1)
                                {
                                    sum++;
                                }
                                else if(s>=2)
                                {
                                    if(a==1&&b==0&&f==0)
                                        continue;
                                    else if(b==1&&a==0&&c==0&&g==0)
                                        continue;
                                    else if(c==1&&b==0&&g==0&&d==0)
                                        continue;
                                    else if(d==1&&e==0&&c==0)
                                        continue;
                                    else if(e==1&&d==0&&g==0&&f==0)
                                        continue;
                                    else if(f==1&&a==0&&e==0&&g==0)
                                        continue;
                                    sum++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",sum-3);
    return 0;
}

