#include<iostream>
using namespace std;

//点和圆 关系案例 

///////点类
class Point
{
	public:
		//设置X 
		void setX(int x)
		{
			X=x;
		}
		//获取X
		int getX()
		{
			return X;
		}
		
		//设置Y
		void setY(int y)
		{
			Y=y;
		}
		//获取Y
		int getY()
		{
			return Y;
		}
		
	private:
	    int X;
		int Y; 
};

///////圆类 
class Circle
{
	public:
		//设置半径
		void setR(int r)
		{
			R=r;
		}
		//获取半径
		int getR()
		{
			return R;
		}
		
		//设置圆心
		void setCenter(Point center)
		{
			Center=center;
		}
		//获取圆心 
		Point getCenter()
		{
			return Center;
		}
		
	private:
		int R;
		Point Center;        //在类中，可以让另一个类做本类中的成员 
};

//判断点和圆的关系
void judge(Circle &c,Point &p)
{
	int distance=( (c.getCenter().getX() - p.getX() ) * (c.getCenter().getX() - p.getX() ) +  (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY())   );
	int t=c.getR()*c.getR();
	if(distance>t)
	{
		cout<<"点在圆外！"<<endl;
	}
	else if(distance==t)
	{
		cout<<"点在圆上！"<<endl;
	}
	else 
	{
		cout<<"点在圆内！"<<endl;
	}
}

int main()
{
	Circle c;
	c.setR(5);
	Point cen;
	cen.setX(0);
	cen.setY(0);
	c.setCenter(cen);
	
	Point p;
	p.setX(2);
	p.setY(5); 
	 
	judge(c,p);
	
	system("pause");
}










//********************************// 

/*#include<iostream>
using namespace std;

class Circle
{
	public:
		//设计圆的半径
		void setR(int r)
		{
			R=r;
		}
		//获取圆的半径
		int getR()
		{
			return R;
		} 
	
	
	private:
		int R;
};

class Point
{
	public:
		//设置点到圆半径的距离
		void setL(int l)
		{
			L=l;
		}
		//获取点到圆半径的距离
		int getL()
		{
			return L;
		}
		
	private:
	    int L; 
};

int main()
{
	Circle c1;
	c1.setR(5);
	
	Point l1;
	l1.setL(2);
	
	if(c1.getR()>l1.getL())
	{
		cout<<"点在圆内！"<<endl;
	}
	else if(c1.getR()==l1.getL())
	{
		cout<<"点在圆上！"<<endl;
	}
	else
	{
		cout<<"点在圆外！"<<endl;
	}
	
	system("pause");
}*/
