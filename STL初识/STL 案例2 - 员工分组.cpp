#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
#include<stdlib.h>     //rand随机数 
#define CEHUA  0
#define MEISHU 1
#define YANFA  2

using namespace std;

class Worker
{
	public:
		string Name;
		int Salary;
};

//1、创建员工 
void creatWorker(vector<Worker>&v)
{
	string nameSeed="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		Worker worker;
		worker.Name="员工";
		worker.Name+=nameSeed[i];
		
		worker.Salary=rand() %10000+10000;   //10000~19999
		v.push_back(worker);
	}
}

//2、员工分组
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
	{
		//产生随机部门编号
		int deptId=rand()%3;    // 0、1、2
		//将员工插入到分组中
		//key部门编号，value具体员工
		m.insert(make_pair(deptId,*it)); 
	}
}

//分组显示员工 
void showWorkerByGourp(multimap<int,Worker>&m)
	{
		cout<<"策划部门："<<endl;
		multimap<int,Worker>::iterator pos=m.find(CEHUA);
		int count=m.count(CEHUA);    //统计具体人数 
		int index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"姓名："<<pos->second.Name<<"   工资："<<pos->second.Salary<<endl;
		}
		
		cout<<"--------------------------"<<endl<<endl;
		cout<<"美术部门："<<endl;
		pos=m.find(MEISHU);
		count=m.count(MEISHU);    //统计具体人数 
		index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"姓名："<<pos->second.Name<<"   工资："<<pos->second.Salary<<endl;
		}
		
		cout<<"--------------------------"<<endl<<endl;
		cout<<"研发部门："<<endl;
		pos=m.find(YANFA);
		count=m.count(YANFA);    //统计具体人数 
		index=0;
		for(;pos!=m.end()&&index<count;pos++,index++)
		{
			cout<<"姓名："<<pos->second.Name<<"   工资："<<pos->second.Salary<<endl;
		}
	} 

int main()
{
	srand((unsigned int)time(NULL));
	
	//1、创建员工 
	vector<Worker>vWorker;
	creatWorker(vWorker);
//	for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++)
//	{
//		cout<<"姓名："<<it->Name<<"   工资："<<it->Salary<<endl;
//	}
	
	//2、员工分组
	multimap<int,Worker>mWorker;
	setGroup(vWorker,mWorker);
	 
	//3、分组显示员工 
	showWorkerByGourp(mWorker); 
	
	system("pause");
	return 0;
	
}
