
//数学法  3要尽量多，剩下的选2
class Solution {
public:
    int cuttingRope(int n) {
       if(n<=3) return n-1;

        int e = 0;

        if(n%3 == 2)
        {
            e = n/3;
            return pow(3,e)*2;
        }
        else if(n%3 == 1)
        {
            e = n/3 -1;
            return pow(3,e)*2*2;
        }
        else
        {
            return pow(3,n/3);
        }
       


    }
};


//