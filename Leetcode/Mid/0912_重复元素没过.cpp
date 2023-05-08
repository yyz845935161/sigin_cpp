
#include<iostream>
#include<vector>
using namespace std;

struct Less
{

    bool operator()(const int& a ,const int& b) const
    {
        return a<=b;
    }
};





class Solution {
public:
    
    int ThreeGetMind(int left,int right,vector<int>& nums)
    {
        int mid = left - (left - right)/2;
        if( (nums[left]-nums[mid])*(nums[mid]-nums[right])>0 ) 
        {
            swap(nums[mid],nums[right]);
        }
            
        else if( (nums[mid]-nums[left])*(nums[left]-nums[right])>0 ) swap(nums[left],nums[right]);
 
        return nums[right];
    }

    template<class Com = Less>
    int _QuickSork(int left,int right,vector<int>& nums)
    {
        Com _com;
        ThreeGetMind(left,right,nums);
        int key = nums[right];
        int keti = right;
        while(left<right)
        {
            while(left<right && _com(nums[left],key))
            {
                left++;
            }
            while(left<right && _com(key,nums[right]))
            {
                right--;
            }
            swap(nums[left],nums[right]);
        }
        swap(nums[keti],nums[right]);
        return left;

    }

    void QuickSork(int left,int right,vector<int>& nums)
    {
        if(left>=right) return;

            int mid = _QuickSork(left,right,nums);
            QuickSork(left,mid-1,nums);
            QuickSork(mid+1,right,nums);
        
    }




    vector<int> sortArray(vector<int>& nums) {
        QuickSork(0,nums.size()-1,nums);
        return nums;
    }
};