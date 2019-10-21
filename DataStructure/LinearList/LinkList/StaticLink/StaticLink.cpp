#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 100
#define ElemType int
#define Status int

class StaticList;

typedef class SL_Node
{
	friend class StaticList;
private:
	ElemType data;
	string name;
	int cur;
}SL_Node;

class StaticList
{
private:
	SL_Node space[MAXSIZE];
	int used_head, free_head;	//���������ͷ 
	int len;
public:
	StaticList();
	StaticList(int n);
	~StaticList();
	int LocateElem_SL(ElemType e);
	void InitSpace_SL();
	int Malloc_SL();
	void Free_SL(int k);
	void difference(int &s);
	Status Insert_SL(const ElemType &e, int index=1);
	bool Delete_SL(ElemType &e, int index=1);
	Status Append_SL();
	void display_SL() const;
	int length();
	
	bool Assign(string name);
};

StaticList::StaticList()
{
	space[0].cur = -1;
	free_head = 1;
	for(int i=1; i<MAXSIZE-1; ++i)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = -1;
}

StaticList::StaticList(int n)
{
	if(n<MAXSIZE)
	{
		len = n;
		space[0].cur = 1;
		for(int i=1; i<=len; ++i)
		{
			cin>>space[i].data;
			space[i].cur = i+1;	
		}
		space[len].cur = 0;
	}
	else return;
}

StaticList::~StaticList()
{
	
}

//�ھ�̬�������в��ҵ�һ��ֵΪe��Ԫ�أ��ҵ��򷵻�λ�ã����򷵻�0 
int StaticList::LocateElem_SL(ElemType e)
{
	int i = space[0].cur;	//iָʾ���е�һ���ڵ� 
	while(i && space[i].data!=e) i=space[i].cur;
	return i;
}

void StaticList::InitSpace_SL()
{
	for(int i=0; i<MAXSIZE-1; ++i) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
}

//������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
int StaticList::Malloc_SL()
{
	int i=space[0].cur;
	if(space[0].cur) space[0].cur = space[i].cur;
	return i; 
}

//���±�Ϊk�Ŀ��нڵ���յ��������� 
void StaticList::Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//(A-B)��(B-A) ,��ǰ��Ϊ��A��������B
void StaticList::difference(int &S)
{
	int nA,nB,i,k;
	
	InitSpace_SL();		//��ʼ�����ÿռ� 
	S = Malloc_SL();	//����S��ͷ��� 
	int r = S;			//rָ��S�ĵ�ǰ���ڵ� 
	
	cin>>nA>>nB;		//����A��B��Ԫ�ظ��� 
	for(int j=1; j<=nA; ++j)	//��������A������ 
	{
		i = Malloc_SL();		//����ڵ� 
		cin>>space[i].data;	 
		space[r].cur = i;		//���뵽��β 
		++len;
		r = i;
	}
	space[r].cur = 0;	//β�ڵ��ָ��Ϊ��
	
	for(int j=1; j<nB; ++j)//����B��Ԫ�أ������ڵ�ǰ��������룬����ɾ�� 
	{
		int b;
		cin>>b;
		
		int p = S;
		k = space[S].cur;	//kָ�򼯺�A�е��׽ڵ� 
		while(k!=space[r].cur && space[k].data!=b)	//�ڵ�ǰ���в����Ƿ���ڸ�Ԫ��
		{
			p = k;
			k = space[k].cur;
		}
		if(k==space[r].cur)		//����A�в����ڸ�Ԫ��,������r�ڵ�֮�� 
		{
			i = Malloc_SL();
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
			++len;
		}
		else	//�Ѵ��ڣ�ɾ�� 
		{
			space[p].cur = space[k].cur;
			Free_SL(k);
			if(r == k) r = p;	//��ɾ������r�ڵ㣬�����޸�βָ�� 
		}
	}
}

Status StaticList::Insert_SL(const int &e, int index)
{
	return ok;
}

Status StaticList::Append_SL()
{
	return ok;
}

void StaticList::display_SL() const
{
	for(int i=used_head; space[i].cur!=0; i=space[i].cur)
	{
		cout<<space[i].data<<" ";
	}
	cout<<endl;	
}


int main()
{
	int n,s;
	
	
	//cin>>n;
	StaticList LA;
	//cin>>n;
	//StaticList LB(n);
	
	//cout<<"LA: "; LA.display_SL();
	//cout<<"LB: "; LB.display_SL();
	
	LA.difference(s);
	LA.display_SL();
	return 0;
}


/*
int main()
{
	int n, num, m;
	string opr, name;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>name>>num;
	}
	
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>opr;
		if("assign"==opr)
		{
			
		}
		else if("return"==opr)
		{
			
		}
		else if("display_free"==opr)
		{
			
		}
		else if("display_used"==opr)
		{
			
		}
		else cout<<"operation name error"<<endl;
	}
	
	
	return 0;
}*/
