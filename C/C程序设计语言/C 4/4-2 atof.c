#include<stdio.h>

#define MAXLINE 100
//�򵥼���������
int main()
{
	double sum,atof(char []);
	int getline(char line[], int maxline);
	char line[MAXLINE]; 
	
	sum = 0;
	while (getline(line,MAXLINE) > 0)
		printf("\tPresent result:%g\n",sum += atof(line));
	return 0;
} 
//�����atof����
double atof(char s[])
{
	double val,power = 1.0;
	int i,sign,ed;
	
	for(i = 0; isspace(s[i]); i++)	//�����հ׷�
		;
	sign = (s[i] == '-')? -1:1; 	//���÷���λ
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
		
	if (s[i] == '.')
		i++;
	for (; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0; 
	}
	
	if (s[i] == 'e' || s[i] == 'E'){
		i++;
		if (s[i] == '-'){
			i++;		
			for (ed = 0.0; isdigit(s[i]); i++)
				ed = 10.0 * ed + (s[i] - '0');
			for (;ed > 0;ed--)
				power *= 10;
		}
		else if (s[i] == '+'){
			i++;		
			for (ed = 0.0; isdigit(s[i]); i++)
				ed = 10.0 * ed + (s[i] - '0');
			for (;ed > 0;ed--)
				power /= 10;
		}
		else {
			for (ed = 0.0; isdigit(s[i]); i++)
				ed = 10.0 * ed + (s[i] - '0');
			for (;ed > 0;ed--)
				power /= 10;
		}
	}
	
	return sign * val / power;
}

/*
//ԭatof���������ַ���sת��Ϊ��Ӧ��˫���ȸ����� 
double atof(char s[])
{
	double val,power;
	int i,sign;
	
	for(i = 0; isspace(s[i]); i++)	//�����հ׷�
		;
	sign = (s[i] == '-')? -1:1; 	//���÷���λ
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0; 
	}
	return sign * val / power;
}
*/
//getline�������ӷ��������棩
int getline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	//putchar('+');
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 
