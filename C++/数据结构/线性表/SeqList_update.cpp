#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define LEFT_ROL 0
#define RIGHT_ROL 1

int equal(int a, int b)
{
	if(a==b){
		return 1;
	}
	else return 0;
}

class SeqList
{
	private:
		int *list;
		int maxsize;
		int size;
	public:
		SeqList();
		SeqList(int *l, int ms, int s);
		~SeqList();
		int list_size();
		int list_insert(int i, int item);
		int list_del(int i);
		int list_get(int i);
		void list_display();
		int multiInsert(int i, int n, int item[]);
		int multiDel(int i, int n);
		int mergeUp(SeqList& var);
		int mergeDown(SeqList& var);
		int Rol(int diretion, int n);
		bool ListEmpty();
		int LocateElem(int e,int(*compare)(int,int));
		void list_union(SeqList& lb);
		
		friend void merge(SeqList* LA, SeqList* LB, SeqList* LC);
};

SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

SeqList::SeqList(int *l, int ms=1000, int s=0)
{
	list = l;
	maxsize = ms;
	size = s;
}

SeqList::~SeqList()
{
	delete []list;
}

int SeqList::list_size()
{
	return size;
}

int SeqList::list_insert(int i, int item)
{
	if(i<1 || i>size+1) return error;
	if(size >= maxsize) return error;
	
	int *q = &(list[i-1]);
	int *p = NULL;
	
	//����λ�ú�����Ԫ�غ��� 
	for(p=&(list[size-1]); p>=q; --p)
	{
		*(p+1) = *p;
	}
	
	*q = item;
	++size;
	
	p = NULL;
	q = NULL;
	free(q);
	free(p);
	return ok;
}

int SeqList::list_get(int i)
{
	if(i<=size && i>=1)
	{
		cout<<*(list+i-1)<<endl;
		return ok;
	}
	else{
		cout<<"error"<<endl;	
	}
}

int SeqList::list_del(int i)
{
	if(i<=size&&(size-1>=0))
	{
		for(int j=i-1; j<size; ++j)
		{
			list[j] = list[j+1];
		}
		size-=1;
		return ok;
	}
	else{
		return error;
	}
}

void SeqList::list_display()
{
	for(int i=0;i<size;++i)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int SeqList::multiInsert(int i,int n,int item[])
{
	if(i>0&&i<=size+1&&(size+n<=maxsize))
	{
		for(int j=size+n-1; j>i-1; --j)
		{
			list[j] = list[j-n];
		}
		for(int j=i-1;j<i+n-1;++j)
		{
			list[j] = item[j-i+1];
		}
		size+=n;
		return 0;
	}
	else return -1;
}

int SeqList::multiDel(int i, int n)
{
	if(i<=size&&(size-n>=0)&&(i+n-1<=size))
	{
		for(int j=i-1; j<size-n+1; ++j)
		{
			list[j] = list[j+n];
		}
		size-=n;
		return ok;
	}
	else{
		return error;
	}
}

int SeqList::mergeUp(SeqList& var)
{
	multiInsert(size,var.size,var.list);
	for(int i=0;i<size;++i)
		for(int j=i+1;j<size;++j)
		{
			if(list[i]>list[j])
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
}

int SeqList::mergeDown(SeqList& var)
{
	multiInsert(size,var.size,var.list);
	for(int i=0;i<size;++i)
		for(int j=i+1;j<size;++j)
		{
			if(list[i]<list[j])
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
}

int SeqList::Rol(int direction,int n)
{
	if(direction==LEFT_ROL)
	{
		int *temp = new int[size];
		for(int i=0;i<size-n;++i)
		{
			temp[i]=list[i+n];
		}
		for(int i=size-n;i<size;++i)
		{
			temp[i]=list[i-size+n];
		}
		for(int i=0;i<size;++i)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else if(direction==RIGHT_ROL)
	{
		int *temp = new int[size];
		for(int i=0;i<n;++i)
		{
			temp[i]=list[i+size-n];
		}
		for(int i=n;i<size;++i)
		{
			temp[i]=list[i-n];
		}
		for(int i=0;i<size;++i)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else return error;
}

bool SeqList::ListEmpty()
{
	if(0==size)
	{
		return true;
	}
	else return false;
}

int SeqList::LocateElem(int e,int(*equal)(int,int))
{
	int *p = list;
	int i = 1;
	for(; i<=size && !(*equal)(*p++,e); ++i)
		;
	if(i<=size)	return i;
	else return error;
}

//��������lb�е�����list�е�����Ԫ�ز��뵽list�� 
void SeqList::list_union(SeqList& lb)
{
	for(int i=1; i<=lb.size; ++i)
	{
		int e = lb.list[i-1];
		if(LocateElem(e,equal)==-1)
		{
			list_insert(size+1, e);
		}
	}
}

void merge(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i,j,k,l;
	i=0;j=0;k=0;
	
	while(i<=LA->size && j<=LB->size)
	{
		if(LA->list[i] <= LB->list[j])
		{
			LC->list[k] = LA->list[i];
			i++;k++;
		}
		else
		{
			LC->list[k] = LB->list[j];
			j++;k++;
		}
	}
	while(i<=LA->size)	//��A�ȱ�B��ʱ
	{
		LC->list[k] = LA->list[i];
		i++;k++;
	}
	while(i<=LB->size)	//��B�ȱ�A��ʱ
	{
		LC->list[k] = LB->list[j];
		j++;k++;
	}
	
	LC->size = LA->size+LB->size;
}


int main()
{
	int s,insLoc,item,delLoc,getLoc;
	cin>>s;
	 
	int *l = new int[100];
	for(int i=0;i<s;i++)
	{
		cin>>l[i];
	}
	SeqList sl(l,1000,s);
	
	sl.list_display();
	
	cin>>insLoc>>item;
	if(sl.list_insert(insLoc,item)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>insLoc>>item;
	if(sl.list_insert(insLoc,item)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>delLoc;
	if(sl.list_del(delLoc)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>delLoc;
	if(sl.list_del(delLoc)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>getLoc;
	sl.list_get(getLoc);
	
	cin>>getLoc;
	sl.list_get(getLoc);
	
	//delete []l1;
	//delete []l2;
}
