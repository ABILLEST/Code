#include<stdio.h>

//lower���������ַ�cת��ΪСд��ʽ 
int lower(int c)
{
	c=(c>='A' && c<='Z')?(c+'a'-'A'):c;//��if-else���ĳ��������ʽ 
	return c;							//return���Ҫ����д 
}

/*
//Answer
//lower: convert c to lower case(ASCII only)
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c+'a'-'A' : c;
}
*/

int main()
{
	char letter;
	printf("����һ����д��ĸ�� ");
	scanf("%c",&letter);
	printf("\n����Сд��ʽ�ǣ� %c",lower(letter));
	return 0; 
}
