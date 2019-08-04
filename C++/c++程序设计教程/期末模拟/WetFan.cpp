#include <iostream>
#include <string>
using namespace std;

class Electronic
{
protected:
	int id,power;
public:
	Electronic(){}
	Electronic(int,int);
	void print();	
};

class CFan : virtual public Electronic
{
protected:
	int direction, windPower;
public:
	CFan(){}
	CFan(int,int,int,int);
	void setDirection(int);
	void setWindPower(int);
};

class CWetter : virtual public Electronic
{
protected:
	float realVolume, maxVolume;
public:
	CWetter(){}
	CWetter(int,int,float,float);
	int warning();
};

class WetFan : public CFan, public CWetter
{
private:
	int postion;
public:
	WetFan(){}
	WetFan(int,int,int,int,float,float,int);
	void setPositon(int);
	void print();
};

Electronic::Electronic(int _id,int _power) : id(_id),power(_power)
{

}

CFan::CFan(int _id,int _power,int d,int wp) : Electronic(_id,_power)
{
	direction = d;
	windPower = wp;
}

void CFan::setDirection(int d)
{
	direction = d;
}

void CFan::setWindPower(int p)
{
	windPower = p;
}

CWetter::CWetter(int _id,int _power,float rv,float mv) : Electronic(_id,_power)
{
	realVolume = rv;
	maxVolume = mv;
}

int CWetter::warning()
{
	if(realVolume>=maxVolume/2)
		return 1;
	else if((realVolume<maxVolume/2 )&& (realVolume>=maxVolume*0.1))
		return 2;
	else if(realVolume<maxVolume*0.1)
		return 3;
} 

WetFan::WetFan(int _id,int _power,int d,int wp,float rv,float mv,int pos) : Electronic(_id,_power),CFan(_id,_power,d,wp),CWetter(_id,_power,rv,mv)
{
	postion = pos;
}

void WetFan::setPositon(int pos)
{
	postion = pos;
	switch(pos)
	{
		case 0:break;
		case 1:
			setDirection(0);
			setWindPower(1);
			break;
		case 2:
			setDirection(1);
			setWindPower(2);
			break;
		case 3:
			setDirection(1);
			setWindPower(3);
			break;
		default:break;
	}
		
}

void WetFan::print()
{
	cout<<"��ʪ����--��λ"<<postion<<endl
		<<"���"<<id<<"--����"<<power<<"W"<<endl;
	if(direction == 0)
		printf("���򴵷�--");
	else if(direction == 1)
		printf("��ת����--");
	cout<<"����"<<windPower<<"��"<<endl
		<<"ʵ��ˮ����"<<realVolume<<"��--";
	if(warning()==1)
		printf("ˮ������\n");
	else if(warning()==2)
		printf("ˮ��ƫ��\n");
	else if(warning()==3)
		printf("ˮ������\n");
}

int main()
{
	int t,id,power,direction,windP,rv,mv,pos;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>id>>power>>direction>>windP>>rv>>mv>>pos;
		WetFan wetfan1(id,power,direction,windP,rv,mv,pos);
		cin>>pos;
		wetfan1.setPositon(pos);
		wetfan1.print(); 
	}
	
	return 0;
}
