#include <iostream>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define ElemType int
#define MAXSIZE 10

typedef struct
{
	char ch[MAXSIZE];
	int num;
}Keytype;

typedef struct
{
	ElemType *elem;
	int count;
	int sizeindex;
}HashTable;

/*
paras:
	p: �����ҳɹ�������pָʾ��������Ԫ���ڱ��е�λ�ã�
		������pָʾ����λ�� 
	c��ͳ�Ƴ�ͻ��������ֵΪ0	 
*/
int SearchHash(HashTable H, Keytype K, int &p, int &c)
{
	p = Hash(K);
	while(H.elem[p])
}
