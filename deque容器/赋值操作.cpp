#include<iostream>
#include<string>
#include<deque>
using namespace std;

//总结：deque赋值方式比较简单，使用operator=或者assign都可以 
//  给deque容器进行赋值
// deque &operator=(const deque &vec);   重载等号操作符 
// assign(beg,end);        将[begin()，end())区间中的数据拷贝赋值给本身 
// assign(n,elem);         将n个elem拷贝赋值给本身 

void printDeque(const deque<int> &d)       // 加const变为只读 
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)     //const_iterator  只读迭代器 
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//deque 容器赋值
void test01()
{
	deque<int> d1;  //默认构造
	for(int i=0;i<10;i++)
	{
		d1.push_back(i);           //后插入数值 
	} 
	printDeque(d1);
	
//赋值 operator=
	deque<int> d2;
	d2=d1; 
	printDeque(d2);
	
//assign
	deque<int> d3;
	d3.assign(d1.begin(),d1.end());    //利用assign区间方式(左闭右开)  将d1赋值给d3    
	printDeque(d3);
	
//n个elem方式赋值
	deque<int> d4;
	d4.assign(10,100);        //10个100赋值给d4 
	printDeque(d4); 
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
