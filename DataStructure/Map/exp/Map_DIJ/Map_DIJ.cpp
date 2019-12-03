#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MaxLen = 20;
const int MaxDist = 9999;

class Map
{
private:
    bool Visit[MaxLen];     //���ʱ�־����
    int Matrix[MaxLen][MaxLen]; //ͼ���ڽӾ���
    int Vexnum;     //ͼ�Ķ�������
    void DFS(int v);    //������ȵݹ����
    void BFS(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void ShortestPath_DIJ(int v0);
};

//�����ڽӾ���
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //����ͼ�Ľڵ���
    for(i=0; i<MaxLen; ++i)
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = MaxDist;
    
    for(i=0; i<Vexnum; ++i)     //�ڽӾ����ʼ��
        for(j=0; j<Vexnum; ++j)
        {
            if(mx[i][j])    //����������0��ʾ���������ֻ����0������
                Matrix[i][j] = mx[i][j];
        }
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

void Map::ShortestPath_DIJ(int v0)
{
    int i,j,v,w,min;
    int *dist = new int[Vexnum];
    bool *final = new bool[Vexnum];
    int path[MaxLen][MaxLen];
    int len[MaxLen];

    for(i=0; i<Vexnum; ++i)
    {
        final[i] = false;
        dist[i] = Matrix[v0][i];
    }

    //��ʼ��path
    for(i=0; i<Vexnum; ++i)
        for (j=0; j<Vexnum; ++j)
        {
            path[i][j] = -1;
        }

    //��ʼ��v0�����������·��
    for(v=0; v<Vexnum; ++v)
    {
        path[v][0] = v0;
        path[v][1] = v;
        len[v] = 2;
    }

    dist[v0] = 0;
    final[v0] = true;
    //��ѭ��
    for(i=0; i<Vexnum; ++i)
    {
        min = MaxDist;
        //Ѱ����v0����Ķ���w
        for(w=0; w<Vexnum; ++w)
            if(!final[w])   //������V-S��
                if(dist[w]<min)  //w������v0����
                {
                    v=w;
                    min = dist[w];
                }
        
        final[v] = true;    //��v0�����v����S��
        for(w=0; w<Vexnum; ++w) //���µ�ǰ���·��������
            if(!final[w] && (min+Matrix[v][w]<dist[w]))
            {
                dist[w] = min + Matrix[v][w];
                for(int x=0; x<Vexnum; ++x)
                    path[w][x] = path[v][x];
                len[w] = len[v]+1;
                path[w][len[w]-1] = w;
            }
    }

    //������
    for(i=0; i<Vexnum; ++i)
    {
        if(i!=v0)
        {
            cout<<v0<<"-"<<i<<"-"<<dist[i];
            cout<<"----[";
            for(j=0; j<len[i]; ++j)
            {
                cout<<path[i][j]<<" ";
            }
            
            cout<<"]"<<endl;
        }
    }

    delete []dist;
    delete []final;
}

int main()
{
    int t;
    int v0,vnum;
    int mx[MaxLen][MaxLen];
    Map map;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        for(int j=0; j<MaxLen; ++j)
            for(int k=0; k<MaxLen; ++k)
                mx[j][k] = 0;

        cin>>vnum;

        for(int j=0; j<vnum; ++j)
            for(int k=0; k<vnum; ++k)
                cin>>mx[j][k];
        
        map.SetMatrix(vnum, mx);
        cin>>v0;
        map.ShortestPath_DIJ(v0);
    }

    return 0;
}