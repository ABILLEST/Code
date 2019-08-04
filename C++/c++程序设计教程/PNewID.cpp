#include <iostream>
using namespace std;

int CertCalGroup[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char CertGroup[12]={"10X98765432"};

class CDate
{
protected:
	int year, month, day;
public:
	CDate(int,int,int);
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}	
	bool check(); //���������Ƿ�Ϸ�
	bool isLeap();
	virtual void print();
};

class COldID
{
protected:
	char *p_id15, *p_name; //15λ���֤���룬����
	CDate birthday; //��������
public:
	COldID(char *p_idval, char *p_nameval, CDate &day);
	virtual bool check(); //��֤15λ���֤�Ƿ�Ϸ�
	//virtual void print();
	~COldID();
};

class CNewID : public COldID
{
private:
	char *p_id18;
	CDate issueday;
	int validyear;
public:
	CNewID(char *p_id15val,char *p_id18val, char *p_nameval, CDate &Bday,CDate &Iday,int _validyear);
	virtual bool check(); //��֤18λ���֤�Ƿ�Ϸ�
	void print();
};

CDate::CDate(int y,int m,int d)
{
	year=y; month=m; day=d;
}

bool CDate::check()
{
	
	if(year>0&&year<65532)		//��Ϊ������
	{
		if(month==1||month==3||month==5
		||month==7||month==8||month==10||month==12)	//����31��
		{
			if(day>=1&&day<=31)
				return true;
			else 
				return false;
		}
		else if(month==4||month==6||month==9||month==11)//С��30�� 
		{
			if(day>=1&&day<=30)
				return true;
			else 
				return false;
		}
		else if(month==2) 
		{
			if(!isLeap())
			{
				if(day>=1&&day<=28)			//ƽ��28��
					return true;
				else 
					return false;
			}
			else{
				if(day>=1&&day<=29)			//����29��
					return true;
				else 
					return false;
			}
		}
		else return false;
	}
	else return false;
}

bool CDate::isLeap()
{
	return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

void CDate::print()
{
	cout<<year<<"��"<<month<<"��"<<day<<"�� "; 
}

COldID::COldID(char *p_idval, char *p_nameval, CDate &day):birthday(day.getYear(),day.getMonth(),day.getDay())
{
	p_id15=p_idval; p_name=p_nameval;
}

bool COldID::check()
{
	if(birthday.check())
	{
		int i=0;
		for(;p_id15[i];i++)
		{
			if(p_id15[i]-'0'<0||p_id15[i]-'0'>9)
				return false;
		}
		if(i-1!=15)
			return false;
	}
	else return false;
}

COldID::~COldID()
{
	delete p_id15,p_name;
}

CNewID::CNewID(char *p_id15val,char *p_id18val, char *p_nameval, CDate &Bday,CDate &Iday,int _validyear)
			:COldID(p_id15val,p_nameval,Bday),issueday(Iday.getYear(),Iday.getMonth(),Iday.getDay())
{
	p_id18 = p_id18val;
	validyear = _validyear;
}

bool CNewID::check()
{
	int i,ysum=0,msum=0,dsum=0;
	
	if(!birthday.check())				//�������ںϷ��Լ�� 
		return false;
	for(i=0;p_id18[i];i++);			
	if(i!=18)						//���ȼ�� 
		return false;
	for(--i;i>0;--i)				//�ַ��Ϸ��Լ�� 
	{
		if(p_id18[i]-'0'<0||p_id18[i]-'0'>9)
			return false;
	}
	for(i=6;i<=9;i++)			//�������ں����֤�������������� 
	{
		ysum=ysum*10+(p_id18[i]-'0');
	}
	for(i=10;i<=11;i++)			 
	{
		msum=msum*10+(p_id18[i]-'0');
	}
	for(i=12;i<=13;i++)			
	{
		dsum=dsum*10+(p_id18[i]-'0');
	}
	if(ysum!=birthday.getYear()||msum!=birthday.getMonth()||dsum!=birthday.getDay())
		return false;
	if(!issueday.check())
		return false;				//ǩ��������Ч��
	if(2015-issueday.getYear()>validyear)	//��Ч�ڼ�� 
		return false;
	else if(2015-issueday.getYear()==20){
		if(issueday.getMonth()>4)
			return false;
		else if(issueday.getMonth()==4){
			if(issueday.getDay()>7)
				return false;
		}
	}	
	
	int extrchek=(p_id18[6]-'0')*10+(p_id18[7]-'0');
	if(extrchek!=birthday.getYear()/100)	//��չ���
		return false;
	for(int i=0;i<6;i++)
		if(p_id15[i]!=p_id18[i])
			return false;
	for(int i=6;i<15;i++)
		if(p_id15[i]!=p_id18[i+2])
			return false;
	
	int sum=0;
	char cert;
	for(int i=0;i<17;i++)						//У��λ���� 
		sum+=(p_id18[i]-'0')*CertCalGroup[i];
	cert=CertGroup[sum%11];
	if(cert!=p_id18[17]) 						//У��λ��� 
		return false;
	return true;
}

void CNewID::print()
{
	cout<<p_name<<endl
		<<p_id18<<" ";
	issueday.print();
	if(validyear>=100)
		cout<<"����"<<endl;
	else 
		cout<<validyear<<"��"<<endl;
}


int main()
{ 
	
	int y1,m1,d1,y2,m2,d2,t,validy;
	
	cin>>t; 
	
	for(int i=0;i<t;i++)
	{
		char *id15 = new char[16];
		char *id18 = new char[19];
		char *name = new char[50];
		cin>>name>>y1>>m1>>d1>>id15>>id18>>y2>>m2>>d2>>validy;
		
		CDate bd(y1,m1,d1); 
		CDate idate(y2,m2,d2);
		CNewID n(id15,id18,name,bd,idate,validy);
		if(!n.check())
		{
			cout<<name<<endl
				<<"illegal id"<<endl;
		}
		else n.print();
	}
	
}
