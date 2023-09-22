class Solution {
public:
    int ans;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n-1);   //不可使用if和else
        ans+=n;
        return ans;
    }
};