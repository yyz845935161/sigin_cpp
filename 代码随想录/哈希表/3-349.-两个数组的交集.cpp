class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> result;
        for(auto& e:nums1)
        {
            m[e]++;
        }
        for(auto& e:nums2)
        {
            if(m[e] > 0)  result.push_back(e);
            m[e]=0;
        }

        return result;


    }
};