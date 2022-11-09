#include<iostream>
#include<string>
#include<vector>
using namespace std;

//总结：vector赋值方式比较简单，使用operator=或者assign都可以 
//  给vector容器进行赋值
// vector &operator=(const vector &vec);   重载等号操作符 
// assign(beg,end);        将[begin()，end())区间中的数据拷贝赋值给本身 
// assign(n,elem);         将n个elem拷贝赋值给本身 

void printVector(vector<int> &p)
{
	for(vector<int>::iterator it=p.begin();it!=p.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//vector 容器赋值
void test01()
{
	vector<int> v1;  //默认构造
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);           //后插入数值 
	} 
	printVector(v1);
	
//赋值 operator=
	vector<int> v2;
	v2=v1; 
	printVector(v2);
	
//assign
	vector<int> v3;
	v3.assign(v1.begin(),v1.end());    //利用assign区间方式(左闭右开)  将v1赋值给v3    
	printVector(v3);
	
//n个elem方式赋值
	vector<int> v4;
	v4.assign(10,100);        //10个100赋值给v4 
	printVector(v4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
