#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAXLEN 20

int trans_16to10(char s[], int l)
{
	int i;
	long long a = 0;
	for (i = 0; i<l; i++){
	if(s[i] >= 'A' && s[i] <= 'Z')
	    s[i] = s[i] - 'A' + 10;
	else
		s[i] = s[i] - '0';
	a += ((s[i]-'0') * (pow(16,l-1-i)));		//������д��� 
	}
	return a;
}

int main()
{
    char s_16[MAXLEN];
    int len;
    scanf("%s",s_16);
    len = strlen(s_16);//�õ��ַ������� 
    printf("%lld",trans_16to10(s_16,len));
    return 0;
}
