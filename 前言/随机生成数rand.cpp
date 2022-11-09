#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned int) time(NULL));
	int num=rand();   
	cout<<num<<endl;
	
	system("pause");
}
