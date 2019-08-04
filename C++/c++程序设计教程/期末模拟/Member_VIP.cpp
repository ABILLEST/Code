#include <iostream>
#include <string>
using namespace std;

class Member //��ͨ��Ա��
{   
protected:
	int id, bonus;
	string name;
public:
	Member(){}
	Member(string,int,int);
	virtual void print();
	virtual void Add(int);
	virtual int Exchange(int);
};


class VIP : public Member //�����Ա��
{  
private:
	int addRate, exchangeRate;
public:
	VIP(){}
	VIP(string,int,int,int,int);
	void print();
	void Add(int);
	int Exchange(int);
};

//member class definition
Member::Member(string n,int _id,int _bonus)
{
	id = _id;
	name = n;
	bonus = _bonus;
}

void Member::print()
{
	cout<<"��ͨ��Ա"<<id<<"--"<<name<<"--"<<bonus<<endl;
}

void Member::Add(int amount)
{
	bonus += amount;
}

int Member::Exchange(int exchange_require_bonus)
{
	int money;
	int exchange_amount_money = exchange_require_bonus / 100;
	int exchange_amount_bonus = exchange_amount_money * 100;
	if(bonus>exchange_amount_bonus){
		bonus -= exchange_amount_bonus;
		money += exchange_amount_money;
	}
	else ;
	
	return money;
}

//VIP class definition
VIP::VIP(string n,int _id,int _bonus,int _addRate,int _exchangeRate):Member(n,_id,_bonus)
{
	addRate = _addRate;
	exchangeRate = _exchangeRate;
}

void VIP::print()
{
	cout<<"�����Ա"<<id<<"--"<<name<<"--"<<bonus<<endl;
}

void VIP::Add(int amount)
{
	bonus += amount * addRate;
}

int VIP::Exchange(int exchange_require_bonus)
{
	int money;
	int exchange_amount_money = exchange_require_bonus / exchangeRate;
	int exchange_amount_bonus = exchange_amount_money * exchangeRate;
	if(bonus>exchange_amount_bonus){
		bonus -= exchange_amount_bonus;
		money += exchange_amount_money;
	}
	else ;
	
	return money;
}

int main()
{

	Member * pm; //����һ���������ָ��
	string name;
	int id,bonus,amount,exchange_bonus,addRate,exchangeRate;
	
	//�������ݣ�������ͨ��Ա����mm
	cin>>id>>name>>bonus
		>>amount>>exchange_bonus;
	Member mm(name,id,bonus);
	//ʹ��ָ��pmִ�����²�����
	//1��pmָ����ͨ��Ա����mm
	pm = &mm;
	//2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	pm->Add(amount);
	pm->Exchange(exchange_bonus);
	//3��ͨ��pm���ô�ӡ�������
	pm->print();

	//�������ݣ����������Ա����vv
	cin>>id>>name>>bonus>>addRate>>exchangeRate
		>>amount>>exchange_bonus;
	VIP vv(name,id,bonus,addRate,exchangeRate);
	//ʹ��ָ��pmִ�����²�����
	//1��pmָ������Ա����vv
	pm = &vv;
	//2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	pm->Add(amount);
	pm->Exchange(exchange_bonus);
	//3��ͨ��pm���ô�ӡ�������
	pm->print();

	return 0;

}
