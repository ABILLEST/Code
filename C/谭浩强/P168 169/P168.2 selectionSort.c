#include<stdio.h>
#define LENGTH 10

int main()
{
	int a[10],i,j,t;   //���彻���м���t���ⲿѭ������i, �ڲ�ѭ������j 
	for(i=0; i<=9; i++) 
		scanf("%d",&a[i]);//����10������ 
	for(i=0; i<LENGTH-1; i++)//��ʾ�±�i��Ԫ�����±�j�ĸ���Ԫ�����αȽ� 
		for(j=i+1; j<LENGTH; j++)//��֤ǰ���źõ�˳�򲻱� 
			if(a[i]>a[j]) //С�ķ�ǰ�� 
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for(i=0; i<=9; i++) //ѭ����� 
		printf("%d ",a[i]);
	return 0;
}
