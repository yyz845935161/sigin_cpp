#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void FindMerge(vector<int>& candidates, int target,int cur,int num,vector<int> temp,vector<vector<int>>& ans)
    {
        for(int j=cur;j<candidates.size();j++)
        {
            if(num+candidates[j]>target) break;

            if (j > cur && candidates[j] == candidates[j - 1]) {
                continue;
            }

            num+=candidates[j];
            temp.push_back(candidates[j]);
            if(num==target)
            {
                ans.push_back(temp);
            }
            else
                FindMerge(candidates,target,j+1,num,temp,ans);


            num-=candidates[j];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        FindMerge(candidates,target,0,0,temp,ans);


    return ans;}
};