#include<stdio.h>

int main()
{
	int i,j;
	int a[10][10];
	
	for(i=0; i<10; i++){		//����һ�кͶԽ���Ԫ�ظ�1 
		a[i][i]=1;
		a[i][0]=1; 
	}
	for(i=2; i<10; i++)			//�ӵ�3�п�ʼ 
		for(j=1; j <= i-1; j++){	//�ӵ�2�п�ʼ��ÿ�ε�i-1�н������� 
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	for(i=0; i<10; i++){
		for(j=0; j<=i; j++)		//�е����Ҫ������ 
			printf("%5d",a[i][j]);
		printf("\n");	
	}
	return 0;
}
