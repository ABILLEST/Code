#include<stdio.h>
#include<string.h>

//itoa����2.0��������nת��Ϊ�ַ��������浽s��,������پ��е����������ƶ�����С��� 
void itoa(int n, char s[], int w)
{
	int i, sign;
	
	if ((sign = n) < 0)	//��¼����
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';		//ȡ��һ������ 
		} while ((n /= 10) > 0);	//ɾ��������
	if (sign < 0)
		s[i++] = '-';			//����Ǹ�������Ӹ��� 
	while (i < w)				//�ڱ�Ҫʱ���ַ���s����ո� 
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s); 				//�ؼ�����λ��Ľ����ṩ���� 
}

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
	itoa(n,s,10);
	puts(s);
	return 0;
}
