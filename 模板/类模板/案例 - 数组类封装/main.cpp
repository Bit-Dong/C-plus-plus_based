#include <iostream>
#include <string>
#include"MyArray.hpp"
using namespace std;

//打印输出数组
void printIntArray(MyArray<int>& arr)
{
	cout<<"数组元素为：";
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<endl;
	
	cout<<"数组容量为："<<arr.getCapacity()<<endl;
	cout<<"数组元素个数为："<<arr.getSize()<<endl; 
	cout<<endl;
}

void test01()
{
	MyArray<int>arr1(5);
//	MyArray<int>arr2(arr1);    //拷贝构造 
//	MyArray<int>arr3(100);     //有参构造 
//	arr3=arr1;                 //operator= 调用 

	for(int i=0;i<5;i++)
	{
		arr1.Push_Back(i);
	}
	cout<<"数组arr1的具体信息："<<endl;
	printIntArray(arr1);
	
	
	MyArray<int>arr2(arr1);
	cout<<"数组arr2的具体信息："<<endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout<<"arr2尾删后的信息为："<<endl;
	printIntArray(arr2);
}


class Person
{
public:
	Person(){};
	Person(string name,int age)
	{
		this->Name=name;
		this->Age=age;
	}
	
	string Name;
	int Age;
};

void printPersonArray(MyArray<Person> &arr)
{
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<"姓名："<<arr[i].Name<<"  年龄："<<arr[i].Age<<endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	
	Person p1("孙悟空",99);
	Person p2("猪八戒",88);
	Person p3("沙和尚",77);
	Person p4("唐三藏",66);
	Person p5("小白龙",55);
	
	//将数据插入到数组中
	arr.Push_Back(p1); 
	arr.Push_Back(p2); 
	arr.Push_Back(p3); 
	arr.Push_Back(p4); 
	arr.Push_Back(p5); 
	
	//打印数组
	printPersonArray(arr);
	
	//输出容量
	cout<<"arr容量为："<<arr.getCapacity()<<endl;
	
	//输出大小 
	cout<<"arr大小为："<<arr.getSize()<<endl;
	
}

int main()
{
//	test01();
	test02();	
	system("pause");
	return 0;
}
