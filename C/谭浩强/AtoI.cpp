#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;


int myAtoi(char* str) {
        int i = 0;
	    long long int sum = 0;
        bool isNeg = false;
        for ( ; *str == ' '; str++);		//��ȥ�ո� 
        if(*str == '-'){					//���� 
            isNeg = true;
            str++;
        }
        else if(*str == '+') str++;				    //����
        while(*str!='\0' && *str>='0'&&*str<='9'){  //��������
            sum = sum*10 + *str - '0';
            str++;
        }
        if(isNeg) sum*=-1;                          //��������
        if (sum > INT_MAX) return INT_MAX;
        else if (sum < INT_MIN) return INT_MIN;
        else return sum;
    }


int main()
{
	char *str1 = "   2222222222";
	char *str2 = "-9812with words inside89038109382013";
	cout<<myAtoi(str1)<<endl;
	cout<<myAtoi(str2)<<endl;
	cout<<"INT_MAX:"<<INT_MAX<<endl;
	cout<<"INT_MIN:"<<INT_MIN<<endl;
	return 0;
}
