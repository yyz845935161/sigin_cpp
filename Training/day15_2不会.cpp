// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a;
    while(cin >> a )// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        int ans=0;
        while(a)
        {
            if((a&1)==1) ans++;
            a = a>>1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_snum=0,left_min =INT16_MAX;
        int right_snum=0,right_min =INT16_MAX;
        int sum =0;
        for(int i=0;i<n;i++)
        {
            if(left[i]*right[i]==0)
            {
                sum+= (left[i]+right[i]);
            }
            else
            {
                left_snum+=left[i];
                right_snum+=right[i];
                left_min = (left_min < left[i]?left_min:left[i]);
                right_min = (right_min < right[i]?right_min:right[i]);
            }
        }
        sum = sum + min(left_snum - left_min,right_snum-right_min) +2;
        return sum;
    }
};