#include<stdio.h>
#include<stdlib.h>

int n;								//���鳤��n 

//��ָ���������Ԫ��λ�øı�
int main()
{
	void exchange(int *before,int *after,int m);	//������������ 
	
	printf("How many numbers: ");
	scanf("%d",&n);
	int *p,m;
	int after[n],before[n];				//���������������ڽ��� 
	
	printf("Please enter %d numbers:\n",n);	
	for (p = before; p < (before+n); p++)		//����n������ 
		scanf("%d",p);
		
	printf("How many number(s) do you want to exchange: ");	//Ҫ��ǰ�������ĸ��� 
	scanf("%d",&m);
	
	printf("\nBefore: ");
	for (p = before; p-before < n; p++) 
		printf("%d ",*p);						//����׷��
	printf("\n");		 
	exchange(before,after,m);					//���ý������� 
	printf("Result: ");
	for (p = after; p-after < n; p++)		//������ 
		printf("%d ",*p);
	return 0;
	system("pause");
} 

//��������
void exchange(int *before,int *after,int m)
{
	int *p1,*p2;				//������ָ��������������Ԫ��λ�� 
	
	for (p1 = before+n-m,p2 = after; p2 < after+m+1; p1++,p2++)	//��ӦԪ����ǰ 
		*p2 = *p1;
	//printf("\n%d,%d\n\n",p1-before,p2-after);			//ָ��λ��׷�� 
	for (p1 = before,--p2; (p2-after) < n; p1++,p2++)				//˳λ�Ӻ� 
		*p2 = *p1;
} 
