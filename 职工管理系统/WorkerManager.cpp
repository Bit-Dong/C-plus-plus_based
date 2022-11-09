#include"WorkerManager.h"

WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //读文件
	
//  1、文件不存在情况 
	if(!ifs.is_open()) 
	{
//		cout<<"文件不存在"<<endl;
		this->EmpNum=0;         //初始化记录人数 
		this->EmpArray=NULL;    //初始化数组指针
		this->FileIsEmpty=true;  //初始化文件是否位空 
		ifs.close();            //关闭文件 
		return;
	}
	
// 2、文件存在，但数据为空
	char ch;
	ifs>>ch;
	if(ifs.eof()) 
	{
//		cout<<"文件为空!"<<endl;
		this->EmpNum=0;         //初始化记录人数 
		this->EmpArray=NULL;    //初始化数组指针
		this->FileIsEmpty=true;  //初始化文件是否位空 
		ifs.close();            //关闭文件 
		return;
	}   
	
// 3、文件存在，并且记录数据
	int num=this->get_EmpNum();
//	cout<<"职工人数为："<<num<<endl;
	this->EmpNum=num; 
	
	
	this->EmpArray=new Worker*[this->EmpNum]; //开辟空间
	this->init_Emp();      //将文件中的数据 存到数组中 、
	
	//测试 
//	for(int i=0;i<this->EmpNum;i++)
//	{
//		cout<<"职工编号："<<this->EmpArray[i]->Id<<"\t姓名："<<this->EmpArray[i]->Name<<"\t部门编号："<<this->EmpArray[i]->DeptId<<endl;
//	} 

}

WorkerManager::~WorkerManager()
{
	if(this->EmpArray!=NULL)
	{
		for(int i=0;i<this->EmpNum;i++)
		{
			if(this->EmpArray[i]!=NULL)
			{
				delete this->EmpArray[i];
			}
		}
		delete[] this->EmpArray;
		this->EmpArray=NULL;
	}	
}

//菜单 
void WorkerManager:: Show_Menu()
{
	cout<<"**************************************************"<<endl;
	cout<<"************ 欢迎使用职工管理系统！***************"<<endl;
	cout<<"**************  0. 退出管理程序   ****************"<<endl;
	cout<<"**************  1. 增加职工信息   ****************"<<endl;
	cout<<"**************  2. 显示职工信息   ****************"<<endl;
	cout<<"**************  3. 删除离职职工   ****************"<<endl;
	cout<<"**************  4. 修改职工信息   ****************"<<endl;
	cout<<"**************  5. 查找职工信息   ****************"<<endl;
	cout<<"**************  6. 按照编号排序   ****************"<<endl;
	cout<<"**************  7. 清空所有文档   ****************"<<endl;
	cout<<"**************************************************"<<endl;
	cout<<endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout<<"欢迎下次使用！"<<endl;
	system("pause");
	exit(0);
} 

