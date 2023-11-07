class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int> a,vector<int> b){
            if(a[0] == b[0]) return a[1]<b[1];
            return a[0] > b[0];
        });

        list<vector<int>> ans;
        for(int i = 0;i < people.size();i++)
        {
            int index = people[i][1];
            auto it = ans.begin();
            while(index-- && it != ans.end())
            {
                it++;
            }
            ans.insert(it,people[i]);
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};