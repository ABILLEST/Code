#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define TRUE 1
#define FALSE 0
#define NUMBER 20
using namespace std;
typedef int Status;
typedef struct
{//����
int x;
int y;
}PosType;
typedef struct
{//�������
int order;
int directory;
PosType seat;
}ElementType;
typedef struct node1
{//ջ����
ElementType node;
struct node1 *next;
}StackNode,* LinkStack;
void InitStack(LinkStack &head);
int IsStackEmpty(LinkStack head);
int Push(LinkStack head, ElementType element);
int Pop(LinkStack head, ElementType &element);
int GetTop(LinkStack head, ElementType &element);
int StackLength(LinkStack head);
Status ClearStack(LinkStack &S);
Status DestroyStack(LinkStack &head);
Status Pass(PosType curpos,int (*a)[10]);//�жϵ�ǰλ���Ƿ��ͨ��
PosType NextPos(PosType curpos,int directory);//����ڵ�ǰλ�õ���һ����λ������
void MarkPrint(int &a);//���²���ͨ���ı��
void InitStack(LinkStack &head){
head=(LinkStack)malloc(sizeof(StackNode));
if(head==NULL){cout<<"����洢�ռ�ʧ�ܣ�"<<endl;exit(0);}
head->next = NULL;
}
int IsStackEmpty(LinkStack head){
if(head->next == NULL) return TRUE;
return FALSE;
}
int Push(LinkStack head, ElementType element){
StackNode *newp;
newp = (StackNode *)malloc(sizeof(StackNode));
if(newp == NULL) {cout<<"����洢�ռ�ʧ�ܣ�"<<endl;exit(0);}
newp->node = element;
newp->next = head->next;
head->next = newp;
return TRUE;
}
int Pop(LinkStack head, ElementType &element){
if(IsStackEmpty(head)) return FALSE;
StackNode *newp = head->next;
element = newp->node;
head->next = newp->next;
free(newp);
return TRUE;
}
int GetTop(LinkStack head, ElementType &element){
element = head->next->node;
if(head->next==NULL)return FALSE;
return TRUE;
}
int StackLength(LinkStack head)
{
LinkStack p;
int i=0;
p=head->next;
while(p)
{
i++;
p=p->next;
}
return i;
}
Status ClearStack(LinkStack &S)
{
LinkStack p;
while(S->next)
{
p=S->next;
S->next=S->next->next;
delete p;
}
return TRUE;
}
Status DestroyStack(LinkStack &head)
{
LinkStack q;
while(head)
{
q=head->next;
delete head;
head=q;
}
return TRUE;
}
//�жϵ�ǰλ���Ƿ��ͨ��
Status Pass(PosType curpos,int (*a)[10]){
if(a[curpos.x][curpos.y]==1||a[curpos.x][curpos.y]==-1)
return FALSE;
return TRUE;
}
//����ڵ�ǰλ�õ���һ����λ������
PosType NextPos(PosType curpos,int directory){
switch(directory)
{
case 1:
curpos.x=curpos.x+1;break;
case 2:
curpos.y=curpos.y+1;break;
case 3:
curpos.x=curpos.x-1;break;
case 4:
curpos.y=curpos.y-1;break;
}
return curpos;
}
//���²���ͨ���ı��
void MarkPrint(int &a){
a=-1;
}
void PrintStack(LinkStack head)
{
LinkStack p;
cout<<"���Թ��ĳ��ڵ���ڵ�·��Ϊ��"<<endl;
while(head->next)
{
cout<<"("<<head->next->node.seat.x<<","<<head->next->node.seat.y<<")"<<" ";
p=head->next;
head->next=head->next->next;
free(p);
}
}
Status MazePath(int (*maze)[10],PosType start,PosType end)
{
//���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջ��
LinkStack S;
ElementType e;
PosType curpos=start;//�趨����ǰλ�á�Ϊ�����λ�á�
int curstep=1;//̽����һ��
InitStack(S);
do{
if(Pass(curpos,maze)){//��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ����
e.order=curstep;
e.directory=1;
e.seat=curpos;
Push(S,e); //����·��
maze[e.seat.x][e.seat.y]=-1;
if(curpos.x==end.x&&curpos.y==end.y)//�����յ㣨���ڣ�
{
PrintStack(S);
return TRUE;
}
curpos=NextPos(curpos,1);//��һλ���ǵ�ǰλ�õĶ���
curstep++;//̽����һ��
}//if
else{//��ǰλ�ò���ͨ��
if(!IsStackEmpty(S))
{
Pop(S,e);
while(e.directory==4&&!IsStackEmpty(S))
{
//maze[e.seat.x][e.seat.y]
MarkPrint(maze[e.seat.x][e.seat.y]);
Pop(S,e);
}//while
if(e.directory<4)
{
e.directory++;
Push(S,e);
maze[e.seat.x][e.seat.y]=-1;
curpos=NextPos(e.seat,e.directory);
}//if
}//if
}//else
}while(!IsStackEmpty(S));
return FALSE;
}
int main()
{
int maze[10][10]={
{1,1,1,1,1,1,1,1,1,1},//0
{1,0,0,0,0,0,0,0,1,1},//1
{1,0,0,0,1,0,1,1,0,1},//2
{1,1,1,0,1,0,0,1,0,1},//3
{1,0,0,0,1,1,0,1,0,1},//4
{1,0,0,1,0,0,0,0,0,1},//5
{1,0,1,0,0,0,1,1,0,1},//6
{1,1,1,0,0,0,0,1,0,1},//7
{1,0,0,0,0,0,0,0,0,1},//8
{1,1,1,1,1,1,1,1,1,1} //9
};
PosType start,end;
start.x=1;start.y=1;
end.x=8;end.y=8;
if(MazePath(maze,start,end)==1)
cout<<"���ɹ���"<<endl;
else cout<<"���ʧ�ܣ�"<<endl;
}
