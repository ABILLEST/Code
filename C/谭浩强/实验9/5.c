#include "stdio.h"
#define LEN 10		//���鳤�� 

//�ж�һ�����������и�Ԫ�ص�ֵ���� 
void judge(int array[],int length)
{
	int i;
	for (i = 0; i <= length; ++i){		//����жϸ�Ԫ��ֵ 
		if (array[i] > 0)
			printf("%d\t",array[i]);
		else
			printf("0\t");
	}
} 

int main( )
{
	int a[LEN],i;
	printf("����10������\n");
	 
	for (i = 0; i <= LEN; ++i){
		scanf("%d",&a[i]);
	}
	
	printf("\n");
	judge(a,LEN);
	return 0; 
}
