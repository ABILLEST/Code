#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[50];	//����a����ַ���
	int b[50];	//���ָ���ַ�λ��
	int flag=0, i, j=0,k, ch;		//�����־������ѭ������

	printf("\n�����ı���");
	gets(a);
	printf("����Ҫ���ҵ��ַ��� ");
	ch = getchar();
	//puts(a);				//������ 
	
	for(i = 0; a[i] != '\0'; i++){
		if (a[i] == ch){			//�ҵ�ָ���ַ�
			b[j] = i;				//���±�����ָ������ 
			flag = 1;				//��־������1��ʾ�ҵ�ָ���ַ� 
			j++;
		}
	}
	
	k = j;							//����b����Чλ 
	if (flag == 0)	printf("û���ҵ����ַ�\n");
	else{
		printf("ָ���ַ�%2c������%3d��\nλ���ǣ� ",ch,j);
		for(j = 0; j < k; j++)
				printf("%d\t",b[j]+1);
	}
	system("pause");
	return 0;
}
