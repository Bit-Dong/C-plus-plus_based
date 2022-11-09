#include<iostream>
#include<map>
#include<string>
using namespace std;

void printMap(map<int,int>&m) 
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<"    key = "<<(*it).first<<"   value = "<<it->second<<endl;
	}
	cout<<endl;
}

 
void test01()
{
	map<int,int>m;
	//插入
	//第一种 
	m.insert(pair<int,int>(1,10));

	//第二种
	m.insert(make_pair(2,20));
	
	//第三种
	m.insert(map<int,int>::value_type(3,30));
	
	//第四种
	m[4]=40;       
	cout<<m[2]<<endl;   //输出key=2的value值，若不存在key=2时，系统会自己创建一个且值为0 
	printMap(m);
	
	//删除
	m.erase(m.begin());
	printMap(m);
	
	m.erase(3);    //按照key值删除   即删除key=3的value值
	printMap(m);
	
	//清空
	//m.erase(m.begin(),m.end());
	m.clear();
	printMap(m); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
