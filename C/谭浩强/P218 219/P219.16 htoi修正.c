#include<stdio.h>
#define MAXLEN 20

//16->10����ת������
int trans_16to10(char *s)
{
	int i, t;			//����ѭ�����Ʊ���i�� 
	long long a = 0;
	
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] <= '9') 
			t = s[i] - '0';		//���ַ�ת��Ϊ���� 
		else
			t = s[i] - 'A' + 10;//��ʮ�������е���ĸת��Ϊ���� 
		a = a * 16 + t;
	}
	return a;
}

int main()
{
	char s_16[MAXLEN];
	printf("����ʮ���������� ");
	scanf("%s",s_16);
	printf("\n��Ӧʮ������Ϊ��%lld\n",trans_16to10(s_16));	
	return 0;
}
/*
//��׼��������� 
int main()
{
	int num;
	scanf("%x",&num);
	printf("%d",num);
	return 0;
}*/
