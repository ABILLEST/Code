#include<stdio.h>
//��ӡˮ�ɻ��� 
int main()
{
	int a,b,c,j;
	printf("1~1000��ˮ�ɻ����У�");
	
	for(j=100; j<999; j++)
	{
		a = j/100;
		b = j/10 - a*10;
		c = j - (b*10 + a*100);
		if(j==a*a*a+b*b*b+c*c*c) printf("%d  ",j);
	}
	printf("\n");
	return 0;
}
