#include<stdio.h>
#define h0 100

int main()
{
	float h;
	int s, times;
	printf("Enter times: ");
	scanf("%d",&times);
	printf("Enter height: ");
	scanf("%f",&h);
	
	s = hei(times) + h0;
	printf("��%d�η���%f�ף�������%f��\n",times,h,s);
	
	return 0;
}

int hei(int times)
{
	int c, h;
	float s;
	h /= 2.0;
	if(times==2)
		s = 50;
	else
		s += hei(times-1) * 2;
	return(s);
} 