//添加职工
void WorkerManager::Add_Emp()
{
	cout<<"请输入添加职工数量："<<endl;
	
	int addNum=0;     //保存用户的输入数量
	cin>>addNum;
	
	if(addNum>0)
	{
		//添加
		int newSize=this->EmpNum+addNum;    //新空间人数=原来记录人数 + 新增人数
		Worker **newSpace=new Worker *[newSize];   //开辟新空间
		if(this->EmpArray!=NULL)
		{
			for(int i=0;i<this->EmpNum;i++)
			{
				newSpace[i]=this->EmpArray[i];
			}
 		}
			//批量添加新数据
			for(int i=0;i<addNum;i++)
			{
				int id;        //职工编号
				string name;   //职工姓名
				int dSelect;   //部门选择
				cout<<"请输入第 "<<i+1<<" 个新职工编号："<<endl; 
				cin>>id;
				cout<<"请输入第 "<<i+1<<" 个新职工姓名："<<endl; 
				cin>>name;
				cout<<"请选择该职工岗位："<<endl; 
				cout<<"1、普通职工"<<endl;
				cout<<"2、经理"<<endl;
				cout<<"3、老板"<<endl;
				cin>>dSelect; 
			
			
			Worker *worker=NULL;
			switch(dSelect)
			{
				case 1:
					worker=new Employee(id,name,1);
					break;
				case 2:
					worker=new Manager(id,name,2);
					break;
				case 3:
					worker=new Boss(id,name,3);
					break;
				default:
					break;
			}
			 //将创建职工职责，保存到数组中
			 newSpace[this->EmpNum+i]=worker; 
		 }
		delete[] this->EmpArray;     //释放原有空间 
		this->EmpArray=newSpace;     //更新新空间指向 
		this->EmpNum=newSize;        //更新新的职工人数
		cout<<"成功添加"<<addNum<<"名新职工！"<<endl;    //提示添加成功 
		
		this->save();    //保存数据到文件中 
	}
	else
	{
		cout<<"输入数据有误"<<endl; 
	}
	
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);    //用输出的方式打开文件 ---写文件
	
	//将每个人数据写入到文件中
	for(int i=0;i<this->EmpNum;i++)
	{
		ofs<<this->EmpArray[i]->Id<<"  "<<this->EmpArray[i]->Name<<"  "<<this->EmpArray[i]->DeptId<<endl;
	} 
	
	ofs.close();   //关闭文件 
} 

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //打开文件 读
	int id;
	string name;
	int did;
	int num=0;     //统计人数变量 
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;    
	} 
	return num; 
} 

//初始化员工 
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);    //打开文件 读
	int id;
	string name;
	int did;
	int index=0;
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker *worker=NULL;
		if(did==1)  //普通职工 
		{
			worker=new Employee(id,name,did);
		}
		else if(did==2)  //经理 
		{
			worker=new Manager(id,name,did);
		}
		else     //老板 
		{
			worker=new Boss(id,name,did);
		}
		this->EmpArray[index]=worker;
		index++; 
	} 
	ifs.close();   //关闭文件 
} 

//显示职工
void WorkerManager::Show_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
	}
	else
	{
		for(int i=0;i<EmpNum;i++)
		{
			this->EmpArray[i]->showInfo();    //利用多态调用接口 
		}
	}
	system("pause");
	system("cls");
} 

//删除职工
void WorkerManager:: Del_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
	} 
	else
	{
		cout<<"请输入想要删除职工编号："<<endl;
		int id=0;
		cin>>id;
		
		int index=this->IsExist(id);
		if(index!=-1)  //说明职工存在，并且要删除掉index位置上的职工
		{
			//数据前移
			for(int i=index;i<this->get_EmpNum()-1;i++)
			{
				this->EmpArray[i]=this->EmpArray[i+1];
			}
			this->EmpNum--;   //更新数组中记录人员个数
			this->save();     //数据同步更新到文件中
			cout<<"删除成功！"<<endl; 
		}
		else
		{
			cout<<"删除失败，未找到该职工"<<endl;
		} 
	}
	system("pause");
	system("cls");
}  

//按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1  
int WorkerManager:: IsExist(int id)
{
	int index=-1;
	for(int i=0;i<this->EmpNum;i++)
	{
		if(this->EmpArray[i]->Id==id)
		{
			index=i;
			break;
		}
	} 
	return index;
}

