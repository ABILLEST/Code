#include<stdio.h>

//print & turn blanks into 1 blank

//My program
/*main()
{
	int c,b,i;
	b = 0;      //number of blanks
	
	while((c = getchar()) != EOF)
	{
		while((c = getchar()) == ' ')
		{
			if((c = getchar()) != ' ')
				break;
			else b++;
		}
		if(b>1)
		{
			for(i=1; i<=b-1; i++)
				printf("\b");
		}
		putchar(c);
	}
		
	return 0;
}*/

//correct answer
#define NONBLANK 'a'
main()
{
	int c,lastc;          //�������������䶯��־�ķ��� 
	
	lastc = NONBLANK;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' || lastc != ' ')    //�����������ַ���ѭ���жϿ����ж��Ƿ����������ַ����÷����� 
			putchar(c);
		lastc = c;
	}
}
