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
	ifstream ifs("person.txt",ios::in | ios::binary);
	
	//3、打开方式 ,并判断是否打开成功 
//	ifs.open("person.txt",ios::in);    //该文件必须在同一文件夹下面 
	
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return;
	}
	
	//4、读数据 
	Person p;
	ifs.read((char *)&p,sizeof(p)); 

	cout<<"姓名：" <<p.Name<<"  年龄：" <<p.Age<<endl;
	
	//5、关闭文件
	ifs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
