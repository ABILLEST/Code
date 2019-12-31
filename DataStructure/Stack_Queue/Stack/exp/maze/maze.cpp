#include <iostream>
#include <stack>
using namespace std;

const int maxx= 100;
int maze[maxx][maxx];
int n;

//�ж��ĸ����������������˳���Ǹ�����
int path(int i, int j)
{
	if(j+ 1< n&&!maze[i][j+ 1])
		return 1;
	else if(i+ 1< n&& !maze[i+ 1][j])
		return 2;
	else if(j- 1>= 0&&!maze[i][j- 1])
		return 3;
	else if(i- 1>= 0&&!maze[i- 1][j])
		return 4;

	return 0;
}

int main()
{

	int t;
	int ii[]= {0, 0, 1, 0, -1};
	int jj[]= {0, 1, 0, -1, 0};
	cin>>t;
	while(t--)
	{
		cin>>n;

		stack<int> stx;
		stack<int> sty;

		for(int i= 0; i< n; i++)
			for(int j= 0; j< n; j++)
				cin>>maze[i][j];

		stx.push(0);
		sty.push(0);
		maze[0][0]= 1;
		int i= 0;
		int j= 0;
		while(1)
		{
			int k= path(i, j);

			if(k)
			{
				i+= ii[k];
				j+= jj[k];
				maze[i][j]= 1;
				stx.push(i);
				sty.push(j);

			}
			else if(!stx.empty()&&!sty.empty()) //�ĸ����򲻿��������
			{
				i= stx.top();
				j= sty.top();
				if(!path(i, j)) 	//���ж��¸õ㻹��û��·��û����pop()�õ�
				{
					stx.pop();
					sty.pop();
				}
			}
			if((stx.empty()&&sty.empty())|| (i== n-1&&j== n-1))
				break;//ȫ��pop���򵽴��յ����˳�ѭ��
		}

		if(stx.empty()&&sty.empty())
		{
			cout<<"no path"<<endl;
		}
		else
		{
			int zuo[1000];
			int len= 0;
			int l= 0;

			while(!stx.empty()&&!sty.empty())
			{
				len+= 2;//ע��������i��jͬʱ���룬����Ҫ��2
				zuo[l++]= stx.top();
				zuo[l++]= sty.top();
				stx.pop();
				sty.pop();
			}

			int flag= 1;
			for(int i= len- 1; i>= 0;)
			{

				cout<<'['<<zuo[i--]<<','<<zuo[i--]<<']'<<"--";
				if((flag++)%4== 0)
					cout<<endl;
			}
			cout<<"END"<<endl;
		}
	}
	return 0;
}

