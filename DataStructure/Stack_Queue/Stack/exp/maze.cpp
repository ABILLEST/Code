#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define ok 1
#define error -1
#define Status int

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

int main()
{
	string str;
	int flag;
	int t, n;
	
	cin>>t;
	for(int i=0; i<t; ++i)
	{
		stack <int>  s;
		
		cin>>n;
		int maze[n][n];
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				cin>>maze[i][j];
			}
		
		//��ֹ�� 
		PosType start,end;
		start.x=0;	start.y=0;
		end.x=7;	end.y=7;
		
		if(MazePath(maze,start,end)==1)
		{
			cout<<"���ɹ���"<<endl;
		}
		else cout<<"���ʧ�ܣ�"<<endl;
	}
	return 0;
}

Status MazePath(int (*maze), PosType start, PosType end)
{
	//���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջ��
	stack <int>  s;
	ElementType e;
	
	PosType curpos=start;//�趨����ǰλ�á�Ϊ�����λ�á�
	int curstep=1;//̽����һ��
	
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
			if(!s.empty())
			{
				e. = s.top();
				s.pop();
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



//path�Ǳ���·���Ķ�ջ����ջ��ÿ��Ԫ�ض�����x�����y���꣬������xp��yp��ʾ

//path1��һ����ʱ��ջ����path�����ݵ��������path1��ʹ��·�����������

//	if(!path.empty())	//�ҵ�·��
//	{	//......���ɴ��룬ʵ��path�����ݵ���path1
//		i=0;  //���������·���Ĵ���
//		while (!path1.empty())
//		{	
//			cpos = path1.top();
//			if ( (++i)%4 == 0 ) 
//				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
//			else
//				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
//
//			path1.pop();
//		}
//		cout<<"END"<<endl;
//	}
//	else
//		cout<<"no path"<<endl; //�Ҳ���·�����no path

