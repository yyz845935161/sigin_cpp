class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n,0);
        int a=0,b=0,c=0;
        v[0] = 1;
        for(int i=1;i<n;i++)
        {
            int n1 = v[a]*2,n2 = v[b]*3,n3 = v[c]*5;
            v[i] = min(min(n1,n2),n3);
            if(v[i] == n1) a++;
            if(v[i] == n2) b++;
            if(v[i] == n3) c++;

        }
        return v[n-1];
    }
};