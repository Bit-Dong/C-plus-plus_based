#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造   参数：容量
	MyArray(int capacity)
	{
//		cout<<"Myarray有参构造调用"<<endl;
		this->Capacity=capacity;
		this->Size=0;
		this->pAddress=new T[this->Capacity];
	} 
	
	//拷贝构造
	MyArray(const MyArray &arr)
	{
//		cout<<"Myarray拷贝构造调用"<<endl;
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
//		this->pAddress=arr.pAddress; 
		
		//深拷贝 
		this->pAddress=new T[arr.Capacity];
		//将arr中的数据都拷贝过来
		for(int i=0;i<this->Size;i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		} 
	}
	
	//operator=  防止浅拷贝问题
	MyArray & operator=(const MyArray& arr)
	{
//		cout<<"Myarray 的operator= 调用"<<endl;
		//先判断原来堆区是否有数据，如果有先释放
		if(this->pAddress!=NULL)
		{
			delete[] this->pAddress;
			this->pAddress=NULL;
			this->Capacity=0;
			this->Size=0;
		}
		
		//深拷贝
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
		this->pAddress=new T[this->Capacity];
		for(int i=0;i<this->Size;i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		}
		return *this;
	} 
	
	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小
		if(this->Capacity==this->Size) 
		{
			return;
		}
		this->pAddress[this->Size]=val;  //在数组末尾插入数据 
		this->Size++;  //更新数组大小 
	} 
	
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if(this->Size==0)
		{
			return;
		}
		this->Size--; 
	} 
	
	//通过下标方式访问数组中的元素  arr[0]=100;
	T & operator[](int index)
	{
		return this->pAddress[index];
	} 
	
	//返回数组容量
	int getCapacity()
	{
		return this->Capacity;
	}
	
	//返回数组大小
	int getSize()
	{
		return this->Size;
	} 
	

	
	//析构函数 
	~MyArray()
	{
		if(this->pAddress!=NULL)
		{
//			cout<<"Myarray析构函数调用"<<endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}
	
private:
	int Capacity;   //数组容量 
	int Size;       //数组大小 
	T *pAddress;    //指针指向堆区开辟的真实数组 
};
