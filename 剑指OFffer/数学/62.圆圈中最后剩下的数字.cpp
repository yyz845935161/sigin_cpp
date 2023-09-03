

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i] = i;
        }
        int ans = 0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            
            int time = 0;
            while (1)
            {
                while (v[j%n] == -1)
                {
                    j++;
                    j%=n;
                }
                time++;
                if(time == m)
                {
                    break;
                }
                j++;
                
            }

            


            cout<<v[j%n]<<" ";
            v[j%n] = -1;
            ans = j%n;

            // while(v[j%n] == -1)
            // {
            //     j++;
            //     j%=n;
            // }

        }
        return ans;
    }
};



#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans=0;
        for(int i=2;i<n+1;i++)
        {
            ans = (ans+m)%i;
        }
        return ans;
    }
};




int main()
{
    Solution a;
    a.lastRemaining(5,3);
}