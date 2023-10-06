#include <functional>
#include <map>
#include <utility>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param groupA int整型vector 
     * @param groupB int整型vector 
     * @return int整型vector
     */
    struct less
    {
        bool operator()(const pair<int, int>& a,const pair<int, int>& b )
        {
            return a.first<=b.first;
        }
    };

    vector<int> advantageCount(vector<int>& groupA, vector<int>& groupB) {
        map<int,int> m;
        for(int& x:groupA)
        {
            m[x]++;
        }
        int n = groupB.size();
        vector<pair<int, int>>  sortB(n);
        vector<int>  ans(n);
        for(int i=0;i<n;i++)
        {
            sortB[i] = {groupB[i],i};
        }

        sort(sortB.begin(),sortB.end());

        for(int i=0;i<n;i++)
        {
            auto it = m.upper_bound(sortB[i].first);
            if(it != m.end())
            {
                ans[sortB[i].second] = it->first;
                it->second--;
                if( it->second == 0)
                {
                    m.erase(it);
                }
            }   
            else
            {
                ans[sortB[i].second] = (*m.begin()).first;
                (*m.begin()).second--;
                if( (*m.begin()).second == 0)
                {
                    m.erase(m.begin());
                }
            }
        }

        return ans;

    }
};