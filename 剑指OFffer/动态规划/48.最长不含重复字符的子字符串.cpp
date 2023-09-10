class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int ans=0;
        int temp = 0;
        int left = 0;
        for(int i=0;i<s.size();i++)
        {
            while(hash[s[i]]==1)
            {
                hash[s[left++]]=0;
                temp--;
            }
            temp++;
            hash[s[i]] =1;
            if(temp>ans) ans = temp;
        }

        return ans;
    }
};