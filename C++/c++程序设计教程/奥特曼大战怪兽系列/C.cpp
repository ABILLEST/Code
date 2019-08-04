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
	void attack(Monster&);
	void attacked(int);
	void restore();
	bool win(Monster&);
	void upgrade();
};

//������Ľ���
class Monster
{
protected:
	int rank,exp,HP,HP_limit,damage,money;
public:
	Monster(){}
	Monster(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	void attack(Ultraman&);
	virtual void attacked(int);
	virtual void fightback(Ultraman&);
	void display();
};

class Monster_Boss : public Monster
{
private:
	int count;
public:
	Monster_Boss();
	void XP(Ultraman&);
	virtual void attack(Ultraman&);
	virtual void attacked(int);
	virtual void fightback(Ultraman&);
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

void Ultraman::attack(Monster& m)
{
	m.attacked(damage);
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
	while(exp>=rank*10)
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
	cout<<"������״̬(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
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

void Monster::attack(Ultraman& utm)
{
	utm.attacked(damage);
}

void Monster::attacked(int damage_utm)
{
	HP -= damage_utm;
}

void Monster::fightback(Ultraman& utm)
{
	utm.attacked(damage);
}

void Monster::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
}

//BOSS���ʵ��
Monster_Boss::Monster_Boss()
{
	rank = 10;
	HP_limit = 300;
	HP = HP_limit;
	damage = 50;
	money = 1001;
	exp=1000;
	count = 0;
}

void Monster_Boss::attack(Ultraman& utm)
{
	utm.attacked(Monster_Boss::damage);
}

void Monster_Boss::XP(Ultraman& utm)
{
	attack(utm);
	attack(utm);
	attack(utm);
}

void Monster_Boss::attacked(int damage_utm)
{
	HP -= damage_utm;
	count++;
}

void Monster_Boss::fightback(Ultraman& utm)
{
	if(count>=5)
		XP(utm);
	else attack(utm);
}

//�����ǲ���������
int main()
{
	int t,n;
	cin>>t;
	
	while(t--)  //ÿ��ʵ�����ǰ���������޵�1��1ս��
	{
		bool dead = false;
		bool ran = false;
		bool flag = true;
		int rank,damage;
		//����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��
		cin>>rank;
		Ultraman Outman(rank);
		Outman.display();
		
		//������޸����͵ȼ�
		cin>>n>>rank;
		while(!dead&&!ran&&n>0)	//ֻҪ������û��Ҳû���ܣ��ͼ�����n�����޵�ս��
		{
			Monster monster(rank);
			//����ս����־flagΪtrue������ս��ѭ�����������£�
			flag = true;
			while(flag) //��ս��δ�����ͼ���
			{
				//����������1�Σ������ǹ��ޱ�����1��
				Outman.attack(monster);
		    	if (monster.getHp()>0)  //�ù����������жϣ���get������
		    	{
					//���޷���1�Σ������ǰ�����������1��
					monster.fightback(Outman);
	            	if(Outman.getHp()>10)        //�ð������������жϣ���get������
	            	{
	            		Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
	            	}
	                else if(Outman.getHp()<=0){
	                	cout<<"lose"<<endl;
						//���������״̬������display����
						Outman.display();
	                	dead = true;
	                }
		    		else
					{
						//���������ܣ������"lose"���س�
						Outman.escape();
						cout<<"lose"<<endl;
						//���������״̬������display����
						Outman.display();
						//����flagΪfalse��ֹͣս��
						flag = false;
						ran = true;
					}
		       }
		       else//��������
		       {     
					//������ʤ���������"win"���س�
					Outman.win(monster);
					cout<<"win"<<endl;
					Outman.upgrade();
		            //����flagΪfalse��ֹͣս��
					//���������״̬������display����
					//Outman.display();
					flag = false;
		       }
			}
			n--;
		}
		
		
		if(!dead&&!ran)//�������n��С���ް�������û��Ҳû���ܣ�����սBoss
		{
			Outman.display();
			Monster_Boss boss;
			
			//����ս����־flagΪtrue������ս��ѭ�����������£�
			flag = true;
			while(!dead&&!ran&&flag)
			{
				Outman.attack(boss);
				if(boss.getHp()>0)
				{
					boss.fightback(Outman);
					if(Outman.getHp()>10)           //�ð������������жϣ���get������
					{
						Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
					}
	                else if(Outman.getHp()<=0){
	                	cout<<"lose"<<endl;
						//���������״̬������display����
						Outman.display();
	                	dead = true;
	                }
		    		else
					{
						//���������ܣ������"lose"���س�
						Outman.escape();
						cout<<"lose"<<endl;
						//���������״̬������display����
						Outman.display();
						//����flagΪfalse��ֹͣս��
						flag = false;
						ran = true;
					}
				}
				else//��������
		       {     
					//������ʤ���������"win"���س�
					Outman.win(boss);
					cout<<"win Boss"<<endl;
					Outman.upgrade();
		            //���������״̬������display����
					Outman.display();
		            //����flagΪfalse��ֹͣս��
					flag = false;
		       }
			}
		}
	}
	
	return 0;
}
