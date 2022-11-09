#include<iostream>
#include<string>
using namespace std;


class student
{
	//访问权想
	public:    //公共权限
	                                           //类中的属性和行为 我们统一称为“成员” 
	//属性                                    //属性   成员属性  成员变量 
	string name;                              //行为   成员函数  成员方法 
	string num;
	
	//行为
//学生c1：	
	string xingming()
	{
		return name;
	}
	string xuehao()
	{
		return num;
	}
	

    //行为
//学生c2： 
	void show()    //显示 
	{
	    cout<<"姓名："<<name<<"  学号:"<<num<<endl; 
    }
    //给姓名赋值
    void setname(string name1)     
    {
        name=name1;
    }
    //给学号赋值 
    void setnum(string num1)    
    {
        num=num1;
	}
	
};

int main()
{
//方法1： 
	student c1;
	c1.name="聂冬";
	c1.num="2006702-03";
	cout<<"姓名："<<c1.xingming()<<"  学号："<<c1.xuehao()<<endl;

//方法2：	
	student c2;
	c2.setname("聂佳");
	c2.setnum("123123");
	c2.show();
	
	system("pause");
}
