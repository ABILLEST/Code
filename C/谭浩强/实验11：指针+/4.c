#include<stdio.h>

int main()
{
	char s[50];
	char *p,c,del;
	
	printf("������һ���ַ����� "); 
	gets(s);
	printf("����Ҫɾ�����ַ��� "); 
	scanf("%c",&del);
	for(p = s; *p != '\0'; p++){
		if (*p != del)			//�������'0'�������ַ�,����������
			  putchar(*p);    
	}
	return 0; 
 } 
