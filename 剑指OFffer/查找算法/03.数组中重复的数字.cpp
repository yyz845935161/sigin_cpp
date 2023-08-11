
/*
它考察的是程序员的沟通能力，先问面试官要时间/空间需求！！！
1、只是时间优先就用字典，
2、还有空间要求，就用指针+原地排序数组，
3、原地交换
3、如果面试官要求空间O(1)并且不能修改原数组，还得写成二分法！！！
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int* v = new int[nums.size()];

        for(int i=0;i<nums.size();i++)
        {
            v[i]=0;
        }

        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]+=1;
            if(v[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};