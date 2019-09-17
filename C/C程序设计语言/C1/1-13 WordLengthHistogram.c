/*#include<stdio.h>

#define IN 1    //�ڵ����� 
#define OUT 0   //�ڵ����� 
//��ӡ�����е��ʳ��ȵ�ֱ��ͼ
/*main() 
{
	int c, state,i=0;
	
	state = OUT;
	int a[20];
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n')
			if(state == IN){
				printf("\n");
				state = OUT;
		}else if(state == OUT){
			state == IN;
			a[i] = c;
		}else a[i] = c;
		i++;
	}
	return 0;
}//������*



#define MAXHIST 15
#define MAXWORD 11
main()
{
	int c, i, nc, state; 
	int len; 				//length of each bar
	int maxvalue;			//maximum value for wl[]
	int ovflow;				//number of overflow words
	int wl[MAXWORD];		//word length counters
	
	state = OUT;
	nc = 0;					//number of chars in a word
	ovflow = 0;				//number of words >= MAXWORD
	for(i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			state = OUT;	//����������� 
			if(nc > 0)		//�жϵ����Ƿ�������Դ�����Ч���� 
				if(nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;				//���õ��ʳ��� 
		}else if (state ==OUT){	//���¿�ʼ���ʳ��ȼ��� 
			state = IN;
			nc = 1;			//beginning of a new word
		}else				
			++nc;			//inside a word
	}
	maxvalue = 0;			//��ʼ������ʵĳ��� 
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
			
	for (i = 1; i <MAXWORD; i++){
		printf("%5d - %5d : ",i,wl[i]);//����Ϊi�ĵ��ʸ�����wl[i] �� 
		if (wl[i] > 0){
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)//���������ȷ��ֱ��ͼ���� 
				len = 1;
		}else
			len = 0;
		while(len > 0){
			putchar (']');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0)
		printf("There are %d words >= %d\n",ovflow,MAXWORD);
	
	return 0;
}*/



//learn by heart
#include<stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

main()
{
	int c, i, nc, state;
	int len;
	int wl[MAXWORD];
	int maxvalue;
	int ovflow;
	
	state = OUT;
	nc = 0;
	ovflow  =0;
	for (i = 0; i < MAXWORD; i++)
		wl[i] = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t'){
			state == OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					wl[nc]++;
				else
					ovflow++;
			nc = 0;
		}else if(state == OUT){
			state = IN;
			nc = 1;
		}else
			++nc;
	}
	maxvalue = 0;

	for(i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
			
	for(i = 1; i < MAXWORD; i++){
		printf("%5d - %5d : ",i,wl[i]);
		if(wl[i] > 0){
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}else
			len = 0;
		while(len > 0){
			putchar('@');
			len--;
		}
		printf("\n");
	}
	if (ovflow > 0)
		printf("There are %d word(s) >= %d",ovflow,MAXWORD);
		
	return 0;
}



