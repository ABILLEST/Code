#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 100
#define ElemType int

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
	int free_node;	//���������ͷ 
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
	bool Insert_SL(const ElemType &e, int index=1);
	bool Delete_SL(ElemType &e, int index=1);
	bool Append_SL();
	void display_SL() const;
	int length();
	
	bool Assign(string name);
};

StaticList::StaticList()
{
	space[0].cur = -1;
	free_node = 1;
	for(int i=1; i<MAXSIZE-1; ++i)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = -1;
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

//
void StaticList::difference(int &s)
{
	
}


int main()
{
	int n;
	StaticList usedList,freeList;
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		usedList.Append_SL();
	}
	
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
