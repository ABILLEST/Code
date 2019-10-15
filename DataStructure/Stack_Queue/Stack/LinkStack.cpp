#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ok 0
#define error -1
#define Elemtype int
#define Status int
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

class LinkStack;

class Node
{
public:
	Elemtype data;
	Node *next;
	friend class LinkStack;
};

class LinkStack
{
	Node *top;
	int stacksize;		//�ѷ���Ĵ洢�ռ� 
public:
	LinkStack();
	~LinkStack();
	Status InitStack();
	Status ClearStack();
	bool isStackEmpty();
	//���� 
	int StackLen();
	Status GetTop(Elemtype &e);		//��ջ�� 
	Status Push(Elemtype e);
	Status Pop(Elemtype &e);
	
};


LinkStack::LinkStack()
{
	//��ʼ���߼���InitStack������ 
}

LinkStack::~LinkStack()
{
	
}

Status LinkStack::InitStack()
{
	top = new Node;
	if(!top) return error;
	top->next = NULL;	//������ջ
	return ok;
} 

bool LinkStack::isStackEmpty()
{
	return (top->next ? true : false);
}

int LinkStack::StackLen()
{
	return (stacksize);
}

Status LinkStack::GetTop(Elemtype &e)
{
	if(top->next = NULL) return error;
	e = top->next->data;
	return ok;
}

Status LinkStack::Push(Elemtype e)
{
	Node *temp;
	temp = new Node;
	if(!temp) return error;		//����ռ�ʧ��
	temp->data = e; temp->next = top->next;	//ͷ�巨 
	top->next = temp;	//�ƶ�ջ��ָ�� 
	++stacksize;
	
	return ok;
} 

Status LinkStack::Pop(Elemtype &e)
{
	Node *temp;
	temp = top->next;
	if(!temp) return error;		//ջ�� 
	top->next = temp->next; e = temp->data; free(temp);
	--stacksize;
	
	return ok;
}


int main()
{

}
