#include<stdio.h>
#define MAXLEN 10 
int max = 0;			//����ȫ�ֱ��� 
int min = 0;

int main()
{
	void maxmin(int *array);		//�����������������Сֵ�ú��� 
	

	int a[MAXLEN] = {1,8,10,2,-5,0,7,15,4,-5};
	maxmin(a);						//���ú����������� 
	printf("max = %d\nmin = %d",max,min);
} 

//�����������������Сֵ���� 
void maxmin(int *array)
{
	int *p;
 
	for (p = array; p < array+MAXLEN-1; p++){
		if (*p > max)	max = *p;
	    if (*p < min)	min = *p;
	}
}
