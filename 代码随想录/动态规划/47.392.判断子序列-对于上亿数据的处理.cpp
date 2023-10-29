class Solution {
public:
	bool isSubsequence(string s, string t) {
		t.insert(t.begin(), ' ');
		int len1 = s.size(), len2 = t.size();
		
		vector<vector<int> > dp(len2 , vector<int>(26, 0));

		for (char c = 'a'; c <= 'z'; c++) {
			int nextPos = -1; //表示接下来再不会出现该字符

			for (int i = len2 - 1; i>= 0; i--) {  //为了获得下一个字符的位置，要从后往前
				dp[i][c - 'a'] = nextPos;
				if (t[i] == c)
					nextPos = i;
			}
		}
			cout<<" begin "<<endl;
        for(int i = 0;i<len2;i++)
        {
					cout<<t[i]<<"  ";
            for(int j = 0;j<26;j++)
            {
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }


		int index = 0;
		for (char c : s) {
			index = dp[index][c - 'a'];
			if (index == -1)
				return false;
		}
		return true;

	}

};

