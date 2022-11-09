#include<iostream>
#include<string>
#include<vector>
using namespace std;

//    创建vector容器
//   vector<T> v;                     采用模板实现类实现，默认构造函数 
//   vector(v.begin(),v.end());       将v[begin(),end())区间中的元素拷贝给本身 
//   vector(n,elem);                  构造函数将n个elem拷贝给本身 
//   vector(const vector &vec);       拷贝构造函数 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector 容器构造
void test01()
{
	vector<int> v1;  //默认构造
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //后插入数值 
	} 
	printVector(v1);
	
//通过区间方式进行构造
	vector<int> v2(v1.begin(),v1.end());     //将v1的值赋给v2 
	printVector(v2);
	
//n个elem方式构造
	vector<int> v3(10,100);        //将10个为100的数值 赋给v3
	printVector(v3);
	
//拷贝构造
	vector<int> v4(v3);          //将v3的值拷贝给v4 
	printVector(v4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
