#include<iostream>
#include<string>
#include<algorithm> 
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

//有五名选手ABCDE  10个评委分别对每一名选手打分，去除最高分和最低分，取平均分 

//选手类 
class Person
{
	public:
		Person(string name,int score)
		{
			this->Name=name;
			this->Score=score;
		}
		
		string Name;   //姓名 
		int Score;    //平均分 
};

// 1、创建五名选手
void creatPerson(vector<Person> &v)
{
	string nameSeed="ABCDE";
	for(int i=0;i<5;i++)
	{
		string name="选手";
		name+=nameSeed[i];
		int score=0;
		Person p(name,score);
		v.push_back(p);    //将创建的Person对象存放到容器中 
	}
}

//2、给五名选手打分
void setScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		//将评委的分数 放到deque容器中
		deque<int>d;
		for(int i=0;i<10;i++)
		{
			int score=rand()%41+60;    //60-100
			d.push_back(score);
		}
		
		//排序
		sort(d.begin(),d.end()); 
		
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();
		
		//取平均分
		int sum=0;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			sum+=*dit;      //累加每个评委的分数 
		} 
		int avg=sum/d.size();
		
		//将平均分 赋值给选手身上
		it->Score=avg; 
	}
}

// 3、显示最后得分
void showScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<"姓名："<<it->Name<<"   平均分："<<it->Score<<endl;
	}
}



int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	
	// 1、创建五名选手 
	vector<Person> v;   //存放选手容器
	creatPerson(v); 
	

	// 2、给五名选手打分
	setScore(v);
	
	
	// 3、显示最后得分 
	showScore(v);
	
	system("pause");
	return 0;
}
