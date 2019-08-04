#include<stdio.h>

//itob������������nת��Ϊb���Ƶ����������浽�ַ���s��
void itob(int n, char s[], int b)
{
	static int i = 0;
	int sign;
	if ((sign = n) < 0){		//ȡ����ֵ 
		n = -n;
		s[i++] = '-';
	}		
    if (n < b)            //�ݹ�������� 
    {
        if (n < 10)        //��ǰ��ת�����ַ������ַ��� 
            s[i] = n + '0';
        else
            s[i] = n - 10 + 'A';
        s[i+1] = '\0'; //�ַ���������־ 
    }
    else
    {
        itob(n / b,s,b);  	//�ݹ���� 
        i++;                //�ַ�������+1 
        n %= b;           //���㵱ǰֵ
        if (n < 10)        //��ǰ��ת�����ַ������ַ��� 
            s[i] = n + '0';
        else
            s[i] = n - 10 + 'A';
        s[i+1] = '\0'; //�ַ���������־ 
    }
} 

int main()
{
	int num,b;
	char s[10];
	
	printf("������һ��ʮ������: ");
	scanf("%d",&num);
	printf("������Ҫת���Ľ���: ");
	scanf("%d",&b);
	itob(num,s,b);
	printf("\nת������� ");
	puts(s);
	return 0;
}
