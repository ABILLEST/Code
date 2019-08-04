#include <iostream>
#include <string>
using namespace std;

class Television
{
	int volume,mode,channel;
	static int TVcount,DVDcount;
public:
	Television(){volume=50;mode=1;TVcount++;}
	void print();
	static int getTVcount(){return TVcount;}
	static int getDVDcount(){return DVDcount;}
	int getMode(){return mode;}
	int getChannel(){return channel;}
	int getVolume(){return volume;}
	void setMode(int m){mode=m;}
	void setChannel(int c){channel=c;}
	void changeVolume(int changeValue);
	friend void remote(Television* t,int mode,int changeVol,int changeChannel,int num);
};

int Television::TVcount = 0;
int Television::DVDcount = 0;

void Television::changeVolume(int changeValue)
{
	if(volume+changeValue>100)
		volume=100;
	else if(volume+changeValue<0)
		volume=0;
	else 
		volume+=changeValue;
}

void Television::print()
{
	if(mode==1)
		cout<<"TVģʽ--";
	else if(mode==2)
		cout<<"DVDģʽ--";
	cout<<"Ƶ��"<<channel<<"--����"<<volume<<endl;
}

void remote(Television* t,int mode,int changeVol,int changeChannel,int num)
{
	if(t->getMode()!=mode)
	{
		t->setMode(mode);
		if(mode==1)
		{
			//t->setChannel(changeChannel);
			t->DVDcount--;
			t->TVcount++;
		}
		else if(mode==2)
		{
			//t->setChannel(99);
			t->TVcount--;
			t->DVDcount++;
		}
	}
	t->setChannel(changeChannel);
	t->changeVolume(changeVol);
	
	cout<<"��"<<num<<"�ŵ��ӻ�--";
	t->print();
}

int main()
{
	int n,t;
	int num,k,x,vol;
	
	cin>>n>>t;
	Television* tvgroup = new Television[n];
	for(int i=0;i<t;i++)
	{
		cin>>num>>k>>x>>vol;
		remote(&tvgroup[num-1],k,vol,x,num);
	}
	cout<<"���ŵ��ӵĵ��ӻ�����Ϊ"<<tvgroup->getTVcount()<<endl;
	cout<<"����DVD�ĵ��ӻ�����Ϊ"<<tvgroup->getDVDcount()<<endl;
}
