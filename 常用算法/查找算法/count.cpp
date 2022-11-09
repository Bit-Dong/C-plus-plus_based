#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

/*
count(iterator beg, iterator end, value ) ;
统计元素出现次数
beg开始迭代器   end结束迭代器   value统计的元素
*/

//内置数据类型
void test01()
{
	vector<int>v;
	v.push_back(7);
	v.push_back(1);
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(1);
	
	int num=count(v.begin(),v.end(),1);
	cout<<"1的个数为："<<num<<endl;
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
		
		// 重载==
		bool operator==(const Person &p)
		{
			if(this->Age==p.Age)
				return true;
			else
				return false;
		} 
	public:
		string Name;
		int Age;
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
	Person p("诸葛亮",40);
	
	int n=count(v.begin(),v.end(),p2); 
	cout<<"与诸葛亮相同岁数的人数："<<n<<endl; 
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
