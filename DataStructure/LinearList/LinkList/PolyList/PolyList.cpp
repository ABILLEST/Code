#define   OK                    1
#define   ERROR                 0
#define   OVERFLOW             -2
#define   TRUE                  1
#define   FALSE                 0
typedef   int   Status;//Ϊ�˷����㷨�����ԣ��㷨��Status����ͨ������ɸ�
#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct{//��ı�ʾ������ʽ������ΪLinkList������Ԫ��
    float coef;//ϵ��
    int expn;//ָ��
}term, ElemType;//�������ͣ�term���ڱ�ADT��ElemTypeΪLinkList�����ݶ�����
typedef struct LNode{//�ڵ�����
    ElemType  data;//�����ʾ��ÿһ���ָ����ϵ��
    struct LNode *next;
}*Link,*Position;
typedef struct{//��������
    Link head, tail;//�ֱ�ָ�����������е�ͷ�������һ�����
    int len;//ָʾ��������������Ԫ�صĸ���
}LinkList;//ÿһ�����һ���б�
typedef LinkList polynomial;

Status InitList(LinkList *L)
{ /* ����һ���յ��������� */
    Link p;
    p = (Link)malloc(sizeof(LNode)); /* ����ͷ��� */
    if (p)
    {
        p->next = NULL;
        (*L).head = (*L).tail = p;
        (*L).len = 0;
        return OK;
    }
    else
        return ERROR;//�ڴ���䲻��
}
Status MakeNode(Link *p, ElemType e)
{ /* ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR */
    *p = (Link)malloc(sizeof(LNode));
    if (!*p)
        return ERROR;
    (*p)->data = e;
    return OK;
}

Status InsFirst(LinkList *L, Link h, Link s) /* �β�����L,��Ϊ���޸�L */
{ /* hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ */
    s->next = h->next;
    h->next = s;
    if (h == (*L).tail) /* hָ��β��� */
        (*L).tail = h->next; /* �޸�βָ�� */
    (*L).len++;
    return OK;
}

Position GetHead(LinkList L)
{ /* ������������L��ͷ����λ�� */
    return L.head;
}
Status SetCurElem(Link p, ElemType e)
{ /* ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ */
    p->data = e;
    return OK;
}

Status LocateElemP(LinkList L, ElemType e, Position *q, int(*compare)(ElemType, ElemType))
{ /* ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�� */
    /* ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж����� */
    /* compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��������һԪ����ʽ�� */
    Link p = L.head, pp;
    do
    {
        pp = p;
        p = p->next;
    } while (p && (compare(p->data, e)<0)); /* û����β��p->data.expn<e.expn */
    if (!p || compare(p->data, e)>0) /* ����β��compare(p->data,e)>0 */
    {
        *q = pp;
        return FALSE;
    }
    else /* �ҵ� */
    {/* û����β��p->data.expn=e.expn */
        *q = p;
        return TRUE;
    }
}
Status Remove_Polyn(LinkList *L, Link q)
{ //�������ָ��Ϊ0��ɾ�������е���
    Link p, h;
    h = L->head;
    while (h->next != q)
    {
        h = h->next;
    }
    //�ҵ���
    if (q == L->tail)
    {//ɾ��������Ǳ�β���ı��β
        L->tail = h;
    }
    h->next = q->next;
    free(q);
    L->len--;
    return OK;
}
int cmp(term a, term b) // CreatPolyn()��ʵ��
{ // ��a��ָ��ֵ<��=��>b��ָ��ֵ���ֱ𷵻�-1��0��+1
    if (a.expn == b.expn)
        return 0;
    else
        return (a.expn - b.expn) / abs(a.expn - b.expn);
}
void CreatPolyn(polynomial &p,int m)
{//����m���ϵ����ָ����������ʾһԪ����ʽ����������P
    InitList(&p);//��ʼ������ʽ����
    Link h = GetHead(p);//����ͷ��������Ԫ��
    ElemType e;//ͷ�������
    Position q,s;
    e.coef = 0.0; e.expn = -1; SetCurElem(h, e);//����ͷ����Ԫ��
    for (int i = 1; i <= m; ++i)//��������m��������
    {
        cout << "��"<<i<<"��"<<"��ϵ��:";
        cin >> e.coef;
        cout << "��" << i << "��" << "��ָ��:";
        cin >> e.expn;
        if (!LocateElemP(p, e,&q, cmp))//��ǰ�����в����ڸ�ָ����
        {
            if (e.coef != 0)//�����ڲŲ���
                if (MakeNode(&s, e))InsFirst(&p,q,s);//���ɽ�㲢��������
        }
        else//��ǰ�����д��ڸ�ָ����,������ϵ��
        {
            q->data.coef = q->data.coef + e.coef;
            //�������������0����ɾ����
            if (q->data.coef == 0)
                Remove_Polyn(&p, q);//ɾ������ǰ�ڵ�
        }
    }
}
Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ /* ���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�� */
    Link p = L.head->next;
    int j;
    for (j = 1; j <= L.len; j++)
    {
        visit(p->data);
        p = p->next;
    }
    cout << "\b ";
    if (L.len == 0)
        cout << "0";
    return OK;
}
void visit(ElemType e)
{
    if (e.coef > 0 && e.coef != 1 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << e.coef << "x^" << e.expn << "+";
        else
            cout << e.coef << "x^(" << e.expn << ")+";
    }
    else if (e.coef < 0 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << "(" << e.coef << ")x^" << e.expn << "+";
        else
            cout << "(" << e.coef << ")x^(" << e.expn << ")+";
    }
    else if (e.coef == 1 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << "x^" << e.expn << "+";
        else
            cout << "x^(" << e.expn << ")+";
    }
    else if (e.expn == 0 && e.coef != 0)
        cout << e.coef<<"+";
    else 
        cout << "";//�����û����������ϵ��Ϊ0����������̫�࣬������һ

}
Position NextPos(Link p)
{ /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�� */
    /* ���޺�̣��򷵻�NULL */
    return p->next;
}
ElemType GetCurElem(Link p)
{ /* ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ */
    return p->data;
}
Status DelFirst(LinkList *L, Link h, Link *q) /* �β�����L,��Ϊ���޸�L */
{ /* hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء� */
    /* ������Ϊ��(hָ��β���)��q=NULL������FALSE */
    *q = h->next;
    if (*q) /* ����ǿ� */
    {
        h->next = (*q)->next;
        if (!h->next) /* ɾ��β��� */
            (*L).tail = h; /* �޸�βָ�� */
        (*L).len--;
        return OK;
    }
    else
        return FALSE; /* ����� */
}

