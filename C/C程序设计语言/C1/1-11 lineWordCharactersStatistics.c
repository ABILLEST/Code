#include<stdio.h>

#define IN 1    //�ڵ����� 
#define OUT 0   //�ڵ����� 

//ͳ����������������������ַ��� 
main()
{
	int c,nl,nw,nc,state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT)
			{
				state = IN;
				++nw;
			}
	}
	printf("%d %d %d\n",nl,nw,nc);
	return 0;
}
//����:�ó���' ','\n','\t'�ֿ����������ʼ������һ�� 
//���磺hello,world

//�𰸣����Ե��ʼ�������ı߽�������û�����롢û�е��ʡ�ÿ�����ʸ�ռһ�С����ʳ������ı������ס����ʳ�����һ���ո�� ����� 
