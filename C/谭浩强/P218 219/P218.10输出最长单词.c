#include<stdio.h>
#include<string.h>
#define MAXLEN 50
/*
//�������ַ�������ĵ������
int main() 
{
	void lestwd(char c[],int n);
	
	char a[MAXLEN];
	gets(a);
	lestwd(a,MAXLEN);
	return 0;
} 

//�������ʺ���
void lestwd(char c[],int n)
{
	int i,j=0,max=0,len = 0,flag = 0;;
	char wordc[n],longestc[n];
	
	for (i = 0; c[i] != '\0'; ++i,++j){
		if (i > n){
			printf("�е��ʳ�����󳤶�!\n"); 
			flag = -1;
			break;
		}
		else if(c[i] == ' ' || c[i] == '\n' || c[i] == '\t'){
			wordc[j] = '\0';
			if(len=strlen(wordc) > max){
				printf("length is: %d\n",len);
				max = len;
				strcpy(longestc,wordc);
			}
			j = -1;
		}else
			wordc[j] = c[i];
	}
	
	if (flag != -1){
		printf("longest word: %s",longestc);
	}
}*/

int main()
{
	void lestwd(char ch[]);
	
	char ch[MAXLEN];
	printf("\n����һ���ַ���");
	gets(ch);
	lestwd(ch);
	return 0;
}

void lestwd(char ch[])
{
	int  i,j,len,max,p;
	len=max=0;
	
	for (i = 0; ch[i] != '\0'; i++){
		j = i++;
		for (len = 0; ch[i] != ' ' && ch[i] != '\0'; i++)	//���㵥�ʳ��� 
	    	len++;
	    
		if (len > max){
			max = len;
			p = j;
	    }
	}
	
	printf("\n");
	if(len == 0)
		printf("\nû�����뵥�ʣ�");
	else{
		printf("��ĵ��ʣ� ");
		for (i = p; i <= p+max; i++)
	    	printf("%c",ch[i]);
		printf("\n");
	}
}
/*Q:1.ΪʲôҪ��do-while�� 		A:whileҲ���� 
	2.ΪʲôiҪ�ڿ�ʼ��ʼ��		A����һ�� 
	3.j=i++��j��p�ֱ����ʲô��	A��1.�Ȱ�iֵ��j��i++��j��¼���ʿ�ʼ��λ�ã�p������󵥴ʿ�ʼλ�� 
	4.Ϊʲô�����Ц������ 
*/ 
	
	 
