#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

class Person
{
	public:
		char Name[64];
		int Age;
};

void test01()
{
	//1、包含头文件 fstream
	 
	//2、创建流对象 
	ofstream ofs("person.txt",ios::out | ios::binary);
	
	//3、指定打开方式 
	//ofs.open("test.txt",ios::out | ios::binary);
	
	Person p={"新疆",52};
	
	//4、写文件
	ofs.write((const char *)&p,sizeof(p)); 

	
	//5、关闭文件
	ofs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
