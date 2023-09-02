
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

//动态规划  n超过一定数目会溢出
class Solution {
public:

    long long max(const long long& a,const long long& b)
    {
        return a>b?a:b;
    }

    int cuttingRope(int n) {
        vector<long long> v(n+1,0);

        v[2] = 1;  
        for(int i=3;i<=n;i++)
        {
            int tempmax = 0;
            int lengh = i;
            for(int j=2;j<i;j++)
            {
                v[i] = max(v[i] , max( (j*(i-j))   , (j*v[i-j])))% 1000000007 ;
            }
            cout<<v[i]<<" ";
        }

        return v[n];


    }
};


//
//适用于数据很大的情况
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        long res = 1;
        while(n > 4) {
            res = (res * 3) % 1000000007;
            n -= 3;
        }
        return (res * n) % 1000000007;  
    }
};