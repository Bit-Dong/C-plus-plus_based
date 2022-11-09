#include<iostream>
#include<string>
using namespace std;

//抽象不同零件类 
//1、抽象CPU类 
class CPU
{
	public:
		//抽象的计算函数
		virtual void calculate()=0; 
};
//2、抽象显卡类 
class VideoCard
{
	public:
		//抽象的显示函数
		virtual void display()=0; 
};
//3、抽象内存条类 
class Memory
{
	public:
		//抽象的存储函数
		virtual void storage()=0; 
};

//电脑类
class Computer
{
	public:
		Computer(CPU *c,VideoCard *v,Memory *m)
		{
			cpu=c;
			vc=v;
			mem=m; 
		}
			//提供析构函数 释放3个电脑零件
	~Computer()
	{
		//释放CPU零件
		if(cpu!=NULL)
		{
			delete cpu;
			cpu=NULL;
		}
		//释放显卡零件
		if(vc!=NULL)
		{
			delete vc;
			vc=NULL;
		} 
		//释放内存条零件
		if(mem!=NULL)
		{
			delete mem;
			mem=NULL;
		}  
	} 
		//提供工作的函数
		void work()
		{
			//让零件工作起来，调用相应接口 
			cpu->calculate();
			vc->display();
			mem->storage();
		} 
	private:
		CPU *cpu;        //CPU的零件指针 
		VideoCard *vc;   //显卡零件指针 
		Memory *mem;     //内存条零件指针 
}; 

//具体厂商
//Intel厂商
class IntelCPU : public CPU
{
	public:
		virtual void calculate()
		{
			cout<<"Intel的CPU开始计算了！"<<endl;
		}
}; 
class IntelVideoCard : public VideoCard
{
	public:
		virtual void display()
		{
			cout<<"Intel的显卡开始显示了！"<<endl;
		}
}; 
class IntelMemory : public Memory
{
	public:
		virtual void storage()
		{
			cout<<"Intel的内存条开始存储了！"<<endl;
		}
}; 

//Lenovo厂商
class LenovoCPU : public CPU
{
	public:
		virtual void calculate()
		{
			cout<<"Lenovo的CPU开始计算了！"<<endl;
		}
}; 
class LenovoVideoCard : public VideoCard
{
	public:
		virtual void display()
		{
			cout<<"Lenovo的显卡开始显示了！"<<endl;
		}
}; 
class LenovoMemory : public Memory
{
	public:
		virtual void storage()
		{
			cout<<"Lenovo的内存条开始存储了！"<<endl;
		}
};  

void test01()
{
	//第一台电脑零件
	CPU *intelcpu=new IntelCPU;
	VideoCard *intelcard=new IntelVideoCard;
	Memory *intelmem=new IntelMemory;
	
	//创建第一台电脑
	cout<<"第一台电脑开始工作："<<endl;
	Computer *computer1=new Computer(intelcpu,intelcard,intelmem);
	computer1->work();
	delete computer1;
	
	//创建第二台电脑
	cout<<"-------------------------------" <<endl;
	cout<<"第二台电脑开始工作："<<endl;
	Computer *computer2=new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
	computer2->work();
	delete computer2;
	
	//创建第三台电脑
	cout<<"-------------------------------" <<endl;
	cout<<"第三台电脑开始工作："<<endl;
	Computer *computer3=new Computer(new LenovoCPU,new IntelVideoCard,new LenovoMemory);
	computer3->work();
	delete computer3;
	
} 

int main()
{
	test01();
	system("pause");
	return 0;
}
