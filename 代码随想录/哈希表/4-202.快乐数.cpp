class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }


    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(n)
        {
            if(n == 1) return true;

            if(m.find(n)!=m.end()) return false;
            m[n] = getSum(n);
            n = m[n];
        }
        return false;
    }
};