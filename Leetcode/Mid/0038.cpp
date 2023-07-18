class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string temp = "1";
        int i=0;
        for(int i=1;i<n;i++)
        {
            ans.clear();
            for(int j=0;j<temp.size();)
            {
                int count =1;
                while(j+1<temp.size() && temp[j]==temp[j+1])
                {
                    count++;
                    j++;
                }
                ans+=(to_string(count));
                ans+=temp[j];
                j++;
            }
            temp=ans;

        }

        return ans;
    }
};