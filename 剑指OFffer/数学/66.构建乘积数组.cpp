
/*
可以定义2个数组：left, right

left[i] 表示数组 a[i] 左边的数的乘积，不包含a[i]
right[i] 表示数组 a[i] 右边的数的乘积，不包含a[i]
最终 b[i] = left[i] * right[i]
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> left(n+1,1);
        vector<int> right(n+1,1);
        vector<int> ans(n,1);
        int temp=1;
        for(int i=0;i<n;i++)
        {
            left[i] = temp;
            temp*=a[i];
            
        }
        temp = 1;
        for(int i=n-1;i>=0;i--)
        {
            right[i] = temp;
            ans[i] = right[i]*left[i];
            cout<<left[i]<<" * "<<right[i]<<" = " <<ans[i]<<endl;
            temp*=a[i];
        }
        return ans;
    }
};