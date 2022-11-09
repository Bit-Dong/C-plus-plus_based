#include<iostream>	
using namespace std;

//   立方体类设计
//         1、创建立方体类      
//         2、设计属性 
//         3、设计行为  获取立方体面积和体积 
//         4、分别利用全局函数和成员函数  判断两个立方体是否相同 
 
 
//创建立方体类 
class Cube
{
   	public:
   		//设置长 
   		void setL(int l)
   		{
   			L=l;
		}
		//获取长
		int getL()
		{
			return L;
		}
		
   		//设置宽 
   		void setW(int w)
   		{
   			W=w;
		}
		//获取宽
		int getW()
		{
			return W;
		}		
   		
   		//设置高 
   		void setH(int h)
   		{
   			H=h;
		}
		//获取高
		int getH()
		{
			return H;
		}
		
		//获取立方体面积
		int getcalculaterS()
		{
			return 2*(L*W+L*H+W*H);
		}
		
		//获取立方体体积
		int getcalculaterV()
		{
			return L*W*H;
		}
		
//成员函数判断两个立方体是否相同 
bool same2(Cube &c)
{
	if(H==c.getH()&&L==c.getL()&&W==c.getW())
	{
		return true;
	}
	return false;
}
		   		
   	private:
   		int L;
   		int W;
   		int H;
}; 

//全局函数判断两个立方体是否相同
bool same1(Cube &c1,Cube &c2)
{
	if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW())
	{
		return true;
	}
	return false;
}

int main()
{
//创建立方体c1 
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout<<"立方体c1的面积为："<<c1.getcalculaterS()<<endl;
	cout<<"立方体c1的体积为："<<c1.getcalculaterV()<<endl;

//创建立方体c2
    Cube c2;
    c2.setL(10);
	c2.setW(10);
	c2.setH(10);
	cout<<"立方体c2的面积为："<<c2.getcalculaterS()<<endl;
	cout<<"立方体c2的体积为："<<c2.getcalculaterV()<<endl;	 

//全局函数判断
    bool ref1=same1(c1,c2);
    if(ref1)
    {
    	cout<<"全局函数判断：立方体c1和立方体c2相同！"<<endl;
	}
	else
	{
		cout<<"全局函数判断：立方体c1和立方体c2不相同！"<<endl;
	}
 
//成员函数判断
    bool ref2=c1.same2(c2);
    if(ref2)
    {
    	cout<<"成员函数判断：立方体c1和立方体c2相同！"<<endl;
	}
	else
	{
		cout<<"成员函数判断：立方体c1和立方体c2不相同！"<<endl;
	}	 
 
	system("pause");
}
