class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        for(int i=1;i<=target/2;i++)
        {
            vector<int>temp;
            int sum=0;
            for(int j=i;j<target;j++)
            {
                sum+=j;
                temp.push_back(j);
                if(sum == target)
                {
                    ans.push_back(temp);
                }
                else if(sum > target)
                {
                    break;
                }
            }
        }

        return ans;
    }
};