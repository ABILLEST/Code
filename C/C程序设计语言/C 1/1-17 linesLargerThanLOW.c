#include<stdio.h>
#define LOW 10	//��ӡ���ڴ�����������
#define MAXLINE 1000	//���������е���󳤶�


int getline(char line[], int maxline);
//��ӡ����LOW������������ 
int main()
{
	int len[MAXLINE];			//ÿһ�г���
	char line[5][MAXLINE];	//��ǰ��������
	int i = 0;			//����������� 
	
	for(i = 0; i < 5; i++)
		len[i] = getline(line[i], MAXLINE)-1;
	printf("\n");
	
	//for(i = 0; i < 5 ; i++)					//test:	lenghth formally
		//printf("%d ",len[i]);
	//for(i = 0; i < 5 ; i++)					//test:	input formally
		//printf("%s",line[i]);
		
	for(i = 0; i < 5; i++)		//output
		if (len[i] > LOW)
			printf("line[%d] : %s\n",i+1,line[i]);
	return 0;
 } 	
 
 //getline��������һ�ж��뵽s�в������䳤��
int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	} 
	s[i] = '\0';	//��������� 
	return i;
} 

