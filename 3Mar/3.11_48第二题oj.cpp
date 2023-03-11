#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <vector>

class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int>> mat, int n, int m) {
        // write code here
        vector<int> ans;
        int num = (min(n,m)+1)/2;
        int line_cur = 0;
        int column_cur = 0 ;
        int left = 0;
        int right = m;
        int top = 0;
        int botton=n;
        while(num--)
        {
             //如果剩下一列
            if(left+1 == right)
            {
                while(line_cur<botton)
                {
                    ans.push_back(mat[line_cur++][column_cur]);
                }
                return ans;
            }
            if(top+1 == botton)
            {
                while(column_cur < right)
                {
                    ans.push_back(mat[line_cur][column_cur++]);
                }
                return ans;
            }
            
            while(column_cur < right-1)
            {
                ans.push_back(mat[line_cur][column_cur++]);
            }
            while(line_cur<botton-1)
            {
                ans.push_back(mat[line_cur++][column_cur]);
            }
            while(left<column_cur)
            {
                ans.push_back(mat[line_cur][column_cur--]);
            }
            while(top<line_cur)
            {
                ans.push_back(mat[line_cur--][column_cur]);
            }
            left++;
            right--;
            top++;
            botton--;
            column_cur++;
            line_cur++;

        }
        
        return ans;
    }
};


void tsest01()
{
    // [[4,46,89],[28,66,99],[26,21,71]],3,3
    vector<vector<int>> v = {{4,46,89},
                            {28,66,99},
                            {26,21,71}};
    Printer a;
    a.clockwisePrint(v,3,3);

}

int main()
{
    tsest01();
    return 0;
}