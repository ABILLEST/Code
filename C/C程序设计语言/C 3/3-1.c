#include<stdio.h>

//���:��û�ж������ܸĽ�������ʧ���˴���ɶ��� 
//binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n)
{
	int low,high,mid;
	
	low = 0;
	high = n-1;
	mid = (low+high) / 2;
	while (low <= high && x != v[mid]){
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low+high) / 2;
	}
	if (x == v[mid])
		return mid;			//found match
	else
		return -1;			//no match
}

/*
//Original version
int binsearch(int x, int v[], int n)
{
	int low,high,mid;
	
	low = 0;
	high = n-1;
	while (low <= high){
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	//�ҵ���ƥ��ֵ 
			return mid;
	}
	return -1;	//û��ƥ���ֵ��� 
}
