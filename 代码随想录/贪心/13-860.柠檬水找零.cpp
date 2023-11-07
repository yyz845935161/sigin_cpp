class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int v[3] = {0};
        for(int i = 0;i<bills.size();i++)
        {
            if(bills[i] == 5)
            {
                v[0]++;
            }
            else if(bills[i] == 10)
            {
                if(v[0] < 1)
                {
                    return false;
                }
                v[0]--;
                v[1]++;
            }
            else
            {
                if(v[1]>=1)
                {
                    v[1]--;
                    if(v[0] < 1)
                    {
                        return false;
                    }
                    v[0]--;
                }
                else
                {
                    if(v[0] < 3)
                    {
                        return false;
                    }
                    v[0]-=3;
                }
            }
        }

        return true;
    }
};