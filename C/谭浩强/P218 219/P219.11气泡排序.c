#include "stdio.h"

int main()
{
	void sort(char array[],int num);	
	void printch(char array[],int n);
	
	int i,n;
	printf("How many chars? ");			 
	scanf("%d",&n);						//���Ƚ��ַ�����
	char a[n];
	printf("Please enter %d chars:\n",n);
	for (i = 0; i < n; ++i)				//�����ַ� 
		scanf("%c",&a[i]);
	printf("\nBefore: "); 
	printch(a,n);
	printf("\nAfter: ");
	sort(a,n);
	printch(a,n);
	return 0;
} 

//���ݷ�����
void sort(char a[],int n)
{
	int i,j;
	char temp;
	
	for (i = 0; i < n-1; i++)				//����n-1��ѭ����ʵ��n-1�˱Ƚ� 
		for (j = 0; j < (n-1-i); j++)		//ÿ���н���n-1-i�αȽ� 
			if (a[j] > a[j+1]){				//���������Ƚ� 
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}

//��ӡ�ַ����麯��
void printch(char a[],int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%c ",a[i]);
}
