class Solution {
public:
    vector<int> printNumbers(int n) {
        int num=1;
        for(int i=0;i<n;i++)
        {
            num*=10;
        }
        vector<int> v;
        v.reserve(num);
        for(int i=1;i<=num-1;i++)
        {
            v.push_back(i);
        }
        return v;

    }
};