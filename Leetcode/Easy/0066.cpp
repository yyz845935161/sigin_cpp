#include <vector>
#include <iostream>

#include <map>
using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool is_jin =true;
        int index = digits.size()-1;
        while(is_jin)
        {
            if(index<0)
            {
                digits.insert(digits.begin(),1);
                break;
            }
            if(digits[index]+1 >9)
            {
                digits[index]=0;
                index--;
            }
            else
            {
                digits[index]++;
                is_jin = false;
            }
        }
        return digits;

    }
};