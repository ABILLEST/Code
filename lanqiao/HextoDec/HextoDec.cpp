#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    string sixt;
    cin>>sixt;

    int len=sixt.length();          //���������ַ��ĳ���
    long long ten=0;                //����һ��Ҫע���������ͣ�����ĿҪ��С��8�ַ�������������long long�����򱨴�
    
	for(int i=len-1;i>=0;i--)       //����ʮ������תʮ���Ƶķ������Ӻ���ǰ
    {
        if(isdigit(sixt[i]))           //�Ƿ�Ϊ�ַ�0~9
            {
               ten+=(sixt[i]-'0')*pow(16,len-1-i);           //�ǵĻ����ַ�0~9ת��Ϊ����0~9�ټ���
            }
        else
            {
               ten+=(sixt[i]-'A'+10)*pow(16,len-1-i);   //�������ַ�A~Fת��Ϊ��Ӧ������10~15
            }
    }
    cout<<ten;
    return 0;
}