#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend class GoodGay;   //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容

	public:
		Building();
	    string sittingroom;
	private:
		string bedroom;
};

class GoodGay
{
	public:
		GoodGay();
		void vivst();
	private:
		Building *build;
};

Building::Building()
{
	sittingroom="客厅";
	bedroom="卧室"; 
}

void GoodGay::vivst()
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
	gg.vivst(); 
}

int main()
{
	
	test01();
	system("pause");
	return 0;
}
