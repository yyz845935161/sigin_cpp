
#include <vector>
#include <iostream>

#include <map>
using namespace std;


// //解法一  复杂度会超
// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
//         map<int,int> m;
//         vector<int> ans;
//         for(auto& flower:flowers)
//         {
//             for(int i=flower[0];i<=flower[1];i++)
//             {
//                 m[i]++;
//             }
//         }

//         for(auto e:people)
//         {
//             ans.push_back(m[e]);
//         }
//         return ans;
//     }
// };


//差分 + 前缀和 的很棒的写法
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> m;
        vector<int> ans;
        //差分  记录start的开始位置 和 end的后一个位置
        for(auto& flower:flowers)
        {
            m[flower[0]]++;
            m[flower[1]+1]--;
        }

        for(auto& p:people)m[p];

        //前缀和
        int sum=0;
        for(auto& it:m)
        {
            sum+=it.second;
            it.second = sum; 
        }

        for(auto e:people)
        {
            ans.push_back(m[e]);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    vector<int> people = {3,3,2};
    a.fullBloomFlowers(flowers, people);
}