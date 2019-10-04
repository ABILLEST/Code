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


class SqStack
{
	Elemtype *base, *top;
	int stacksize;		//�ѷ���Ĵ洢�ռ� 
public:
	SqStack();
	~SqStack();
	void InitStack();
	Status ClearStack();
	bool isStackEmpty();
	bool isStackFull();
	int StackLen();
	Status GetTop(Elemtype &e);		//��ջ�� 
	Status Push(Elemtype e);
	Status Pop(Elemtype &e);
	Status D2O(int nD, int &nO);	//ʮ����ת�˽��� 
	Status BrackMatch(char* str); 
	friend bool Match(char ch1, char ch2);	//��������ƥ�� 
	
};


SqStack::SqStack()
{
	//��ʼ���߼���InitStack������ 
}

SqStack::~SqStack()
{
	
}

void SqStack::InitStack()
{
	base = new Elemtype[STACK_INIT_SIZE];
	if(!base) exit(error);
	top = base;
	stacksize = STACK_INIT_SIZE; 
} 

bool SqStack::isStackEmpty()
{
	return (base == top ? true : false);
}

bool SqStack::isStackFull()
{
	return (top - base >= stacksize ? true : false);
}

int SqStack::StackLen()
{
	return (top-base);
}

Status SqStack::GetTop(Elemtype &e)
{
	if(top == base) return error;
	e = *(top-1);
	return ok;
}

Status SqStack::Push(Elemtype e)
{
	if(top-base >= stacksize)	//ջ����׷�Ӵ洢�ռ�
	{
		base = new Elemtype[STACK_INCREMENT];
		if(!base) return(error);	//�ռ����ʧ�� 
		
		top = base + stacksize;
		stacksize += STACK_INCREMENT;
	}
	*top++ = e;
	return ok;
} 

Status SqStack::Pop(Elemtype &e)
{
	if(top == base) return error;		//ջ�� 
	e = *--top;
	return ok;
}

Status SqStack::D2O(int nD, int &nO)
{
	while(nD)
	{
		Push(nD%8);
		nD /= 8;
	}
	while(!isStackEmpty())
	{
		Pop(nO);
		cout<<nO;	//��λ��ӡ 
	}
	cout<<endl;
	return ok;
}
/*
Status SqStack::BrackMatch(char* str)
{
	char ch;
	for(int i=0; str[i]!='\0'; ++i)
	{
		switch(str[i])
		{
			case '(': 
			case '[':
			case '{':
				Push(str[i]); break;	//�����Ž�ջ 
			case ')':
			case ']':
			case '}':
				if(isStackEmpty()){
					cout<<"�����Ŷ���"<<endl;
					return error;
				}
				else{
					GetTop(ch);
					if(Match(ch,str[i])){
						Pop(ch);
					}
					else{
						cout<<"�������Ų�ƥ��"<<endl;
						return error;
					}
				}
		}
		
		if(isStackEmpty())
		{
			cout<<"����ƥ��"<<endl;
			return ok;
		}
		else
		{
			cerr<<"�����Ŷ���"<<endl;
			return error;
		}
	}
}
*/
bool Match(char chL, char chR)
{
	if(chL=='(')
	{
		if(chR==')') return true;
		else return false;
	}
	else if(chL=='[')
	{
		if(chR==']') return true;
		else return false;
	}
	else if(chL=='{')
	{
		if(chR=='}') return true;
		else return false;
	}
	else{
		cerr<<"single match error"<<endl;
		return false;
	}
}


int main()
{
	SqStack s; 
}
