#include "stdio.h"

long int jf (int n)                         /*������׳˺���jf*/
{ 
	int  i;
  	long int t=1;
 	for(i=1; i<=n; i++)
    t*=i;
    return t;
}

long int cmn(int m, int n)           /*���������������cmn*/
{ return (jf(m) / (jf(n)*jf(m-n)));}      /*��return��䷵�ؽ��*/ 

int main()
{ 
	int m,n;   
    printf("please enter m and n(�����Ķ�������): ");
    scanf("%d��%d", &m, &n );   //scanf���������������Ķ������� 
    printf("C(m,n) = %ld\n",cmn(m,n)); 
    return 0;        
  }
