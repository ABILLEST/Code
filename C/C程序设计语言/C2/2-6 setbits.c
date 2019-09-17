#include <stdio.h>


/*           My answer          */ 
//��x�дӵ�pλ��ʼ��n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ��x�������λ���ֲ��� 
unsigned setbits(unsigned x, int p, int n, int y)
{
	int setValue = y & ~(~0 << n);
	return (x ^ (setValue << (p-n)));
}


unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

/*
test case:
	input:(7,5,2,3)
	output:31
*/

int main()
{
	while(1)
	{
		int input;
		scanf("%d",&input);
		printf("setbits : %d\n",setbits(input,5,2,3));
		//printf("getbits : %d\n",getbits(input,4,3));
	}
	
}
