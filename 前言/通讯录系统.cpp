#include<iostream>
#include<string>
using namespace std;
#define max 1000

//定义联系人结构体
struct lxr
{
	string name;     //姓名 
	string sex;      //性别 
	int age;         //年龄 
	string phone;    //手机号码 
	string addr;     //家庭地址 
};
 
//定义通讯录结构体 
struct txl
{
	struct lxr abc[max];
	int count;
};

void showmean()
{
	cout<<"******************************"<<endl;
	cout<<"*****   1.添加联系人    ******"<<endl; 
	cout<<"*****   2.显示联系人    ******"<<endl;
	cout<<"*****   3.删除联系人    ******"<<endl;
	cout<<"*****   4.查找联系人    ******"<<endl;
	cout<<"*****   5.修改联系人    ******"<<endl;
	cout<<"*****   6.清空联系人    ******"<<endl;
	cout<<"*****   0.退出通讯录    ******"<<endl;
	cout<<"******************************"<<endl;
}

//添加联系人
int add(struct txl *mn)
{
	if(mn->count>=max)
	{
		cout<<"通讯录已满！"<<endl;
		return 0;
	}
	else
	{
		cout<<"请输入联系人的姓名："<<endl;
		string name;
		cin>>name;
		mn->abc[mn->count].name=name;
		
		cout<<"请输入联系人的性别："<<endl;
		string sex;
		cin>>sex;
		mn->abc[mn->count].sex=sex;
		
		cout<<"请输入联系人的年龄："<<endl;
		int age;
		cin>>age;
		mn->abc[mn->count].age=age;
		
		cout<<"请输入联系人的手机号码："<<endl;
		string phone;
		cin>>phone;
		mn->abc[mn->count].phone=phone;
		
		cout<<"请输入联系人的家庭地址："<<endl;
		string addr;
		cin>>addr;
		mn->abc[mn->count].addr=addr;
		
		mn->count++;
		
		cout<<"添加联系人成功！"<<endl;
		
	}
} 

//显示联系人
int display(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"暂无联系人！"<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<mn->count;i++)
		{
			cout<<" 姓名: "<<mn->abc[i].name<<"    性别: "<<mn->abc[i].sex<<"    年龄: "<<mn->abc[i].age<<"     手机号码: "<<mn->abc[i].phone<<"     家庭地址: "<<mn->abc[i].addr<<endl<<endl;
		}
	}
} 

//删除联系人 
int del(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"通讯录联系人为空！"<<endl;
		return 0;
	}
	

	else
	{
		string name;
		int flag;
		cout<<"请输入想删除的联系人姓名："<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			 flag=1;
			if(mn->abc[i].name==name)
			{
				int t=i;
				flag=0;
				for(int j=t;j<mn->count;j++)
				{
					mn->abc[j]=mn->abc[j+1];
				}
				mn->count--;
				cout<<"删除成功！"<<endl;
				break;
			}
		
		}
			if(flag==1)
			{
				cout<<"查无此人，请重新选择！"<<endl;
			}
	}
}


//查找联系人
int find(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"暂无联系人，请重新选择！"<<endl;
		return 0;
	}
	else
	{
		int flag;
		string name;
		cout<<"请输入需要查找联系人的姓名："<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			 flag=1;
			if(mn->abc[i].name==name)
			{
			    flag=0;
				cout<<"查找成功！该联系人的信息为："<<endl;
				display(mn);
             	break;
			}
		
		}
			if(flag==1)
			{
				cout<<"查找失败，请重新选择！"<<endl;
			}
	}
}


//修改联系人
int change(struct txl *mn)
{
	if(mn->count==0)
	{
		cout<<"暂无联系人，请重新选择！"<<endl;
		return 0;
	}
	else
	{
		int flag;
		string name;
		cout<<"输入想修改联系人的姓名："<<endl;
		cin>>name;
		for(int i=0;i<mn->count;i++)
		{
			flag=1;
			if(mn->abc[i].name==name)
			{
			    flag=0;
			    cout<<"存在该联系人"<<endl; 
			    cout<<"请重新输入:"<<endl;
			    
			    cout<<"姓名：";
			    string name1;
			    cin>>name1;
			    mn->abc[i].name=name1;
			    
			    cout<<endl<<"性别：";
			    string sex1;
			    cin>>sex1;
			    mn->abc[i].sex=sex1;
			    
			    cout<<endl<<"年龄：";
			    int age1;
			    cin>>age1;
			    mn->abc[i].age=age1;
			    
			    cout<<endl<<"手机号码：";
			    string phone1;
			    cin>>phone1;
			    mn->abc[i].phone=phone1;
			    
			    cout<<endl<<"家庭地址：";
			    string addr1;
			    cin>>addr1;
			    mn->abc[i].addr=addr1;
			    
			    cout<<endl<<"修改成功！"<<endl;
				break;
			}
		
		}
			if(flag==1)
			{
				cout<<"查无此人，请重新选择！"<<endl;
			}
	}
}


//清空联系人
int cls(struct txl *mn)
{
	for(int j=0;j<=mn->count;j++)
	{
		mn->abc[j]=mn->abc[j+1];
		mn->count--;
	}
	cout<<"清空成功！"<<endl;
}

 
int main()
{
	struct txl mn;
	mn.count=0;
	while(1)
	{
		showmean();
		int t;
		cout<<"请输入选项序号:"<<endl;
		cin>>t;
		switch(t)
		{
			case 1:           
				add(&mn);
				break;
				
			case 2:
				display(&mn);
				break;
				
			case 3:
				del(&mn);
				break;
				
			case 4:
				find(&mn);
				break;
				
			case 5:
				change(&mn);
				break;
				
			case 6:
				cls(&mn); 
				break;
				
			case 0:
				cout<<"退出成功，欢迎下次使用！"<<endl;
				return 0;
				break;
			default:
				cout<<"请重新输入正确选项序号："<<endl;
				break;

		}
		system("pause");
		system("cls");
		
	}
	
	
	system("pause");
}
