#include<stdio.h> 
#define MAXLINE 1000

int getline(char line[], int maxline);
int strindex(char source[],char searchfor[]);

char pattern[] = "this";	//�����ҵ�ģʽ

//�ҳ�������ģʽƥ����� 
int main()
{
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line,MAXLINE) > 0)
		if (strindex(line,pattern) >= 0) {
			printf("%sthe index is %d\n",line,strindex(line,pattern)+1);
			found++;
		}
	return found;
}

//getline��������һ�ж��뵽s�в������䳤��
int getline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 


//strrindex����������t��s�����ұ߳��ֵ�λ�ã���δ�ҵ��򷵻�-1 
int strindex(char s[],char t[])
{
	int i, j, k, l;
	
	for(i = 0; s[i] != '\0'; i++)//�ѹ��ָ��s�ĺ���һ�� 
		; 
	i--;						//���ص�s�����һ�� 
	for(k = 0; t[k] != '\0'; k++)//�ѹ��ָ��t�ĺ���һ�� 
		; 
	k--;						//���ص�t�����һ�� 
	for (j = i; i > 0; i--){
		for (j=i; t[k] != '\0' && s[j]==t[k]; j--, k--)
		;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;	
} 

