#include<stdio.h>

//�Ż�P244����8.10
int main()
{
	void sort(int x[],int n);
	int i,*p,a[10];
	p = a;
	printf("Please enter 10 integer numbers: ");
	for (i = 0; i < 10; i++)
		scanf("%d",p++);
	p = a;
	sort(p,10);
	for (p = a; p < (a+10); p++)			//ʹ��ָ��������飬������� 
		printf("%d ",*p);
	printf("\n");
	return 0;
}

//�Ż����ѡ�����򷨺��� 
void sort(int *x,int n)
{
	int *p1,*p2,k,t;
	for(p1 = x; p1 < x+n-1; p1++){			//ʹ��ָ��������飬�������
		k = p1-x;
		for (p2 = p1+1; p2 < x+n; p2++)		//ʹ��ָ��������飬�������
			if (*p2 > *(x+k)) k = p2-x;		//��ָ����������Ԫ�� 
				if (k != p1-x)
					{t = *p1;*p1 = *(x+k);*(x+k) = t;}
	}
}
