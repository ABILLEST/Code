#include<iostream>
using namespace std;

//����������⣬������Խ���������Ҫ�Ŀ���
int bitCount_one(long x)
{
    int n=0;
    while (x)
    {
        x &= x-1;
        ++n;
    }
    return n;
}

int main()
{
    long L,R;
    long long count=0;
    cin>>L>>R;

    for(int i=L; i<=R; ++i)
    {
        count+=bitCount_one(i);
    }

    cout<<count<<endl;

    return 0;
}