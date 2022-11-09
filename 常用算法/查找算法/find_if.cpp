#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
find_if(iterator beg,iterator end，_Pred) ;
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 beg 开始迭代器   end结束迭代器    _Pred 函数或者谓词(返回bool类型的仿函数)
*/

//内置数据类型
class GreatFive
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
}; 
void test01()
{
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	
	//查找容器中大于 5 的元素
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreatFive());
	if(it==v.end())
		cout<<"没有找到！"<<endl;
	else
		cout<<"找到大于5的元素："<<*it<<endl;
}



//自定义数据类型查找 
class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		
		string Name;
		int Age;
};

class Greater20
{
	public:
		bool operator()(Person &p)
		{
			return p.Age>30;
		}
}; 

 
void test02()
{
	vector<Person> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	vector<Person>::iterator it=find_if(v.begin(),v.end(),Greater20());
	if(it==v.end())
		cout<<"没有找到！"<<endl;
	else
		cout<<"找到元素 "<<"  姓名："<<it->Name<<"    年龄："<<it->Age<<endl;  
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
