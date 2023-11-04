
#include <iostream>
using namespace std;
#include <set>
#include <vector>

vector<int> m(vector<vector<int>>& k_sorted_array)
{
    set<int> s;
    for (int i = 0; i < k_sorted_array.size();i++)
    {
        for (int j = 0; k_sorted_array[i].size(); j++)
        {
            s.insert(k_sorted_array[i][j]);
        }
    }

    vector<int>  ans(s.begin(),s.end());
    return ans;
}

int main()
{
}
