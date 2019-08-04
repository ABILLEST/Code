#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//4ms 8.1MB
//��λ��������λ��
class Solution {
public:
    int findNthDigit(int n) {
        long long level=1;		//������
        long long width=1;
        long long cnt=0;		//λ�����ۣ�ǰһλ�������ֵ�������ֵĸ����� 
        int num, pos, left;
        
		//ȷ��n����Ӧ���������Ϳ�� 
        while(cnt+9*level*width < n )	
        {
            cnt += (9*level*width);
            level*=10;
            ++width;
        }

        if((n-cnt)%width == 0)		//nָ�����ֵ����һλ
        {
            num = level+(n-cnt)/width-1;	//(n-cnt)/width�൱�ڵ�ǰ��������ƫ����
            left = width;
            pos = width-left+1;
        }
        else
        {
            num = level+(n-cnt)/width;
            left = (n-cnt)%width;
            pos = width-left+1;		//����ָ�����ֵ�λ��
        }
        
    	//ȡ��
        while(pos>1)	 //���磺pos==1�����������һλ
        {
            num/=10;
            --pos;
        }
    	// cout <<"ret="<<num%10<<endl;
        return (num%10);
    }
};

//8ms 8.5MB
/*
class Solution {
public:
	int findNthDigit(int n)
	{
	    if (n < 10)  return n;//step 1
	    
	    long long length = 0, cnt = 9, i = 1;
	    
	    for (; length + cnt*i < n; ++i){//step 2
	        length += cnt * i;
	        cnt *= 10;
	    }//step 3
	    
	    long long num = pow(10, i-1) + (n-length-1)/i;
	    long long index = (n-length-1)%i;
	    return to_string(num)[index]-'0';
	}
};
*/

int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.findNthDigit(n)<<endl;
}
