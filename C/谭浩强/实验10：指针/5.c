#define S(a,b) a*b
#include <stdio.h>

int main( ) 
{
	int c,d,t ;
	scanf("%d,%d",&c,&d);
	t = S(c+d,c-d);	/*��չ���������� c,d ��ֵ���Ӷ���ñ��� t ��ֵ*/
	printf("%d",t);
}

