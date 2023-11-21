class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto& e:s)
        {
            m[e]++;
        }
        for(auto& e:t)
        {
            m[e]--;
        }

        for(auto& e:m)
        {
            cout<<e.first<<" "<<e.second<<endl;
            if(e.second != 0) return false;
        }

        return true;
    }
};