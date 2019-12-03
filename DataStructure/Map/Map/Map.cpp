#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MaxLen = 20;

struct 
{
    int adjvex; 
};

class Map
{
private:
    bool Visit[MaxLen];     //���ʱ�־����
    int Matrix[MaxLen][MaxLen]; //ͼ���ڽӾ���
    int Vexnum;     //ͼ�Ķ�������
    void DFS(int v);    //������ȵݹ����
    void BFS(int v);
    void MiniSpanTree_PRIM();   //��С������-����ķ�㷨
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void MiniSpanTree_PRIM();
};

//�����ڽӾ���
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //����ͼ�Ľڵ���
    for(i=0; i<MaxLen; ++i)
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = 0;
    
    for(i=0; i<Vexnum; ++i)     //�ڽӾ����ʼ��
        for(j=0; j<Vexnum; ++j)
            Matrix[i][j] = mx[i][j];
}

void Map::DFSTraverse()
{
    int v;
    //���ʱ�־�����ʼ��
    for(v=0; v<Vexnum; ++v)
        Visit[v] = false;
    
    //�����ж�����м��
    for(v=0; v<Vexnum; ++v)
        if(!Visit[v])       //�������δ����
            DFS(v);         //���������������
    
    cout<<endl;
}

//�ӵ�v����������ݹ��������ȱ���ͼG
void Map::DFS(int v)
{
    int w,i,k;

    //�Զ���v���з���
    Visit[v] = true;
    cout<<v<<" ";

    //�ҳ���v�������������нڵ㣬�����AdjVex��
    int *AdjVex = new int[Vexnum];      //���v���ӵĶ�����
    for(int i=0; i<Vexnum; ++i)
        AdjVex[i] = -1;
    
    k=0;    //����AdjVex�Ŀ�λ���±�

    //�����ڽӾ����ҳ��붥��v���ӵĵ�����������
    for(i=0;i<Vexnum;++i)
    {
        if(Matrix[v][i]==1)
            AdjVex[k++] = i;
    }

    for(i=0; i<k; ++i)
    {
        if(!Visit[AdjVex[i]])
            DFS(AdjVex[i]);
    }
        
    delete []AdjVex;
}

void Map::BFSTraverse()
{
    BFS(0);
}

void Map::BFS(int v)
{
    int w,u;
    int i,k;
    int *AdjVex = new int[Vexnum];
    queue<int> Q;

    for(i=0; i<Vexnum; ++i)
        Visit[i] = false;

    for(v=0; v<Vexnum; ++v)
    {
        if(!Visit[v])
        {
            Visit[v] = true;
            cout<<v<<" ";
            Q.push(v);

            while(!Q.empty())
            {
                u = Q.front();
                Q.pop();

                for(int i=0; i<Vexnum; ++i)
                    AdjVex[i] = -1;

                k=0;
                for(i=0; i<Vexnum; ++i)
                {
                    if(Matrix[u][i]==1)
                        AdjVex[k++] = i;
                }

                i=0;
                for(w=AdjVex[i]; w!=-1; w=AdjVex[i++])
                {
                    if(!Visit[w])
                    {
                        Visit[w] = true;
                        cout<<w<<" ";
                        Q.push(w);
                    }
                        
                }
            }
        }
    }
    cout<<endl;
}

void Map::MiniSpanTree_PRIM()
{
    for(int i=0; i<Vexnum; ++i)
        if(i!=k) clos
}

int main()
{
    int t;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        int n;
        Map map;
        cin>>n;
        int mx[MaxLen][MaxLen];

        for(int j=0; j<n; ++j)
            for(int k=0; k<n; ++k)
                cin>>mx[j][k];
        
        map.SetMatrix(n, mx);
        map.BFSTraverse();
    }

    return 0;
}