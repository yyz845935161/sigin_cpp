class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size()-1;
        while(left < right)
        {
            int m = left +(right-left)/2;
            if(numbers[m]<numbers[right])
            {
                right = m;
            }
            else if(numbers[m] > numbers[right])
            {
                left = m+1;
            }
            else
            {
                right--;
            }
        }
        return numbers[left];
    }
};