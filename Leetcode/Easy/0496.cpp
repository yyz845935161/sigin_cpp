class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        unordered_map<int,int> b;
        for(int i=0;i<nums2.size();i++)
        {
            a[i]=nums2[i];
            b[nums2[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int index = b[nums1[i]];
            for(int j=index;j<nums2.size();j++)
            {
                if(nums2[j]>nums1[i])
                {
                    ans.push_back(nums2[j]);
                    break;
                }

                if(j==nums2.size()-1)
                {
                    ans.push_back(-1);
                }

            }

        }

        return ans;
    }
};