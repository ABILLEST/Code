#include<stdio.h>
#include<string.h>
//�����ַ���
int main()
{
	void get_3_str(char *a,char *b,char *c);
	void swap(char *a,char *b);
	void put_3_str(char *a,char *b,char *c);
	
	char a[100],b[100],c[100];	//����Ҫ���㹻����ַ����� 

	get_3_str(a,b,c);		//���������ַ��� 
	swap(a,b);				//���ַ�����С���� 
	swap(b,c);
	swap(a,c);
	printf("\n");
	
	put_3_str(a,b,c);		//��������ַ��� 
	return 0;
}

//���뺯��
void get_3_str(char *a,char *b,char *c)
{
	gets(a);
	gets(b);
	gets(c);
 } 

//������
void swap(char *a,char *b)
{
	char t[100];
	if (strcmp(a,b)>0)	{
		strcpy(t,a);
		strcpy(a,b);
		strcpy(b,t);
	}
 }
 
 //�������
 void put_3_str(char *a,char *b,char *c)
 {
 	puts(a);
 	puts(b);
 	puts(c);
 }
