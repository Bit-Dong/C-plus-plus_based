#include<iostream>
#include<string>
using namespace std;

//C++开发提倡利用多态设计程序架构，因为多态优点很多 

//普通实现 
class Calculator
{
	public:
		int getResult(string oper)
		{
			if(oper == "+")
			{
				return A+B;
			}
			else if(oper == "-")
			{
				return A-B;
			}
			else if(oper == "*")
			{
				return A*B;
			}
		}
	public:
		int A;
		int B;
};
void test01()
{
	Calculator c;
	int A=10;
	int B=10;
	cout<<A<<" + "<<B<<" = "<<c.getResult("+")<<endl;
	cout<<A<<" - "<<B<<" = "<<c.getResult("-")<<endl;
	cout<<A<<" * "<<B<<" = "<<c.getResult("*")<<endl;
} 


//多态实现
//抽象计算器类 
// 多态优点：代码组织结构清晰，可读性强，利于前期和后期的拓展以及维护
class AbstractCalculator
{
	public:		
		virtual int getResult()
		{
			return 0;
		}
	
	public:
		int A;
		int B; 
};

//加法计算器 
class AddCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A+B;
		}
};
//减法计算器
class SubCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A-B;
		}
};
//乘法计算器 
class MulCalculator :public AbstractCalculator
{
	public:
		int getResult()
		{
			return A*B;
		}
};

void test02()
{
	//创建加法计算器
	AbstractCalculator *abc=new AddCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" + "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //用完销毁 
	
	//创建减法计算器
	abc=new SubCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" - "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //用完销毁  
	
	//创建乘法计算器
	abc=new MulCalculator;
	abc->A=10;
	abc->B=10;
	cout<<abc->A<<" * "<<abc->B<<" = "<<abc->getResult()<<endl; 
	delete abc;   //用完销毁 
 

}

int main()
{
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
