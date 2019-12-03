#include <iostream>
using namespace std;

const int MaxLen = 20;
const int MaxDist = 9999;

class Map
{
private:
    bool Visit[MaxLen];     //���ʱ�־����
    int Matrix[MaxLen][MaxLen]; //ͼ���ڽӾ���
    int isFinished[MaxLen];     //������Ķ���
    int Vexnum;     //ͼ�Ķ�������
    void DFS(int v, int &c);    //������ȵݹ����
    void BFS(int v);
    int select();
    void update(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void ShortestPath_DIJ(int v0);
    bool isStrongConnect();
    bool isZeroInDegree(int vexNo);
    void TopologicalSort();
};

//�����ڽӾ���
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //����ͼ�Ľڵ���

    for(i= 0; i<Vexnum; ++i)
              isFinished[i]= false;

    for(i=0; i<MaxLen; ++i)
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = 0;
    
    for(i=0; i<Vexnum; ++i)     //�ڽӾ����ʼ��
        for(j=0; j<Vexnum; ++j)
        {
            if(mx[i][j])    //����������0��ʾ���������ֻ����0������
                Matrix[i][j] = mx[i][j];
        }
}

int Map::select()
{
    for(int i=0; i<Vexnum; ++i)
    {
        if(!isFinished[i] && isZeroInDegree(i)) //�ҵ���Ϊ0�Ķ���
        {
            isFinished[i]= true;        //��ʾ�Ѿ��ҵ����Ķ���
            return i;
}
    }
}

//�ж϶���Ķ��Ƿ�Ϊ0
bool Map::isZeroInDegree(int vexNo)
{
    int i;
    //���в���
    for(i= 0; i<Vexnum && !Matrix[i][vexNo]; ++i)
    {
        if(i==Vexnum-1 && !Matrix[i][vexNo])
            return true;
    }
    return false;
}

//������ö���
void Map::update(int v)
{
    for(int i=0; i<Vexnum; ++i)
    {
        Matrix[v][i] = 0;
    }
}

void Map::TopologicalSort()
{
    for(int i= 0; i< Vexnum; i++)
    {
        int v= select();
        if(v== -1)
            break;
            
        update(v);
        cout<<v<<" ";
    }
    cout<<endl;
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
        map.TopologicalSort();
    }

    return 0;
}