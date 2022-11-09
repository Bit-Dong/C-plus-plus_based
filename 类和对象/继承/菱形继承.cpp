#include<iostream>
#include<string>
using namespace std;

class Animal
{
	public:
		int A;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal{}; 
class Tuo : virtual public Animal{}; 
class SheepTuo : public Sheep,public Tuo{};

void test01()
{
	SheepTuo st;
	st.Sheep::A=100;
	st.Tuo::A=200;
	
	cout<<"st.Sheep::A = "<<st.Sheep::A<<endl;
	cout<<"st.Tuo::A = "<<st.Tuo::A<<endl;
	cout<<"st.A =  "<<st.A<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
