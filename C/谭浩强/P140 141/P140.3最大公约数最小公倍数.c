#include<stdio.h>

int main()
{
	int x,y,m,i,a=1;
	printf("��������������");
	scanf("%d %d",&x,&y);
	
	if(x<=0||y<=0) printf("���벻��Ϊ��������\n"); 
	else
	{	m = x;
		if(x<y)
		{
			x = y;
			y = m;
		}
		
		for(i=2;i<=y;i++)
		{
			if(x%i==0&&y%i==0) 
			a = i;
		 } 
		 
		m = (x*y)/a;
		printf("���Լ���� %d ,��С�������� %d",a,m);
	}
	return 0;
}
//��ǿ����
//#include <stdio.h>

/*int fun(int a,int b)	// 2�����Ĺ�Լ�� 
{
	int t;

	while(b)
	{
		t = a%b;
		a = b;
		b = t;         //�������� 
	}

	return a;
}

int main()
{
	int a[100];
	int n;
	int i;
	int res;

	scanf("%d",&n);	        	// ��������������n 
	if(n < 2)
	{
		printf("n����С��2\n");
		return 0;
	}
	for(i=0;i<n;i++)       	// ����n����  
		scanf("%d",&a[i]);
	res = fun(a[0],a[1]);  
	for(i=2;i<n;i++)
		res = fun(res,a[i]);       //�ݹ� 
	printf("%d\n",res);

	return 0;
}  */ 
