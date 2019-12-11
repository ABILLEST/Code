#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define Status int

class ListNode
{
	public:
		Status data;
		ListNode* next;
};

class LinkList
{
	public:
		int len;
		ListNode* head,tail;
		
		LinkList();
		void Init_LL(int n);
		~LinkList();
		int getLen(){ return len; }	//��ȡ���� 
		Status GetElem(int i,Status& e);	//��ȡָ���ڵ������ 
		Status ListIns(int i,Status e);	//��ָ��λ�ò���ڵ� 
		Status ListDel(int i,Status &e);	//ɾ��ָ��λ�üӵ�
		void display();
		
		//void ClearList();
		//void InsFirst(ListNode* h, ListNode* s);
		//void DelFirst(ListNode* h, ListNode& q);
		//void append(ListNode* s);
		
		ListNode* LL_index(int i);	//��ȡ��i���Ľڵ� 
		ListNode* LL_PrvIndex(int i);//��ȡ��i���ڵ��ǰ�� 
		Status swap(int pa,int pb);	//��������λ�õ����� 
		Status LL_merge(ListNode *La, ListNode *Lb, ListNode* Lc);	//˳��ϲ�
		Status LL_Difference(ListNode* Lb); 
		Status LL_Reverse();
		void BinAddOne();

		friend int ListLength(LinkList L);
};

LinkList::LinkList()
{
	head = new ListNode;
	head->next = NULL;
}

void LinkList::Init_LL(int n)
{
	len = n;
	head = new ListNode;
	head->next = NULL;
	ListNode *q = head;
	for(int i=n; i>0; --i)
	{
		ListNode* p = new ListNode;
		cin>>p->data;
		q->next = p;
		q = q->next;
	}
	q->next = NULL;
}

LinkList::~LinkList()
{
	int j=0;
	ListNode* p=head;
	ListNode* a=head;
	while(p->next && j<len)
	{
		p = p->next;
		free(a);
		a = p;
		++j;
	}
	head = NULL;
	len = 0;
}

ListNode* LinkList::LL_index(int i)
{
	ListNode* p = head;
	int count=0;

	while(p && count<i)
	{
		p = p->next;
		++count;
	}
	if(!p || count>i) return NULL;
	return p;
}

//��ȡiλ�õ�ǰ��p
ListNode* LinkList::LL_PrvIndex(int i)
{
	ListNode* p = head;
	int count=0;

	while(p->next && count<i-1)
	{
		p = p->next;
		++count;
	}
	if(!(p->next) || count>i-1) return NULL;
	return p;
}

int LinkList::GetElem(int i,int& e)
{
	if(i==0) return error;		//���ɻ�ȡͷ����ֵ
	ListNode* p = LL_index(i);
	if(!p) return error;	//�������� 
	e = p->data;
	return ok;
}

//��ָ��λ�ò���Ԫ��
int LinkList::ListIns(int i,int e)
{
	int j=0;
	
	//����Ԫ��
	ListNode* p = LL_PrvIndex(i);

	//����λ�ò��Ϸ�
	if(!p) return error;
	
	//����
	ListNode *s = new ListNode;
	s->next = p->next;		//�ȸĺ�ָ���ٸ�ǰָ�룬ֻ��Ҫ2����� 
	p->next = s;

	//��������
	s->data = e;
	++len;

	return ok;
}

int LinkList::ListDel(int i,int &e)
{
	int j=0;
	ListNode* q = new ListNode;
	
	if(!i) return error;	//ͷ��㲻��ɾ�� 
	
	ListNode* p = LL_PrvIndex(i);	//�õ�ǰ�� 
	if(!p) return error;
	
	e = p->next->data;
	q = p->next;
	p->next = p->next->next;
	delete q;
	--len;
	return ok;
}

void LinkList::display()
{
	ListNode* p = head;
	/*if(!p->next)
	{
		cout<<"������"<<endl;
		return;
	}*/
	p = p->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int LinkList::swap(int pa,int pb)
{
	if((pa>len||pa<=0) || (pb>len||pb<=0))		//λ�ô��� 
	{
		return error;
	}
	else if(pa==pb) return ok;
	else
	{
		ListNode *p,*q,*p_prv,*q_prv,*temp;
		p = LL_index(pa);
		q = LL_index(pb);
		p_prv = LL_index(pa-1);
		q_prv = LL_index(pb-1);
				
		temp=q->next;
		p_prv->next=q;
		q->next=p->next;
		q_prv->next=p;
		p->next=temp;
		return ok;
	}
}

//��ԭ���㷨����δ��������ϲ�������
int LinkList::LL_merge(ListNode *La, ListNode *Lb, ListNode* Lc)	
{
	ListNode *pa = La->next;
	ListNode *pb = Lb->next;
	ListNode *pc = Lc;
	
	while(pa && pb)
	{
		ListNode *newNode = new ListNode;		//�½��ڵ�
		newNode->next = NULL;
		
		if(pa->data <= pb->data)		//�Ƚ�������Ԫ�ش�С�����β��� 
		{
			newNode->data = pa->data;
			pa = pa->next;
		}
		else
		{
			newNode->data = pb->data;
			pb = pb->next;
		}
		
		pc->next = newNode;
		pc = pc->next;
	}
	
	//ע������������䣬�㷨������B��C�������غϵĲ���
	pc->next = pa ? pa : pb;	//����ʣ���
}

//��ǰ�����Lb�Ĳ��������ڵ�ǰ���� 
Status LinkList::LL_Difference(ListNode* Lb)
{
	ListNode *pre, *p, *q, *r;
	
	//��ǰ��ָ�� 
	pre = head;
	p = head->next;
	
	while(p!=NULL)
	{
		q = Lb->next;
		while(q!=NULL && q->data!=p->data)
		{
			q = q->next;
		}
		if(q!=NULL)		//�ҵ���ֵͬ��ɾ���ڵ� 
		{
			r = p;
			pre->next = p->next;
			p = p->next;
			free(r);
		}
		else
		{
			pre = p;
			p = p->next;
		} 
	}
}

//�͵�����
Status LinkList::LL_Reverse()
{
	ListNode* p = head->next;	//������һ��Ԫ�ص�λ�� 
	ListNode* q = NULL;			//ͷ����next�ÿջ�������� 
	head->next = NULL;
	while(p!=NULL)
	{
		q = p->next;		//�ݴ�ԭ�� 
		
		p->next = head->next;	//ͷ������ 
		head->next = p;
		
		p = q;
	}
	return ok;
}

//����������һ 
void LinkList::BinAddOne()
{
	ListNode *q, *r, *s;
	
	q = head->next;
	r = head;
	
	while(q!=NULL)		//�������һ��Ϊ0�Ľڵ� 
	{
		if(q->data == 0) r = q;
		q = q->next;
	}
	if(r!=head) r->data = 1;	//��1
	else{
		s = new ListNode;
		s->data = 1;
		//ͷ��
		s->next = head->next;
		head->next = s;
		r = s; 
	}
	r = r->next;
	while(r!=NULL)		//������Ľڵ���0
	{
		r->data = 0;
		r = r->next;
	}
}


int ListLength(LinkList L)
{
	ListNode* p;
	p = L.head->next;
	int count=0;
	while(p!=NULL)
	{
		p = p->next;
		++count;
	}
	return count;
}


int main()
{
	int n, Pos, e;
    cin>>n;
    LinkList L;
    L.Init_LL(n);
    L.display();
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
 
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
	
	return 0;
}
