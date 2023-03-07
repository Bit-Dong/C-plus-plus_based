/*
【问题描述】对于不带头结点的单链表L，设计一个递归算法逆置所有结点。
			编写完整的实验程序，并采用相应数据进行测试。
*/
#include<iostream>
#include<list>
#include<malloc.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{	ElemType data;
	struct Node *next;
} LinkNode;
void CreateList(LinkNode *&L,ElemType a[],int n)	//由a[0..n-1]创建单链表L
{
	LinkNode *p, *r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->data=a[0];
	r=L;					//r指向当前尾结点
	for (int i=1;i<n;i++)
	{
		p=(LinkNode *)malloc(sizeof(LinkNode));
		p->data=a[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;			//尾结点next域置为空
}
void DispList(LinkNode *L)	//输出单链表L
{
	LinkNode *p=L;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
LinkNode *Reverse(LinkNode *L)	//逆置不带头结点的单链表L
{	LinkNode *p,*q;
	if (L==NULL || L->next==NULL)
		return L;
	p=Reverse(L->next);
	q=L->next;
	q->next=L;
	L->next=NULL;
//	L->next->next=L; 			//将L结点链接到L->next结点后面
//	L->next=NULL;				//将L结点作为整个逆置后的尾结点
	return p;
}
int main()
{
	ElemType a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkNode *L;
	CreateList(L,a,n);
	cout<<"实验结果:"<<endl;
	cout<<"  逆置前L: "<<endl;
	DispList(L);
	cout<<"  执行L=Reverse(L)"<<endl;
	L=Reverse(L);
	cout<<"  逆置后L: "<<endl;
	DispList(L);
	return 0;
}
