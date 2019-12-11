#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void quicksort(vector<int> &nums, int low, int high){
    if(low<high){
        int i = low, j = high, temp = nums[low];
        while(i<j){
            while(i<j&&nums[j]>=temp) j--;//�� ���������ҵ�һ��С��temp��������Ϊ��j--�Ĺ����л����j<i���������while����б������i<j
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i]<= temp) i++;// ����������ҵ�һ�����ڵ���temp���� 
            if(i<j) nums[j--] = nums[i];
        }
        nums[i] = temp;
        quicksort(nums, low, i-1);
        quicksort(nums, i+1, high);
    }
}

void BubbleSort(int* nums, int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(nums[i]>nums[j])
            {
                int temp=nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    //vector<int> nums(n);
    int *nums = new int[n];
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }
    //quicksort(nums,0,n-1);
    BubbleSort(nums,n);
    for(int i=0; i<n; ++i)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}