void FreeNode(Link *p)
{ /* �ͷ�p��ָ��� */
    free(*p);
    *p = NULL;
}
Status ListEmpty(LinkList L)
{ /* ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
    if (L.len)
        return FALSE;
    else
        return TRUE;
}
Status Append(LinkList *L, Link s)
{ /* ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)�� */
    /* һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���� */
    /* ��β��� */
    int i = 1;
    (*L).tail->next = s;
    while (s->next)
    {
        s = s->next;
        i++;
    }
    (*L).tail = s;
    (*L).len += i;
    return OK;
}
void AddPolyn(polynomial &Pa, polynomial &Pb)
{//����ʽ�ӷ�:Pa = Pa+Pb,������������ʽ�Ľ�㹹�ɡ��Ͷ���ʽ��
    Position ha, hb, qa=NULL, qb=NULL;
    term a, b;
    ha = GetHead(Pa); hb = GetHead(Pb);//ha��hb�ֱ�ָ��Pa��Pb��ͷ���
    if (Pa.len != 0 && Pb.len != 0)
    {
        qa = NextPos(ha); qb = NextPos(hb);//qa��qb�ֱ�ָ��Pa��Pb�еĵ�ǰ���
        //��ʱqa��qb����ָ�����ʽ��һ��
        while (qa && qb)
        {//qa��qb�ǿ�
            a = GetCurElem(qa);
            b = GetCurElem(qb); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
            float sum;
            switch (cmp(a, b))//�Ƚ����ߵ�ָ��ֵ
            {
            case -1://����ʽ��PA�еĽ���ָ��С
                ha = qa;	//�ݴ�qas
                qa = NextPos(ha);
                break;
            case 0://����ָ��ֵ���
                sum = a.coef + b.coef;
                if (sum != 0)
                {
                    //�޸�paָ��ĸý���ϵ��ֵ
                    qa->data.coef = sum;
                    //��һ��
                    ha = qa;
                }
                else
                {
                    //ɾ�����
                    DelFirst(&Pa, ha, &qa);
                    FreeNode(&qa);
                }
                DelFirst(&Pb, hb, &qb);//Ҳɾ����qb�Ľ��
                //�������ƶ�һλ
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            case 1://����ʽPB�еĵ�ǰ���ָ��ֵС
                DelFirst(&Pb, hb, &qb);//�ѵ�ǰ����PB��ɾ��������qbָ��ǰ������Բ���
                InsFirst(&Pa, ha, qb);//������haǰ
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            }//switch
        }//while
        if (!ListEmpty(Pb))Append(&Pa, qb);//����Pb��ʣ����
        FreeNode(&hb);//�ͷ�Pb��ͷ���
    }//A,B��Ϊ��
    if (Pa.len == 0)
    {
        Pa = Pb;//��ӽ������B
    }
    if (Pb.len == 0)
    {
        //��ӽ������A
    }   
    //����һ���Ѿ�����

}//AddPolyn


int main()
{
    cout << "***************************************************************************" << endl;
    cout << "                   �����ݽṹ��<C���԰汾>��ε�� ��ΰ�� ����              " << endl;
    cout << "                                ��д����2016��3��                         " << endl;
    cout << "                                 ��д��:YuYunTan                          " << endl;
    cout << "                                 һԪ����ʽ���                           " << endl;
    cout << "***************************************************************************" << endl;

    polynomial A, B;
    cout << "�������һ������ʽ������Ϊ��";
    int length;
    cin >> length;
    CreatPolyn(A, length);
    //��ʾA����
    cout << "PA(x) = ";
    ListTraverse(A, visit);
    cout << endl;
    //����B
    cout << "������ڶ�������ʽ������Ϊ��";
    cin >> length;
    CreatPolyn(B, length);
    //���B
    cout << "PB(x) = ";
    ListTraverse(B, visit);
    cout << endl;
    //������������ɹ�
    //�������
    AddPolyn(A, B);
    //��ʱ��A�Ǻϲ���Ľ��
    cout << "PA(x)+PB(x) = ";
    ListTraverse(A, visit);
    cout << endl;
    system("pause");
    return 0;
}