#include<stdio.h>
#define IN 1    //�ڵ����� 
#define OUT 0   //�ڵ����� 

//��ÿ��һ�����ʵ���ʽ��ӡ������ 
/*main() 
{
	int c,state;
	state = OUT;
		
	while((c = getchar()) != EOF)
	{	
		if(c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			printf("\n");
		}
			
		else if(state == OUT)
				state = IN;
		putchar(c);
	}
	return 0;
}*/

//Answer
main() 
{
	int c, state;
	
	state = OUT;
	while((c = getchar()) != EOF)
	{	
		if(c == ' ' || c == '\n' || c == '\t'){	
			if(state == IN){
				printf("\n");
				state = OUT;
			}
		}else if(state == OUT){
				state = IN;
				putchar(c);
		}else putchar(c);
	}
	return 0;
}
