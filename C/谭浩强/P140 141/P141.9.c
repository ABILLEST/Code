#include<stdio.h>

int main()
{
	int i,yinzi,s;//���� ѭ�����Ʊ��������ӣ����Ӻ� 
	for(i=2; i<1000; i++)//����2~1000 
	{ 
		s = 0;//����ֵ��*��Ҫ*�� 
		yinzi = 1;
		do//ѭ���������� 
		{
			if(i%yinzi==0) s += yinzi;//�����ۼ� 
			yinzi++; 
		}while(yinzi<i);//�˴��ķֺŲ���© 
		
		if(i==s) //�ж��Ƿ������� 
		{printf("%d its factors are ",i);
		 for(yinzi=1; yinzi<i; yinzi++)//ѭ��������� 
		 {
      		if(i%yinzi==0) printf("%d ", yinzi);
   		}
   		printf("\n");
		}
	}
		 return 0;
} 

