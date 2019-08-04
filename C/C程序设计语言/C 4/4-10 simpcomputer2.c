#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100	//操作数或运算符的最大长度
#define NUMBER '0'	//标识找到一个数
#define MAXVAL 100	//栈val的最大深度
#define BUFSIZE 100	//缓冲区大小 
#define MAXLINE 100 //最大读入长度 
 
int getop(char []);
void push(double);
double pop (void);
int getch(void);
void ungetch(int);
void ungets(char *);
void clear(void);
int getline(char s[], int lim);

int sp = 0;			//下一个空闲栈位置
double val[MAXVAL];	//值栈 
char buf[BUFSIZE];	//用于ungetch函数的缓冲区
int bufp = 0;		//buf中的下一个空闲位置 

//逆波兰运算器
int main()
{
	int type,near,i,var = 0.0;
	double op1,op2,v;
	char s[MAXOP];
	double variable[26];
	
	
	printf("注意：两个操作数之间用空格隔开\n");
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;
	while ((type = getop(getline(s,MAXLINE)) != EOF){	//判断下一个位置的类型 
		switch (type){
			case NUMBER:  
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
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
			case 's':		//使用sin()
				sin(pop());
				break;
			case 'e':
				exp(pop());
				break; 
			case '?':		//帮助信息 helping
				 printf("\n帮助信息：\np	打印栈顶元素并压入堆栈\nc	清空栈\nd	复制栈顶元素\nS	交换栈顶元素\n");
			case 'p':		//打印栈顶元素并压入堆栈 print top element of the stack
				op2 = pop();
				printf("\t%.8g\n",op2);
				push(op2);
				break;
			case 'c':		//清空栈 clear the stack
				clear();
				break;
			case 'd':		//复制栈顶元素 duplicate top elem. of the stack 
				 op2 = pop();
				 push(op2);
				 push(op2);
				 break;
			case 'S':		//交换栈顶元素 swap the top two elems.
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '=':
				pop();
				if (var >= 'A' && var <= 'Z'){
					variable[var - 'A'] = pop();
					printf("%c <- %lld",var,variable[var - 'A']);
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
 
//push函数：把f压入到值栈中
void push(double f)
{
 	if (sp < MAXVAL)
 		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
} 
  
//pop函数：弹出并返回栈顶的值
double pop(void)
{
	if (sp > 0)
		return val[--sp];	//倒序弹出的是栈顶值 
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
} 
   
//getop函数：获取下一个运算符或数值操作数
int getop(char s[])
{
	int i=0,c;
	
	while ((s[0] = s[i]) == ' ' || s[i] == '\t')//跳过空格和制表符 
		i++;
	s[1] = '\0';		//???
	i = 0;				//重新写入s 
	if (!isdigit(s[i]) && s[i] != '.' && s[i] != '-')
		return s[i];	//不是数、小数点、负号 
	if (s[i] == '-')	//最后getch会超前读入来确定'-'的意义
		if (isdigit(s[i]) || s[i] == '.')	//短路运算
			;		//负数的负号 
		else 				//'-'后不紧跟数字
			return '-';		//减号
		
	if (isdigit(s[i]))			//收集数字 
		while (isdigit(s[++i])
			;
	if (s[i] == '.')	//收集小数
	   while (isdigit(s[++i])
			;
	s[i] = '\0';	
	return NUMBER;	//是数字
}
	
int getch(void)	//取一个字符（可能是压回的字符）
{
	return (bufp > 0) ? buf[--bufp] : getchar();//缓冲区中还有就从中取，否则用getchar()取 
}

void ungetch(int c)	//把字符压回输入中
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])//把整个字符串压回输入中 
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

//getline函数：将一行读入到s中并返回其长度
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
