#include<stdio.h>
#define MAXLEN 10

//��ָ����Ϊ�������������� 
int main()
{
	void sort(int *array);

	int a[MAXLEN] = {1,8,10,2,-5,0,7,15,4,-5};
	int *p;
	sort(a);
	
	for (p = a; p < (a+MAXLEN); p++)	//��ָ����� 
		printf("%d ",*p);
	return 0;
}

//ð�ݷ�����
void sort(int *array)
{
	int temp;
	int *p1,*p2;
	
	for (p1 = array; p1 < array+MAXLEN-1; p1++){ 			// 10������10 - 1��ð�ݣ�ÿһ�ֶ�����ǰ�������Ƶ����      
	  	for (p2 = array; p2 < array+MAXLEN-1 - p1; p2++) // 9 - i����˼��ÿ������һ��ð�ݺ󣬾ͼ���һ�αȽ�   
	        if (*p2 > *(p2+1)){   
	          temp = *p2;   
	          *p2 = *(p2+1);   
	          *(p2+1) = temp;   
	        }
    }  
}
 
