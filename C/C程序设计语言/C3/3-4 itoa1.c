#include<stdio.h>
#include<string.h>
//���ͣ������(10000000)�󸺺���00000000������n = -n ��-(2^�ֳ�-1)�����0 

//my altered version
void itoa(int n, char s[])
{
	int i, sign;
	
	sign = n;
	i = 0;
	do {
		s[i++] = -(n % 10 + '0');		//ȡ��һ������ 
		} while ((n /= 10) < 0);	//ɾ��������
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}
/*
//original version
//itoa������������nת��Ϊ�ַ��������浽s�� 
void itoa(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0)	//��¼����
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';		//ȡ��һ������ 
		} while ((n /= 10) > 0);	//ɾ��������
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}
*/

//reverse�����������ַ���s�и����ַ���λ��
void reverse(char s[])
{
	int c,i,j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
} 

int main()
{
	int n;
	char s[10];
	scanf("%d",&n);
	itoa(n,s);
	puts(s);
	return 0;
}
