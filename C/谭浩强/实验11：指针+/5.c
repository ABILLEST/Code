#include<stdio.h>

int main()
{
	int num,ge,shi,bai,a;
	char *pa[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	
	printf("Please enter a number(>=100): ");
	scanf("%d",&num);			//����һ����λ�� 
	ge = num%10;				//�ֱ�ȡ����λ���ĸ���λ 
	shi = (num/10)%10;
	bai = num/100;
	a = ge+shi+bai;
	if(a >= 1 && a <= 12)
		printf("%s",pa[a-1]);
	else printf("***\n");
	return 0;
 } 
