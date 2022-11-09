#include<iostream>
#include<string>
using namespace std;

 
class  Base
{
	public:
		int A;
	protected:
		int B;
	private:
		int C;     //私有成员只是被隐藏了 ，但是还是会继承下去  
};

//公共继承
class son : public Base
{
	public:
		int D;
};

void test01()
{
	cout<<"sizeof son ="<<sizeof(son)<<endl;
} 

int main()
{
	test01();
	
	system("pause");
	return 0;
}
