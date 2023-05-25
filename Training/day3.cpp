// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    while(getline(cin, s))// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        int count=0;
        int last=0;
        int max_count=0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<='9'&& s[i]>='0')
            {
                count++;
            }
            if(!(s[i]<='9'&& s[i]>='0') || i==s.size()-1)
            {
                if(count>max_count)
                {
                    ans=s.substr(last,count);
                    max_count = count;
                }
                count=0;
                last=i+1;
            }
        }
        cout<<ans<<endl;
        
    }
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        int cur = numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++)
        {
            if(numbers[i]==cur)
            {
                count++;
            }
            else
            {
                count--;
                if(count<1)
                {
                    count=1;
                    cur = numbers[i];
                }
            }
        }
        return cur;
    }
};