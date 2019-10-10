#include <stdio.h>
#define StackSize 100
typedef struct{
int i,j;
}PosType;
typedef struct{
PosType pos;
int di;
} ElemType;
typedef struct {
ElemType elem[StackSize];
int top;
}SqStack;
InitStack(SqStack *pS)
{
pS->top=0; /* topָ��ջ������һ��Ԫ�� */
}
int Push(SqStack *pS,ElemType e)
{
if (pS->top==StackSize-1) /* ջ�� */
return 0;
pS->elem[pS->top]=e;
pS->top=pS->top+1;
return 1;
}
int Pop(SqStack *pS,ElemType* pe)
{
if (pS->top==0) /* ջ�� */
return 0;
pS->top = pS->top - 1;
*pe = pS->elem[pS->top];
return 1;
}
main()
{
SqStack S;
ElemType e;
PosType pos,pos_end;
int maze[10][10]={ /* ��ɢ�Թ�����0��ʾǽ�� */
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,0,1,1,1,0,1,0},
{0,1,1,0,1,1,1,0,1,0},
{0,1,1,1,1,0,0,1,1,0},
{0,1,0,0,0,1,1,1,1,0},
{0,1,1,1,0,1,1,1,1,0},
{0,1,0,1,1,1,0,1,1,0},
{0,1,0,0,0,1,0,0,1,0},
{0,0,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0}
};
int i,j;
InitStack(&S);
pos_end.i=8;pos_end.j=8;
pos.i=1;pos.j=1;
do {
if (maze[pos.i][pos.j]==1) { /* ��ǰλ�ò���ǽ�ڲ���û�߹� */
maze[pos.i][pos.j]=2; /* ������߹� */
e.pos = pos;
e.di = 1;
Push(&S,e); /* ����·�� */
if (pos.i==pos_end.i && pos.j==pos_end.j) /* ����Ѿ������յ㣬�˳�ѭ������õ�·������ջ�� */
break;
else
pos.j++; /* ��һ��λ���ǵ�ǰλ�õ����� */
}
else{ /* ��ǰλ�ò���ͨ�� */
if(S.top>0){
Pop(&S,&e);
while(e.di==4 && S.top>0){
maze[e.pos.i][e.pos.j]=-1; /* ���²���ͨ���ı�ǣ����˻�һ�� */
Pop(&S,&e);
}
if (e.di<4){
e.di++; Push(&S,e); /* ����һ���������� */
pos.i=e.pos.i; pos.j=e.pos.j;
if (e.di==2) pos.i++; /* �趨��ǰλ���Ǹ÷����ϵ����ڿ顰�������ϡ� */
else if (e.di==3) pos.j--;
else if (e.di==4) pos.i--;
}
}
}
}while(S.top>0);
/* ��õ�·������ջ�� */
printf("\n");
while(Pop(&S,&e))
printf("\n(%d,%d)",e.pos.i,e.pos.j);
/* ��ӡ�������Թ���2�������ҵ���·����-1���߹��Ĳ�ͨ��·�� */
printf("\n\n");
for(i=0;i<10;i++) {
for(j=0;j<10;j++)
printf("%2d ",maze[i][j]);
printf("\n");
}
}
