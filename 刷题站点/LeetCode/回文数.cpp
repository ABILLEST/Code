#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
	�������ص㣺
		1.
		2. 
*/

/*
	����1��ת�ַ������� 
	����2����תȫ��������ʱ�䳤������Ҫ��������� 
	����2����תһ��
	����3����ͷ��λ�Ƚ�
	����4��������������ַ�����Ƚ� 
*/ 

class Solution
{
	public:
		//תString 
		bool isPalindrome(int x)
		{
			string originStr = to_string(x);
			string reversedStr = to_string(x);
			reverse(reversedStr.begin(), reversedStr.end());
			if(originStr == reversedStr)
				return true;
			else return false;
		}
		
		//��ת�������� 
		bool isPalindrome_2(int x)
		{
			int reversed=0, pop =0, _x=x;

			if(x<0) return false;
			while(x>0)
			{
				pop = x%10;
				//����ж�
				if(reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
				if(reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;
				reversed = reversed*10 + pop;
				x /= 10;
			}
			if(reversed==_x) return true;
			else return false;
		}
		
		//��ת���ֵ�һ�� 
		bool isPalindrome_3(int x)
		{
			
		}
};

int main()
{
	Solution s;
	int input;
	while(1)
	{
		cout<<"Enter number:";
		cin>>input;
		if(s.isPalindrome_2(input))
			cout<<"true\n"<<endl;
		else cout<<"false\n"<<endl;
	}

}
