#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(){
    int k, l;
    cin >> k >> l;
    vector<vector<int>> dp(l+1, vector<int>(k, 0));//��0�в�ʹ�ã�������l+1��
    for (int i = 0; i < k;i++)//��ʼ��
        dp[1][i] = 1;
    
    for (int i = 2; i <= l;i++){//����Ϊl
        for (int j = 0; j < k;j++){//��k��β
            int sum = 0;
            for (int m = 0; m < k;m++){
                if(abs(m-j)!=1){
                    sum = (sum + dp[i - 1][m]) % 1000000007;
                }
                dp[i][j] = sum;
            }
        }
    }
    int result = 0;
    for (int i = 1; i < k;i++){
        result = (result + dp[l][i]) % 1000000007;
    }
    cout << result;
    //system("pause");
    return 0;

