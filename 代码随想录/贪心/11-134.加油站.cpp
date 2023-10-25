class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int cursum = 0;
        int start = 0;

        for(int i = 0;i < gas.size();i++)
        {
            total += gas[i] - cost[i];
            cursum += gas[i] - cost[i];
            if(cursum < 0)
            {
                start = i+1;
                cursum = 0;
            }

        }
        if(total < 0) return -1;
        return start;
    }
};