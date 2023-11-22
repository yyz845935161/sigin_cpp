class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto& e:magazine)
        {
            m[e]++;
        }

        for(auto& e:ransomNote)
        {
            m[e]--;
            if(m[e] < 0) return false;
        }
        return true;
    }
};