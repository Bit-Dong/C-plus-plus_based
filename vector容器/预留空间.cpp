#include<iostream>
#include<string>
#include<vector>
using namespace std;

        //总结：   如果数据量较大时，可以一开始利用reserve 预留空间 
        
//减少vector在动态扩展容量时的扩展次数 
//  reserve(int len);  容器预留len个元素长度，预留位置不初始化，元素不可访问 

void test01()
{
	vector<int> v;  
	
	//预留空间 
	v.reserve(10000);         //未加此行代码前 num=15，即需要动态扩展十五次    加此行代码只需要1次，即起预留作用 
	
	int num=0;
	int *p=NULL;
	for(int i=0;i<10000;i++)
	{
		v.push_back(i);
		if(p!=&v[0])
		{
			p=&v[0];
			num++;
		}
	}
	cout<<"num = "<<num<<endl;

} 

int main()
{
	test01();
	
	system("pause");
	return 0;
} 
