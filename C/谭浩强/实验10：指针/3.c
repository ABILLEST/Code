#include<stdio.h>

//ָ�뷨���� 12 ����,Ȼ��ÿ�� 4 �������
int main()
{
	int a[12];
	int *p;
	printf("Please enter 12 numbers: ");
	
	for (p = a; p < (a+12); p++)	//��ָ������ 
		scanf("%d",p);
		
	printf("Answer:\n");
	for (p = a; p < (a+12);){		//��ָ�����,ѭ���������� 
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("\n");				//�ĸ�һ�� 
	}
	return 0;
 } 
