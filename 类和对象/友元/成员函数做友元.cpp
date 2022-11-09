#include<iostream>
#include<string>
using namespace std;

class Building; 
class GoodGay
{
	public:
		GoodGay();
		void visit();
	private:
		Building *build;
};

class Building
{
	friend void GoodGay::visit();    //告诉编译器goodGay类中的visit成员函数是Building好朋友，可以访问私有内容
	public:
		Building();
	    string sittingroom;
	private:
		string bedroom;
};



Building::Building()
{
	sittingroom="客厅";
	bedroom="卧室"; 
}

void GoodGay::visit()
{
	cout<<"好基友正在访问："<<build->sittingroom <<endl;
	cout<<"好基友正在访问："<<build->bedroom<<endl;	
}

GoodGay::GoodGay()
{
	build=new Building;
}

void test01()
{
	GoodGay gg;
	gg.visit(); 
}

int main()
{
	
	test01();
	system("pause");
	return 0;
}