//修改职工
void WorkerManager:: Mod_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
	}
	else
	{
		cout<<"请输入修改职工的编号："<<endl;
		int id;
		cin>>id;
		int ret=this->IsExist(id);
		if(ret!=-1)     //查找到编号的职工 
		{
			delete this->EmpArray[ret];
			int newId=0;
			string newName=" ";
			int dSelect=0;
			cout<<"查到 "<<id<<" 号职工，请输入新职工编号："<<endl;
			cin>>newId;
			cout<<"请输入新姓名："<<endl;
			cin>>newName;
			cout<<"请输入岗位："<<endl;
			cout<<"1、普通职工"<<endl;
			cout<<"2、经理"<<endl;
			cout<<"3、老板"<<endl;
			cin>>dSelect;
			
			Worker *worker=NULL;
			switch(dSelect)
			{
				case 1:
					worker=new Employee(newId,newName,dSelect);
					break;
				case 2:
					worker=new Manager(newId,newName,dSelect);
					break;
				case 3:
					worker=new Boss(newId,newName,dSelect);
					break;
				default:
					break;
			}
			this->EmpArray[ret]=worker;    //更新数据 到数组中
			cout<<"修改成功！"<<endl;
			this->save();     //保存到文件中 
		}
		else  
		{
			cout<<"修改失败，查无此人！"<<endl;
		} 
	}
	system("pause");
	system("cls");
} 

//查找职工
void WorkerManager::Find_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
	}
	else
	{
		cout<<"请输入查找的方式："<<endl;
		cout<<"1、按职工编号查找"<<endl;
		cout<<"2、按姓名查找"<<endl;
		int select=0;
		cin>>select;
		if(select==1)
		{
			int id;
			cout<<"请输入查找职工的编号："<<endl;
			cin>>id;
			int ret=IsExist(id);
			if(ret!=-1)
			{
				cout<<"查找成功！该职工信息如下："<<endl;
				this->EmpArray[ret]->showInfo();
			}
			else
			{
				cout<<"查找失败，查无此人！"<<endl;
			}
		}
		else if(select==2)   //按姓名查找
		{
			string name;
			cout<<"请输入要查找的姓名："<<endl;
			cin>>name;
			bool flag=false;   //查找到的标志
			for(int i=0;i<EmpNum;i++)
			{
				if(EmpArray[i]->Name==name)
				{
					cout<<"查找成功，职工编号："<<EmpArray[i]->Id<<"号的信息如下："<<endl;
					flag=true;
					this->EmpArray[i]->showInfo();
				}
			}
			if(flag==false)
			{
				cout<<"查找失败，查无此人"<<endl;
			} 
		}
		else
		{
			cout<<"输入选项有误！"<<endl;
		}		
	}
	system("pause");
	system("cls");
}

//排序职工 
void WorkerManager::Sort_Emp()
{
	if(this->FileIsEmpty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout<<"请输入排序的方式："<<endl;
		cout<<"1、按职工编号进行升序"<<endl;
		cout<<"2、按职工编号进行降序"<<endl;
		int select=0;
		cin>>select;
		for(int i=0;i<EmpNum;i++)
		{
			int minOrMax=i;
			for(int j=i+1;j<EmpNum;j++)
			{
				if(select==1)   //升序
				{
					if(EmpArray[minOrMax]->Id > EmpArray[j]->Id)
					{
						minOrMax=j;
					}
				}
				else        //降序 
				{
					if(EmpArray[minOrMax]->Id < EmpArray[j]->Id)
					{
						minOrMax=j;
					}
				} 
			}
			if(i!=minOrMax)
			{
				Worker *temp=EmpArray[i];
				EmpArray[i]=EmpArray[minOrMax];
				EmpArray[minOrMax]=temp;
			}
		}
		cout<<"排序成功，排序后的结果为："<<endl;
		this->save();
		this->Show_Emp(); 
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout<<"确认清空？"<<endl;
	cout<<"1、确认"<<endl;
	cout<<"2、返回"<<endl;
	
	int select=0;
	cin>>select;
	if(select==1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		if(this->EmpArray!=NULL)
		{
			for(int i=0;i<this->EmpNum;i++)
			{
				if(this->EmpArray[i]!=NULL)
				{
					delete this->EmpArray[i];
				}
			}
			this->EmpNum=0;
			delete[] this->EmpArray;
			this->EmpArray=NULL;
			this->FileIsEmpty=true;
		}
		cout<<"清空成功！"<<endl;
	}
	system("pause");
	system("cls");
}
