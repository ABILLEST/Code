#include<stdio.h>

int main()
{
	int divisor(int a,int b);			//���Լ������ԭ�� 
	int mutiple(int a,int b);			//��С����������ԭ�� 
	
	int num1,num2;
	
	printf("Enter two numbers: \n");
	scanf("%d",&num1);					//���������� 
	scanf("%d",&num2);
	if (divisor(num1,num2) == -1)		//�ж������Ƿ���� 
		printf("Wrong enter!\n");
	else{								//��� 
		printf("The largest common divisor is %d\n",divisor(num1,num2));
		printf("The least common mutiple is %d\n",mutiple(num1,num2));
	}
	return 0;
}

//���Լ��������շת������� 
int divisor(int a,int b)
{
	int c;			//�������� 
	c = a%b; 
	if (a == 0 || b == 0)	//����Ϊ0ʱ���� 
		return -1;
	else if (c == 0)		//����Ϊ0ʱ������Ϊ���Լ�� 
		return(b);
	else{
		a = b; b = c;		//���Ľ��� 
		b = divisor(a,b);	//�ݹ���� 
	}
}

//��С����������
int mutiple(int a,int b)
{return (a*b/divisor(a,b));}

