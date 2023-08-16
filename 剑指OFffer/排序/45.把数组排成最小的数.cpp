
//想到排序 a+b  < b+a
struct MyLess
{
    bool operator()(const int& a1,const int& b1)
    {
        // atoi(to_string(a)+to_string(b)) < 
        int a = a1;
        int b = b1;
        string s1 = to_string(a)+to_string(b);
        string s2 = to_string(b)+to_string(a);
        return s1 < s2;
    }

};



class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),MyLess());
        string ans;
        for(auto &e :nums)
        {
            ans+=to_string(e);
            cout<<e<<" ";
        }
        return ans;
    }
};