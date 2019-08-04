#include <iostream>
#include <string>
using namespace std;

//ֻ֧���������͵ļ��������
template<class T>
class Cryption { 

	T ptxt[100];	//����
	T ctxt[100];	//����
	T key;	//��Կ
	int len;	//����

public:
	Cryption(T tk, T tt[], int tl); //�������ζ�Ӧ��Կ�����ġ�����
	void Encrypt(); //����
	void Print() //��ӡ���������
	{	int i;
		for (i=0; i<len-1; i++)
			cout<<ctxt[i]<<" ";
		cout<<ctxt[i]<<endl;
	}
	T Max(T* txt,int n);
};

template<class T>
Cryption<T>::Cryption(T tk, T tt[], int tl)
{
	key = tk;
	len = tl;
	for(int i=0;i<len;i++)
		ptxt[i] = tt[i];
}

template<class T>
void Cryption<T>::Encrypt()
{
	T max_value = Max(ptxt,len);
	for(int i=0;i<len;i++)
	{
		ctxt[i] = key + (max_value - ptxt[i]);
	}
}

template <class T>
T Cryption<T>::Max(T* txt,int n)
{
	T max_value = txt[0];	//��Ҫ����һ�����������ֵҪ�ȸ�������ֵ�ı�������ֵ�� 
	
	for(int i=0;i<n;i++)
		if(txt[i]>max_value)
			max_value = txt[i];
	return max_value;
}


int main()
{	
	int i;
	int length; //����
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];

	//��������

	cin>>ik>>length;

	for (i=0; i<length; i++)
		cin>>itxt[i];

	Cryption<int> ic(ik, itxt, length);

	ic.Encrypt();

	ic.Print();

	//����������

	cin>>dk>>length;

	for (i=0; i<length; i++)
		cin>>dtxt[i];

	Cryption<double> dc(dk, dtxt, length);

	dc.Encrypt();

	dc.Print();

	//�ַ�����

	cin>>ck>>length;

	for (i=0; i<length; i++)
		cin>>ctxt[i];

	Cryption<char> cc(ck, ctxt, length);

	cc.Encrypt();

	cc.Print();

	return 0;

}
