#include<stdio.h>

//ɾ���ַ���s1����s2�е�ƥ����ַ� 
void queeze(char s1[], char s2[])
{
	int i,j,k,flag = 0;			//���ñ�־�����ж��Ƿ��ҵ�ƥ���ַ� 
	
	for (i = j = 0; s1[i] != '\0'; i++){	//��ÿ��s1�е��ַ��ж��Ƿ��s2�е������ַ�ƥ�� 
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				flag = 1;			//��ǰs1�ַ�ƥ������1 
		if (!flag)	s1[j++] = s1[i];//��ǰs1��ƥ������ ����jָ����һ��������λ 
		flag = 0;					//������0 
	}
	s1[j] = '\0';					//ѭ������������ַ��������� 
}

/*
//Answer��squeeze�� delete each char in s1 which is in s2 
void queeze(char s1[], char s2[])
{
	int i,j,k;
	
	for (i = j = 0; s1[i] != '\0'; i++){
		for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++);
			if (s2[k] == '\0')				//end of string - no match
				s1[j++] = s1[i];
	}
	s1[j] = '\0';	
}
*/
int main()
{
	char s1[50],s2[50];
	printf("�������ַ���1�� ");
	gets(s1);
	printf("�������ַ���2�� ");
	gets(s2);
	queeze(s1,s2);
	printf("����� ");
	puts(s1);
	return 0;
}
