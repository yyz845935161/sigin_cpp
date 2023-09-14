/*

dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配
        a b * . *    
      1 0 0 0 0 0
    a 0 1 0 1 0 1
    b
    a

初始化：
    dp[0][0] = true： 代表两个空字符串能够匹配。
    dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*'： 首行 s 为空字符串

--两种方案
    当 p[j - 1] = '*' 
        1、 dp[i][j - 2]：                            p[j - 2] 看作出现 0 次时，能否匹配；
        2、dp[i - 1][j] && s[i - 1] == p[j - 2]:      p[j - 2] 看作至少出现 1 次时，能否 与s[i-1]这一个字符  匹配；
        3、dp[i - 1][j] && p[j - 2] == '.':           p[j - 2] 看作至少出现 1 次时，能否 .  匹配；


    当 p[j - 1] ！= '*' 
        1、dp[i - 1][j - 1] && s[i - 1] == p[j - 1]     前面的必须匹配，这次也必须匹配（字符）
        2、dp[i - 1][j - 1] && p[j - 1] == '.'          前面的必须匹配，这次也必须匹配（.）

*/


class Solution {
public:
    bool isMatch(string s, string p) {


            vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
            dp[0][0] = 1;
            for(int i=0;i<=p.size();i++)
            {
                if(i>=2 && dp[0][i-2] && p[i-1] == '*') dp[0][i]=1;
                cout<<  dp[0][i] << " ";
            }


            for(int i = 1;i<=s.size();i++)
            {
                for(int j = 1;j<=p.size();j++)
                {
                    if(p[j-1] == '*')
                    {
                        if(   ( j>=2 && dp[i][j-2] ) || ( dp[i-1][j]&& s[i-1] == p[j-2] )  ||  ( dp[i-1][j]&& '.' == p[j-2] ) )
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }
                    else{
                        if( ( dp[i-1][j-1]&& s[i-1] == p[j-1] ) || ( dp[i-1][j-1]&& '.' == p[j-1] ) )
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }
                    cout<< dp[i][j]<<" ";
                }
            }

            if(dp[s.size()][p.size()]) return true;
            else
             return false;

    }
};