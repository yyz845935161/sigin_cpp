#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void find_zu(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> temp,int index,int cur)
    {

        for(int i=index;i<candidates.size();i++)
        {
            if(cur+candidates[i]>target) break;
            if(cur+candidates[i]==target) 
            {
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                break;
            }
            cur +=candidates[i];
            temp.push_back(candidates[i]);
            find_zu(candidates,target,ans,temp,i,cur);
            cur -=candidates[i];
            temp.pop_back();    
        }
    
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        find_zu(candidates,target,ans,temp,0,0);
        return ans;

    }
};