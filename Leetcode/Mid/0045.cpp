class Solution {
public:
    int jump(vector<int>& nums) {
        vector<uint> v(nums.size()+1,-1);
        v[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j > nums.size()-1) break;

                v[i+j] = min(v[i+j],v[i]+1);

            }
        }
        // cout<<v[nums.size()-1];
        for(auto &e:v)
        {
            cout<<e<<' ';
        }

        return v[nums.size()-1];


    }
};