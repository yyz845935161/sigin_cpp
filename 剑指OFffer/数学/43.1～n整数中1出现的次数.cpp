class Solution {
public:
    int countDigitOne(int n) {
        
        int temp = n;
        long long  cur = 1;

        int ans=0;
        while(temp)
        {
            int high = n / (cur*10);
            int low = n % cur;
            int cur_dig = n/cur % 10;

            if(cur_dig < 1)
            {
                ans += high *  cur;
            }
            else if(cur_dig == 1)
            {
                ans +=  (high *  cur) + low + 1;
            }
            else
            {
                ans += (high+1) * cur;
            }
          
            cur*=10;
            temp/=10;
        }

        return ans;
    }
};