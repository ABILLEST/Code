#include<stdio.h>

void turn(int n)
{ 
	int i; 
	
	if ((i=n/10)!=0)		//�������i����10��Ϊ0,˵����λ����ֵ
		turn(i);			//��������,ʹ�ó���10���iֵ
	putchar(n%10+'0');		//��ӡ����,��ת��Ϊ'0' 
}
int main()
{
	int number;
	printf("\nInput an integer:");
	scanf("%d",&number);	//����һ������
	printf("Output:");		//�����Ϣ
	if (number<0){			//����Ǹ���  
		putchar('-');			//��ӡ����
	    number=-number;	//������Ϊ����
	}
	turn(number); 			//�ݹ麯������ 
}
