#include <vector>
#include <iostream>

#include <map>
using namespace std;



class Solution {
public:
    int pivotInteger(int n) {
        int left=0;
        int right = (1+n)*n/2 ;
        for(int i=1;i<=n;i++)
        {
            left+=i;
            if(left==right) return i;
            right-=i;
            

        }
        return -1;
    }
};