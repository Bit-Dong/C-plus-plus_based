#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
count_if(iterator beg, iterator end，_pred) ;
 按条件统计元素出现次数
 beg 开始迭代器   end结束迭代器    _Pred谓词
*/

//内置数据类型
class GreaterFive
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
};

void test01()
{
	vector<int>v;
	v.push_back(7);
	v.push_back(1);
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(1);
	
	int num=count_if(v.begin(),v.end(),GreaterFive());
	cout<<"大于5的个数为："<<num<<endl;
} 


//自定义数据类型 
class Person
{
	public:
		Person(string name,int age)
		{
			this->Name=name;
			this->Age=age;
		}
		

	public:
		string Name;
		int Age;
};

class AgeGreater15
{
	public:
		bool operator()(const Person&p)
		{
			return p.Age>15;
		}
};

void test02()
{
	vector<Person> v;
	Person p1("刘备",10);
	Person p2("张飞",20);
	Person p3("关羽",20);
	Person p4("赵云",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	int n=count_if(v.begin(),v.end(),AgeGreater15()); 
	cout<<"年龄大于15岁的人数为："<<n<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
