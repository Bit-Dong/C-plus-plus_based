#include<iostream>

using namespace std;

int main()
{
	//原始数组 
	int str[10]={5,6,8,2,0,1,9,7,4,4};
	int i,j;
	for(i=0;i<10;i++)
	{
		cout<<str[i]<<"  ";
	}
	cout<<endl<<endl;
	
	for(i=0;i<10-1;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(str[j]>str[j+1])
			{
				int t=str[j];
				str[j]=str[j+1];
				str[j+1]=t;
			}
		
		}
	}
	//冒泡排序后的数组 
		for(i=0;i<10;i++)
	{
		cout<<str[i]<<"  ";
	}
	cout<<endl;
	
	system("pause");
 } 
