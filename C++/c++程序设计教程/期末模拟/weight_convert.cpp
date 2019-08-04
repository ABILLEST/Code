#include <iostream>
#include <string.h>
using namespace std;

class CN; //��ǰ����
class EN; //��ǰ����
class Weight
{ //������
protected:
	char kind[20]; //��������
	int gram; //��
public:
	Weight (char tk[]="no name", int tg=0)
	{ strcpy(kind, tk);	
	  gram = tg;
	}
	virtual void Print(ostream & out) = 0; //�����ͬ���͵ļ�����Ϣ
};

class CN: public Weight 
{ //�й�����
	int jin,liang,qian;
	friend class EN; 
public:
	CN(){}
	CN(int,int,int,int,char*);
	CN(CN&);
	void Convert(const int);
	void Print(ostream & out);
};

class EN: public Weight 
{ //Ӣ������
	int pound,oz,dram;
public:
	EN(){}
	EN(int,int,int,int,char*);
	void Convert(const int);
	operator CN ();
	void Print(ostream & out);
};

CN::CN(int j,int l,int q,int g,char* k) : Weight(k,g)
{
	jin = j;
	liang = l;
	qian = q;
}

CN::CN(CN& cn)
{
	jin = cn.jin;
	liang = cn.liang;
	qian = cn.qian;
	gram = cn.gram;
}

void CN::Convert(const int g)
{
	gram = g;
	int temp;
	
	temp = gram/500;
	jin += temp;
	gram -= temp*500;
	
	temp = gram/50;
	liang += temp;
	gram -= temp*50;
	
	temp = gram/5;
	qian += temp;
	gram -= temp*5;
}

void CN::Print(ostream& out)
{
	out<<kind<<":"<<jin<<"��"<<liang<<"��"<<qian<<"Ǯ"<<gram<<"��"<<endl;
}

EN::EN(int p,int _oz,int d,int g,char* k) : Weight(k,g)
{
	pound = p;
	oz = _oz;
	dram = d;
}

void EN::Convert(const int g)
{
	gram = g;
	int temp;
	
	temp = gram/512;
	pound += temp;
	gram -= temp*512;
	
	temp = gram/32;
	oz += temp;
	gram -= temp*32;
	
	temp = gram/2;
	dram += temp;
	gram -= temp*2;
}

EN::operator CN ()
{
	CN cn(0,0,0,0,"�й�����");
	gram += pound*512 + oz*32 + dram*2;
	int temp;
	
	temp = gram/500;
	cn.jin += temp;
	gram -= temp*500;
	
	temp = gram/50;
	cn.liang += temp;
	gram -= temp*50;
	
	temp = gram/5;
	cn.qian += temp;
	gram -= temp*5;
	cn.gram = gram;//important 
	
	return cn;
} 

void EN::Print(ostream& out)
{
	out<<kind<<":"<<pound<<"��"<<oz<<"��˾"<<dram<<"����"<<gram<<"��"<<endl;
}

//��ȫ�ֺ�����ʽ������������������3-5��....���б�д

//���غ�����������������ostream������Weight����󣬲��������Ƕ�����������

//���غ���������ò���Weight�����Print����
ostream& operator << (ostream& out, Weight& w)
{
	w.Print(out);
}


int main()//������

{	int tw;

//����һ���й����������cn

//���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind

	CN cn(0,0,0,0, "�й�����");

	cin>>tw;

	cn.Convert(tw); //������Ŀ���ת���й�����

	cout<<cn;

	

//����Ӣ�����������en

//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind

	EN en(0,0,0,0,"Ӣ������");

	cin>>tw;

	en.Convert(tw); //������Ŀ���ת��Ӣ������

	cout<<en;

	cn=en; //��Ӣ������ת���й�����

	cout<<cn;

return 0;

}
