#include <iostream>
using namespace std;

const int MaxLen = 20;
const int MaxDist = 9999;

class Map
{
private:
    bool Visit[MaxLen];     //���ʱ�־����
    int Matrix[MaxLen][MaxLen]; //ͼ���ڽӾ���
    int Vexnum;     //ͼ�Ķ�������
    void DFS(int v, int &c);    //������ȵݹ����
    void BFS(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void ShortestPath_DIJ(int v0);
    bool isStrongConnect();
    void MST_Prim(int v);
    void MST_Kruskal(int v);
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
    int v,c =0;
    //���ʱ�־�����ʼ��
    for(v=0; v<Vexnum; ++v)
        Visit[v] = false;
    
    //�����ж�����м��
    for(v=0; v<Vexnum; ++v)
        if(!Visit[v])       //�������δ����
            DFS(v, c);         //���������������
    
    cout<<endl;
}

//�ӵ�v����������ݹ��������ȱ���ͼG
void Map::DFS(int v, int &c)
{
    int w,i,k;

    //�Զ���v���з���
    Visit[v] = true;
    //cout<<v<<" ";
    ++c;    //��ͨ������

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
            DFS(AdjVex[i],c);
    }
        
    delete []AdjVex;
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

bool Map::isStrongConnect()
{
    bool flag = true;
    int c;
    //�����ж�����м��
    for(int i=0; i<Vexnum; ++i)
    {
        c = 0;
        for(int j=0; j<Vexnum; ++j)
            Visit[j] = false;
        DFS(i,c);         //���������������
        if(c!=Vexnum)
            flag=false;
    }
        
    return flag;
}

void Map::MST_Prim(int u)
{
    struct
    {
        string adjVex;
        int lowcost;
    }closedge[MaxLen];
    int k=u;
    int mincost;

    for(int j=0; j<Vexnum; ++j)
        if(j!=k)
            closedge[j] = {u , Matrix[k][j]};
    closedge[k].lowcost = 0;
    for(int i=1; i<Vexnum; ++i)
    {
        mincost = closedge[1].lowcost;
        for(int j=1; j<Vexnum; ++j)
        {
            if(closedge[j].lowcost>mincost)
            {
                mincost = closedge[j].lowcost;
                k = j;
            }
        }

        cout<<
    }
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
        if(map.isStrongConnect())
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}