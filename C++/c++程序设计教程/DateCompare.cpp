#include <iostream>
using namespace std;

class CDate
{
	int year,month,day;
public:
	CDate(){}
	CDate(int id);
	void Print();
	operator int(){return (year*10000+month*100+day);}
};

CDate::CDate(int id)
{
	year=id/10000;
	month=(id%10000)/100;
	day=id%100;
}

void CDate::Print()
{
	cout<<year<<"��";
	if(month<10)
		cout<<"0";
	cout<<month<<"��";
	if(day<10)
		cout<<"0";
	cout<<day<<"��"<<endl;
}

int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin>>t;
	while (t--)
	{	
		cin>>t1>>t2;
		C1 = t1;
		C2 = t2;
		((C1>C2)?C1:C2).Print(); //���ڴ��������ڴ���C1>C2�У����Զ���C1��C2ת��Ϊ�������бȽ�
	}
  	return 0;
}
