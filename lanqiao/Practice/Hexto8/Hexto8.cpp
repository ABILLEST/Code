#include<iostream>
using namespace std;

string trans(char a)//ʮ������ת������
{
	switch(a)
	{
		case'0':return "0000";
		case'1':return "0001";
		case'2':return "0010";
		case'3':return "0011";
		case'4':return "0100";
		case'5':return "0101";
		case'6':return "0110";
		case'7':return "0111";
		case'8':return "1000";
		case'9':return "1001";
		case'A':return "1010";
  		case'B':return "1011";
		case'C':return "1100";
		case'D':return "1101";
		case'E':return "1110";
		case'F':return "1111";
        default:return "";
	}
}

int main()
{
	int n;
	//string sixteen[10];	//��1<=n<=10��
	cin>>n;
    string *sixteen = new string[n];
	for(int i=0;i<n;i++)
	{
		cin>>sixteen[i];
	}
	for(int i=0;i<n;i++)
	{
		string eight;
		string two;
		char eig;
		for(int j=0;j<sixteen[i].length();j++)
			two+=trans(sixteen[i][j]);					//���ú���ʮ�������ַ������ÿ���ַ����ת������
		int m=two.length()%3;							//һλ�˽��Ƶ�����λ������
		if(m==1)two.insert(0,"00");						//�����1��0λ�ò�������0 (����ת���ɰ˽��ƶ��ճ���λ)
		else if(m==2)two.insert(0,"0");					//�����2��0λ�ò���һ��0
		if(!(two[0]=='0' && two[1]=='0' && two[2]=='0'))	//���insert���ǰ��λ���Ƕ�Ϊ0
		{
			eig=(two[0]-'0')*4+(two[1]-'0')*2+(two[2]);	 //4 2 1
			eight+=eig;									 //�˽����ַ����ĵ�һ���ַ�
		}
		for(int k=3;k<two.length();k+=3)
		{
			if(two.substr(k,3)=="000")eight+="0";		//��ȡk֮��������ַ�(����k) 
			else if(two.substr(k,3)=="001")eight+="1";
			else if(two.substr(k,3)=="010")eight+="2";
			else if(two.substr(k,3)=="011")eight+="3";
			else if(two.substr(k,3)=="100")eight+="4";
			else if(two.substr(k,3)=="101")eight+="5";
			else if(two.substr(k,3)=="110")eight+="6";
			else if(two.substr(k,3)=="111")eight+="7";
		}
		cout<<eight<<endl;
	}
	return 0;
}
