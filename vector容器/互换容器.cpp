#include<iostream>
#include<string>
#include<vector>
using namespace std;

//实现两个容器内元素进行互换 
//  swap(vwc);   将vec与本身的元素互换 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector 容器进行插入、删除操作 
void test01()
{
	cout<<"交换前："<<endl;
	vector<int> v1;  //默认构造
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	
	vector<int> v2;  //默认构造
	for(int i=9;i>=0;i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	
	cout<<"交换后："<<endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

} 

//实际用途
//巧用swap可以收缩内存空间 
void test02()
{
	vector<int> v;  
	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
	}
	cout<<"最初时："<<endl;
	cout<<"v的容量为："<<v.capacity()<<endl;
	cout<<"v的大小为："<<v.size()<<endl;	
	
	//重新指定大小
	cout<<endl<<"重新指定大小后："<<endl; 
	v.resize(3);     
	cout<<"v的容量为："<<v.capacity()<<endl;
	cout<<"v的大小为："<<v.size()<<endl; 
	
	//巧用swap收缩内存
	cout<<endl<<"创建匿名对象进行交换后："<<endl;
	vector<int>(v).swap(v);     //创建匿名对象进行交换，匿名对象最终会被系统自动释放 
	cout<<"v的容量为："<<v.capacity()<<endl;
	cout<<"v的大小为："<<v.size()<<endl;
}

int main()
{
//	test01();
	test02();
	
	system("pause");
	return 0;
} 
