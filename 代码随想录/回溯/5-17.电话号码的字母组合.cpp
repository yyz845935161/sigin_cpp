class Solution {
public:
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };
    string temp;
    vector<string> ans;

    void traceBack(int index, const string& digits)
    {
        
        if(temp.size() == digits.size())
        {
            ans.push_back(temp);
            return;
        }


        int pos = (int)(digits[index] - '0');
        cout<< pos<<" ";
        for(int j = 0; j < letterMap[pos].size(); j++)
        {
            temp += letterMap[pos][j];
            
            traceBack(index + 1, digits);
            temp.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        traceBack(0, digits);
        return ans;
    }
};