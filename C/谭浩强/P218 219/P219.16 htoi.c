#include <stdio.h>
#define HEXLEN 40
 
char saveH [HEXLEN]; //���ڴ��ת���õ�ʮ�������ַ������ɸ�����Ҫ���峤��
 
//10����ת16���ƺ��� 
char * ItoH(int aa)
{
    static int i = 0;
    if (aa < 16)            //�ݹ�������� 
    {
        if (aa < 10)        //��ǰ��ת�����ַ������ַ��� 
            saveH[i] = aa + '0';
        else
            saveH[i] = aa - 10 + 'A';
        saveH[i+1] = '\0'; //�ַ���������־ 
    }
    else
    {
        ItoH(aa / 16);  	//�ݹ���� 
        i++;                //�ַ�������+1 
        aa %= 16;           //���㵱ǰֵ
        if (aa < 10)        //��ǰ��ת�����ַ������ַ��� 
            saveH[i] = aa + '0';
        else
            saveH[i] = aa - 10 + 'A';
        saveH[i+1] = '\0'; //�ַ���������־ 
    }
    return (saveH);
}
 
int main ()
{
  int num;
  char * hex_str;			//����ָ�� 
  printf ("Enter a number: ");
  scanf ("%d",&num);
  hex_str = ItoH(num);		
  printf ("Hexadecimal number: %sH\n", hex_str);	//��ָ������ַ��� 
  return 0;
}

/*
//��׼���������
int main()
{
	int num;
	scanf("%d",&num);
	printf("%x",num);
	return 0;
} 
