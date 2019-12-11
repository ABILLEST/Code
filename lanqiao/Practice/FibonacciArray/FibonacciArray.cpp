#include <iostream>
#include <string.h>
using namespace std;

/*
    ע�����ͣ���Ϊ�൱�ڶ���ģ10007�����㣬����һ������һ�߼���Fibonacci�����ȷ���һ�ȽϿ�
*/

long long Fibonacci(long long n,long long a[])
{
    a[0]=1; a[1]=1; a[2]=1;
    for(long long i=3;i<=n;++i)
    {
        a[i] = (a[i-1]+a[i-2]) % 10007;
    }

    return a[n];
}

int main()
{
    long long n;
    cin>>n;
    long long *Fn = new long long[n+1];
    cout<<Fibonacci(n,Fn)<<endl;

    return 0;
}
