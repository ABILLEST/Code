#include<stdio.h>

int main()
{
	int n,i=1,a=2;
	long p=0,s=0;
	scanf("%d",&n);
	//printf("n=%d\n",n);
	if(n>9) printf("����̫������\n");
	else if(n<0) printf("���벻��Ϊ��\n");
	else while(i<=n)
	{
		printf("i=%d,a=%d,",i,a);
		p += a;
		a = a*10;
		s += p;
		i++;
		printf("p=%d\n",p);
	}
	
	printf("Sum = %ld",s);
	return 0;
}
