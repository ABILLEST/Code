#include<stdio.h>
#include<stdlib.h>

float orih;

//�ص��߶Ⱥ���
float height(int x)
{
	float c;
	if (x == 0)
		c = orih;
	else
		c = height(x - 1)/2;
	return(c);
}

//�������Ⱥ���
float length(int x)
{
	float c;
	if (x == 0)
		c = orih;
	else
		c = length(x - 1) + height(x) * 2;
	return(c);
}

int main()
{
	float height(int n);
	float length(int n);

	int x;

	printf("Enter the original height: ");				//����ԭʼ�߶Ⱥͻص����� 
	scanf_s("%f", &orih);
	printf("Enter times: ");
	scanf_s("%d", &x);
	printf("The height is %f\n", height(x));
	printf("The length is %f\n", length(x));

	system("pause");
	return 0;
}
