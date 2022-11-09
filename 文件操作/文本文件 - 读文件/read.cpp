#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

void test01()
{
	//1、包含头文件 fstream
	 
	//2、创建流对象 
	ifstream ifs;
	
	//3、打开方式 ,并判断是否打开成功 
	ifs.open("test.txt",ios::in);    //该文件必须在同一文件夹下面 
	
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return;
	}
	
	//4、读数据 
	
//	//第一种
//	char buf[1024]={0};
//	while(ifs>>buf)
//	{
//		cout<<buf<<endl;
//	}
//	
//	//第二种
//	char buf[1024]={0};
//	while(ifs.getline(buf,sizeof(buf))) 
//	{
//		cout<<buf<<endl;
//	}
//	
//	//第三种 
//	string buf;
//	while(getline(ifs,buf))
//	{
//		cout<<buf<<endl;
//	} 
//	
	//第四种       //平常不建议用这种 
	char c;
	while((c=ifs.get())!=EOF)   //EOF:end of file  文件尾
	{
		cout<<c;
	} 
	
	//5、关闭文件
	ifs.close(); 
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
