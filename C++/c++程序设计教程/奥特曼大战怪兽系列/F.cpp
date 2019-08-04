#include <iostream>
using namespace std;

class Ultraman;
class Monster;
//���￪ʼд��Ľ������
//�ػ�����Ľ���
class Angel
{
private:
	int rank,damage,money,exp;
public:
	Angel();
	void setUtm(int);
	void setMst(int);
	int getExp();
	int getMoney();
	void attack(Ultraman&);
	void attack(Monster&);
	void upgrade(int);
}; 

//��������Ľ���
class Ultraman
{
private:
	int rank,exp,HP,HP_limit,damage,money;
public:
	Angel angel;
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
	void operator ++ ();
	void operator -- ();
	bool operator < (Monster&);
	bool operator == (Monster&);
	friend ostream& operator << (ostream& out, Ultraman& utm);
};

//������Ľ���
class Monster
{
protected:
	int rank,exp,HP,HP_limit,damage,money;
public:
	Angel angel;
	Monster(){}
	Monster(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	virtual void attack(Ultraman&);
	virtual void attacked(int);
	virtual void fightback(Ultraman&);
	virtual void display();
	virtual void lose();
};

//��ͨ�͹��� 
class NMonster : public Monster
{
public:
	NMonster(){}
	NMonster(int);
};

//�����͹��� 
class AMonster : public Monster
{
public:
	AMonster(){}
	AMonster(int);
	void attack(Ultraman&);
	void fightback(Ultraman&);
};

//�����͹��� 
class DMonster : public Monster
{
public:
	DMonster(){}
	DMonster(int);
	void attacked(int);
};

//�⼦�͹��� 
class SMonster : public Monster
{
public:
	SMonster(){}
	SMonster(int);
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
	void lose();
	virtual void display();
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
	angel.setUtm(rank);
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
	angel.attack(m);
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
	if(m.getHp()<=0)	//���������û�� 
	{
		if(m.getMoney() == m.getRank()*20)	//SMonster
		{
			money += m.getMoney();
			exp += m.getExp();
		}
		money += m.getMoney() + m.angel.getMoney();
		exp += m.getExp() + m.angel.getExp();
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
	angel.upgrade(rank);
}

void Ultraman::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
}

void Ultraman::operator ++()
{
	rank *= 2;
	HP_limit = rank*10;
	HP = HP_limit;
	damage = rank*3;
	exp *= 2;
	money *= 2;
}

void Ultraman::operator --()
{
	HP /= 2;
	damage /=2;
	exp /= 2;
	money /= 2;
}

bool Ultraman::operator <(Monster& m)
{
	if(m.getRank()<this->rank)
	{
		HP += m.getHp()*0.5;
		damage += m.getDamage()*0.5;
		money += m.getMoney()*0.5;
		exp += m.getExp()*0.5;
		return true;
	}
	else return false;
}

bool Ultraman::operator ==(Monster& m)
{
	if(m.getRank()==this->rank)
	{
		HP += m.getHp();
		damage += m.getDamage();
		money += m.getMoney();
		exp += m.getExp();
	}
	else return false;
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
	angel.setMst(rank);
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

void Monster::lose()
{
	cout<<"Boss!Help!"<<endl;
}

void Monster::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
}

NMonster::NMonster(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*2;
	money = r*10;
	exp=r*10;
}

//�����͹�����ʵ�� 
AMonster::AMonster(int r)
{
	rank = r;
	HP_limit = r*5;
	HP = HP_limit;
	damage = r*4;
	money = r*10;
	exp=r*10;
	angel.setMst(rank);
}

void AMonster::attack(Ultraman& utm)
{
	utm.attacked(damage);
	angel.attack(utm);
}

void AMonster::fightback(Ultraman& utm)
{
	this->attack(utm);
}

//�����͹�����ʵ�� 
DMonster::DMonster(int r)
{
	rank = r;
	HP_limit = r*20;
	HP = HP_limit;
	damage = r*1;
	money = r*10;
	exp=r*10;
	angel.setMst(rank);
}

void DMonster::attacked(int damage_utm)
{
	HP -= damage_utm/2;
}

SMonster::SMonster(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*1;
	money = r*20;
	exp=r*20;
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
}

void Monster_Boss::attack(Ultraman& utm)
{
	utm.attacked(Monster_Boss::damage);
}

void Monster_Boss::XP(Ultraman& utm)
{
	//cout<<"XP*****"<<endl;
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

void Monster_Boss::display()
{
	cout<<"Boss����״̬(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
}

void Monster_Boss::lose()
{
	cout<<"I'll be back!"<<endl;
}

//�ػ������ʵ��
Angel::Angel()
{
	rank = 0;
	money = 0;
	damage = 0;
	exp = 0;
}

void Angel::setUtm(int r)
{
	rank = r;
	damage = r/2;
}

void Angel::setMst(int r)
{
	rank = r;
	damage = r/2;
	money = rank*5;
	exp = rank*5;
}

void Angel::attack(Ultraman& utm)
{
	utm.attacked(damage);
}

void Angel::attack(Monster& m)
{
	if(m.getDamage() == m.getRank()*5)	//AMonster 
		m.attacked(damage+1);
	else if(m.getHp() == m.getRank()*20)	//DMonster
		m.attacked(damage+2);
	else m.attacked(damage);
}

void Angel::upgrade(int r)
{
	rank = r;
	damage = r*0.5;
}

int Angel::getExp()
{
	return exp;
}

int Angel::getMoney()
{
	return money;
}

ostream& operator << (ostream& out, Ultraman& utm)
{
	out<<"������״̬(rank="<<utm.rank<<" hp="<<utm.HP<<" damage="<<utm.damage<<" exp="<<utm.exp<<" money="<<utm.money<<")"<<endl;
}

//�����ǲ���������
int main()
{
	int t;
	bool flag,eflag;
	int winflag1=0,winflag2=0,winflag3=0,winflag4=0;
	cin>>t;
	
	while(t--)
	{
		int rank;
		int mgrad[4];
		
		cin>>rank;
		Ultraman Outman(rank);
		Outman.display();
		
		for(int i=0;i<4;i++)
			cin>>mgrad[i];
		NMonster nmst(mgrad[0]);
		SMonster smst(mgrad[1]);
		DMonster dmst(mgrad[2]);
		AMonster amst(mgrad[3]);
		nmst.display();
		smst.display();
		dmst.display();
		amst.display();
 		
 		flag = true;
 		eflag = false;
 		winflag1=0,winflag2=0,winflag3=0,winflag4=0;
 		while(flag)
 		{
 			Outman.attack(nmst);
			Outman.attack(smst);
 			Outman.attack(dmst);
 			Outman.attack(amst);
 			
 			if(nmst.getHp()>0)
	    	{
				nmst.fightback(Outman);
            	if(Outman.getHp()>10)        //�ð������������жϣ���get������
            	{
            		Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
            	}
                else if(Outman.getHp()<=0){
                	cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
                	flag = false;
                }
	    		else
				{
					//���������ܣ������"lose"���س�
					Outman.escape();
					eflag = true;
					cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
					//����flagΪfalse��ֹͣս��
					flag = false;
				}
	       }
	       else if(nmst.getHp()<0 && !winflag1)//���������һ������
	       {     
				Outman.win(nmst);
				printf("win\n");
				//cout<<"win"<<endl;
				Outman.upgrade();
				Outman.display();
				winflag1 = true;
	       }
	       
	       if(smst.getHp()>0)
	    	{
				smst.fightback(Outman);
            	if(Outman.getHp()>10)        //�ð������������жϣ���get������
            	{
            		Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
            	}
                else if(Outman.getHp()<=0){
                	cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
                	flag = false;
                }
	    		else
				{
					//���������ܣ������"lose"���س�
					Outman.escape();
					eflag = true;
					cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
					//����flagΪfalse��ֹͣս��
					flag = false;
				}
	       }
	       else if(smst.getHp()<0 && !winflag2)//���������һ������
	       {     
				Outman.win(smst);
				printf("win\n"); 
				//cout<<"win"<<endl;
				Outman.upgrade();
				Outman.display();
				winflag2 = true;
	       }
	       
	       if(dmst.getHp()>0)
	    	{
				dmst.fightback(Outman);
            	if(Outman.getHp()>10)        //�ð������������жϣ���get������
            	{
            		Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
            	}
                else if(Outman.getHp()<=0){
                	cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
                	flag = false;
                }
	    		else
				{
					//���������ܣ������"lose"���س�
					Outman.escape();
					eflag = true;
					cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
					//����flagΪfalse��ֹͣս��
					flag = false;
				}
	       }
	       else if(dmst.getHp()<0 && !winflag3)//���������һ������
	       {     
				Outman.win(dmst);
				printf("win\n");
				//cout<<"win"<<endl;
				Outman.upgrade();
				Outman.display();
				winflag3 = true;
	       }
	       
	       if (amst.getHp()>0)
	    	{
				amst.fightback(Outman);
            	if(Outman.getHp()>10)        //�ð������������жϣ���get������
            	{
            		Outman.restore();		//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
            	}
                else if(Outman.getHp()<=0){
                	cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
                	flag = false;
                }
	    		else
				{
					//���������ܣ������"lose"���س�
					Outman.escape();
					eflag = true;
					cout<<"lose"<<endl;
					//���������״̬������display����
					Outman.display();
					//����flagΪfalse��ֹͣս��
					flag = false;
				}
	       }
	       else if(amst.getHp()<0 && !winflag4)//���������һ������
	       {     
				Outman.win(amst);
				printf("win\n");
				//cout<<"win"<<endl;
				Outman.upgrade();
				Outman.display();
				winflag4 = true;
	       }
	       
	       if(winflag1&&winflag2&&winflag3&&winflag4)
	       {
	    		flag = false;
	    		cout<<"win all"<<endl;
		   }
		}//end of while flag
	}//end of while t--

	return 0;
}

