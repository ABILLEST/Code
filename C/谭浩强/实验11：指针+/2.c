#include <stdio.h>

int main()
{
	void fsum(int a, int b, int *c);
	void swap(int *a, int *b);

	int a, b,c=0,*sum=&c,*pa=&a,*pb=&b;
	void (*p)();
	scanf_s("%d,%d", &a, &b);
	p = fsum;
	(*p)(a, b, sum);				//*p��Ҫ���� 
	p = swap;
	(*p)(pa, pb);
	printf("sum=%d\n", *sum);
	printf("a=%d,b=%d\n", a, b);
}

//��ͺ��� 
void fsum(int a, int b, int *sum)	//����Ϊ�գ���ָ����ؽ�� 
{
	*sum = a + b;
}


//�������� 
void swap(int *a, int *b)			//����Ϊ�գ���ָ����ؽ�� 
{
	int t; t = *a;	*a = *b; *b = t;
}

