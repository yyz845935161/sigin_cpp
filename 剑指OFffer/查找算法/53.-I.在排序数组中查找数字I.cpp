//方法一 找到以后顺序找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int begin=0,end = nums.size()-1;
        int index = -1;
        int ans=0;
        while(begin<=end)
        {
            int mid = (begin+end) / 2;
            if(nums[mid] == target)
            {
                index = mid;
                break;
            }
            else if(nums[mid] > target)
            {
                end=mid-1;
            }
            else if(nums[mid] < target)
            {
                begin=mid+1;
            }
        }
        if(index == -1) return 0;
        int temp=index;
        while(index >=0 && nums[index] == target)
        {
            ans++;
            index--;
        }
        while(temp <nums.size() && nums[temp]==target)
        {
            ans++;
            temp++;
        }
        return --ans;

    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int begin=0,end = nums.size()-1;
        int index = -1;
        int ans=0;
        
        int left = -1;
        int right = -1;

        while(begin<=end)
        {
            int mid = (begin+end)/2;
            if(nums[mid] >= target)
            {
                end = mid-1;
            }
            else
            {
                begin = mid+1;
            }
        }

        left= begin;
        begin = 0;
        end = nums.size()-1;
        while(begin<=end)
        {
            int mid = (begin+end)/2;
            if(nums[mid] <= target)
            {
                begin = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }

        right= end;
        return right-left+1;

    }
};