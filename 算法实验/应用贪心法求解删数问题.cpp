/*
【问题描述】编写一个实验程序实现求解删数问题。给定共有n位的正整数d，
			去掉其中任意,k<=n个数字后剩下的数字按原次序排列组成一个新的正整数。
			对于给定的n位正整数d和正整数k，找出剩下数字组成的新数最小的删数方案。
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string N;
    int k,i;
    cin >> N >> k;
    while (k--)
    {
        int len=N.length();
        for (i=0;i<len-1;i++)
            if (N[i]>N[i+1])
            {
                N.erase(N.begin()+i);
                break;
            }
        if (i==len-1)
            N.erase(N.end()-1);	 //删除最后数字
    }
    while(N[0]=='0'&&N.length()>1)
        N.erase(N.begin());
    cout << N << endl;
	return 0;
}
