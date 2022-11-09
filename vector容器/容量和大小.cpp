#include<iostream>
#include<string>
#include<vector>
using namespace std;

//对vector容器的容量和大小操作

// empty();    判断容器是否为空 
// capacity();  容器的容量 
// size();    返回容器中元素的个数 
// resize(int num);  重新指定容器的长度为num，若容器变长，则以默认值填充新位置
//                                            若容器变短，则末尾超出容器长度的元素被删除 
// resize(int num,elem);   重新指定容器的长度为num，若容器变长，则以elem值填充新位置
//                                                  若容器变短，则末尾超出容器长度的元素被删除 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector容器的容量和大小操作
void test01()
{
	vector<int> v1;  //默认构造
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //后插入数值 
	} 
	printVector(v1);
	
	if(v1.empty())    //为真 代表容器为空
	{
		cout<<"v1为空"<<endl;
	}
	else
	{
		cout<<"v1不为空"<<endl;
		cout<<"v1的容量为："<<v1.capacity()<<endl;
		cout<<"v1的大小为："<<v1.size()<<endl;
	}
	
//重新指定大小
	v1.resize(15,100);     //利用重载版本，可以指定默认填充值  这里设定的大小长度为15，长出的部分用100填充（不设定的话，默认用0填充） 
	printVector(v1);
	
	v1.resize(5);       //设定的大小长度为5 
	printVector(v1);   //如果重新指定的长度比原来短了，超出部分会删除掉 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
