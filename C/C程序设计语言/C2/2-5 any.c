#include<stdio.h>

//���Ľ� 
//�����ַ�s2��s1�е�һ�γ��ֵ�λ�÷��� 
int any(char s1[], char s2[])
{
	int i,j;
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return (i+1);		//���ص�һ�γ��ֵ�λ�ã�ֱ�ӽ��������� 
	return -1;						//ѭ������δ�������ʾδ�ҵ�ƥ�� 
}

int main()
{
	char s1[50],s2[50];
	printf("�������ַ���1�� ");
	gets(s1);
	printf("�������ַ���2�� ");
	gets(s2);
	if(any(s1,s2) == -1)
		printf("\nNot found\n");
	else
		printf("Location: %d",any(s1,s2));
	return 0;
}
