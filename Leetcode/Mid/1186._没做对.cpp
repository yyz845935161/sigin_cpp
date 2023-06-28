#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> v_min;
        int val = 0;
        int max = INT16_MIN;
        int min = 0;
        int temp_min =  0;
        for(int i=0; i<arr.size();i++)
        {
            val+=arr[i];
            if(temp_min+arr[i]<temp_min)
            temp_min+=arr[i];
            else
            {
                if(temp_min<min)
                min = temp_min;
                temp_min=0;
            }
        }

        return val-min;

    }
};