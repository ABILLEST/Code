#include <iostream>
#include <string>
#include <queue>
using namespace std;


class BiTreeNode
{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode() : LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode(){}
};

class BiTree
{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
    void LeafCount(BiTreeNode* t, int& n);
    void LevelOrder(BiTreeNode * t);
    void LevelCount(BiTreeNode* t, int& n);
    void Exchange(BiTreeNode *t);
public:
    BiTree();
    ~BiTree();
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
    int LeafCount();
    void LevelOrder();
    int LevelCount();
    void Exchange();
};

BiTree::BiTree(/* args */)
{
    Root = new BiTreeNode();
}

BiTree::~BiTree()
{
}

void BiTree::CreateTree(string TreeArray)
{
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree()
{
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if('#' == ch)
    {
        T = NULL;
    }
    else
    {
        T = new BiTreeNode();
        T->data = ch;
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
    }

    return T;
}

void BiTree::PreOrder()
{   
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        PreOrder(Root);  
    cout<<endl;
}

void BiTree::PreOrder(BiTreeNode* t)
{
    if(t)
    {
        cout<<t->data<<" ";
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

void BiTree::InOrder()
{
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        InOrder(Root);
    cout<<endl;
}

void BiTree::InOrder(BiTreeNode* t)
{
    if(t)
    {
        InOrder(t->LeftChild);
        cout<<t->data<<" ";
        InOrder(t->RightChild);
    }
}

void BiTree::PostOrder()
{
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        PostOrder(Root);
    cout<<endl;
}

void BiTree::PostOrder(BiTreeNode* t)
{
    if(t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data<<" ";
    }
}

int BiTree::LeafCount()
{
    int n=0;
    LeafCount(Root, n);
    return n;
}

void BiTree::LeafCount(BiTreeNode* t, int& n)
{
    if(t)
    {
        if(!t->LeftChild && !t->RightChild)
        {
            ++n;
        }
        LeafCount(t->LeftChild,n);
        LeafCount(t->RightChild,n);
    }
}

void BiTree::LevelOrder()
{
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        LevelOrder(Root);
}

void BiTree::LevelOrder(BiTreeNode* t)
{
    queue<BiTreeNode*> tq;
    BiTreeNode* p = t;
    /*
        ��p��ָ��ǰ�ڵ��ָ����������p���գ���p��ӣ�Ȼ��ִ������ѭ����
        1.����Ԫ�س��ӵ�p�����벻ֹ1�У�
        2.���p�����ݣ���ʾ�ڵ�p�ѱ���
        3.��p�������ӽڵ��������
    */
    if(p)
    {
        tq.push(p);
    }
    while(!tq.empty())
    {
        p = tq.front();
        tq.pop();
       
        cout<<p->data<<" ";

        if(p->LeftChild) tq.push(p->LeftChild);
        if(p->RightChild) tq.push(p->RightChild);
       
   }
   cout<<endl;
}

int BiTree::LevelCount()
{
    int n;
    LevelCount(Root, n);
    return n;
}

void BiTree::LevelCount(BiTreeNode* t, int& n)
{
    int h1,h2;
    if(!t) n=0;
    if(t)
    {
        LevelCount(t->LeftChild,h1);
        LevelCount(t->RightChild,h2);
        n = (h1>h2?h1:h2)+1;
    }
}

void BiTree::Exchange(BiTreeNode *t)
{
    if(t!=NULL)
    {
        Exchange(t->LeftChild);
        Exchange(t->RightChild);
        BiTreeNode *temp;
        temp = t->LeftChild;
        t->LeftChild = t->RightChild;
        t->RightChild = temp;
    }
}

void BiTree::Exchange()
{
    Exchange(Root);
}

int main()
{
     int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        BiTree t;
        t.CreateTree(s);
        t.Exchange();
        t.PreOrder();
        t.InOrder();
        t.PostOrder();
        t.LevelOrder();
    }

    return 0;
}