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
	virtual void display();
	virtual void lose();
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

void Monster::lose()
{
	cout<<"Boss!Help!"<<endl;
}

void Monster::display()
{
	cout<<"����״̬(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
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

//�����ǲ���������
int main()
{
//����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��

    int ograd;   cin>>ograd;

    Ultraman uobj(ograd); 

    int t;   cin>>t;//����Ҫ��Ĺ��޸�����

    while(t--&&uobj.getHp()>10){//ֻҪ������û��Ҳû���ܣ��ͼ�������޵�ս��

         uobj.display();   

         Monster* p;  

         char c=0;

         while(1){

             cin>>c;

             if(c=='B') {p=new Monster_Boss();break;}

             else if(c=='M') {int r;cin>>r;p=new Monster(r);break;}   

             else cout<<"�����������������"<<endl;

         }

         p->display();         

         //����ս����־flagΪtrue������ս��ѭ�����������£�

         int flag=1;

         while(flag) //��ս��δ�����ͼ���

         {   uobj.attack(*p);//����������1��             

             if (p->getHp()>0)  //����û��

             {   p->fightback(uobj);//���޷���1��

                  if (uobj.getHp()>10)      //����������ֵ���ڵ㣬������

                      uobj.restore();//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ

                  else {   //���������ܣ������"lose"���س�

                      uobj.escape();

                      cout<<"lose"<<endl;                    

                      uobj.display();//���������״̬        

                      flag=0;//ֹͣս��                  

                  }

             }

             else //��������

             {   uobj.win(*p);     //������ʤ���������"win"���س�

                  cout<<"win"<<endl;

                  uobj.upgrade();//����������

				p->lose();//�������ս����Ϣ

                  flag=0;//ֹͣս�� 

             }

         }

    }

    return 0;

}
