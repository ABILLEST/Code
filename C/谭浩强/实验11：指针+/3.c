#include<stdio.h>
#define N 10		//�������鳤�� 

int main()
{
	void input(int *a);
	void fuc(int *a);
	void output(int *a);
	
	int a[N];
	void (*p)();	//����ָ�뺯�����ֱ������������ 
	p = input;
	(*p)(a);
	p = fuc;
	(*p)(a);
	p = output;
	(*p)(a);
	return 0;
	
 } 
 
//���뺯��
void input(int *a)
{
	int *p;
	printf("Please enter %d numbers\n",N);
	for (p = a; p < (a+N); p++){	//����ָ������������Ч�� 
		scanf("%d",p);
	}
 } 
 
//������
void fuc(int *a)
{
	int max,*p1,*p2,t;				//p1ѭ����p2��¼maxλ�� 
	for (p1 = a; p1<a+N;p1++) 		//����ָ������������Ч�� 
		if (*p1 > max){
			max = *p1;
			p2 = p1;
		} 
	//printf("max is %d,p:%d\n",max,p2-a);
	t = *p2;						//����������һ��������λ�� 
	*p2 = *(a+N-1);
	*(a+N-1) = t;
}


//�������
void output(int *a)
{
	int *p;
	printf("\n");
	for (p = a; p < (a+N); p++){	//����ָ������������Ч�� 
		printf("%d  ",*p);
	}
 }

