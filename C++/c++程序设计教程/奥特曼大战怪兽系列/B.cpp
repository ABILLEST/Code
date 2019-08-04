#include <iostream>
using namespace std;

class Ultraman;
class Monster;
//���￪ʼд��Ľ������
//��������Ľ���
class Ultraman
{
private:
	int rank,exp,HP,HP_limit,damage,money;
public:
	Ultraman(){}
	Ultraman(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	void display();
	void escape();
	void attack(){}
	void attacked(int);
	void restore();
	bool win(Monster&);
	void upgrade();
};

//������Ľ���
class Monster
{
private:
	int rank,exp,HP,HP_limit,damage,money;
public:
	Monster(){}
	Monster(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	void attacked(int);
	void fightback();
	void display();
};

//���￪ʼд���ʵ�ִ���
//���������ʵ��
Ultraman::Ultraman(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*3;
	money = r*10;
	exp=0;
}

int Ultraman::getDamage()
{
	return damage;
}

int Ultraman::getExp()
{
	return exp;
}

int Ultraman::getHp()
{
	return HP;
}

int Ultraman::getMoney()
{
	return money;
}

int Ultraman::getRank()
{
	return rank;
}

void Ultraman::escape()
{
	//hp<=10
	money = 0;
	//lose
}

void Ultraman::attacked(int damage_mst)
{
	HP -= damage_mst/2;
}

void Ultraman::restore()
{
	if(10<HP && HP<0.5*HP_limit)
	{
		while(money>=10)
		{
			if(HP==HP_limit)
				break;
			HP++;
			money-=10;
		}
	}
}

bool Ultraman::win(Monster& m)
{
	if(m.getHp()<=0)
	{
		money += m.getMoney();
		exp += m.getExp();
		return true;
	}
	return false;
}

void Ultraman::upgrade()
{
	if(exp>=rank*10)
	{
		exp -= rank*10;
		rank++;
		HP_limit = rank*10;
		HP = HP_limit;
		damage = rank*3;
	}
}

void Ultraman::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
}

//�������ʵ��
Monster::Monster(int r)
{
	rank = r;
	HP_limit = r*20;
	HP = HP_limit;
	damage = r*2;
	money = r*10;
	exp=r*10;
}

int Monster::getDamage()
{
	return damage;
}

int Monster::getExp()
{
	return exp;
}

int Monster::getHp()
{
	return HP;
}

int Monster::getMoney()
{
	return money;
}

int Monster::getRank()
{
	return rank;
}

void Monster::attacked(int damage_utm)
{
	HP -= damage_utm;
}

void Monster::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
}


//�����ǲ���������
int main()
{
	int t;	
	cin>>t;
	
	while(t--)  //ÿ��ʵ�����ǰ���������޵�1��1ս��
	{
		int rank,damage;
		//����������͹��޵ĵȼ��������ó�ʼ���������ж����ʼ��
		cin>>rank;
		Ultraman Outman(rank);
		cin>>rank;
		Monster monster(rank);
		//����������͹���״̬������display������ÿ�����һ��
		Outman.display();
		monster.display();
		//����ս����־flagΪtrue������ս��ѭ�����������£�
		bool flag = true;
		while(flag) //��ս��δ�����ͼ���
		{     
			//����������1�Σ������ǹ��ޱ�����1��
			monster.attacked(Outman.getDamage());
	    	if (monster.getHp()>0)  //�ù����������жϣ���get������
	    	{     
				//���޷���1�Σ������ǰ�����������1��
				Outman.attacked(monster.getDamage());
            	if (Outman.getHp()>10)           //�ð������������жϣ���get������
                     Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
	    		else
				{     
					//���������ܣ������"lose"���س�
					Outman.escape();
					cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
					//����flagΪfalse��ֹͣս��
					flag = false;
				}
	       }
	       else//��������
	       {     
				//������ʤ���������"win"���س�
				Outman.win(monster);
				cout<<"win"<<endl;
				Outman.upgrade();
	            //���������״̬������display����
				Outman.display();
	            //����flagΪfalse��ֹͣս��
				flag = false;
	       }
		}
	}
	return 0;
}
