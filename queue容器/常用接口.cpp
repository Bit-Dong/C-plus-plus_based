#include<iostream>
#include<string>
#include<queue>
using namespace std;

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

void test01()
{
	//创建队列
	queue<Person> p;     
	
	//准备数据
	Person p1("唐三藏",40);
	Person p2("孙悟空",70);
	Person p3("猪八戒",60);
	Person p4("沙师弟",50);
	
	//入队 
	p.push(p1);
	p.push(p2);
	p.push(p3);
	p.push(p4); 
	
	cout<<"出队前 队列大小："<<p.size()<<endl;
	
	//判断队列是否为空，不为空 取对头和队尾，出队
	cout<<"逐步出队："<<endl; 
	while(!p.empty()) 
	{
		cout<<endl<<"对头元素 --- 姓名为："<<p.front().Name<<"   队头元素 --- 年龄为："<<p.front().Age<<endl;
		cout<<"对尾元素 --- 姓名为："<<p.back().Name<<"   队尾元素 --- 年龄为："<<p.back().Age<<endl;
		
		//出队
		p.pop(); 
	}
	cout<<"出队完成！"<<endl<<endl;
	cout<<"出队后 队列大小："<<p.size()<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
