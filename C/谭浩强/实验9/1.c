#include "stdio.h"

//��x��n�η� 
int main()
{
	long int fact(long x,long n) ; 			/*����fact����*/
	
	long int x, n;
	printf("please enter X , N (>=0): ");
    scanf("%ld,%ld", &x, &n );
    
    printf("%ld��%ld�η� = %ld",x,n, fact(x,n));  /*����fact���� */
	return 0;
 } 

long int fact(long int x, long int n)        /*����fact������xn */
{ 
	long int  i,s;
    s = 1;                       /*���ۻ������ĳ�ʼ��*/
	if (n == 0)  return 1;
	for(i=1; i<=n; i++)                     /*��ѭ��ʵ��xn*/
		s=s*x; 
    return(s);                              /*���ؽ��xn*/
}
