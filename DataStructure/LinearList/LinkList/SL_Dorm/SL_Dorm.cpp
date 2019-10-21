#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 20
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
	int len;
public:
	StaticList();
	StaticList(int n);
	~StaticList();
	int LocateElem_SL(ElemType e);
	void InitSpace_SL();
	int Index_SL(int i);
	int Malloc_SL();
	void Free_SL(int k);
	Status difference(int &s);
	Status Insert_SL(const ElemType &e, int index=1);
	Status Delete_SL(ElemType &e, int index=1);
	Status Append_SL();
	void display_SL() const;
	int length();
	
	Status Dorm_Init(StaticList &freeList, int n);
	Status Assign(string name,StaticList &free);
	Status Return(int roomNum,StaticList &free);
	void display_used();
};

//�������ÿռ�Ϊ�ձ�����ռ�Ϊ���ñ� 
StaticList::StaticList() : len(0)
{
	space[0].cur = -1;	//���ÿռ�Ϊ�� 
	for(int i=1; i<MAXSIZE-1; ++i)
	{
		space[i].cur = i+1;	
	}
	
	space[MAXSIZE-1].cur = -1 ;
}

StaticList::StaticList(int n)
{
	if(n<MAXSIZE)
	{
		len = n;
		space[0].cur = 1;
		for(int i=1; i<len; ++i)
		{
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
	while(i && space[i].data!=e)
		i=space[i].cur;
	return i;
}

void StaticList::InitSpace_SL()
{
	for(int i=0; i<MAXSIZE-1; ++i) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
}

//���������е�i��Ԫ�ص�λ�� 
int StaticList::Index_SL(int i)
{
	int p = space[0].cur;
	
	if(i<0) return error;
	if(i==0) return 0;
	
	for (int j = 1; j < i; j++)
	{
		if (space[p].cur == -1)
			return -1;                        //����Ԫ�ظ���С��i
		p = space[p].cur;
	}
	return p;
} 

//������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
int StaticList::Malloc_SL()
{
	int i=space[0].cur;
	//������һ�ε�һ�����õĿ��нڵ�Ϊ���ؽڵ����һ���ڵ�
	if(space[0].cur) space[0].cur = space[i].cur;
	return i; 
}

//���±�Ϊk�Ŀ��нڵ���յ��������� 
void StaticList::Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status StaticList::Insert_SL(const ElemType &e, int index)
{
	int p = Index_SL(index);
	int n = Malloc_SL();
	
	if(!n) return error;
	
	int temp = n;
	space[n].data = e;
	space[n].cur = space[p].cur;
	
	
}

Status StaticList::Delete_SL(ElemType &e, int index)
{	
	if(-1 == index) return error;
	space[index-1].cur = space[index].cur;
	Free_SL(index);
	
	return ok;
}

void StaticList::display_SL() const
{
	for(int i=1; i<=len; ++i)
	{
		cout<<space[i].data<<"-";
	}
	cout<<endl;	
}

//
Status StaticList::difference(int &s)
{
	
}
//
Status StaticList::Dorm_Init( StaticList &freeL, int n)
{
	string name;
	ElemType e;
	int roomNum, p,q, last;
	
	//��ʼ������� 
	freeL.len = 0;
	this->len = 0;
	space[0].cur = 1;
	freeL.space[0].cur = 1;
	for(int j=1; j<=MAXSIZE; ++j)
	{
		freeL.space[j].data = 100+j;
		freeL.space[j].cur = j+1;
	}
	freeL.space[MAXSIZE].cur = 0;
	
	this->InitSpace_SL();
	q = this->Malloc_SL();	//����ͷ��� 
	last = q;	//ָ��ĩ�� 
	
	//���䷿�� 
	for(int i=1; i<=n; ++i)
	{
		cin>>name>>roomNum;
		p = freeL.LocateElem_SL(roomNum);
		q = this->Malloc_SL();	 
		
		space[q].name = name;	//�������� 
		space[q].data = roomNum;
		
		space[last].cur = q;	//���뵽��β
		last=q; 
	}
	space[last].cur = 0;
	len = n;

	return ok;
} 

Status StaticList::Assign(string name, StaticList& free)
{
	//�����Ƿ��䲻�ɹ� 
	int insIndex = this->Malloc_SL();
	int freeIndex = free.Malloc_SL();
	int preIndex;
	
	if(!insIndex) return error;

	this->space[insIndex].data = free.space[freeIndex].data;//���ݸ��� 
	for(preIndex=1; preIndex<=insIndex-1; ++preIndex) ;
	space[insIndex].cur = preIndex;
	space[preIndex].cur = insIndex; 
	space[insIndex].name = name;
	++len;
	return ok;

}

Status StaticList::Return(int roomNum,StaticList &free)
{	
	//�����ǽ������ɹ� 
	
}

void StaticList::display_used()
{
	int count=0;
	for(int i=1; i<=MAXSIZE&&count<len; ++i)
	{
		if(space[i].name.empty()) continue;
		cout<<space[i].name<<"("<<space[i].data<<")";
		++count;
		if(count<len) cout<<"-";
		
	}
	cout<<endl;	
}



int main()
{
	int n, roomNum;
	string name;
	StaticList usedList,freeList;
	
	cin>>n;
	if(usedList.Dorm_Init(freeList,n)==error)
	{
		cerr<<"��ʼ���������!"<<endl;
	}
	else usedList.display_used();
	
//	
//	cin>>n;
//	for(int i=0;i<n;++i)
//	{
//		cin>>name>>roomNum;
//		usedList.Assign_n(name,roomNum,freeList);
//	}
//	usedList.display_used();
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		string opr;
		cin>>opr;
		if("assign"==opr)
		{
			cin>>name;
			usedList.Assign(name,freeList);
		}
		else if("return"==opr)
		{
			cin>>roomNum;
			usedList.Return(roomNum,freeList);
		}
		else if("display_free"==opr)
		{
			freeList.display_SL();
		}
		else if("display_used"==opr)
		{
			usedList.display_used();
		}
		else cout<<"operation name error"<<endl;
		
		cout<<"result: "; usedList.display_used();
	}
	
	return 0;	
}



