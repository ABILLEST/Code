#include<iostream>
using namespace std;
#include<cstdlib>

int main()
{
    long long n;//��ֹ������
    int m;
    int k = 0;
    char str[100];

    cin >> n;

    if(0<=n && n<=9)
    {
        cout<<n;
		return 1;
    }

    while (n>0)
    {
        m = n % 16;		//���泬��16���������Ĳ���
        n /= 16;
        //ת��Ϊ�ַ���
        if (m > 9)
            str[k++] = 'A' + m-10;
        else
            str[k++] = '0' + m;
    }

	//��������ַ���
    for (int i = k - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    return 0;
}