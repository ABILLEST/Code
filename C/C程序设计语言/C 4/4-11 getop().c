#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100	//�����������������󳤶�
#define NUMBER '0'	//��ʶ�ҵ�һ����
#define MAXVAL 100	//ջval��������
#define BUFSIZE 100	//��������С 
 
int getop(char []);
void push(double);
double pop (void);
int getch(void);
//void ungetch(int);
void ungets(char *);
void clear(void);

int sp = 0;			//��һ������ջλ��
double val[MAXVAL];	//ֵջ 
char buf[BUFSIZE];	//����ungetch�����Ļ�����
int bufp = 0;		//buf�е���һ������λ�� 

//�沨��������(��һ����̬��������getch����������)
int main()
{
	int type,near,i,var = 0.0;
	double op1,op2,v;
	char s[MAXOP];
	double variable[26];
	const double pi=acos(-1.0);
	
	
	printf("ע�⣺����������֮���ÿո����\n");
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;
	while ((type = getop(s)) != EOF){	//�ж���һ��λ�õ����� 
		switch (type){
			case NUMBER:  
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();//������ 
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)//��ĸ��Ϊ�� 
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case 's':		//ʹ��sin()
				push(sin(pop()*pi/180));
				break;
			case 'e':
				push(exp(pop()));
				break; 
			case '?':		//������Ϣ helping
				 printf("\n������Ϣ��\np	��ӡջ��Ԫ�ز�ѹ���ջ\nc	���ջ\nd	����ջ��Ԫ��\nx	����ջ��Ԫ��\n");
			case 'p':		//��ӡջ��Ԫ�ز�ѹ���ջ print top element of the stack
				op2 = pop();
				printf("\t%.8g\n",op2);
				push(op2);
				break;
			case 'c':		//���ջ clear the stack
				clear();
				break;
			case 'd':		//����ջ��Ԫ�� duplicate top elem. of the stack 
				 op2 = pop();
				 push(op2);
				 push(op2);
				 break;
			case 'x':		//����ջ��Ԫ�� swap the top two elems.
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '='://��������ֵ 
				pop();
				if (var >= 'A' && var <= 'Z'){
					variable[var - 'A'] = pop();
					//printf("%c <- %ld\n",var,variable[var - 'A']);
				}
					
				else
					printf("error: no variable name\n");
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if (type >= 'a' && type <= 'z')
					if (type == 'v')
						push(v);
					else
						printf("PLEASE USE UPPER LETTER.\n");
				else
					printf("error: unknown command %s.\n",s);
				break;
		};
		var = type;
	}
	return 0;
 } 
 
//push��������fѹ�뵽ֵջ��
void push(double f)
{
 	if (sp < MAXVAL)
 		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
} 
  
//pop����������������ջ����ֵ
double pop(void)
{
	if (sp > 0)
		return val[--sp];	//���򵯳�����ջ��ֵ 
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
} 
   
//getop��������ȡ��һ�����������ֵ������
int getop(char s[])
{
	int i, c;
	static int lastc;//�������һ����������ַ�
	
	if (lastc == 0)
		c = getch();
	else{
		c = lastc;
		lastc = 0;
	} 
	while ((s[0] = c)== ' ' || c == '\t')//ֻ�д����굱ǰ�ַ�����Ҫ�������ַ� 
		c = getch();
	s[1] = '\0';		//???
	i = 0;				//����д��s 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	//��������С���㡢���� 
	if (c == '-')	//���getch�ᳬǰ������ȷ��'-'������
		if (isdigit(c = getch()) || c == '.')	//��·����
			s[++i] = c;		//���������Ǹ��� 
		else {				//'-'�󲻽�������
			if (c != EOF)
				lastc = c;
			return '-';		//����
		}
	if (isdigit(c))			//�ռ��������� 
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//�ռ�С������ 
	   while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';	
	if (c != EOF)
		lastc = c;
	return NUMBER;	//������
}
	
int getch(void)	//ȡһ���ַ���������ѹ�ص��ַ���
{
	return (bufp > 0) ? buf[--bufp] : getchar();//�������л��оʹ���ȡ��������getchar()ȡ 
}

/*
void ungetch(int c)	//���ַ�ѹ��������
{
	if (bufp >= BUFSIZE)//�������� 
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
*/

void ungets(char s[])//�������ַ���ѹ�������� 
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		ungetch(s[i]);
}

int printop(void)
{
	if (sp > 0)
		printf("the stack top is %lld",val[sp]);
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

//clear: clear the stack
void clear(void)
{
	sp = 0;
}
